#ifndef Cliente_h
#define Cliente_h

#include <map>
#include <string>
#include "Usuario.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"

class Cliente:public Usuario {
public:
	Cliente(std::string nome, int idade, std::string telefone);
	~Cliente();
	
	float getDivida();

	float pagarDvivida(float valor); // retorna o troco

	void addEmprestimo(Emprestimo* emprestimo);  // retorna true se a operaçao foi bem sucedida
	Emprestimo* removerEmprestimo(std::string, float valor_diario_multa);
	bool livroEstaEmprestado(std::string nome_livro);
	void printLivrosEmprestados();

private:
	std::map<std::string, Emprestimo*> livros_emprestados;
	float divida;

	void devolverTodosLivros();
	void addDivida(Emprestimo* emprestimo);
};


#endif