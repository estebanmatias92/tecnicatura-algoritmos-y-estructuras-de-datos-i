#include "menu_controller.h"
#include <iostream>
#include <limits>

MenuController::MenuController() : currentState(MenuState::MAIN_MENU), sucursalService(nullptr), vendedorService(nullptr)
{
    // Initialize services, potentially via dependency injection
    // For now, these will be set externally or created as needed
}

MenuController::~MenuController()
{
    // Cleanup if needed
}

void MenuController::run()
{
    std::string input;

    while (currentState != MenuState::EXIT)
    {
        switch (currentState)
        {
        case MenuState::MAIN_MENU:
            displayMainMenu();
            break;
        case MenuState::CREATE_MENU:
            displayCreateMenu();
            break;
        case MenuState::READ_MENU:
            displayReadMenu();
            break;
        case MenuState::UPDATE_MENU:
            displayUpdateMenu();
            break;
        case MenuState::DELETE_MENU:
            displayDeleteMenu();
            break;
        default:
            displayMainMenu(); // Default to main menu
            break;
        }

        std::cout << "\nEnter your choice: ";
        std::getline(std::cin, input);
        currentState = handleInput(input);
    }

    std::cout << "Exiting application. Goodbye!" << std::endl;
}

void MenuController::displayMainMenu()
{
    clearScreen();
    std::cout << "\n================================================" << std::endl;
    std::cout << "         VENDOR MANAGEMENT SYSTEM" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "                 MAIN MENU" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "1. Create Operations" << std::endl;
    std::cout << "2. Read/View Operations" << std::endl;
    std::cout << "3. Update Operations" << std::endl;
    std::cout << "4. Delete Operations" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "================================================" << std::endl;
}

void MenuController::displayCreateMenu()
{
    clearScreen();
    std::cout << "\n================================================" << std::endl;
    std::cout << "              CREATE OPERATIONS" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "1. Create New Sucursal" << std::endl;
    std::cout << "2. Create New Vendedor" << std::endl;
    std::cout << "3. Go Back to Main Menu" << std::endl;
    std::cout << "================================================" << std::endl;
}

void MenuController::displayReadMenu()
{
    clearScreen();
    std::cout << "\n================================================" << std::endl;
    std::cout << "              READ/VIEW OPERATIONS" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "1. View All Sucursales" << std::endl;
    std::cout << "2. View All Vendedores" << std::endl;
    std::cout << "3. Search/Filter Options" << std::endl;
    std::cout << "4. Go Back to Main Menu" << std::endl;
    std::cout << "================================================" << std::endl;
}

void MenuController::displayUpdateMenu()
{
    clearScreen();
    std::cout << "\n================================================" << std::endl;
    std::cout << "              UPDATE OPERATIONS" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "1. Update Sucursal" << std::endl;
    std::cout << "2. Update Vendedor" << std::endl;
    std::cout << "3. Go Back to Main Menu" << std::endl;
    std::cout << "================================================" << std::endl;
}

void MenuController::displayDeleteMenu()
{
    clearScreen();
    std::cout << "\n================================================" << std::endl;
    std::cout << "              DELETE OPERATIONS" << std::endl;
    std::cout << "================================================" << std::endl;
    std::cout << "1. Delete Sucursal" << std::endl;
    std::cout << "2. Delete Vendedor" << std::endl;
    std::cout << "3. Go Back to Main Menu" << std::endl;
    std::cout << "================================================" << std::endl;
}

MenuState MenuController::handleInput(const std::string &input)
{
    // Validate input is numeric
    if (input.length() == 0 || !isdigit(input[0]))
    {
        displayMessage("Invalid input. Please enter a number.");
        return currentState; // Stay in current state
    }

    int choice = std::stoi(input);

    switch (currentState)
    {
    case MenuState::MAIN_MENU:
        switch (choice)
        {
        case 1:
            return MenuState::CREATE_MENU;
        case 2:
            return MenuState::READ_MENU;
        case 3:
            return MenuState::UPDATE_MENU;
        case 4:
            return MenuState::DELETE_MENU;
        case 5:
            return MenuState::EXIT;
        default:
            displayMessage("Invalid choice. Please select a valid option.");
            return MenuState::MAIN_MENU;
        }

    case MenuState::CREATE_MENU:
        switch (choice)
        {
        case 1:
            handleCreateOperations();      // This would trigger Sucursal creation
            return MenuState::CREATE_MENU; // Stay in create menu
        case 2:
            handleCreateOperations();      // This would trigger Vendedor creation
            return MenuState::CREATE_MENU; // Stay in create menu
        case 3:
            return MenuState::MAIN_MENU;
        default:
            displayMessage("Invalid choice. Please select a valid option.");
            return MenuState::CREATE_MENU;
        }

    case MenuState::READ_MENU:
        switch (choice)
        {
        case 1:
            handleReadOperations();      // This would trigger Sucursal viewing
            return MenuState::READ_MENU; // Stay in read menu
        case 2:
            handleReadOperations();      // This would trigger Vendedor viewing
            return MenuState::READ_MENU; // Stay in read menu
        case 3:
            handleReadOperations();      // This would trigger filtering
            return MenuState::READ_MENU; // Stay in read menu
        case 4:
            return MenuState::MAIN_MENU;
        default:
            displayMessage("Invalid choice. Please select a valid option.");
            return MenuState::READ_MENU;
        }

    case MenuState::UPDATE_MENU:
        switch (choice)
        {
        case 1:
            handleUpdateOperations();      // This would trigger Sucursal update
            return MenuState::UPDATE_MENU; // Stay in update menu
        case 2:
            handleUpdateOperations();      // This would trigger Vendedor update
            return MenuState::UPDATE_MENU; // Stay in update menu
        case 3:
            return MenuState::MAIN_MENU;
        default:
            displayMessage("Invalid choice. Please select a valid option.");
            return MenuState::UPDATE_MENU;
        }

    case MenuState::DELETE_MENU:
        switch (choice)
        {
        case 1:
            handleDeleteOperations();      // This would trigger Sucursal deletion
            return MenuState::DELETE_MENU; // Stay in delete menu
        case 2:
            handleDeleteOperations();      // This would trigger Vendedor deletion
            return MenuState::DELETE_MENU; // Stay in delete menu
        case 3:
            return MenuState::MAIN_MENU;
        default:
            displayMessage("Invalid choice. Please select a valid option.");
            return MenuState::DELETE_MENU;
        }

    default:
        return MenuState::MAIN_MENU;
    }
}

void MenuController::handleCreateOperations()
{
    displayMessage("Create operation handler would be implemented here.");
    // In a real implementation, this would handle the specific create operation
}

void MenuController::handleReadOperations()
{
    displayMessage("Read operation handler would be implemented here.");
    // In a real implementation, this would handle the specific read operation
}

void MenuController::handleUpdateOperations()
{
    displayMessage("Update operation handler would be implemented here.");
    // In a real implementation, this would handle the specific update operation
}

void MenuController::handleDeleteOperations()
{
    displayMessage("Delete operation handler would be implemented here.");
    // In a real implementation, this would handle the specific delete operation
}

void MenuController::displayMessage(const std::string &msg)
{
    std::cout << "\n>>> " << msg << " <<<" << std::endl;
}

void MenuController::clearScreen()
{
    /*#ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif*/
}