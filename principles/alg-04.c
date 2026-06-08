#include <stdio.h>

#define N 10

int binarySearch(int S[], int searchElement) {
    int left = 0;
    int right = N - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (S[middle] == searchElement) {
            return middle;
        } else if (searchElement > S[middle]) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main() {
    int S[N];
    int option;
    int i;
    int filled = 0;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir elementos no array\n");
        printf("2 - Apresentar array original\n");
        printf("3 - Informar elemento a ser buscado\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &option);

        switch(option) {

            case 1:
                printf("\nDigite %d elementos:\n", N);

                for(i = 0; i < N; i++) {
                    printf("S[%d] = ", i);
                    scanf("%d", &S[i]);
                }

                filled = 1;
                break;

            case 2:
                if(!filled) {
                    printf("\nArray vazio!\n");
                    break;
                }

                printf("\nArray original:\n");

                for(i = 0; i < N; i++) {
                    printf("%d ", S[i]);
                }

                printf("\n");
                break;

            case 3:
                if(!filled) {
                    printf("\nArray vazio!\n");
                    break;
                }

                int searchElement;

                printf("\nInformar elemento a ser buscado: ");
                scanf("%d", &searchElement);

                int findedElement = binarySearch(S, searchElement);

                if (findedElement != -1) {
                    printf("\nElemento encontrado na posição: %d\n", findedElement);
                } else {
                    printf("\nElemento não encontrado!\n");
                }

                printf("\n");
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
