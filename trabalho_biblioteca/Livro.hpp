#ifndef Livro_h
#define Livro_h

#include <string>

class Livro {
	public:
		Livro(std::string titulo, std::string autor, std::string editora, int disponiveis);

		std::string getTitulo();
		int getDisponiveis();

		bool removeDisponiveis(); // retorna true se o emprestimo foi bem sucedido, se nao retorna false
		void addDisponiveis();
	
	private:
		std::string titulo;
		std::string autor;
		std::string editora;
		int disponiveis;

		bool estaDisponivel();
};
#endif

