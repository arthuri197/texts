/*
Programa: Implementação da Classe Empregado

Autor: Arthur

Data: 09-06-2025

Description: Implementa os métodos da classe Empregado.

License: CC BY
*/

#include "./include/empregado.hpp"

Empregado::Empregado(const std::string& nome, int idade, double salario)
    : Pessoa(nome, idade, 0), salario(salario) {}

Empregado::~Empregado() {
    std::cout << "Destruindo Empregado " << std::endl;
}