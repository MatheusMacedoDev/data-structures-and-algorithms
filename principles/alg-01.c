#include <stdio.h>
int main(void)
{
    int x[10];
    int t;

    for(t=0; t<10; ++t)
        x[t] = t;

    for(t=0; t<10; ++t)
        printf("%d ", x[t]);

    return 0;
}
