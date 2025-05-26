%{
Programa: Leitura e Parsing de Arquivo

Autor: Arthur Oliveira

Data: 26/05/2025

Descrição: Script MATLAB que abre um arquivo de texto com campos separados por vírgula,
           lê linha a linha, divide cada linha em campos usando a vírgula como separador
           e exibe os campos no console.

License: CC BY
%}


% Abre arquivo CSV para leitura
fid = fopen('test_file_2.txt', 'r');
if fid == -1
    error('Erro ao abrir o arquivo.');
end

% Lê o arquivo linha a linha
while ~feof(fid)
    linha = fgetl(fid);  % Lê uma linha
    if ischar(linha)
        campos = strsplit(linha, ','); % Separa campos pela vírgula
        disp(campos);                  % Exibe os campos
    end
end

fclose(fid); % Fecha o arquivo
