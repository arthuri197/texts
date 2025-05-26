%{
Programa: Leitura de arquivo texto linha a linha

Autor: Arthur Oliveira
Data: 26/05/2025

Descri��o: Script MATLAB que abre um arquivo de texto para leitura, l� o conte�do
           linha a linha at� o final do arquivo e exibe cada linha no console.

License: CC BY
%}


% Abre o arquivo para leitura
fid = fopen('test_file.txt', 'r');
if fid == -1
    error('Erro ao abrir o arquivo.');
end

% L� linha a linha at� o fim do arquivo
while ~feof(fid)
    linha = fgetl(fid); % L� uma linha do arquivo
    disp(linha);        % Exibe a linha no console
end

fclose(fid); % Fecha o arquivo
