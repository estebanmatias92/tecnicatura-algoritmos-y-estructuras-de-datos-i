#include "homework/utils.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::left;
using std::numeric_limits;
using std::streamsize;
using std::string;

namespace Homework {

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pause(const string& mensaje) {
    cout << mensaje;
    // Clear any error flags
    cin.clear();
    // Only ignore if there's data waiting in the buffer
    if (cin.rdbuf()->in_avail() > 0) {
        clearInputBuffer();
    }
    cin.get(); // Wait for the user to press ENTER
}

} // namespace Homework
