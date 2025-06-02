/*
Programa: Leitura e escrita em arquivo binário com posicionamento

Autor: Arthur Oliveira 
Data: 02/06/2025

Descrição:
    Programa que abre um arquivo binário para leitura e escrita,
    escreve um caractere na posição especificada,
    depois lê um bloco de dados a partir dessa posição e exibe no console.

License: CC BY
*/

#include <iostream>   // Para std::cout e std::cerr
#include <fstream>    // Para manipulação de arquivos (std::fstream)

int main() {
    const int position = 3;           // Posição desejada (índice) para leitura/escrita no arquivo
    const int bufferSize = 100;       // Tamanho do buffer (em bytes)
    char buffer[bufferSize] = {};     // Buffer inicializado com zeros para armazenar dados lidos

    // Abre o arquivo "data.bin" para leitura e escrita binária, truncando-o (zerando) caso já exista
    std::fstream file("data.bin", std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    if (!file) {  // Verifica se o arquivo foi aberto corretamente
        std::cerr << "Erro ao abrir arquivo para escrita." << std::endl;
        return 1;  // Sai do programa indicando erro
    }

    // Move o ponteiro de escrita para a posição desejada (posição * tamanho do buffer)
    file.seekp(position * bufferSize, std::ios::beg);

    // Escreve o caractere 'G' na posição atual do arquivo
    file.put('G');

    // Fecha o arquivo após a escrita
    file.close();

    // Reabre o arquivo "data.bin" para leitura binária
    std::fstream fileIn("data.bin", std::ios::in | std::ios::binary);
    if (!fileIn) {  // Verifica se o arquivo foi aberto corretamente para leitura
        std::cerr << "Erro ao abrir arquivo para leitura." << std::endl;
        return 1;  // Sai do programa indicando erro
    }

    // Move o ponteiro de leitura para a mesma posição usada na escrita
    fileIn.seekg(position * bufferSize, std::ios::beg);

    // Lê 'bufferSize' bytes do arquivo a partir da posição atual e armazena no buffer
    fileIn.read(buffer, bufferSize);

    // Imprime o conteúdo lido do arquivo (pode mostrar 'G' seguido de lixo ou zeros)
    std::cout << "Dado lido: " << buffer << std::endl;

    // Fecha o arquivo após a leitura
    fileIn.close();

    return 0;  // Finaliza o programa indicando sucesso
}