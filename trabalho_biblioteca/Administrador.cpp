#include "Administrador.hpp"
#include <string>

Administrador::Administrador(std::string nome, int idade, std::string telefone, std::string senha): Usuario::Usuario(nome, idade, telefone), senha(senha) {}

bool Administrador::setSenha(std::string senhaAntiga, std::string senhaNova) {
	if (admValido(senhaAntiga)) {
		this->senha = senhaNova;
		return true;
	}
	else return false;
}

bool Administrador::admValido(std::string senha) {
	return this->senha == senha;
}