# Stage 1: Base image for building and development setup
FROM gcc:11 AS base_env

ARG SRC_HOST_DIR=./src
ARG SRC_CONTAINER_DIR=/app/src
ARG BUILD_DIR=/app/build
ARG EXECUTABLE_NAME=main

WORKDIR /app
RUN mkdir -p ${BUILD_DIR}

COPY ${SRC_HOST_DIR}/ ${SRC_CONTAINER_DIR}/
COPY ./include /app/include

# --- NUEVO: Copiar los scripts de build y run ---
COPY build.sh run.sh /app/
RUN chmod +x /app/build.sh /app/run.sh

# Stage 2: Builder - compiles the application
FROM base_env AS builder

# --- CAMBIO: Usar el script de build ---
RUN /app/build.sh

# Stage 3: Development - interactive environment with pre-built binaries
FROM base_env AS development

COPY --from=builder ${BUILD_DIR}/ ${BUILD_DIR}/

CMD ["bash"]

# Stage 4: Production/Runtime - smallest image for deployment
FROM alpine:latest AS production

RUN apk add --no-cache libstdc++

WORKDIR /app

COPY --from=builder ${BUILD_DIR}/ ${BUILD_DIR}/
# --- NUEVO: Copiar el script de run ---
COPY --from=builder /app/run.sh /app/run.sh

# --- CAMBIO: El entrypoint ahora es el script de run ---
ENTRYPOINT ["/app/run.sh"]