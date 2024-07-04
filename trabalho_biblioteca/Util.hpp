#ifndef Util_h
#define Util_h

#include <iostream>

namespace Util {
    template <typename T>
    void consoleIn(T& valor) {
        std::cin >> valor;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    void clearConsole();
};

#endif