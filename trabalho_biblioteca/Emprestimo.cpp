#include <ctime>
#include <iostream>
#include <chrono>
#include "Emprestimo.hpp"

Emprestimo::Emprestimo(int id, int duracao_maxima, Cliente* cliente, Livro* livro) {
	this->id = id;
	this->multa = 0;
	auto agora = std::chrono::system_clock::now();
	this->data_emprestimo = std::chrono::system_clock::to_time_t(agora);
	this->data_devolucao_esperada = data_emprestimo + (duracao_maxima * 86400);
	this->data_devolucao = 0;
	this->dias_atraso = 0;
	this->cliente = cliente;
	this->livro = livro;
}

/* GET */

int Emprestimo::getId() {
	return id;
}

Cliente* Emprestimo::getCliente() {
	return cliente;
}

int Emprestimo::getDiasAtraso() {
	return dias_atraso;
}

float Emprestimo::getMulta() {
	return multa;
}

time_t* Emprestimo::getDataDevolucaoEsperada() {
	return &data_devolucao_esperada;
}

time_t* Emprestimo::getDataEmprestimo() {
	return &data_emprestimo;
}

time_t* Emprestimo::getDataDevolucao() {
	return &data_devolucao;
}

Livro* Emprestimo::getLivro() {
	return livro;
}

/* FUNÇOES */ 

void Emprestimo::calcDiasAtraso() {
	double tempo_segundos = difftime(this->data_devolucao, this->data_emprestimo);
	double tempo_esperado_segundos = difftime(this->data_devolucao_esperada, this->data_emprestimo);
	double tempo_atraso_segundos = tempo_segundos - tempo_esperado_segundos;
	this->dias_atraso = static_cast<int>(tempo_atraso_segundos / (60 * 60 * 24));
}

void Emprestimo::calcMulta(float multa_dia) {
	calcDiasAtraso();
	if (dias_atraso > 0) multa = dias_atraso * multa_dia;
}

/* DEVOLUÇÃO */

void Emprestimo::encerrarEmprestimo(float multa_dia) {
	auto agora = std::chrono::system_clock::now();
	this->data_devolucao = std::chrono::system_clock::to_time_t(agora);
	calcMulta(multa_dia);
	this->livro->addDisponiveis();
}
