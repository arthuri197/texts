/*
Programa: Classe MicroEmpreendedor

Autor: Arthur

Data: 09-06-2025

Description: Classe com herança múltipla de Pessoa e Empresa.

License: CC BY
*/

#ifndef MICROEMPREENDEDOR_HPP
#define MICROEMPREENDEDOR_HPP

#include "pessoa.hpp"
#include "empresa.hpp"
#include <iostream>

class MicroEmpreendedor : public Pessoa, public Empresa {
public:
    MicroEmpreendedor(const std::string& nome, int idade, int cpf, int cnpj);
    void exibe_cpf();
    void exibe_cnpj();
    virtual ~MicroEmpreendedor();
};

#endif // MICROEMPREENDEDOR_HPP
