%{

Program: Prática 1 - Entrada e saída, declaração e inicialização de variáveis e constantes e alocação dinâmica de memória

Author: Arthur Oliveira

Date: 17/03/2025

Description: Progama que realiza cálculos relacionados ao círculo ou ao retângulo

License: CC BY

%}

% Explica ao usuário o que o programa faz 
disp('Esse programa calcula o comprimento de uma circunferência e a área de um círculo e também calcula o perímetro e a área de um retângulo');

% Pergunta ao usuário quais cálculos ele deseja
disp('Para calcular o comprimento de uma circunferência e a área de um círculo, digite 1');
disp('Para calcular o perímetro e a área de um retângulo, digite 2');
disp('Para realizar os dois cálculos, digite 3');
opcao = input('Opção desejada: ');

% Condicionais para a opção escolhida pelo usuário
if opcao == 1
    % Solicita o valor do raio ao usuário
    raio = input('\nDigite o valor do raio do círculo: ');
    
    % Defini o valor de pi como constante
    pi = 3.14;
    
    % Calcula o comprimento da circunferência (C = 2 * pi * r)
    comprimento = 2 * pi * raio;
    
    % Calcula a área do círculo (A = pi * r^2)
    area = pi * raio^2;
    
    % Exibir os resultados
    fprintf('O comprimento da circunferência é: %.2f\n', comprimento);
    fprintf('A área do círculo é: %.2f\n', area);

elseif opcao == 2
    % Solicita o valor dos lados ao usuário
    lado1 = input('\nDigite o valor do primeiro lado do retângulo: ');
    lado2 = input('Digite o valor do segundo lado do retângulo: ');
    
    % Calcula a área do retângulo 
    area_retangulo = lado1 * lado2;
    
    % Calcula o perímetro do retângulo
    perimetro_retangulo = 2 * (lado1 + lado2);
    
    % Exibi os resultados
    fprintf('A área do retângulo é: %.2f\n', area_retangulo);
    fprintf('O perímetro do retângulo é: %.2f\n', perimetro_retangulo);

elseif opcao == 3
    % Cálculos para o círculo
    raio = input('\nDigite o valor do raio do círculo: ');
    pi = 3.14;
    comprimento = 2 * pi * raio;
    area = pi * raio^2;
    
    % Exibir os resultados do círculo
    fprintf('O comprimento da circunferência é: %.2f\n', comprimento);
    fprintf('A área do círculo é: %.2f\n', area);
    
    % Cálculos para o retângulo
    lado1 = input('\nDigite o valor do primeiro lado do retângulo: ');
    lado2 = input('Digite o valor do segundo lado do retângulo: ');
    area_retangulo = lado1 * lado2;
    perimetro_retangulo = 2 * (lado1 + lado2);
    
    % Exibir os resultados do retângulo
    fprintf('A área do retângulo é: %.2f\n', area_retangulo);
    fprintf('O perímetro do retângulo é: %.2f\n', perimetro_retangulo);

else
    disp('Opção inválida! Tente novamente.');  % Exibe uma mensagem de erro caso a opção escolhida seja inválida
end
