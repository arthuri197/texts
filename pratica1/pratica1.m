%{

Program: Pr�tica 1 - Entrada e sa�da, declara��o e inicializa��o de vari�veis e constantes e aloca��o din�mica de mem�ria

Author: Arthur Oliveira

Date: 17/03/2025

Description: Progama que realiza c�lculos relacionados ao c�rculo ou ao ret�ngulo

License: CC BY

%}

% Explica ao usu�rio o que o programa faz 
disp('Esse programa calcula o comprimento de uma circunfer�ncia e a �rea de um c�rculo e tamb�m calcula o per�metro e a �rea de um ret�ngulo');

% Pergunta ao usu�rio quais c�lculos ele deseja
disp('Para calcular o comprimento de uma circunfer�ncia e a �rea de um c�rculo, digite 1');
disp('Para calcular o per�metro e a �rea de um ret�ngulo, digite 2');
disp('Para realizar os dois c�lculos, digite 3');
opcao = input('Op��o desejada: ');

% Condicionais para a op��o escolhida pelo usu�rio
if opcao == 1
    % Solicita o valor do raio ao usu�rio
    raio = input('\nDigite o valor do raio do c�rculo: ');
    
    % Defini o valor de pi como constante
    pi = 3.14;
    
    % Calcula o comprimento da circunfer�ncia (C = 2 * pi * r)
    comprimento = 2 * pi * raio;
    
    % Calcula a �rea do c�rculo (A = pi * r^2)
    area = pi * raio^2;
    
    % Exibir os resultados
    fprintf('O comprimento da circunfer�ncia �: %.2f\n', comprimento);
    fprintf('A �rea do c�rculo �: %.2f\n', area);

elseif opcao == 2
    % Solicita o valor dos lados ao usu�rio
    lado1 = input('\nDigite o valor do primeiro lado do ret�ngulo: ');
    lado2 = input('Digite o valor do segundo lado do ret�ngulo: ');
    
    % Calcula a �rea do ret�ngulo 
    area_retangulo = lado1 * lado2;
    
    % Calcula o per�metro do ret�ngulo
    perimetro_retangulo = 2 * (lado1 + lado2);
    
    % Exibi os resultados
    fprintf('A �rea do ret�ngulo �: %.2f\n', area_retangulo);
    fprintf('O per�metro do ret�ngulo �: %.2f\n', perimetro_retangulo);

elseif opcao == 3
    % C�lculos para o c�rculo
    raio = input('\nDigite o valor do raio do c�rculo: ');
    pi = 3.14;
    comprimento = 2 * pi * raio;
    area = pi * raio^2;
    
    % Exibir os resultados do c�rculo
    fprintf('O comprimento da circunfer�ncia �: %.2f\n', comprimento);
    fprintf('A �rea do c�rculo �: %.2f\n', area);
    
    % C�lculos para o ret�ngulo
    lado1 = input('\nDigite o valor do primeiro lado do ret�ngulo: ');
    lado2 = input('Digite o valor do segundo lado do ret�ngulo: ');
    area_retangulo = lado1 * lado2;
    perimetro_retangulo = 2 * (lado1 + lado2);
    
    % Exibir os resultados do ret�ngulo
    fprintf('A �rea do ret�ngulo �: %.2f\n', area_retangulo);
    fprintf('O per�metro do ret�ngulo �: %.2f\n', perimetro_retangulo);

else
    disp('Op��o inv�lida! Tente novamente.');  % Exibe uma mensagem de erro caso a op��o escolhida seja inv�lida
end
