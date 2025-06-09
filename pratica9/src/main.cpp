/*
Programa: Programa Principal - Herança, Polimorfismo e Herança Múltipla

Autor: Arthur

Data: 09-06-2025

Description: Testa o uso de herança simples, polimorfismo e herança múltipla.

License: CC BY
*/

#include "./include/pessoa.hpp"
#include "./include/empregado.hpp"
#include "./include/empresa.hpp"
#include "./include/microempreendedor.hpp"

int main() {
    // Criação de uma Pessoa
    Pessoa* p = new Pessoa("Lucas", 30, 1182345678);

    // Criação de um Empregado
    Empregado* e = new Empregado("Luis", 23, 1500.00);

    // Upcasting: Empregado tratado como Pessoa
    Pessoa* p2 = e;

    // Criando Empresa
    Empresa empresa(2905700001);
    empresa.paga(*e); // Ampliação

    // Downcasting explícito
    empresa.contrata(*(static_cast<Empregado*>(p2))); // Estreitamento

    // Criando MicroEmpreendedor
    MicroEmpreendedor me("Carlos", 40, 123456789, 987654321);
    me.exibe_cpf();
    me.exibe_cnpj();

    // Liberação de memória
    delete p;
    delete e;

    return 0;
}
