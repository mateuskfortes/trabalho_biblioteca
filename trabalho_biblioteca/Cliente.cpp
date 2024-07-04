#include <iostream>
#include "Cliente.hpp"
#include <string>
#include <algorithm>
#include "Livro.hpp"

Cliente::Cliente(std::string nome, int idade, std::string telefone): 
	Usuario::Usuario(nome, idade, telefone), 
	divida(0) 
{}

Cliente::~Cliente() {
	devolverTodosLivros();
}

float Cliente::getDivida() {
	return divida;
}

void Cliente::addDivida(Emprestimo* emprestimo) {
	this->divida += emprestimo->getMulta();
}

float Cliente::pagarDvivida(float valor) {
	if (divida >= valor) {
		divida -= valor;
		return 0;
	}
	else {
		return valor - divida;
		divida = 0;
	}
}

void Cliente::addEmprestimo(Emprestimo* emprestimo) {
	livros_emprestados[emprestimo->getLivro()->getTitulo()] = emprestimo;
}

Emprestimo* Cliente::removerEmprestimo(std::string nome_livro, float valor_diario_multa) {
	std::map<std::string, Emprestimo*>::iterator iterador_emprestimo = livros_emprestados.find(nome_livro);
	if (iterador_emprestimo != livros_emprestados.end()) {
		Emprestimo* emprestimo = iterador_emprestimo->second;
		emprestimo->encerrarEmprestimo(valor_diario_multa);
		livros_emprestados.erase(nome_livro);
		addDivida(emprestimo);
		return emprestimo;
	}
	else return nullptr;
}

bool Cliente::livroEstaEmprestado(std::string nome_livro) {
	auto negoco = livros_emprestados.find(nome_livro);
	if (negoco != livros_emprestados.end()) return true;
	else return false;
}

void Cliente::devolverTodosLivros() {
	while (!livros_emprestados.empty()) {
		auto it = livros_emprestados.begin(); 
		removerEmprestimo(it->first, 0);   
	}
}

void Cliente::printLivrosEmprestados() {
	std::cout << "Livros emprestados: ";
	for (const auto& par : livros_emprestados) {
		std::cout << par.first << ", ";
	}
	std::cout << std::endl;
}
