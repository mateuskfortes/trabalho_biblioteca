#ifndef Administrador_h
#define Administrador_h

#include <string>
#include "Usuario.hpp"
class Administrador:public Usuario {
public:
	Administrador(std::string nome, int idade, std::string telefone, std::string senha);
	bool admValido(std::string senha);
	void setSenha(std::string senha);

private:
	std::string senha;
};
#endif