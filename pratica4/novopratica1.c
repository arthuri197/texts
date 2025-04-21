#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Para _getch()


// Função para calcular o comprimento da circunferência e a área do círculo
void calcular_circulo(){
    
    // Definindo o tipo circle com typedef
    typedef struct {
    float raio;
    float comprimento;
    float area;
} circle;

    //Defini o valor de pi como constante
    const float pi = 3.14;
    
    // Criando uma variável do tipo circle
    circle c;
    
    // Solicitar o valor do raio ao usuário
    printf("\nDigite o valor do raio do círculo: ");
    scanf("%f", &c.raio);
    
    // Calcula o comprimento da circunferência (C = 2 * pi * r)
    c.comprimento = 2 * pi * c.raio;
    
    // Calcula a área do círculo (A = pi * r^2)
    c.area = pi * c.raio * c.raio;
    
    // Exibir os resultados
    printf("O comprimento da circunferência é: %.2f\n", c.comprimento);
    printf("A área do círculo é: %.2f\n", c.area);
}

// Função para calcular a área e o perímetro do retângulo
void calcular_retangulo(){
    
    // Ponteiros para armazenar os lados do retângulo
    float *lado1, *lado2;
    
    //Declaração da variáveis utilizadas no código
    float area, perimetro;
    
    // Alocando memória dinamicamente para os lados
    lado1 = (float*)malloc(sizeof(float));
    lado2 = (float*)malloc(sizeof(float));
    
    // Solicitando ao usuário os valores dos lados do retângulo
    printf("\nDigite o valor do primeiro lado do retângulo: ");
    scanf("%f", lado1);
    printf("Digite o valor do segundo lado do retângulo: ");
    scanf("%f", lado2);
    
    // Calcula a área do retângulo 
    area = (*lado1) * (*lado2);
    
    // Calcula o perímetro do retângulo
    perimetro = 2 * (*lado1 + *lado2);
    
    
    // Exibir os resultados
    printf("\nA área do retângulo é: %.2f\n", area);
    printf("O perímetro do retângulo é: %.2f\n", perimetro);
    
    // Liberando a memória alocada
    free(lado1);
    free(lado2);
}

int main(){
    
    // Declara a variável opção que será usada para filtrar quais cáculos o usuário deseja realizar
    int opcao;
    char tecla;

    // Explica ao usuário o que o progama faz 
    printf("Esse progama calcula o comprimento de uma circunferência e a área de um círculo \ne também calcula o perímetro e a área de um retângulo.\n");

  for (;;) {  // Loop infinito, sai com a tecla Esc

    // Perguntar ao usuário quais cálculos ele deseja
    printf("\nPara calcular o comprimento de uma circunferência e a área de um círculo, digite 1\n");
    printf("Para calcular o perímetro e a área de um retângulo, digite 2\n");
    printf("Para realizar os dois cálculos, digite 3\n");
    printf("Opção desejada: ");
    scanf("%d", &opcao);

    // Condicionais para a opção escolhida pelo usuário
    if (opcao == 1) {
        calcular_circulo();}  // Chama a função para calcular o círculo
    
    else if (opcao == 2) {
        calcular_retangulo();}  // Chama a função para calcular o retângulo
    
    else if (opcao == 3) {
        calcular_circulo();  // Chama a função para calcular o círculo
        calcular_retangulo();}  // Chama a função para calcular o retângulo
      
    else {
        printf("\nOpção inválida! Tente novamente.\n");  // Exibe uma mensagem de erro se a opção for inválida
         }

  printf("\nPressione qualquer tecla para continuar ou Esc para sair...\n");
        tecla = _getch();  // Captura uma tecla sem precisar pressionar Enter

        if ((int)tecla == 27) {  // 27 = ASCII para Esc
            printf("Encerrando o programa.\n");
            break;
        }
    }

    return 0;
}