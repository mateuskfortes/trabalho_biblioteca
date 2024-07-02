// g++ -o biblioteca trabalho_biblioteca.cpp Usuario.cpp Cliente.cpp Administrador.cpp Livro.cpp Emprestimo.cpp Biblioteca.cpp
// .\biblioteca.exe

#include <iostream>
#include <chrono>
#include "Usuario.hpp"
#include "Biblioteca.hpp"


int main()
{
    Biblioteca bibs(6, 5, 1);
    Cliente* user = bibs.cadastrarCliente();
    bibs.cadastrarLivro();
    bibs.emprestarLivro(user);
    bibs.devolverLivro(user);
    bibs.pagarDivida(user);

    return 0;
}
