%{

Programa: Acesso Direto a Arquivo Binário

Autor: Arthur Oliveira

Data: 26/05/2025

Descrição: Script em MATLAB que realiza escrita e leitura em posições específicas
           de um arquivo binário

License: CC BY

%}


% Abre o arquivo para escrita binária ('w+' zera o arquivo)
fid = fopen('data.bin', 'w+');
if fid == -1
    error('Erro ao abrir o arquivo.');
end

position = 300; % Posição em bytes (exemplo: posição 300)

% Move o ponteiro de escrita para posição desejada
fseek(fid, position, 'bof');

% Escreve o caractere 'G' na posição
fwrite(fid, 'G', 'char');

% Importante: fecha para garantir que os dados sejam escritos
fclose(fid);

% Reabre o arquivo agora apenas para leitura
fid = fopen('data.bin', 'r');
if fid == -1
    error('Erro ao reabrir o arquivo.');
end

% Move o ponteiro de leitura para a mesma posição
fseek(fid, position, 'bof');

% Lê 1 caractere na posição
valor = fread(fid, 1, 'char');

% Exibe o caractere lido
fprintf('Caractere lido: %c\n', char(valor));

fclose(fid); % Fecha o arquivo
