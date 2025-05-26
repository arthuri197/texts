%{
Programa: Leitura e Parsing de Arquivo

Autor: Arthur Oliveira

Data: 26/05/2025

Descri��o: Script MATLAB que abre um arquivo de texto com campos separados por v�rgula,
           l� linha a linha, divide cada linha em campos usando a v�rgula como separador
           e exibe os campos no console.

License: CC BY
%}


% Abre arquivo CSV para leitura
fid = fopen('test_file_2.txt', 'r');
if fid == -1
    error('Erro ao abrir o arquivo.');
end

% L� o arquivo linha a linha
while ~feof(fid)
    linha = fgetl(fid);  % L� uma linha
    if ischar(linha)
        campos = strsplit(linha, ','); % Separa campos pela v�rgula
        disp(campos);                  % Exibe os campos
    end
end

fclose(fid); % Fecha o arquivo
