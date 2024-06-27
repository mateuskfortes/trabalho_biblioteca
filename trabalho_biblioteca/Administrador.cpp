#include "Administrador.hpp"
#include <string>

Administrador::Administrador(std::string nome, int idade, std::string telefone, std::string senha): Usuario::Usuario(nome, idade, telefone), senha(senha) {}

void Administrador::setSenha(std::string senha) {
	this->senha = senha;
}

bool Administrador::admValido(std::string senha) {
	return this->senha == senha;
}