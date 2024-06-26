#include <iostream>
#include <map>
#include "Biblioteca.hpp"
#include "Cliente.hpp"
#include "Livro.hpp"
#include "Administrador.hpp"

Biblioteca::Biblioteca(float max_multa, float multa_dia): 
	id_user(0), 
	id_livro(0), 
	limite_multa(max_multa), 
	multa_por_dia_atraso(multa_dia)
{}

/* CLIENTE */

Cliente* Biblioteca::cadastrarCliente() {
	std::string nome;
	int idade;
	std::string telefone;
	std::cout << "Digite seu login: ";
	std::getline(std::cin, nome);
	std::cout << "Digite sua idade: ";
	std::cin >> idade;
	std::cin.ignore();
	std::cout << "Digite seu telefone: ";
	std::getline(std::cin, telefone);
	Cliente* novo_cliente = new Cliente(nome, idade, telefone);
	clientes[novo_cliente->getNome()] = novo_cliente;
	return novo_cliente;
}

Cliente* Biblioteca::entrarCliente() {
	std::string nome;
	std::cout << "Digite seu login: ";
	std::getline(std::cin, nome);
	std::map<std::string, Cliente*>::iterator cliente = clientes.find(nome);
	if (cliente != clientes.end()) {
		return cliente->second;
	}
	else return cliente->second;
}

void Biblioteca::alterarDadosCliente(Cliente* cliente) {
	std::string string;
	int inteiro;
	int escolha;
	while (true) {
		std::cout << "O que deseja alterar\n(1) - nome\n(2) - idade\n(3) - telefone\n(0) - sair\nSua escolha: ";
		std::cin >> escolha;
		std::cin.ignore();
		switch (escolha) {
		case 0:
			return;
		case 1:
			std::cout << "Digite o novo nome: ";
			std::getline(std::cin, string);
			cliente->setNome(string);
			break;
		case 2:
			std::cout << "Digite a nova idade: ";
			std::getline(std::cin, string);
			inteiro = std::stoi(string);
			cliente->setIdade(inteiro);
			break;
		case 3:
			std::cout << "Digite o novo telefone: ";
			std::getline(std::cin, string);
			cliente->setTelefone(string);
			break;
		default:
			std::cout << "Escolha inv�lida, tente novamente.\n";
			break;
		}
		cliente->printDados();
	}
}

void Biblioteca::printClientes() {
	std::cout << "Clientes: ";
	for (const auto& cliente : clientes) {
		std::cout << cliente.first << " ";
	}
	std::cout << std::endl;
}

/* ADMINISTRADOR */

Administrador* Biblioteca::cadastrarAdministrador() {
	std::string nome;
	int idade;
	std::string telefone;
	std::string senha;

	std::cout << "Digite o login: ";
	std::getline(std::cin, nome);

	std::cout << "Digite sua idade: ";
	std::cin >> idade;
	std::cin.ignore();

	std::cout << "Digite seu telefone: ";
	std::getline(std::cin, telefone);

	std::cout << "Digite sua senha: ";
	std::getline(std::cin, senha);

	Administrador* novo_adm = new Administrador(nome, idade, telefone, senha);
	administradores[novo_adm->getNome()] = novo_adm;
	return novo_adm;
}

Administrador* Biblioteca::entrarAdministrador() {
	std::string nome;
	std::string senha;
	std::map<std::string, Administrador*>::iterator adm;
	while (true) {
		std::cout << "Digite seu login (0 para sair): ";
		std::getline(std::cin, nome);
		adm = administradores.find(nome);
		if (adm != administradores.end()) {
			while (true) {
				std::cout << "Digite sua senha (0 para sair): ";
				std::getline(std::cin, senha);
				if (adm->second->admValido(senha)) {
					return adm->second;
				}
				else if (senha == "0") return nullptr;
			}
		}
		else if (nome == "0") {
			return nullptr;
		}
	}
}

void Biblioteca::printAdministradores() {
	std::cout << "Administradores: ";
	for (const auto& adm : administradores) {
		std::cout << adm.first << " ";
	}
	std::cout << std::endl;
}

/* LIVROS */
/* erro 
void Biblioteca::cadastrarLivro() {
	std::string titulo;
	std::string autor;
	std::string editora;
	int disponiveis;
	while (true) {
		std::cout << "Digite o titulo (0 para sair): ";
		std::getline(std::cin, titulo);
		if (!livroEstaCadastrado(titulo)) {
			std::cout << "Digite o autor: ";
			std::getline(std::cin, autor);
			std::cout << "Digite o nome da editora: ";
			std::getline(std::cin, editora);
			std::cout << "Digite a quantidade de livros disponiveis: ";
			std::cin >> disponiveis;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Livro* livro = new Livro(titulo, autor, editora, disponiveis);
			livros[titulo] = livro;
			std::cout << "Livro cadastrado com sucesso!" << std::endl;
			return;
		}
		else if (titulo == "0") {
			return;
		}
		else std::cout << "Esse livro ja esta cadastrado." << std::endl;
	}
	
}*/

void Biblioteca::printLivros() {
	std::cout << "Livros: ";
	for (const auto& livro : livros) {
		std::cout << livro.first << " ";
	}
	std::cout << std::endl;
}

/* PRIVATE */

bool Biblioteca::clienteEstaCadastrado(Cliente* cliente) {
	std::map<std::string, Cliente*>::iterator cliente_cadastrado = clientes.find(cliente->getNome());
	return cliente_cadastrado != clientes.end();

}
bool Biblioteca::admEstaCadastrado(Administrador* adm) {
	std::map<std::string, Administrador*>::iterator adm_cadastrado = administradores.find(adm->getNome());
	return adm_cadastrado != administradores.end();
}
bool Biblioteca::livroEstaCadastrado(const std::string& titulo) {
	std::map<std::string, Livro*>::iterator livro_cadastrado = livros.find(titulo);
	return livro_cadastrado != livros.end();
}