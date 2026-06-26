#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LETTERS_AMOUNT 25
#define MAX_INFO 5

int hash(char text[30]);

struct Table
{
    char info[30];
} infoTable[LETTERS_AMOUNT];

void main(void){
    int i;
    int j;
    int flag;
    char aux[30];

    printf("Tabela Hash para guardar PAIS e CAPITAL \n");
    printf("Não há tratamento de colisões \n");

    for (i=0;i<LETTERS_AMOUNT;i++)
    {
        strcpy(infoTable[i].info, "Ainda não prenchido.");
    }

    printf("Entrada de dados... \n");
    printf("\n");
    printf("Siga este formato: PAIS-CAPITAL (cinco informações) \n");

    for (i=0; i < MAX_INFO; i++)
    {
        printf("Entre com a informação %d: ", i + 1);
        scanf("%s", aux);

        j = hash(aux);

        printf("\nO índice na tabela é: %d", j);

        strcpy(infoTable[j].info, aux);

        printf("\n %s: ",infoTable[j].info);

        printf("\n");
    }

    flag = 1;
    while (flag == 1)
    {
        printf("\n");
        printf("Entre com o país que deseja saber a capital \n");
        scanf("\n %s",aux);

        j = hash(aux);

        printf("\n");
        printf("País-Capital é: %s ", infoTable[j].info);
        printf("\n");
        printf("Indice na tabela hash é: %d ", j);
        printf("\n");
        printf("Digite C (nova pesquisa) ou qualquer outra tecla para SAIR \n");
        scanf("\n %s", aux);

        if (aux[0] =='C') flag = 1;
        else flag = 0;

        printf("\n");
    }
}

int hash(char text[30])
{
    char fist_letter = tolower(text[0]);
    int index = fist_letter - 'a';

    return index;
}

