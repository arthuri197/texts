#ifndef LIST_H
#define LIST_H

#ifdef __cplusplus
extern "C" {
#endif

// Definição da lista e funções

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} tList;

// Funções da lista
tList create_list();
void insert_end(tList* list, const char* data);
int remove_node(tList* list, const char* data);
void print_list(const tList* list);
void free_list(tList* list);

#ifdef __cplusplus
}
#endif

#endif // LIST_H

