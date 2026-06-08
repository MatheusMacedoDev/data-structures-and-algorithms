#include <stdio.h>

#define N 8

typedef struct {
    int data[N];
    int head;
} Stack;

void construct(Stack *stack) {
    stack->head = -1;
}

int isEmpty(Stack *stack) {
    return stack->head == -1;
}

int isFull(Stack *stack) {
    return stack->head == N - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("\nStack overflow!\n");
        return;
    }

    stack->data[++stack->head] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("\nStack underflow!\n");
        return -1;
    }

    return stack->data[stack->head--];
}

void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("\nStack is empty!\n");
        return;
    }

    printf("\nStack elements:\n");

    for (int i = stack->head; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }

    printf("\n");
}

int main() {
    Stack P1, P2, aux;
    int option;
    int i;

    construct(&P1);
    construct(&P2);
    construct(&aux);

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir elemento na pilha P1\n");
        printf("2 - Apresentar a pilha P1 original\n");
        printf("3 - Apresentar a pilha P1 após a remoção dos números pares\n");
        printf("4 - Apresentar a pilha P2 após a inserção dos números pares\n");
        printf("5 - Sair do programa\n");
        printf("Opcao: ");
        scanf("%d", &option);

        switch(option) {

            case 1:
                printf("\nDigite o elemento: ");

                int value;
                scanf("%d", &value);

                push(&P1, value);

                break;

            case 2:
                printStack(&P1);
                break;

            case 3:
                while (!isEmpty(&P1)) {
                    int number = pop(&P1);
                    push(&aux, number);
                }

                while (!isEmpty(&aux)) {
                    int number = pop(&aux);

                    if (number % 2 == 0) {
                        push(&P2, number);
                    } else {
                        push(&P1, number);
                    }
                }

                printStack(&P1);
                break;

            case 4:
                printStack(&P2);
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
