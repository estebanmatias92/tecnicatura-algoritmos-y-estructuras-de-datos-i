#include "homework/homework.h"
#include <iostream>
#include <cstdlib>  // for rand()
#include <cctype>   // for tolower()
#include <ctime>    // for time() if seeding rand()

namespace Homework {

void exercise1() {
    int arr[10];
    int *ptr = arr;

    std::cout << "Ingrese 10 números: ";
    for (int i = 0; i < 10; ++i) {
        std::cin >> *(ptr + i);
    }

    std::cout << "Números pares y sus direcciones de memoria:\n";
    for (int i = 0; i < 10; ++i) {
        if (*(ptr + i) % 2 == 0) {
            std::cout << "Número: " << *(ptr + i) << ", Dirección: " << (ptr + i) << std::endl;
        }
    }
}

void exercise2() {
    int n;
    std::cout << "Ingrese el número de elementos: ";
    std::cin >> n;

    int *arr = new int[n];
    int *ptr = arr;

    std::cout << "Ingrese " << n << " números: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> *(ptr + i);
    }

    int *min_ptr = ptr;
    for (int i = 1; i < n; ++i) {
        if (*(ptr + i) < *min_ptr) {
            min_ptr = ptr + i;
        }
    }

    std::cout << "El elemento más pequeño es: " << *min_ptr << std::endl;

    delete[] arr;
}

void exercise3() {
    int n;
    std::cout << "Ingrese el número de elementos: ";
    std::cin >> n;

    int *arr = new int[n];
    int *ptr = arr;

    std::cout << "Ingrese " << n << " números: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> *(ptr + i);
    }

    // Bubble sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }

    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; ++i) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;

    delete[] arr;
}

void exercise4() {
    char str[100];
    char *ptr = str;
    int count_a = 0, count_e = 0, count_i = 0, count_o = 0, count_u = 0;

    std::cout << "Ingrese una cadena de caracteres: ";
    std::cin.ignore();
    std::cin.getline(str, 100);

    while (*ptr != '\0') {
        switch (tolower(*ptr)) {
            case 'a':
                count_a++;
                break;
            case 'e':
                count_e++;
                break;
            case 'i':
                count_i++;
                break;
            case 'o':
                count_o++;
                break;
            case 'u':
                count_u++;
                break;
        }
        ptr++;
    }

    std::cout << "Conteo de vocales:\n";
    std::cout << "a: " << count_a << std::endl;
    std::cout << "e: " << count_e << std::endl;
    std::cout << "i: " << count_i << std::endl;
    std::cout << "o: " << count_o << std::endl;
    std::cout << "u: " << count_u << std::endl;
}

void exercise5() {
    int rows, cols;
    std::cout << "Ingrese el número de filas y columnas para las matrices: ";
    std::cin >> rows >> cols;

    int **matrix1 = new int *[rows];
    int **matrix2 = new int *[rows];
    int **sum = new int *[rows];

    for (int i = 0; i < rows; ++i) {
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
        sum[i] = new int[cols];
    }

    // Fill matrices with random numbers
    srand(time(0));  // Seed random number generator
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    // Print first matrix
    std::cout << "\nMatriz 1:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix1[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Print second matrix
    std::cout << "\nMatriz 2:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix2[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Calculate sum
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print sum
    std::cout << "\nMatriz 1 + Matriz 2 (Resultado):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << sum[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Free memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] sum[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] sum;
}

void exercise6() {
    int rows, cols;
    std::cout << "Ingrese el número de filas y columnas para la matriz: ";
    std::cin >> rows >> cols;

    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Fill matrix with random numbers
    srand(time(0));  // Seed random number generator
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Print original matrix
    std::cout << "\nMatriz original (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Create transpose
    int **transpose = new int *[cols];
    for (int i = 0; i < cols; ++i) {
        transpose[i] = new int[rows];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print transpose
    std::cout << "\nMatriz transpuesta (" << cols << "x" << rows << "):\n";
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            std::cout << transpose[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Free memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < cols; ++i) {
        delete[] transpose[i];
    }
    delete[] transpose;
}
void exercise7() {
    struct student {
        char name[50];
        int age;
        float average;
    };

    student students[3];
    student *ptr_student = students;

    std::cin.ignore();  // Clear buffer once before loop
    
    for (int i = 0; i < 3; ++i) {
        std::cout << "Ingrese los datos para el alumno " << i + 1 << ":\n";
        std::cout << "Nombre: ";
        std::cin.getline((ptr_student + i)->name, 50);
        std::cout << "Edad: ";
        std::cin >> (ptr_student + i)->age;
        std::cout << "Promedio: ";
        std::cin >> (ptr_student + i)->average;
        std::cin.ignore();  // Clear newline after reading numbers
    }

    student *best_student = ptr_student;
    for (int i = 1; i < 3; ++i) {
        if ((ptr_student + i)->average > best_student->average) {
            best_student = ptr_student + i;
        }
    }

    std::cout << "\nAlumno con el mejor promedio:\n";
    std::cout << "Nombre: " << best_student->name << std::endl;
    std::cout << "Edad: " << best_student->age << std::endl;
    std::cout << "Promedio: " << best_student->average << std::endl;
}

void showMenu() {
    std::cout << "\n--- Menú de Tareas ---\n";
    std::cout << "1. Números pares y sus direcciones de memoria\n";
    std::cout << "2. Encontrar el elemento más pequeño en un arreglo\n";
    std::cout << "3. Ordenar un arreglo dinámico\n";
    std::cout << "4. Contar vocales en una cadena\n";
    std::cout << "5. Suma de dos matrices dinámicas\n";
    std::cout << "6. Traspuesta de una matriz dinámica\n";
    std::cout << "7. Alumno con el mejor promedio\n";
    std::cout << "0. Salir\n";
    std::cout << "Ingrese su opción: ";
}

void execute() {
    int choice;
    do {
        showMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                exercise1();
                break;
            case 2:
                exercise2();
                break;
            case 3:
                exercise3();
                break;
            case 4:
                exercise4();
                break;
            case 5:
                exercise5();
                break;
            case 6:
                exercise6();
                break;
            case 7:
                exercise7();
                break;
            case 0:
                std::cout << "Exiting homework...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

} // namespace Homework
