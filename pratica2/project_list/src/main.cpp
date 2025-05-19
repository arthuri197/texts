#include <iostream>
#include "list.h"  // Incluindo o cabeçalho C que foi preparado para C++

using namespace std;

int main() {
    tList list = create_list();

    // Inserindo elementos na lista
    insert_end(&list, "Carro");
    insert_end(&list, "Banana");
    insert_end(&list, "Moto");

    // Imprimindo os elementos da lista
    cout << "Lista após inserção:" << endl;
    print_list(&list);

    // Removendo um elemento da lista
    if (remove_node(&list, "Banana")) {
        cout << "Palavra 'Banana' removida." << endl;
    }

    // Imprimindo os elementos restantes
    cout << "Lista após remoção da 'Banana':" << endl;
    print_list(&list);

    // Liberando a memória
    free_list(&list);

    return 0;
}
