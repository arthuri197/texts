#include <stdio.h>
#include <stdlib.h>

// Estrutura de nó
typedef struct node {
    int data;
    struct node* next;
} tNode;

// Estrutura da pilha
typedef struct stack {
    tNode* top; // Aponta para o topo da pilha
} tStack;

// Inicializa a pilha
tStack create_stack() {
    tStack stack;
    stack.top = NULL;
    return stack;
}

// Insere um elemento no topo (PUSH)
void push(tStack* stack, int x) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Erro: Sem memória disponível.\n");
        return;
    }
    new_node->data = x;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Remove e retorna o elemento do topo (POP)
int pop(tStack* stack) {
    if (stack->top == NULL) {
        printf("Erro: Pilha vazia.\n");
        return -1; // Valor indicativo de erro
    }

    tNode* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

// Imprime a pilha
void print_stack(tStack* stack) {
    tNode* current = stack->top;
    printf("Topo -> ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("<- Base\n");
}

// Libera toda a memória da pilha
void free_stack(tStack* stack) {
    tNode* current = stack->top;
    while (current != NULL) {
        tNode* temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
}

// MAIN para teste
int main() {
    tStack stack = create_stack();

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    print_stack(&stack);  // Deve mostrar: Topo -> 30 20 10 <- Base

    int val = pop(&stack);
    printf("Elemento removido (pop): %d\n", val);

    print_stack(&stack);  // Deve mostrar: Topo -> 20 10 <- Base

    free_stack(&stack);

    return 0;
}
