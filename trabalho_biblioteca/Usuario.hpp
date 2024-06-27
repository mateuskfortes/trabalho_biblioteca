#ifndef Usuario_h
#define Usuario_h
#include <string>

class Usuario {
public:
	Usuario(std::string nome, int idade, std::string telefone);
	
	std::string getNome();
	int getIdade();
	std::string getTelefone();

	void setNome(std::string nome);
	void setIdade(int idade);
	void setTelefone(std::string telefone);

	void printDados();

	/* VIRTUAL */
	
	void devolverTodosLivros() {}
	void printLivrosEmprestados(){}

protected:
	std::string nome;
	int idade;
	std::string telefone;
};
#endif