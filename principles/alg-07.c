#include <stdio.h>

#define N 9

int main() {
    int array[N];
    int head = -1;
    int option;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir elemento no array\n");
        printf("2 - Apresentar array\n");
        printf("3 - Apresentar a moda e informar quantas vezes ela se repete\n");
        printf("4 - Sair do programa\n");
        printf("Opção: ");
        scanf("%d", &option);

        switch(option) {

            case 1:
                if (head == N - 1) {
                    printf("\nFull array!\n");
                    break;
                }

                printf("\nDigite o elemento: ");

                int value;
                scanf("%d", &value);

                array[++head] = value;

                break;

            case 2:
                if (head == -1) {
                    printf("\nArray empty!\n");
                    break;
                }

                for (int i = 0; i <= head; i++) {
                    printf("%d ", array[i]);
                }

                break;

             case 3:
                int mode, repetitions = 0, max = 0;

                for (int i = 0; i <= head; i++) {
                    for (int j = 0; j <= head; j++) {
                        if (array[i] == array[j]) {
                            repetitions++;
                        }
                    }

                    if (repetitions > max) {
                        mode = array[i];
                        max = repetitions;
                    }

                    repetitions = 0;
                }

                printf("\nMode: %d\nRepetitions: %d\n", mode, max);

                break;

             case 4:
                 printf("\nEncerrando programa...\n");
                 break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(option != 4);

    return 0;
}
