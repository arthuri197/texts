#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/list.h"

// Função para criar a lista
tList create_list() {
    tList list;
    list.head = NULL;  // Inicializando a lista como vazia
    return list;
}

// Função para inserir um nó no final da lista
void insert_end(tList* list, const char* value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = strdup(value);  // Copiar a string para o novo nó
    new_node->next = NULL;

    // Se a lista estiver vazia, o novo nó é a cabeça da lista
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        // Caso contrário, percorre a lista até o final e adiciona o novo nó
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Função para remover um nó da lista
int remove_node(tList* list, const char* value) {
    if (list->head == NULL) {
        return 0;  // Lista vazia, nada para remover
    }

    Node* temp = list->head;
    Node* prev = NULL;

    // Verifica se a cabeça contém o valor
    if (temp != NULL && strcmp(temp->data, value) == 0) {
        list->head = temp->next;  // Atualiza a cabeça para o próximo nó
        free(temp->data);
        free(temp);
        return 1;
    }

    // Percorre a lista em busca do valor
    while (temp != NULL && strcmp(temp->data, value) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // Se não encontrou o valor
    if (temp == NULL) {
        return 0;  // Valor não encontrado
    }

    // Remove o nó
    prev->next = temp->next;
    free(temp->data);
    free(temp);
    return 1;  // Valor removido com sucesso
}

// Função para imprimir todos os elementos da lista
void print_list(const tList* list) {
    if (list->head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Node* temp = list->head;
    printf("Elementos da lista: ");
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Função para liberar a memória alocada pela lista
void free_list(tList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp->data);
        free(temp);
        temp = next;
    }
    list->head = NULL;
}
