#include <stdio.h>

#define N 8

int main() {
    int S[N];
    int option;
    int i;
    int filled = 0;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir elementos no array\n");
        printf("2 - Apresentar array original\n");
        printf("3 - Apresentar array invertido\n");
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

                printf("\nArray invertido:\n");

                for(i = N - 1; i >= 0; i--) {
                    printf("%d ", S[i]);
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
