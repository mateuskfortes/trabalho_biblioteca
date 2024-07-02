#ifndef Emprestimo_h
#define Emprestimo_h

#include <ctime>
#include "Livro.hpp"

class Cliente;

class Emprestimo {
public:
	Emprestimo(int id, int duracao_maxima, Cliente* cliente, Livro* livro);
	
	int getId();
	int getDiasAtraso(); 
	float getMulta();
	Cliente* getCliente();
	Livro* getLivro();
	time_t* getDataDevolucaoEsperada();
	time_t* getDataEmprestimo();
	time_t* getDataDevolucao();

	void encerrarEmprestimo(float multa_dia);

private:
	int id;
	int dias_atraso;
	float multa;
	Cliente* cliente;
	Livro* livro;
	time_t data_emprestimo;
	time_t data_devolucao_esperada;
	time_t data_devolucao;
	
	void calcDiasAtraso();
	void calcMulta(float multa_dia);

};

#endif 