/*
* Considere uma sequência de n elementos inteiros. Escrever um programa em C que implemente uma lista encadeada
* (alocação dinâmica). O programa deve ter um menu com as seguintes opções: inserir elemento; exibir lista; liberar
* (memória) lista. Como trata-se de alocação dinâmica, o valor de n não precisa ser definido.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} List;

int isEmpty(List *list) {
    return list->head == NULL;
}

void add(List *list, int value) {
    Node* node = (Node*) malloc(sizeof(Node));

    node->data = value;
    node->next = list->head;

    list->head = node;
}

void freeAll(List **listRef) {
    if (listRef == NULL || *listRef == NULL) {
        printf("\nList is NULL!\n");
        return;
    }

    List* list = *listRef;

    Node* currentNode = list->head;
    Node* nextNode = NULL;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    free(list);

    *listRef = NULL;
}

void printList(List *list) {
    if (list == NULL) {
        printf("\nList is NULL!\n");
        return;
    }

    if (isEmpty(list)) {
        printf("\nList is empty!\n");
        return;
    }

    Node* currentNode = list->head;

    printf("(HEAD) ");
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
}

int main() {
    List* L1 = (List*) malloc(sizeof(List));
    L1->head = NULL;

    int option;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir elemento na lista\n");
        printf("2 - Apresentar a lista\n");
        printf("3 - Liberar memória\n");
        printf("4 - Sair do programa\n");
        printf("Opção: ");
        scanf("%d", &option);

        switch(option) {

            case 1:
                printf("\nDigite o elemento: ");

                int value;
                scanf("%d", &value);

                add(L1, value);

                break;

            case 2:
                printList(L1);
                break;

            case 3:
                freeAll(&L1);
                break;

            case 4:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while(option != 4);

    return 0;
}
