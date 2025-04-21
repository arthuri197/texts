import msvcrt
from pydoc import cli

# Função para calcular o comprimento da circunferência e a área do círculo
def calcular_circulo():
    
    #Defini o valor de pi como constante
    pi=3.14
    
    # Solicitar o valor do raio ao usuário
    raio = float(input("\nDigite o valor do raio do círculo: "))
    
    # Calcula o comprimento da circunferência (C = 2 * pi * r)
    comprimento = 2 * pi * raio
    
    # Calcula a área do círculo (A = pi * r^2)
    area = pi * raio ** 2
    
    # Exibir os resultados
    print(f"O comprimento da circunferência é: {comprimento:.2f}")
    print(f"A área do círculo é: {area:.2f}")


# Função para calcular a área e o perímetro do retângulo
def calcular_retangulo():

    # Solicitar o valor dos lados ao usuário
    lado1 = float(input("\nDigite o valor do primeiro lado do retângulo: "))
    lado2 = float(input("Digite o valor do segundo lado do retângulo: "))
    
    # Calcula a área do retângulo 
    area = lado1*lado2
    
    # Calcula o perímetro do retângulo
    perimetro = 2 * (lado1+lado2)
    
    # Exibir os resultados
    print(f"A área do retângulo é: {area:.2f}")
    print(f"O perímetro do retângulo é: {perimetro:.2f}")
    
#Explica ao usuário o que o progama faz 
print("Esse progama calcula o comprimento de uma circunferência e a área de um círculo \ne tambem calcula o perímetro e a área de um retângulo\n")

for _ in iter(int, 1):  #loop infinito, termina com Esc

    #Pergunta ao usuário quais cálculos ele deseja
    print("Para calcular o comprimento de uma circunferência e a área de um círculo, digite 1")
    print("Para calcular o perímetro e a área de um retângulo, digite 2")
    print("Para realiazr os dois cálculos, digite 3")
    opcao=int(input("Opção desejada: "))

    #Condicionais para a opção escolhida pelo usuário
    if opcao == 1:
        calcular_circulo()
    
    elif opcao == 2:
        calcular_retangulo()

    elif opcao == 3:
        calcular_circulo()
        calcular_retangulo()
    
    else:
        print("\nOpção inválida! Tente novamente.\n")  #Exibe uma mensagem de erro caso a opção escolhida pelo usuário seja inválida

    print("\nPressione qualquer tecla para continuar ou ESC para sair...")
    
    tecla = msvcrt.getch()
    if tecla == b'\x1b':  # ASCII 27 = ESC
        print("Encerrando o programa.")
        break
    print("\n")
