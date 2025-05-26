"""
Programa: Parsing de arquivo CSV

Autor: Arthur Oliveira

Data: 26/05/2025

Descrição:
    Script Python que abre um arquivo txt modelo CSV para leitura,
    interpreta seu conteúdo separando os campos por vírgulas,
    e exibe cada linha como uma lista de campos no console.

License: CC BY
"""


import csv

with open('test_file_2.txt', 'r', newline='') as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        print(row)
