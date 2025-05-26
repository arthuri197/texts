"""
Programa: Acesso direto em arquivo binário

Autor: Arthur Oliveira

Data: 26/05/2025

Descrição:
    Programa em Python que abre um arquivo binário para leitura e escrita,
    move o cursor para uma posição específica, escreve um byte,
    depois volta para essa posição e lê o byte escrito, exibindo-o no console

License: CC BY
"""


# Abre arquivo para leitura e escrita em modo binário
with open('data.bin', 'r+b') as file:
    position = 10  # posição do cursor em bytes
    
    # Move o cursor para a posição desejada
    file.seek(position)
    
    # Escreve um byte (exemplo: letra 'G')
    file.write(b'G')
    
    # Volta para a posição para ler
    file.seek(position)
    
    # Lê 1 byte a partir da posição
    data = file.read(1)
    
    print('Byte lido:', data.decode())