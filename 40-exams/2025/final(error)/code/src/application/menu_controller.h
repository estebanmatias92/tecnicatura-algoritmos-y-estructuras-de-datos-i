#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include <string>
#include <vector>

// Forward declarations
class SucursalCRUD;
class VendedorCRUD;

enum class MenuState {
    MAIN_MENU,
    CREATE_MENU,
    READ_MENU,
    UPDATE_MENU,
    DELETE_MENU,
    SUCURSAL_MENU,
    VENDEDOR_MENU,
    EXIT
};

class MenuController {
private:
    MenuState currentState;
    SucursalCRUD* sucursalService;
    VendedorCRUD* vendedorService;

public:
    MenuController();
    ~MenuController();

    // Main menu loop
    void run();

    // Display menu functions
    void displayMainMenu();
    void displayCreateMenu();
    void displayReadMenu();
    void displayUpdateMenu();
    void displayDeleteMenu();

    // Navigation functions
    void navigateTo(MenuState newState);
    MenuState handleInput(const std::string& input);
    
    // Menu operation handlers
    void handleCreateOperations();
    void handleReadOperations();
    void handleUpdateOperations();
    void handleDeleteOperations();
    
    // Utility functions
    void displayMessage(const std::string& msg);
    void clearScreen();
};

#endif // MENU_CONTROLLER_H