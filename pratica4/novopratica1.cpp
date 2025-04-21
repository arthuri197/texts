#include <iostream>
#include <conio.h>  // Para _getch()
using namespace std; 


// Função para calcular o comprimento da circunferência e a área do círculo
void calcular_circulo(){
    
    //Declaração da variáveis utilizadas no código
    float raio, comprimento, area;
    
    //Defini o valor de pi como constante
    const float pi = 3.14;
    
    // Solicitar o valor do raio ao usuário
    cout << "\nDigite o valor do raio do círculo: " << endl;
    cin >> raio;
    
    // Calcula o comprimento da circunferência (C = 2 * pi * r)
    comprimento = 2 * pi * raio;
    
    // Calcula a área do círculo (A = pi * r^2)
    area = pi * raio * raio;
    
    // Exibir os resultados
    cout << "O comprimento da circunferência é: "<< comprimento << endl;
    cout << "A área do círculo é: "<< area << endl;
    }
    
// Função para calcular a área e o perímetro do retângulo
void calcular_retangulo(){
    
    //Declaração da variáveis utilizadas no código
    float lado1, lado2, area, perimetro;
    
    // Solicitar o valor dos lados ao usuário
    cout << "\nDigite o valor do primeiro lado do retângulo: " << endl;
    cin >> lado1;
    cout << "Digite o valor do segundo lado do retângulo: " << endl;
    cin >> lado2;
    
    // Calcula a área do retângulo 
    area = lado1*lado2;
    
    // Calcula o perímetro do retângulo
    perimetro = 2 * (lado1+lado2);
    
    // Exibir os resultados
    cout << "A área do retângulo é: "<< area << endl;
    cout << "O perímetro do retângulo é: "<< perimetro << endl;
    }
    
int main(){
    
    //Declara a variável opção que será usada para filtrar quais cáculos o usuário deseja realizar
    int opcao;
    char tecla;
    
    //Explica ao usuário o que o progama faz 
    cout << "Esse progama calcula o comprimento de uma circunferência e a área de um círculo \ne também calcula o perímetro e a área de um retângulo.\n" << endl;
    
   for (;;) {  // Loop infinito, termina com Esc
    //Pergunta ao usuário quais cálculos ele deseja
    cout << "Para calcular o comprimento de uma circunferência e a área de um círculo, digite 1" << endl;
    cout << "Para calcular o perímetro e a área de um retângulo, digite 2" << endl;
    cout << "Para realiazr os dois cálculos, digite 3" << endl;
    cout << "Opção desejada: " << endl;
    cin >> opcao;
    
    //Condicionais para a opção escolhida pelo usuário
    if (opcao == 1) {
    calcular_circulo(); }  //Chama a função para calcular o círculo


    else if (opcao == 2) {
    calcular_retangulo(); }  //Chama a função para calcular o retângulo

    else if (opcao == 3) {
    calcular_circulo();  //Chama a função para calcular o círculo
    calcular_retangulo(); } //Chama a função para calcular o retângulo
   
    else {
    cout << "\nOpção inválida! Tente novamente.\n" << endl; //Exibe uma mensagem de erro caso a opção escolhida pelo usuário seja inválida
         }
   cout << "\nPressione qualquer tecla para continuar ou ESC para sair...\n";
        tecla = _getch();  // Captura tecla sem precisar do Enter

        if ((int)tecla == 27) {  // 27 = ASCII do ESC
            cout << "Encerrando o programa.\n";
            break;
        }
    }
    
    return 0;
}