/*
Programa: Classe Empregado

Autor: Arthur

Data: 09-06-2025

Description: Define a classe Empregado que herda de Pessoa e adiciona salário.

License: CC BY
*/

#ifndef EMPREGADO_HPP
#define EMPREGADO_HPP

#include "pessoa.hpp"

class Empregado : public Pessoa {
private:
    double salario;

public:
    Empregado(const std::string& nome, int idade, double salario);
    virtual ~Empregado(); // Destrutor virtual
};

#endif /* EMPREGADO_HPP */
