#include <iostream>
#include <map>
#include "Livro.hpp"
#include "Cliente.hpp"
#include "Administrador.hpp"
#include "Biblioteca.hpp"

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
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;
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
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;

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
			std::cout << "Escolha invalida, tente novamente.\n";
			break;
		}
		cliente->printDados();
	}
}

void removerCliente(Cliente* cliente) {
	std::cout << "Deseja excluir essa conta (0 - voltar, 1 - excluir): ";
	
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
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;

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

void Biblioteca::alterarDadosAdministrador(Administrador* adm) {
	std::string string;
	int inteiro;
	int escolha;
	while (true) {
		std::cout << "O que deseja alterar\n(1) - nome\n(2) - idade\n(3) - telefone\n(4) - senha\n(0) - sair\nSua escolha: ";
		std::cin >> escolha;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;

		switch (escolha) {
		case 0:
			return;
		case 1:
			std::cout << "Digite o novo nome: ";
			std::getline(std::cin, string);
			adm->setNome(string);
			break;
		case 2:
			std::cout << "Digite a nova idade: ";
			std::getline(std::cin, string);
			inteiro = std::stoi(string);
			adm->setIdade(inteiro);
			break;
		case 3:
			std::cout << "Digite o novo telefone: ";
			std::getline(std::cin, string);
			adm->setTelefone(string);
			break;
		case 4:
			while (true) {
				std::cout << "Digite a antiga senha: ";
				std::getline(std::cin, string);
				if (adm->admValido(string)) break;
				else std::cout << "Senha incorreta!" << std::endl;
			}
			std::cout << "Digite a nova senha: ";
			std::getline(std::cin, string);
			adm->setSenha(string);
			std::cout << "Senha redefinida com sucesso!" << std::endl;
		default:
			std::cout << "Escolha invalida, tente novamente.\n";
			break;
		}
		adm->printDados();
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

void Biblioteca::cadastrarLivro() {
	std::string titulo;
	std::string autor;
	std::string editora;
	int disponiveis;
	while (true) {
		std::cout << "Digite o titulo (0 para sair): ";
		std::getline(std::cin, titulo);

		if (titulo == "0") {
			return;
		}

		else if (!livroEstaCadastrado(titulo)) {
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
		}

		else std::cout << "Esse livro ja esta cadastrado." << std::endl;
	}
	
}

void Biblioteca::emprestarLivro(Cliente* cliente) {
	std::string nome_livro;
	std::map<std::string, Livro*>::iterator livro;
	while (true)
	{
		printLivros();
		std::cout << "Digite o nome do livro que deseja emprestar (0 - sair): ";
		std::getline(std::cin, nome_livro);

		if (nome_livro == "0") return;

		livro = livros.find(nome_livro);

		if (cliente->livroEstaEmprestado(nome_livro)) std::cout << "Voce ja alugou esse livro." << std::endl;

		else if (livro != livros.end()) {
			if (cliente->addLivrosEmprestados(livro->second)) {
				std::cout << "Livro " << livro->second->getTitulo() << " emprestado com sucesso!" << std::endl;
			}
			else std::cout << "Este livro nao esta disponivel." << std::endl;
		}

		else std::cout << "Livro nao encontrado." << std::endl;
	}
}

void Biblioteca::devolverLivro(Cliente* cliente) {
	std::string nome_livro;
	while (true) {
		cliente->printLivrosEmprestados();
		std::cout << "Livro que deseja devolver (0 - sair): ";
		std::getline(std::cin, nome_livro);
		if (cliente->removeLivrosEmprestados(nome_livro)) {
			std::cout << "Livro devolvido com sucesso!" << std::endl;
		}
		else if (nome_livro == "0") return;
		else {
			std::cout << "Livro nao encontrado." << std::endl;
		}
	}
}

void Biblioteca::printLivros() {
	std::cout << "Livros Disponiveis: ";
	for (const std::pair<const std::string, Livro*>& livro : livros) {
		if (livro.second->estaDisponivel())
		std::cout << livro.first << ": " << livro.second->getDisponiveis() << ", ";
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