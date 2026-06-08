#include <stdlib.h>
#include <stdio.h>

int fatorial(int numlido);

long int total=1, numlido, num;

int main(void)
{
    printf("Informe o numero a ser calculado o N!: \n ");
    scanf("%d", &num);

    total = fatorial(num);

    printf(" N! de %d é: %d \n",num, total);

    getchar();
}

int fatorial (int n)
{
    if(n<=1)
        return 1;

    return fatorial(n-1)* n;
}
