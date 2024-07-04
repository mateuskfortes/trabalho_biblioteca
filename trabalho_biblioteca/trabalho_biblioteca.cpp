// g++ -o biblioteca trabalho_biblioteca.cpp Usuario.cpp Cliente.cpp Administrador.cpp Livro.cpp Emprestimo.cpp Biblioteca.cpp
// .\biblioteca.exe

#include <iostream>
#include "Biblioteca.hpp"
#include <cstdlib>
#include "Util.hpp"

using namespace std;

void opcoesAdministrador(Biblioteca& biblioteca, Administrador* administrador);

void opcoesCliente(Biblioteca& biblioteca, Cliente* cliente) {
    int escolha;
    Administrador* administrador;
    while (true) {
        cout << "---------------------------------------------" << endl
            << "O que deseja fazer" << endl
            << "1 - cadastrar cliente" << endl
            << "2 - entrar na conta de um cliente" << endl
            << "3 - alterar dados do cliente" << endl
            << "4 - excluir conta" << endl
            << "5 - emprestar um livro" << endl
            << "6 - devolver um livro" << endl
            << "7 - checar divida" << endl
            << "8 - pagar divida" << endl
            << "9 - entrar na conta de um administrador" << endl
            << "Sua escolha: ";
        Util::consoleIn(escolha);
        Util::clearConsole();
        switch (escolha)
        {
        case 1:
            cliente = biblioteca.cadastrarCliente();
            break;
        case 2:
            cliente = biblioteca.entrarCliente();
            break;
        case 3:
            biblioteca.alterarDadosCliente(cliente);
            break;
        case 4:
            biblioteca.removerCliente(cliente);
            break;
        case 5:
            biblioteca.emprestarLivro(cliente);
            break;
        case 6:
            biblioteca.devolverLivro(cliente);
            break;
        case 7:
            biblioteca.checarDivida(cliente);
            break;
        case 8:
            biblioteca.pagarDivida(cliente);
            break;
        case 9:
            administrador = biblioteca.entrarAdministrador();
            opcoesAdministrador(biblioteca, administrador);
            break;
        default:
            cout << "Escolha uma opcao valida" << endl;
            break;
        }
    }
}

void opcoesAdministrador(Biblioteca& biblioteca, Administrador* administrador) {
    int escolha;
    Cliente* cliente;
    while (true) {
        cout << "---------------------------------------------" << endl
            << "O que deseja fazer" << endl
            << "1 - cadastrar outro administrador" << endl
            << "2 - entrar na conta de outro administrador" << endl
            << "3 - alterar dados" << endl
            << "4 - remover conta" << endl
            << "5 - cadastrar um livro" << endl
            << "6 - cadastrar um cliente" << endl
            << "7 - entrar na conta de um cliente" << endl
            << "Sua escolha: ";
        Util::consoleIn(escolha);
        Util::clearConsole();
        switch (escolha)
        {
        case 1:
            administrador = biblioteca.cadastrarAdministrador();
            break;
        case 2:
            administrador = biblioteca.entrarAdministrador();
            break;
        case 3:
            biblioteca.alterarDadosAdministrador(administrador);
            break;
        case 4:
            biblioteca.removerAdministrador(administrador);
            break;
        case 5:
            biblioteca.cadastrarLivro();
            break;
        case 6:
            cliente = biblioteca.cadastrarCliente();
            opcoesCliente(biblioteca, cliente);
            break;
        case 7:
            cliente = biblioteca.entrarCliente();
            if (cliente) opcoesCliente(biblioteca, cliente);
            break;
        default:
            cout << "Escolha uma opcao valida" << endl;
            break;
        }
    }
}

int main()
{
    int duracao_max_emprestimo;
    float max_multa, multa_por_dia_atraso;
    cout << "Digite a duracao maxima do emprestimo: ";
    Util::consoleIn(duracao_max_emprestimo);
    cout << "Digite a multa maxima: R$";
    Util::consoleIn(max_multa);
    cout << "Digite a multa por dia de atraso: R$";
    Util::consoleIn(multa_por_dia_atraso);
    Biblioteca biblioteca(duracao_max_emprestimo, max_multa, multa_por_dia_atraso);

    Administrador* administrador = biblioteca.cadastrarAdministrador();
    opcoesAdministrador(biblioteca, administrador);

    return 0;
}
