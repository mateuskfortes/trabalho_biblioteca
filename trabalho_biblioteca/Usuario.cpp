#include <iostream>
#include "Usuario.hpp"

using namespace std;

bool Usuario::tipoUsuario() {
	string perguntaUsuario;
	cout << "O Usu�rio em quest�o � um cliente ou administrador?\nEscreva 'Cliente' ou 'Administrador' para a respectiva escolha. :" << endl;
	cin >> perguntaUsuario;

	if (perguntaUsuario == "Cliente") {
		Usuario::Administrador = false;
	}

	else if (perguntaUsuario == "Administrador") {
		Usuario:: Administrador = true;
	}

	else {
		cout << "C�digo Inv�lido.";
	}

	return Usuario::Administrador;
};