#include <string>
class Livros {
	public:
	
	private:
		std::string titulo;
		std::string autor;
		int disponiveis;
		std::string editora;

	protected:
		bool estaDisponivel() const;
		void emprestarLivros();

};