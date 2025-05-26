#include <iostream>     // Para std::cout e std::cerr
#include <fstream>      // Para std::ifstream
#include <sstream>      // Para std::stringstream (separar string em tokens)
#include <string>       // Para std::string

int main() {
    std::ifstream file("C:\\Users\\20241en20047\\Desktop\\pratica8\\test_file_2.txt");  // Abre o arquivo para leitura

    if (!file) {  // Verifica se o arquivo abriu corretamente
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;  // Sai do programa em caso de erro
    }

    std::string line;  // Variável para armazenar cada linha do arquivo

    // Lê o arquivo linha por linha até o fim
    while (std::getline(file, line)) {
        std::stringstream ss(line);  // Cria um stream para dividir a linha em tokens separados por vírgula
        std::string token;            // Variável para armazenar cada campo separado

        // Enquanto conseguir extrair um token separado por vírgula
        while (std::getline(ss, token, ',')) {
            std::cout << token << std::endl;  // Imprime o token (campo)
        }
    }

    file.close();  // Fecha o arquivo

    return 0;  // Finaliza o programa com sucesso
}
