/*
Programa: Implementação da Classe MicroEmpreendedor

Autor: Arthur

Data: 09-06-2025

Description: Métodos da classe com herança múltipla (Pessoa + Empresa).

License: CC BY
*/

#include "./include/microempreendedor.hpp"

MicroEmpreendedor::MicroEmpreendedor(const std::string& nome, int idade, int cpf, int cnpj)
    : Pessoa(nome, idade, cpf), Empresa(cnpj) {
    std::cout << "MicroEmpreendedor criado!" << std::endl;
}

void MicroEmpreendedor::exibe_cpf() {
    std::cout << "CPF: " << cpf << std::endl;
}

void MicroEmpreendedor::exibe_cnpj() {
    std::cout << "CNPJ: " << cnpj << std::endl;
}

MicroEmpreendedor::~MicroEmpreendedor() {
    std::cout << "Destruindo MicroEmpreendedor!" << std::endl;
}
