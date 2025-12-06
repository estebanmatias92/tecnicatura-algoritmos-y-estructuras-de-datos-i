#include "app/Sistema.h"
#include "utils/InputHandler.h"
#include "utils/helpers.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace app
{

    Sistema::Sistema() : sucursal_count(0), next_sucursal_id(1)
    {
        // Initialize the array to nullptr
        for (int i = 0; i < MAX_SUCURSALES; i++)
        {
            sucursales[i] = nullptr;
        }

        // Create a default sucursal to hold our vendedores
        sucursales[sucursal_count] = new domain::Sucursal(next_sucursal_id++, "Sucursal Principal");
        sucursal_count++;
    }

    Sistema::~Sistema()
    {
        // Clean up allocated memory
        for (int i = 0; i < sucursal_count; i++)
        {
            delete sucursales[i];
        }
    }

    void Sistema::run()
    {
        menuPrincipal();
    }

    void Sistema::menuPrincipal()
    {
        int opcion;

        do
        {
            utils::clearScreen();
            cout << "=== Sistema de Gestion de Vendedores ===" << endl;
            cout << "1. Crear Vendedores (3 requeridos)" << endl;
            cout << "2. Listar Vendedores en Sucursal" << endl;
            cout << "3. Listar Todos los Vendedores" << endl;
            cout << "4. Eliminar Vendedor" << endl;
            cout << "5. Modificar Vendedor" << endl;
            cout << "0. Salir" << endl;
            cout << "Elija una opcion: ";

            cin >> opcion;
            cin.ignore(); // Clear the input buffer

            switch (opcion)
            {
            case 1:
                crearVendedores();
                break;
            case 2:
                listarVendedoresEnSucursal();
                break;
            case 3:
                listarTodosVendedores();
                break;
            case 4:
                eliminarVendedor();
                break;
            case 5:
                modificarVendedor();
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                utils::pauseConsole("Presione Enter para continuar...");
            }
        } while (opcion != 0);
    }

    void Sistema::crearVendedores()
    {
        utils::clearScreen();
        cout << "=== Crear 3 Vendedores (uno por categoria) ===" << endl;

        // Get the first sucursal (we'll add all vendedores to the main sucursal)
        domain::Sucursal *sucursal = sucursales[0];

        // Create Vendedor Particular
        cout << "\n--- Creando Vendedor Particular ---" << endl;
        string name = utils::InputHandler::getStringInput("Nombre: ");
        float salary = utils::InputHandler::getFloatInput("Salario: ");
        string area = utils::InputHandler::getStringInput("Area: ");
        string contact = utils::InputHandler::getStringInput("Contacto: ");

        domain::VendedorParticular *vp = new domain::VendedorParticular(name, salary, area, contact);
        sucursal->addVendedor(vp);

        // Create Vendedor Profesional
        cout << "\n--- Creando Vendedor Profesional ---" << endl;
        name = utils::InputHandler::getStringInput("Nombre: ");
        salary = utils::InputHandler::getFloatInput("Salario: ");
        area = utils::InputHandler::getStringInput("Area: ");
        contact = utils::InputHandler::getStringInput("Contacto: ");

        domain::VendedorProfesional *vr = new domain::VendedorProfesional(name, salary, area, contact);
        sucursal->addVendedor(vr);

        // Create Vendedor Empresa
        cout << "\n--- Creando Vendedor Empresa ---" << endl;
        name = utils::InputHandler::getStringInput("Nombre: ");
        salary = utils::InputHandler::getFloatInput("Salario: ");
        area = utils::InputHandler::getStringInput("Area: ");
        contact = utils::InputHandler::getStringInput("Contacto: ");

        domain::VendedorEmpresa *ve = new domain::VendedorEmpresa(name, salary, area, contact);
        sucursal->addVendedor(ve);

        cout << "\nLos 3 vendedores han sido creados y asignados a la sucursal." << endl;

        // Demonstrate the trabajar() method for each vendedor
        cout << "\nDemostrando el metodo trabajar() para cada vendedor:" << endl;
        for (int i = 0; i < sucursal->getVendedorCount(); i++)
        {
            domain::Empleado *emp = sucursal->getVendedor(i);
            emp->trabajar(); // Polymorphic call
        }

        utils::pauseConsole("Presione Enter para continuar...");
    }

    void Sistema::listarVendedoresEnSucursal()
    {
        utils::clearScreen();
        cout << "=== Listar Vendedores en Sucursal ===" << endl;

        if (sucursal_count == 0)
        {
            cout << "No hay sucursales disponibles." << endl;
            utils::pauseConsole("Presione Enter para continuar...");
            return;
        }

        // Let user choose a sucursal (for this implementation, just use the first one)
        cout << "Sucursales disponibles:" << endl;
        for (int i = 0; i < sucursal_count; i++)
        {
            cout << (i + 1) << ". " << sucursales[i]->getVendedorCount()
                 << " vendedores en " << sucursales[i]->getName() << endl;
        }

        int choice = utils::InputHandler::getIntInput("Seleccione la sucursal (1): ");
        choice = 1; // For simplicity, always use the first (and main) sucursal

        if (choice >= 1 && choice <= sucursal_count)
        {
            domain::Sucursal *selectedSucursal = sucursales[choice - 1];
            selectedSucursal->displayInfo();
        }
        else
        {
            cout << "Seleccion invalida." << endl;
        }

        utils::pauseConsole("Presione Enter para continuar...");
    }

    void Sistema::listarTodosVendedores()
    {
        utils::clearScreen();
        cout << "=== Listar Todos los Vendedores ===" << endl;

        for (int i = 0; i < sucursal_count; i++)
        {
            cout << "\n--- " << sucursales[i]->getName() << " ---" << endl;
            for (int j = 0; j < sucursales[i]->getVendedorCount(); j++)
            {
                domain::Empleado *emp = sucursales[i]->getVendedor(j);
                if (emp != nullptr)
                {
                    cout << "[" << (j + 1) << "] ";
                    emp->displayInfo(); // Polymorphic call
                    emp->trabajar();    // Polymorphic call
                }
            }
        }

        utils::pauseConsole("Presione Enter para continuar...");
    }

    void Sistema::eliminarVendedor()
    {
        utils::clearScreen();
        cout << "=== Eliminar Vendedor ===" << endl;

        if (sucursal_count == 0)
        {
            cout << "No hay sucursales disponibles." << endl;
            utils::pauseConsole("Presione Enter para continuar...");
            return;
        }

        // Show all vendedores with indices
        domain::Sucursal *sucursal = sucursales[0]; // Using main branch
        int vendedorCount = sucursal->getVendedorCount();

        if (vendedorCount == 0)
        {
            cout << "No hay vendedores para eliminar." << endl;
            utils::pauseConsole("Presione Enter para continuar...");
            return;
        }

        cout << "Vendedores disponibles para eliminar:" << endl;
        for (int i = 0; i < vendedorCount; i++)
        {
            domain::Empleado *emp = sucursal->getVendedor(i);
            if (emp != nullptr)
            {
                cout << "[" << (i + 1) << "] ";
                emp->displayInfo();
            }
        }

        int choice = utils::InputHandler::getIntInput("\nIngrese el numero del vendedor a eliminar (0 para cancelar): ");

        if (choice == 0)
        {
            cout << "Operacion cancelada." << endl;
        }
        else if (choice >= 1 && choice <= vendedorCount)
        {
            domain::Empleado *vendedorAEliminar = sucursal->getVendedor(choice - 1);

            if (vendedorAEliminar != nullptr)
            {
                // Note: For proper memory management, we should delete the vendedor object
                // But in this context, we just remove it from the branch
                sucursal->removeVendedor(vendedorAEliminar);
                cout << "Vendedor eliminado correctamente." << endl;
            }
        }
        else
        {
            cout << "Seleccion invalida." << endl;
        }

        utils::pauseConsole("Presione Enter para continuar...");
    }

    void Sistema::modificarVendedor()
    {
        utils::clearScreen();
        cout << "=== Modificar Vendedor ===" << endl;

        if (sucursal_count == 0)
        {
            cout << "No hay sucursales disponibles." << endl;
            utils::pauseConsole("Presione Enter para continuar...");
            return;
        }

        // Show all vendedores with indices
        domain::Sucursal *sucursal = sucursales[0]; // Using main branch
        int vendedorCount = sucursal->getVendedorCount();

        if (vendedorCount == 0)
        {
            cout << "No hay vendedores para modificar." << endl;
            utils::pauseConsole("Presione Enter para continuar...");
            return;
        }

        cout << "Vendedores disponibles para modificar:" << endl;
        for (int i = 0; i < vendedorCount; i++)
        {
            domain::Empleado *emp = sucursal->getVendedor(i);
            if (emp != nullptr)
            {
                cout << "[" << (i + 1) << "] ";
                emp->displayInfo();
            }
        }

        int choice = utils::InputHandler::getIntInput("\nIngrese el numero del vendedor a modificar (0 para cancelar): ");

        if (choice == 0)
        {
            cout << "Operacion cancelada." << endl;
        }
        else if (choice >= 1 && choice <= vendedorCount)
        {
            domain::Empleado *vendedorAModificar = sucursal->getVendedor(choice - 1);

            if (vendedorAModificar != nullptr)
            {
                cout << "\nIngrese los nuevos datos del vendedor:" << endl;
                string name = utils::InputHandler::getStringInput("Nombre: ");
                float salary = utils::InputHandler::getFloatInput("Salario: ");
                string area = utils::InputHandler::getStringInput("Area: ");
                string contact = utils::InputHandler::getStringInput("Contacto: ");

                // Use the virtual setters to modify the vendedor
                vendedorAModificar->setName(name);
                vendedorAModificar->setSalary(salary);
                vendedorAModificar->setArea(area);
                vendedorAModificar->setContactInfo(contact);

                cout << "\nVendedor modificado correctamente." << endl;
            }
        }
        else
        {
            cout << "Seleccion invalida." << endl;
        }

        utils::pauseConsole("Presione Enter para continuar...");
    }

} // namespace app