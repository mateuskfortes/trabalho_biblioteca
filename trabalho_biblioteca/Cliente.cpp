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
/* erro */
void Cliente::addLivrosEmprestados(Livro* livro) {
	livros_emprestados[livro->getTitulo()] = livro;
}
/* erro */
void Cliente::removeLivrosEmprestados(Livro* livro) {
	livros_emprestados.erase(livro->getTitulo());
}

void Cliente::printLivrosEmprestados() {
	for (const auto& par : livros_emprestados) {
		std::cout << par.first << std::endl;
	}
}
