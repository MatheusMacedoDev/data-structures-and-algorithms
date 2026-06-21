#include <stdio.h>

#define N 10

typedef struct {
    int data[N];
    int head;
    int tail;
} Queue;

void construct(Queue *queue) {
    queue->head = N - 1;
    queue->tail = queue->head;
}

int isEmpty(Queue *queue) {
    return queue->head == queue->tail;
}

int isFull(Queue *queue) {
    return queue->tail == -1;
}

void add(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("\nQueue overflow!\n");
        return;
    }

    queue->data[queue->tail--] = value;
}

int poll(Queue *queue) {
    if (isEmpty(queue)) {
        printf("\nEmpty queue!\n");
        return -1;
    }

    return queue->data[queue->head--];
}

void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("\nQueue is empty!\n");
        return;
    }

    for (int i = queue->tail + 1; i <= queue->head; i++) {
        printf("%d ", queue->data[i]);
    }

    printf("<- HEAD\n");
}

int main() {
    Queue Q1, Q2, aux;
    int option;
    int i;

    construct(&Q1);
    construct(&Q2);
    construct(&aux);

    for (int i = 1; i <= 10; i++) {
        add(&Q1, i);
    }

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir elemento na fila Q1\n");
        printf("2 - Apresentar a fila Q1 original\n");
        printf("3 - Apresentar a fila Q1 após a remoção dos números pares\n");
        printf("4 - Apresentar a fila Q2 após a inserção dos números pares\n");
        printf("5 - Sair do programa\n");
        printf("Opção: ");
        scanf("%d", &option);

        switch(option) {

            case 1:
                printf("\nDigite o elemento: ");

                int value;
                scanf("%d", &value);

                add(&Q1, value);

                break;

            case 2:
                printQueue(&Q1);
                break;

            case 3:
                construct(&aux);

                while (!isEmpty(&Q1)) {
                    int number = poll(&Q1);
                    printf("\nNumber: %d\n", number);
                    add(&aux, number);
                }
                
                construct(&Q1);

                while (!isEmpty(&aux)) {
                    int number = poll(&aux);

                    if (number % 2 == 0) {
                        add(&Q2, number);
                    } else {
                        add(&Q1, number);
                    }
                }

                printQueue(&Q1);
                break;

             case 4:
                 printQueue(&Q2);
                 break;

             case 5:
                 printf("\nEncerrando programa...\n");
                 break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(option != 5);

    return 0;
}
