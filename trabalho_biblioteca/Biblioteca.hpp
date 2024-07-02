#include <map>
#include <string>
#include "Cliente.hpp"
#include "Administrador.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"

class Biblioteca {
public:

	Biblioteca(int duracao_maxima_emprestimo, float max_multa, float multa_dia);

	Cliente* cadastrarCliente();
	Cliente* entrarCliente();
	void alterarDadosCliente(Cliente* cliente);
	void removerCliente(Cliente* cliente);
	void printClientes();

	Administrador* cadastrarAdministrador();
	Administrador* entrarAdministrador();
	void alterarDadosAdministrador(Administrador* adm);
	void removerAdministrador(Administrador* adm);
	void printAdministradores();

	void cadastrarLivro();
	void emprestarLivro(Cliente* cliente);
	void devolverLivro(Cliente* cliente);
	void printLivros();

	void printEmprestimosAtivos();
	void printEmprestimosEncerrados();

	void pagarDivida(Cliente* cliente);
	void checarDivida(Cliente* cliente);

private:
	std::map <std::string, Cliente*> clientes;
	std::map <std::string, Administrador*> administradores;
	std::map <std::string, Livro*> livros;
	std::map <int, Emprestimo*> Emprestimos_ativos;
	std::map <int, Emprestimo*> Emprestimos_encerrados;

	int duracao_maxima_emprestimo;
	float limite_multa;
	float multa_por_dia_atraso;
	int id_emprestimo;

	bool clienteEstaCadastrado(Cliente* cliente);
	bool admEstaCadastrado(Administrador* adm);
	bool livroEstaCadastrado(const std::string& titulo);
};