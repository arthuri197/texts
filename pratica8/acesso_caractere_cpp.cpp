#include <iostream>   // Para std::cout e std::cerr
#include <fstream>    // Para std::ifstream (leitura de arquivos)

int main() {
    std::ifstream file("C:\\Users\\20241en20047\\Desktop\\pratica8\\test_file.txt");  // Abre o arquivo para leitura

    if (!file) {  // Verifica se o arquivo abriu corretamente
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;  // Sai do programa com código de erro
    }

    char ch;  // Variável para armazenar cada caractere lido

    // Enquanto conseguir ler um caractere do arquivo
    while (file.get(ch)) {
        std::cout << ch << std::endl;  // Imprime o caractere seguido de quebra de linha
    }

    file.close();  // Fecha o arquivo após a leitura

    return 0;  // Finaliza o programa com sucesso
}
