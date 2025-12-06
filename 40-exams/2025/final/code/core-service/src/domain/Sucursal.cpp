#include "domain/Sucursal.h"
#include <iostream>

namespace app::domain
{

    Sucursal::Sucursal() : id(0), name(""), vendedor_count(0), max_vendedores(MAX_VENDEDORES)
    {
        // Initialize the array to nullptr
        for (int i = 0; i < MAX_VENDEDORES; i++)
        {
            vendedores[i] = nullptr;
        }
    }

    Sucursal::Sucursal(int id, const std::string &name) : id(id), name(name), vendedor_count(0), max_vendedores(MAX_VENDEDORES)
    {
        // Initialize the array to nullptr
        for (int i = 0; i < MAX_VENDEDORES; i++)
        {
            vendedores[i] = nullptr;
        }
    }

    void Sucursal::addVendedor(Empleado *vendedor)
    {
        if (vendedor_count < max_vendedores)
        {
            vendedores[vendedor_count] = vendedor;
            vendedor_count++;
        }
        else
        {
            std::cout << "No se pueden agregar mas vendedores a la sucursal." << std::endl;
        }
    }

    void Sucursal::removeVendedor(Empleado *vendedor)
    {
        for (int i = 0; i < vendedor_count; i++)
        {
            if (vendedores[i] == vendedor)
            {
                // Shift all elements after this index one position left
                for (int j = i; j < vendedor_count - 1; j++)
                {
                    vendedores[j] = vendedores[j + 1];
                }

                vendedores[vendedor_count - 1] = nullptr;
                vendedor_count--;
                break;
            }
        }
    }

    Empleado **Sucursal::listarVendedores()
    {
        return vendedores;
    }

    Empleado *Sucursal::getVendedor(int index)
    {
        if (index >= 0 && index < vendedor_count)
        {
            return vendedores[index];
        }
        return nullptr;
    }

    int Sucursal::getVendedorCount() const
    {
        return vendedor_count;
    }

    std::string Sucursal::getName() const
    {
        return name;
    }

    void Sucursal::displayInfo()
    {
        std::cout << "Sucursal: " << name << " (ID: " << id << ")" << std::endl;
        std::cout << "Numero de vendedores: " << vendedor_count << std::endl;
        for (int i = 0; i < vendedor_count; i++)
        {
            if (vendedores[i] != nullptr)
            {
                vendedores[i]->displayInfo();
            }
        }
    }

    Sucursal::~Sucursal()
    {
        // Note: We don't delete the vendedores here because they might be managed elsewhere
        // This depends on the overall object lifecycle management of the application
        // For this implementation, we'll assume external management of vendedor objects
    }

} // namespace app::domain