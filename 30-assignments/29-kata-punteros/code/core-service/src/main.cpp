#include <iostream>
using namespace std;

void ejercicio3_dinamica_experimento() {
    cout << "--- Ejercicio 3 Simplificado: Manipulación Direccional ---" << endl;
    
    // Asignación de un único entero en el Heap e inicialización a 2025.
    int* ptr_dinamico = new int(2025); 
    
    cout << "\n[Estado Inicial]" << endl;
    cout << "Dirección Inicial (new): " << ptr_dinamico << endl;
    cout << "Valor Apuntado: " << *ptr_dinamico << endl;

    // --- Aplicación de Aritmética de Punteros ---
    cout << "\n[Paso 1: Incremento de Dirección (ptr++)]" << endl;
    
    // Se lee el valor (2025) y, posteriormente, el puntero se mueve sizeof(int) bytes.
    cout << "Valor desreferenciado antes de la reasignación: " << *ptr_dinamico++ << endl; 
    
    cout << "\n[Estado Intermedio]" << endl;
    cout << "Dirección Actual (Desplazada): " << ptr_dinamico << endl;
    
    // Acceso a memoria no asignada (Comportamiento Indefinido o Undefined Behavior)
    cout << "Valor en ubicación adyacente (UB): " << *ptr_dinamico << endl; 
    
    // --- Restauración de la Dirección Original ---
    cout << "\n[Paso 2: Decremento de Dirección (ptr--)]" << endl;
    
    // Se lee el valor (UB) y, posteriormente, el puntero es restaurado a la dirección inicial.
    cout << "Valor desreferenciado antes de la restauración: " << *ptr_dinamico-- << endl; 
    
    cout << "\n[Estado Final y Verificación]" << endl;
    // Se verifica que la dirección es nuevamente la asignada por 'new'.
    cout << "Dirección Final (Restaurada): " << ptr_dinamico << endl;
    // Se comprueba que el valor original (2025) sigue intacto en la posición inicial.
    cout << "Valor Apuntado (Verificado): " << *ptr_dinamico << endl;
    
    // 3. Liberación crítica de la memoria.
    // El puntero debe apuntar a la dirección de 'new' para un 'delete' correcto.
    delete ptr_dinamico; 
    
    // 4. Establecer el puntero a nullptr para evitar punteros colgantes (dangling pointers)[cite: 139].
    ptr_dinamico = nullptr;
    cout << "\nMemoria liberada y puntero seteado a nullptr." << endl;
}

int main() {
    ejercicio3_dinamica_experimento();
    return 0;
}