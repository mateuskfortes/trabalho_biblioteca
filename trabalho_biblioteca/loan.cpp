#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
#include <windows.h>
#include "loan.hpp"
#include "book.hpp"

Emprestimo::Emprestimo(Livro &livro, int &counterLoan) {
    multa = 0;
    dtaEntrada = std::chrono::system_clock::now();
    dtaAlteracao = std::chrono::system_clock::now();
    dtaSaida = dtaEntrada + std::chrono::hours(24 * 7 * 4);
    livroEmprestado = &livro;
    livroEmprestado->available = false;
    id = counterLoan;
    counterLoan++;
}

Emprestimo::~Emprestimo() {
    livroEmprestado->available = true;
}

void Emprestimo::setMulta(float _multa) {
    multa = _multa;
    dtaAlteracao = std::chrono::system_clock::now();
}

Livro* Emprestimo::getLivroEmprestado() {
    return livroEmprestado;
}

std::string Emprestimo::getDtaSaida() {
    std::time_t dtaSaida2 = std::chrono::system_clock::to_time_t(dtaSaida);
    struct tm sttime;
    localtime_s(&sttime, &dtaSaida2);
    std::string dia = std::to_string(sttime.tm_mday);
    std::string mes = std::to_string(sttime.tm_mon);
    std::string ano = std::to_string(sttime.tm_year);
    return dia + "/" + mes + "/" + ano;
}

std::string Emprestimo::getDtaEntrada() {
    std::time_t dtaEntrada2 = std::chrono::system_clock::to_time_t(dtaEntrada);
    struct tm sttime;
    localtime_s(&sttime, &dtaEntrada2);
    std::string dia = std::to_string(sttime.tm_mday);
    std::string mes = std::to_string(sttime.tm_mon);
    std::string ano = std::to_string(sttime.tm_year);
    return dia + "/" + mes + "/" + ano;
}

float Emprestimo::getMulta() {
    return multa;
}

int Emprestimo::getId() {
    return id;
}

void Emprestimo::calcMulta(){
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    if (now > dtaAlteracao) {
        int dias = (now - dtaAlteracao) / std::chrono::hours(24);
        multa = 2 * dias;
    }
}

