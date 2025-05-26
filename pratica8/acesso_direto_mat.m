%{

Programa: Acesso Direto a Arquivo Bin�rio

Autor: Arthur Oliveira

Data: 26/05/2025

Descri��o: Script em MATLAB que realiza escrita e leitura em posi��es espec�ficas
           de um arquivo bin�rio

License: CC BY

%}


% Abre o arquivo para escrita bin�ria ('w+' zera o arquivo)
fid = fopen('data.bin', 'w+');
if fid == -1
    error('Erro ao abrir o arquivo.');
end

position = 300; % Posi��o em bytes (exemplo: posi��o 300)

% Move o ponteiro de escrita para posi��o desejada
fseek(fid, position, 'bof');

% Escreve o caractere 'G' na posi��o
fwrite(fid, 'G', 'char');

% Importante: fecha para garantir que os dados sejam escritos
fclose(fid);

% Reabre o arquivo agora apenas para leitura
fid = fopen('data.bin', 'r');
if fid == -1
    error('Erro ao reabrir o arquivo.');
end

% Move o ponteiro de leitura para a mesma posi��o
fseek(fid, position, 'bof');

% L� 1 caractere na posi��o
valor = fread(fid, 1, 'char');

% Exibe o caractere lido
fprintf('Caractere lido: %c\n', char(valor));

fclose(fid); % Fecha o arquivo
