#ifndef Administrador_h
#define Administrador_h

#include <string>
#include "Usuario.hpp"
class Administrador:public Usuario {
public:
	Administrador(std::string nome, int idade, std::string telefone, std::string senha);
	bool admValido(std::string senha);
	bool setSenha(std::string senhaAntiga, std::string senhaNova); // retorna true se a mudança de senha foi bem sucedida

private:
	std::string senha;
};
#endif