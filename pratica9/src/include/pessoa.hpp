/*
Programa: Classe Pessoa

Autor: Arthur

Data: 09-06-2025

Description: Define a classe base Pessoa com nome, idade e CPF.

License: CC BY
*/

#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>

class Pessoa {
protected:
    std::string nome;
    int idade;
    int cpf;

public:
    Pessoa(const std::string& nome, int idade, int cpf);
    const std::string& pega_nome();
    virtual ~Pessoa(); // Destrutor virtual para permitir destruição adequada em herança
};

#endif /* PESSOA_HPP */
