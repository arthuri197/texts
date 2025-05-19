/*
Programa: Uso de árvore binária com função de busca
Autor: Arthur Oliveira
Data: 18-05-2025
Descrição: Implementa uma árvore binária com inserção, busca, remoção 
Licença: CC BY
*/

#include <stdio.h>      // Biblioteca padrão para entrada/saída (ex: printf)
#include <stdlib.h>     // Biblioteca padrão para alocação de memória e exit()

// Definição da estrutura de um nó da árvore
typedef struct node {
    int key;               // Valor inteiro armazenado no nó
    struct node *left;     // Ponteiro para o filho à esquerda
    struct node *right;    // Ponteiro para o filho à direita
} tNode;

// Função para criar um novo nó com um valor
tNode *create_node(int key) {
    tNode *new_node = (tNode *) malloc(sizeof(tNode)); // Aloca memória para um novo nó
    if (new_node == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memoria.\n");
        exit(EXIT_FAILURE);  // Encerra o programa com erro
    }
    new_node->key = key;           // Define o valor do nó
    new_node->left = NULL;         // Inicializa o filho esquerdo como vazio
    new_node->right = NULL;        // Inicializa o filho direito como vazio
    return new_node;               // Retorna o novo nó criado
}

// Função para inserir um valor na BST (forma recursiva)
tNode *insert_node(tNode *root, int key) {
    if (root == NULL) {
        return create_node(key);  // Se a árvore está vazia, cria o nó raiz
    }

    if (key < root->key) {
        root->left = insert_node(root->left, key);  // Insere à esquerda
    } else {
        root->right = insert_node(root->right, key);  // Insere à direita (permite duplicatas)
    }

    return root;  // Retorna o ponteiro da raiz atual
}

// Função para buscar um valor 'k' na BST
int search_node(tNode *root, int k) {
    if (root == NULL) {
        return 0;  // Se chegamos ao final, o valor não está na árvore
    }

    if (k == root->key) {
        return 1;  // Valor encontrado
    } else if (k < root->key) {
        return search_node(root->left, k);  // Busca recursiva à esquerda
    } else {
        return search_node(root->right, k);  // Busca recursiva à direita
    }
}

// Função auxiliar para encontrar o menor valor de uma subárvore
tNode *min_value_node(tNode *node) {
    tNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;  // Caminha para o filho mais à esquerda
    }
    return current;
}

// Função para remover um nó com determinado valor
tNode *remove_node(tNode *root, int key) {
    if (root == NULL) {
        fprintf(stderr, "Erro: Chave nao encontrada.\n");
        return root;
    }

    if (key < root->key) {
        root->left = remove_node(root->left, key);  // Remover da subárvore esquerda
    } else if (key > root->key) {
        root->right = remove_node(root->right, key);  // Remover da subárvore direita
    } else {
        // Caso 1: Nó sem filhos ou com um filho
        if (root->left == NULL) {
            tNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tNode *temp = root->left;
            free(root);
            return temp;
        }

        // Caso 2: Nó com dois filhos
        tNode *temp = min_value_node(root->right); // Pega o menor valor da subárvore direita
        root->key = temp->key;                     // Substitui o valor do nó atual
        root->right = remove_node(root->right, temp->key); // Remove o nó duplicado
    }

    return root;
}

// Função para deletar a árvore e liberar memória
void delete_tree(tNode *root) {
    if (root != NULL) {
        delete_tree(root->left);     // Deleta subárvore esquerda
        delete_tree(root->right);    // Deleta subárvore direita
        free(root);                  // Libera o nó atual
    }
}

// Função para imprimir os valores da árvore em ordem crescente
void inorder_traversal(tNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);     // Visita a subárvore esquerda
        printf("%d ", root->key);          // Imprime o valor do nó atual
        inorder_traversal(root->right);    // Visita a subárvore direita
    }
}

// Função principal com testes de inserção, busca e impressão
int main() {
    tNode *root = NULL;  // Inicializa a árvore vazia

    // Inserção de nós
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    insert_node(root, 50); // Inserção de valor duplicado (irá à direita)

    // Impressão da árvore em ordem
    printf("Arvore em ordem: ");
    inorder_traversal(root);
    printf("\n");

    // Testes de busca por chaves
    int test_keys[3] = {40, 25, 50};  // 40 está presente, 25 não, 50 é duplicado
    for (int i = 0; i < 3; i++) {
        int result = search_node(root, test_keys[i]);
        printf("Busca por %d: %s\n", test_keys[i], result ? "Encontrado" : "Nao encontrado");
    }

    // Liberação de memória
    delete_tree(root);
    return 0;
}
