"""
Programa: Leitura serial de arquivo texto

Autor: Arthur Oliveira

Data: 26/05/2025

Descrição:
    Script Python que abre um arquivo de texto para leitura, 
    lê o conteúdo linha a linha e exibe cada linha no console.

License: CC BY
"""


# Abre o arquivo para leitura
with open('test_file.txt', 'r') as file:
    # Lê e exibe linha a linha
    for line in file:
        print(line.strip())  # strip() remove espaços e quebras de linha extras
