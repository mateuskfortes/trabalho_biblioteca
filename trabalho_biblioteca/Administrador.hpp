#include <string>
#include "Usuario.hpp"
class Administrador:Usuario {
private:
	std::string senha;

protected:
	bool admValido(std::string senha, std::string nome);
};