// g++ -o biblioteca trabalho_biblioteca.cpp Usuario.cpp Cliente.cpp Administrador.cpp Livro.cpp Biblioteca.cpp
// .\biblioteca.exe

#include <iostream>
#include "Cliente.hpp"
#include "Livro.hpp"


int main()
{
    Cliente cli("oi", 12, "56y7u");
    Livro l("rew", "5678", "678i", 5);
    cli.addLivrosEmprestados(&l);
    cli.printDados();
    return 0;
}
