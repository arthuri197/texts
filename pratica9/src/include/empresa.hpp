/*
Programa: Classe Empresa

Autor: Arthur

Data: 09-06-2025

Description: Define a classe Empresa com métodos para pagar e contratar.

License: CC BY
*/

#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include "pessoa.hpp"
#include "empregado.hpp"

class Empresa {
protected:
    int cnpj;

public:
    Empresa(int cnpj);
    void paga(Pessoa& pes);
    void contrata(Empregado& emp);
    virtual ~Empresa(); // Destrutor virtual
};

#endif /* EMPRESA_HPP */
