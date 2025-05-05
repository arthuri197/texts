#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} tNode;

typedef struct queue {
    tNode* front; // Início da fila (dequeue)
    tNode* rear;  // Fim da fila (enqueue)
} tQueue;

// Cria uma fila vazia
tQueue create_queue() {
    tQueue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

// Insere elemento no final da fila (enqueue)
void insert_rear(tQueue* q, int x) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Erro: Sem memória disponível.\n");
        return;
    }

    new_node->data = x;
    new_node->next = NULL;

    if (q->rear == NULL) {
        // Fila está vazia
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Remove elemento do início da fila (dequeue)
int remove_front(tQueue* q, int* x) {
    if (q->front == NULL) {
        printf("Erro: Fila vazia.\n");
        return 0; // Falha
    }

    tNode* temp = q->front;
    *x = temp->data;

    q->front = temp->next;

    if (q->front == NULL) {
        // Fila ficou vazia após remoção
        q->rear = NULL;
    }

    free(temp);
    return 1; // Sucesso
}

// Imprime a fila
void print_queue(tQueue* q) {
    tNode* current = q->front;
    printf("Fila: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Libera toda a fila
void free_queue(tQueue* q) {
    tNode* current = q->front;
    while (current != NULL) {
        tNode* temp = current;
        current = current->next;
        free(temp);
    }
    q->front = NULL;
    q->rear = NULL;
}

// MAIN para teste
int main() {
    tQueue q = create_queue();

    insert_rear(&q, 10);
    insert_rear(&q, 20);
    insert_rear(&q, 30);

    print_queue(&q);  // Esperado: Fila: 10 20 30

    int removed;
    if (remove_front(&q, &removed))
        printf("Removido da fila: %d\n", removed);  // Esperado: 10

    print_queue(&q);  // Esperado: Fila: 20 30

    insert_rear(&q, 40);
    insert_rear(&q, 50);

    print_queue(&q);  // Esperado: Fila: 20 30 40 50
    
    if (remove_front(&q, &removed))
        printf("Removido da fila: %d\n", removed);  // Esperado: 10
        
    print_queue(&q);

    free_queue(&q);

    return 0;
}
