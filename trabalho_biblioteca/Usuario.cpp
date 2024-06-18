#include <iostream>
#include "Usuario.hpp"

using namespace std;

bool Usuario::tipoUsuario() {
	string perguntaUsuario;
	cout << "O Usuário em questão é um cliente ou administrador?\nEscreva 'Cliente' ou 'Administrador' para a respectiva escolha. :" << endl;
	cin >> perguntaUsuario;

	if (perguntaUsuario == "Cliente") {
		Usuario::Administrador = false;
	}

	else if (perguntaUsuario == "Administrador") {
		Usuario:: Administrador = true;
	}

	else {
		cout << "Código Inválido.";
	}

	return Usuario::Administrador;
};