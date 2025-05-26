%{
Programa: Leitura de arquivo texto linha a linha

Autor: Arthur Oliveira
Data: 26/05/2025

Descrição: Script MATLAB que abre um arquivo de texto para leitura, lê o conteúdo
           linha a linha até o final do arquivo e exibe cada linha no console.

License: CC BY
%}


% Abre o arquivo para leitura
fid = fopen('test_file.txt', 'r');
if fid == -1
    error('Erro ao abrir o arquivo.');
end

% Lê linha a linha até o fim do arquivo
while ~feof(fid)
    linha = fgetl(fid); % Lê uma linha do arquivo
    disp(linha);        % Exibe a linha no console
end

fclose(fid); % Fecha o arquivo
