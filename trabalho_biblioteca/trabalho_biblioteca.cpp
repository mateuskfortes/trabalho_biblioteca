// trabalho_biblioteca.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "Usuario.hpp"

int main()
{
    Usuario user;
    bool tipoUser = user.tipoUsuario();
    std::cout << tipoUser;
    return 0;
}
