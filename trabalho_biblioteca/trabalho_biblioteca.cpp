// g++ -o biblioteca trabalho_biblioteca.cpp Usuario.cpp Cliente.cpp Administrador.cpp Livro.cpp Biblioteca.cpp
// .\biblioteca.exe

#include <iostream>
#include "Usuario.hpp"
#include "Biblioteca.hpp"


int main()
{
    Biblioteca bibs(5, 1);
    Usuario* user = bibs.cadastrarCliente();
    bibs.cadastrarLivro();
    bibs.emprestarLivro((Cliente*)user);
    dynamic_cast<Cliente*>((Cliente*)user)->devolverTodosLivros();
    dynamic_cast<Cliente*>((Cliente*)user)->printLivrosEmprestados();
    bibs.printLivros();

    return 0;
}
