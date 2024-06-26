#include <iostream>
#include <string>
#include "Usuario.hpp"

Usuario::Usuario(std::string nome, int idade, std::string telefone): nome(nome), idade(idade), telefone(telefone) {}

/* GET */

std::string Usuario::getNome() {
	return nome;
}

int Usuario::getIdade() {
	return idade;
}

std::string Usuario::getTelefone() {
	return telefone;
}

/* SET */

void Usuario::setNome(std::string nome) {
	this->nome = nome;
}

void Usuario::setIdade(int idade) {
	this->idade = idade;
}

void Usuario::setTelefone(std::string telefone) {
	this->telefone = telefone;
}

/* USUARIO */

void Usuario::printDados() {
	std::cout << "Nome: " << nome << std::endl;
	std::cout << "Idade: " << idade << std::endl;
	std::cout << "Telefone: " << telefone << std::endl;
}
