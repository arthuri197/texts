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


import csv  # Importa o módulo csv para manipulação de arquivos CSV

# Abre o arquivo 'test_file_2.txt' no modo leitura ('r'), garantindo o controle correto de quebras de linha com 'newline=""'
with open('test_file_2.txt', 'r', newline='') as csvfile:
    # Cria um objeto leitor que interpreta o arquivo CSV linha a linha
    reader = csv.reader(csvfile)
    
    # Itera sobre cada linha do arquivo CSV
    for row in reader:
        # Imprime a linha lida como uma lista de campos (strings separadas pela vírgula)
        print(row)