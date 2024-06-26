#ifndef Cliente_h
#define Cliente_h

#include <map>
#include <string>
#include "Usuario.hpp"
#include "Livro.hpp"

class Cliente:public Usuario {
public:
	Cliente(std::string nome, int idade, std::string telefone);
	
	float getDivida();

	void addDivida(float valor);
	void pagarDvivida(float valor);

	void addLivrosEmprestados(Livro* livro);
	void removeLivrosEmprestados(Livro* livro);
	void printLivrosEmprestados();

private:
	std::map<std::string, Livro*> livros_emprestados;
	float divida;
};


#endif