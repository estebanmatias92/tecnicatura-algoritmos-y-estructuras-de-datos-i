#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <cctype>

const int MAX_CLIENTS = 100;
const std::string CLIENTS_DB_CONNECTION = "clients.txt";

typedef struct
{
    std::string client_code = "N/A";
    std::string name = "Desconocido";
    unsigned int phone = 0;
    std::string email = "N/A";
} Client;

typedef struct
{
    Client items[MAX_CLIENTS];
    int length = 0;
} ClientArray;

void clear_input_buffer();
void trim_leading_whitespace(std::string& s);
void clear_screen();
void press_enter_to_continue();

Client read_client_data_from_console();
Client read_client_from_file(std::ifstream& input_file);
ClientArray load_clients();
bool write_client_to_file(std::ofstream& output_file, const Client& client_item);
bool save_clients(const ClientArray& clients_to_save);
void add_client(ClientArray& clients_to_add_to);
void list_all_clients(const ClientArray& clients_to_display);
int find_client_index_by_code(const ClientArray& clients, const std::string& client_code);
void search_client_by_code_and_display(const ClientArray& clients);
void delete_client_by_code(ClientArray& clients);
void modify_client_data(ClientArray& clients);
void display_main_menu();
bool handle_menu_choice(int choice, ClientArray& current_client_list);
void run_app();


int main()
{
    run_app();
    return 0;
}


void clear_input_buffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void trim_leading_whitespace(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void press_enter_to_continue() {
    std::cout << "\nPresione Enter para continuar...";
    clear_input_buffer();
}

Client read_client_data_from_console()
{
    Client client_item;

    std::cout << "\n  Nombre Completo: ";
    std::getline(std::cin, client_item.name);

    if (std::cin.fail())
    {
        std::cerr << "[ERROR_LEER_CLIENTE]: Error en el flujo de entrada al leer el nombre." << std::endl;
        return Client();
    }

    std::cout << "  Teléfono: ";
    std::cin >> client_item.phone;
    if (std::cin.fail()) {
        std::cerr << "[ERROR_LEER_CLIENTE]: Fallo al leer el teléfono para el nombre '" << client_item.name << "'." << std::endl;
        clear_input_buffer();
        return Client();
    }
    clear_input_buffer();

    std::cout << "  Email: ";
    std::cin >> client_item.email;
    if (std::cin.fail()) {
        std::cerr << "[ERROR_LEER_CLIENTE]: Fallo al leer el email para el nombre '" << client_item.name << "'." << std::endl;
        clear_input_buffer();
        return Client();
    }
    clear_input_buffer();

    return client_item;
}

Client read_client_from_file(std::ifstream& input_file)
{
    Client client_item;

    input_file >> client_item.client_code;

    if (input_file.fail())
    {
        std::string line_content;
        input_file.clear();
        std::getline(input_file, line_content);
        trim_leading_whitespace(line_content);

        if (line_content == "X") { input_file.setstate(std::ios::failbit); }

        return Client();
    }

    input_file >> client_item.phone;
    if (input_file.fail()) { std::cerr << "[ERROR_LEER_CLIENTE]: Fallo al leer el teléfono del archivo para el código '" << client_item.client_code << "'." << std::endl; return Client(); }

    input_file >> client_item.email;
    if (input_file.fail()) { std::cerr << "[ERROR_LEER_CLIENTE]: Fallo al leer el email del archivo para el código '" << client_item.client_code << "'." << std::endl; return Client(); }
    
    std::getline(input_file, client_item.name);
    
    if (client_item.name == "X") 
    {
        input_file.setstate(std::ios::failbit);
        return Client();
    }

    trim_leading_whitespace(client_item.name);

    if (input_file.fail())
    {
        std::cerr << "[ERROR_LEER_CLIENTE]: Fallo al leer el nombre del archivo para el código '" << client_item.client_code << "'." << std::endl;
        return Client();
    }

    return client_item;
}

ClientArray load_clients()
{
    std::ifstream input_file(CLIENTS_DB_CONNECTION);
    ClientArray clients_in_file;

    if (!input_file.is_open())
    {
        std::cout << "[INFO]: No se encontraron datos de clientes existentes. Se iniciará una nueva lista." << std::endl;
        return clients_in_file;
    }

    while (true)
    {
        Client temp_client = read_client_from_file(input_file);

        if (input_file.fail())
        {
            if (!input_file.eof())
            {
                std::cout << "[INFO_CARGAR_CLIENTES]: La carga de la lista de clientes terminó por centinela 'X' o error de formato." << std::endl;
            }
            break;
        }

        if (clients_in_file.length >= MAX_CLIENTS)
        {
            std::cout << "[ADVERTENCIA_CARGAR_CLIENTES]: Se alcanzó el límite máximo de clientes (" << MAX_CLIENTS << "). No se pueden cargar más clientes." << std::endl;
            break;
        }

        clients_in_file.items[clients_in_file.length] = temp_client;
        clients_in_file.length++;
    }

    input_file.close();
    return clients_in_file;
}

bool write_client_to_file(std::ofstream& output_file, const Client& client_item)
{
    output_file << client_item.client_code << " "
                << client_item.phone << " "
                << client_item.email << " "
                << client_item.name << std::endl;

    if (output_file.fail())
    {
        std::cerr << "[ERROR_ESCRIBIR_DETALLES]: Fallo al escribir datos para el cliente con código '" << client_item.client_code << "'." << std::endl;
        return false;
    }

    return true;
}

bool save_clients(const ClientArray& clients_to_save)
{
    std::ofstream output_file(CLIENTS_DB_CONNECTION);

    if (!output_file.is_open())
    {
        std::cerr << "[ERROR_GUARDAR_CLIENTES]: No se pudo abrir el archivo '" << CLIENTS_DB_CONNECTION << "' para guardar." << std::endl;
        return false;
    }

    for (int i = 0; i < clients_to_save.length; ++i)
    {
        if (!write_client_to_file(output_file, clients_to_save.items[i]))
        {
            std::cerr << "[ERROR_GUARDAR_CLIENTES]: Fallo al guardar el cliente con código '" << clients_to_save.items[i].client_code << "'. Operación de guardado incompleta." << std::endl;
            output_file.close();
            return false;
        }
    }

    output_file << "X" << std::endl;

    output_file.close();

    if (output_file.fail())
    {
        std::cerr << "[ERROR_GUARDAR_CLIENTES]: Ocurrió un error al escribir o cerrar el archivo '" << CLIENTS_DB_CONNECTION << "'." << std::endl;
        return false;
    }

    return true;
}

void add_client(ClientArray& clients_to_add_to)
{
    std::cout << "\n--- Ingresar Nuevo Cliente ---\n" << std::endl;
    char continue_adding_choice = 'y';

    while (clients_to_add_to.length < MAX_CLIENTS && (continue_adding_choice == 'y' || continue_adding_choice == 'Y'))
    {
        std::string new_client_code = "C" + std::to_string(100 + clients_to_add_to.length);

        std::cout << "\n--- Añadiendo Cliente " << (clients_to_add_to.length + 1) << " (Código: " << new_client_code << ") ---\n" << std::endl;
        Client new_client = read_client_data_from_console();

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "Entrada inválida detectada para el cliente. Por favor, inténtelo de nuevo o elija detenerse." << std::endl;
        } else {
            new_client.client_code = new_client_code;
            clients_to_add_to.items[clients_to_add_to.length] = new_client;
            clients_to_add_to.length++;
            std::cout << "Cliente '" << new_client.name << "' añadido con código: " << new_client.client_code << std::endl;
        }
        
        if (clients_to_add_to.length < MAX_CLIENTS)
        {
            std::cout << "\n¿Desea continuar añadiendo clientes? (s/N): ";
            std::cin >> continue_adding_choice;
            clear_input_buffer();
        } else {
            std::cout << "\n[ADVERTENCIA]: Se alcanzó el límite máximo de clientes (" << MAX_CLIENTS << "). No se pueden añadir más clientes." << std::endl;
            continue_adding_choice = 'n';
        }
    }
    std::cout << "\n--- Entrada de clientes completada. ---" << std::endl;
    if (save_clients(clients_to_add_to)) {
        std::cout << "Lista de clientes guardada." << std::endl;
    } else {
        std::cerr << "Fallo al guardar la lista de clientes actualizada." << std::endl;
    }
}

void list_all_clients(const ClientArray& clients_to_display)
{
    std::cout << "\n--- Lista Actual de Clientes ---\n" << std::endl;

    if (clients_to_display.length == 0)
    {
        std::cout << "La lista de clientes está vacía." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(10) << "Código"
              << std::left << std::setw(30) << "Nombre"
              << std::left << std::setw(15) << "Teléfono"
              << std::left << std::setw(30) << "Email"
              << std::endl;
    std::cout << std::string(85, '-') << std::endl;

    for (int i = 0; i < clients_to_display.length; ++i)
    {
        std::cout << std::left << std::setw(10) << clients_to_display.items[i].client_code
                  << std::left << std::setw(30) << clients_to_display.items[i].name
                  << std::left << std::setw(15) << clients_to_display.items[i].phone
                  << std::left << std::setw(30) << clients_to_display.items[i].email
                  << std::endl;
    }

    std::cout << std::string(85, '-') << std::endl;
    std::cout << "Total de clientes: " << clients_to_display.length << std::endl;
}

int find_client_index_by_code(const ClientArray& clients, const std::string& client_code) {
    for (int i = 0; i < clients.length; ++i) {
        if (clients.items[i].client_code == client_code) {
            return i;
        }
    }
    return -1;
}

void search_client_by_code_and_display(const ClientArray& clients) {
    std::cout << "\n--- Buscar Cliente por Código ---\n" << std::endl;
    std::string code_to_search;
    std::cout << "Ingrese el código del cliente a buscar (ej. C100): ";
    std::cin >> code_to_search;
    clear_input_buffer();

    int found_index = find_client_index_by_code(clients, code_to_search);

    if (found_index != -1) {
        const Client& client_found = clients.items[found_index];
        std::cout << "\n--- Cliente Encontrado ---" << std::endl;
        std::cout << "  Código:   " << client_found.client_code << std::endl;
        std::cout << "  Nombre:   " << client_found.name << std::endl;
        std::cout << "  Teléfono: " << client_found.phone << std::endl;
        std::cout << "  Email:    " << client_found.email << std::endl;
        std::cout << "--------------------------" << std::endl;
    } else {
        std::cout << "\nCliente con código '" << code_to_search << "' no encontrado." << std::endl;
    }
}


void delete_client_by_code(ClientArray& clients) {
    std::cout << "\n--- Eliminar Cliente ---\n" << std::endl;
    list_all_clients(clients);

    std::string code_to_delete;
    std::cout << "\nIngrese el código del cliente a eliminar (ej. C100): ";
    std::cin >> code_to_delete;
    clear_input_buffer();

    int found_index = find_client_index_by_code(clients, code_to_delete);

    if (found_index != -1) {
        std::cout << "\n¿Está seguro de que desea eliminar al cliente: " 
                  << clients.items[found_index].name << " (Código: " 
                  << clients.items[found_index].client_code << ")? (s/N): ";
        char confirm_choice;
        std::cin >> confirm_choice;
        clear_input_buffer();

        if (confirm_choice == 's' || confirm_choice == 'S') {
            for (int i = found_index; i < clients.length - 1; ++i) {
                clients.items[i] = clients.items[i + 1];
            }
            clients.length--;
            std::cout << "\nCliente con código '" << code_to_delete << "' eliminado exitosamente." << std::endl;
            for (int i = 0; i < clients.length; ++i) {
                clients.items[i].client_code = "C" + std::to_string(100 + i);
            }

            if (save_clients(clients)) {
                std::cout << "Lista de clientes guardada." << std::endl;
            } else {
                std::cerr << "Fallo al guardar la lista de clientes actualizada." << std::endl;
            }
        } else {
            std::cout << "\nEliminación cancelada." << std::endl;
        }
    } else {
        std::cout << "\nCliente con código '" << code_to_delete << "' no encontrado." << std::endl;
    }
}

void modify_client_data(ClientArray& clients) {
    std::cout << "\n--- Modificar Datos del Cliente ---\n" << std::endl;
    list_all_clients(clients);

    std::string code_to_modify;
    std::cout << "\nIngrese el código del cliente a modificar (ej. C100): ";
    std::cin >> code_to_modify;
    clear_input_buffer();

    int found_index = find_client_index_by_code(clients, code_to_modify);

    if (found_index != -1) {
        Client& client_ref = clients.items[found_index];
        
        clear_screen();
        std::cout << "\n--- Modificando Cliente: " << client_ref.name << " (Código: " << client_ref.client_code << ") ---\n" << std::endl;
        std::cout << "  Datos Actuales:" << std::endl;
        std::cout << "    Nombre:   " << client_ref.name << std::endl;
        std::cout << "    Teléfono: " << client_ref.phone << std::endl;
        std::cout << "    Email:    " << client_ref.email << std::endl;

        int choice;
        std::cout << "\n¿Qué desea modificar?" << std::endl;
        std::cout << "1. Nombre" << std::endl;
        std::cout << "2. Número de Teléfono" << std::endl;
        std::cout << "3. Email" << std::endl;
        std::cout << "\nIngrese su elección: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cerr << "Entrada inválida. Por favor, ingrese un número." << std::endl;
            std::cin.clear();
            clear_input_buffer();
            return;
        }
        clear_input_buffer();

        switch (choice) {
            case 1:
                std::cout << "  Nombre Actual: " << client_ref.name << std::endl;
                std::cout << "  Ingrese nuevo nombre: ";
                std::getline(std::cin, client_ref.name);
                break;
            case 2:
                std::cout << "  Número de Teléfono Actual: " << client_ref.phone << std::endl;
                std::cout << "  Ingrese nuevo número de teléfono: ";
                std::cin >> client_ref.phone;
                if (std::cin.fail()) { std::cerr << "Número de teléfono inválido." << std::endl; }
                clear_input_buffer();
                break;
            case 3:
                std::cout << "  Email Actual: " << client_ref.email << std::endl;
                std::cout << "  Ingrese nuevo email: ";
                std::cin >> client_ref.email;
                if (std::cin.fail()) { std::cerr << "Email inválido." << std::endl; }
                clear_input_buffer();
                break;
            default:
                std::cout << "Elección de modificación inválida." << std::endl;
                break;
        }

        std::cout << "\nDatos del cliente modificados exitosamente." << std::endl;
        if (save_clients(clients)) {
            std::cout << "Lista de clientes guardada." << std::endl;
        } else {
            std::cerr << "Fallo al guardar la lista de clientes actualizada." << std::endl;
        }
    } else {
        std::cout << "\nCliente con código '" << code_to_modify << "' no encontrado." << std::endl;
    }
}

void display_main_menu() {
    std::cout << "\n--- Sistema de Gestión de Clientes 'Productos de Granja' ---\n" << std::endl;
    std::cout << "1. Dar de alta Cliente" << std::endl;
    std::cout << "2. Dar de Baja Cliente (código)" << std::endl;
    std::cout << "3. Modificar Cliente (código)" << std::endl;
    std::cout << "4. Listar todos los Clientes" << std::endl;
    std::cout << "5. Buscar un Cliente (código)" << std::endl;
    std::cout << "0. Salir de la Aplicación" << std::endl;
    std::cout << "\nIngrese su elección: ";
}

bool handle_menu_choice(int choice, ClientArray& current_client_list) {
    switch (choice)
    {
        case 1:
            add_client(current_client_list);
            press_enter_to_continue();
            return true;
        case 2:
            delete_client_by_code(current_client_list);
            press_enter_to_continue();
            return true;
        case 3:
            modify_client_data(current_client_list);
            press_enter_to_continue();
            return true;
        case 4:
            list_all_clients(current_client_list);
            press_enter_to_continue();
            return true;
        case 5:
            search_client_by_code_and_display(current_client_list);
            press_enter_to_continue();
            return true;
        case 0:
            std::cout << "\nSaliendo de la aplicación. Guardando la lista de clientes actual..." << std::endl;
            return false;
        default:
            std::cout << "\nElección inválida. Por favor, intente de nuevo." << std::endl;
            press_enter_to_continue();
            return true;
    }
}


void run_app()
{
    clear_screen();
    ClientArray current_client_list = load_clients();
    
    list_all_clients(current_client_list); 
    press_enter_to_continue(); 

    int choice;
    bool running = true;

    while (running)
    {
        clear_screen();
        display_main_menu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cerr << "Entrada inválida. Por favor, ingrese un número." << std::endl;
            std::cin.clear();
            clear_input_buffer();
            press_enter_to_continue();
            continue;
        }
        clear_input_buffer();

        clear_screen();
        running = handle_menu_choice(choice, current_client_list);
    }

    if (save_clients(current_client_list))
    {
        std::cout << "Lista de clientes actualizada y guardada exitosamente en el archivo." << std::endl;
    }
    else
    {
        std::cerr << "Fallo al guardar la lista de clientes actualizada en el archivo. Los datos podrían perderse." << std::endl;
    }
    
    press_enter_to_continue();
}
