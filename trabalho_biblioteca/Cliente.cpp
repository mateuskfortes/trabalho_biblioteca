#include <iostream>
#include "Cliente.hpp"
#include <string>
#include <algorithm>
#include "Livro.hpp"

Cliente::Cliente(std::string nome, int idade, std::string telefone): Usuario::Usuario(nome, idade, telefone), divida(0) {}

float Cliente::getDivida() {
	return divida;
}

void Cliente::addDivida(float valor) {
	divida += valor;
}

void Cliente::pagarDvivida(float valor) {
	divida -= valor;
}

bool Cliente::addLivrosEmprestados(Livro* livro) {
	if (livro->removeDisponiveis()) {
		livros_emprestados.insert({ livro->getTitulo(), livro });
		return true;
	}
	else return false;
}

bool Cliente::removeLivrosEmprestados(std::string livro) {
	std::map<std::string, Livro*>::iterator livro_emprestado = livros_emprestados.find(livro);
	if (livro_emprestado != livros_emprestados.end()) {
		livro_emprestado->second->addDisponiveis();
		livros_emprestados.erase(livro);
		return true;
	}
	else return false;
}

bool Cliente::livroEstaEmprestado(std::string nome_livro) {
	auto negoco = livros_emprestados.find(nome_livro);
	if (negoco != livros_emprestados.end()) return true;
	else return false;
}

void Cliente::devolverTodosLivros() {
	while (!livros_emprestados.empty()) {
		auto it = livros_emprestados.begin(); 
		removeLivrosEmprestados(it->first);   
	}
}

void Cliente::printLivrosEmprestados() {
	std::cout << "Livros emprestados: ";
	for (const auto& par : livros_emprestados) {
		std::cout << par.first << ", ";
	}
	std::cout << std::endl;
}
