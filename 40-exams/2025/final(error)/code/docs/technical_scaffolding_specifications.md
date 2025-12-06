# Technical Scaffolding Specifications

## Overview

This document outlines the technical non-functional specifications for the project scaffolding. It describes the architectural patterns, build automation, containerization, and development workflow that can be reused across different applications.

## Project Structure (Pitchfork Layout)

The project follows the Pitchfork layout pattern, which separates application concerns into distinct directories:

```bash
project-root/
├── compose.yaml (root-level orchestration)
├── Makefile (build automation shortcuts)
├── .env (environment configuration)
├── .gitignore (version control exclusions)
├── README.md (project documentation)
└── core-service/ (main application service)
    ├── .dockerignore (Docker build exclusions)
    ├── Dockerfile (container image definition)
    ├── compose.yaml (service-specific orchestration)
    ├── build.sh (compilation script)
    ├── run.sh (execution script)
    ├── build/ (compiled artifacts output)
    ├── data/ (data files directory)
    ├── docs/ (documentation files)
    ├── include/ (header files)
    │   ├── app/ (application layer headers)
    │   ├── domain/ (domain layer headers)
    │   └── utils/ (utility headers)
    └── src/ (source code files)
        ├── app/ (application layer implementations)
        ├── domain/ (domain layer implementations)
        ├── utils/ (utility implementations)
        └── main.cpp (application entry point)
```

### Directory Purpose and Scope

- **core-service**: Contains the main application service with all business logic
- **include**: Contains header files organized by functional layers (app, domain, utils)
- **src**: Contains implementation files matching the include directory structure
- **build**: Output directory for compiled binaries (excluded from version control)
- **docs**: Documentation files (requirements, diagrams, technical specs)
- **data**: Static data files for the application

## Containerization Strategy

### Docker Multi-Stage Build Pattern

The project implements a multi-stage Docker build with four distinct targets:

1. **base_env**: Base image with build tools and dependencies
2. **builder**: Compilation stage that builds the application
3. **development**: Interactive environment with pre-built binaries
4. **production**: Minimal runtime image for deployment

#### Base Environment Stage

- Uses `gcc:11` as the foundation
- Sets up build directory structure
- Copies source and include directories
- Copies build and run scripts for containerized operations

#### Builder Stage

- Inherits from base environment
- Executes build script to compile the application
- Creates the final executable in the build directory

#### Development Stage

- Inherits from base environment
- Copies compiled binaries from builder stage
- Provides interactive bash environment for development
- Supports live development with volume mounts

#### Production Stage

- Uses minimal `alpine:latest` image
- Installs only required runtime dependencies
- Copies executable from builder stage
- Uses run script as the entry point

### Docker Compose Configuration

The project uses two separate compose files for different purposes:

#### Root-level compose.yaml

- Contains production service configuration
- Uses production build target
- Configured for deployment scenarios

#### Service-level compose.yaml

- Contains development service configurations
- Includes three distinct services:
  - `dev_interactive`: Interactive development environment (profile: "interactive")
  - `run_dev_app`: Application runner for development
  - `isolated_tool`: Separate service for ad-hoc tasks (profile: "tools")

## Build Automation

### Shell Scripts

#### build.sh

- Compiles C++ applications using g++
- Uses find and xargs to automatically locate all .cpp files
- Supports multiple include directories (-I flags)
- Provides success/failure feedback
- Creates executable in build directory

#### run.sh

- Executes the compiled application
- Accepts project root as parameter
- Locates executable in build directory
- Simple execution wrapper

### Makefile Integration

The Makefile provides standardized targets for common operations:

#### Production Operations

- `up-prod`: Start production services with build
- `down-prod`: Stop production services
- `logs-prod`: Follow production logs
- `clean-prod`: Stop services and remove volumes

#### Development Operations

- `up-dev`: Start development services with build
- `run-dev`: Run development container interactively
- `down-dev`: Stop development services
- `logs-dev`: Follow development logs
- `clean-dev`: Stop services and remove volumes
- `config-dev`: Show development configuration

### Environment Configuration

- Uses .env file for environment variables
- Includes .env in Makefile for variable export
- Supports different environments through compose profiles

## Build and Execution Workflow

### Local Development

1. Navigate to core-service directory
2. Set execute permissions on scripts: `chmod +x build.sh run.sh`
3. Compile: `./build.sh`
4. Execute: `./run.sh`

### Docker Development

1. Use `make run-dev` for interactive development
2. Or `docker compose --profile interactive run --rm dev_interactive`
3. Volume mounts keep source changes synchronized

### Production Deployment

1. Use `make up-prod` from project root
2. Or `docker compose up --build` from project root
3. Uses production multi-stage target

## Technical Constraints and Standards

### Build Process Standards

- All compilation artifacts must be placed in build directory
- No compilation dependencies in runtime image
- Build process must be deterministic and reproducible
- Scripts must provide meaningful error messages

### Container Image Standards

- Multi-stage builds to minimize image size
- Minimal base images (Alpine for production)
- Proper dependency segregation (build vs runtime)
- Security-focused image selection

### Development Environment Standards

- Isolated development containers
- Volume-based live reloading
- Profile-based service orchestration
- Interactive capabilities for debugging

## Reusability Guidelines

### For New Projects

1. Replicate the Pitchfork directory structure
2. Update Docker ARG values for different source directories if needed
3. Modify build script to handle different compilation requirements
4. Adjust compose services based on application needs
5. Maintain the multi-stage build pattern for consistency

### Customization Points

- SRC_HOST_DIR and SRC_CONTAINER_DIR: Adjust for different source locations
- EXECUTABLE_NAME: Change for different application names
- Include directories: Modify based on project structure
- Compose services: Add/remove based on service requirements
- Build commands: Update for different languages/build systems
