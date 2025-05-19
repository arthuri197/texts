#include <stdio.h>
#include <string.h>
#include "./include/list.h"

int main() {
    // Criação da lista encadeada de palavras
    tList list = create_list();

    // Inserção de palavras na lista
    insert_end(&list, "Carro");
    insert_end(&list, "Banana");
    insert_end(&list, "Moto");

    // Imprimir a lista de palavras
    printf("Lista após inserção:\n");
    print_list(&list);

    // Remover palavra da lista
    if (remove_node(&list, "Banana")) {
        printf("Palavra 'Banana' removida.\n");
    } else {
        printf("Palavra 'Banana' não encontrada.\n");
    }

    // Imprimir a lista após remoção
    printf("Lista após remoção da 'Banana':\n");
    print_list(&list);

    // Liberar a memória alocada
    free_list(&list);

    return 0;
}
