#include <string>
#include "Livro.hpp"

Livro::Livro(std::string titulo, std::string autor, std::string editora, int disponiveis):
titulo(titulo),
autor(autor),
editora(editora),
disponiveis(disponiveis)
{}

std::string Livro::getTitulo() {
	return this->titulo;
}

int Livro::getDisponiveis() {
	return disponiveis;
}

bool Livro::estaDisponivel() {
	return disponiveis > 0;
}
bool Livro::removeDisponiveis() {
	if (estaDisponivel()) {
		disponiveis -= 1;
		return true;
	}
	else return false;
}
void Livro::addDisponiveis() {
	disponiveis += 1;
}