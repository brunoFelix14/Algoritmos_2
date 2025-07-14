/*1) Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e
exiba o maior endereço.*/

#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int var1;
    int var2; 

    printf("Endereço da variável 1: %p\n", &var1);
    printf("Endereço da variável 2: %p\n", &var2);

    int *pA1 = &var1;
    int *pA2 = &var2;

    if(pA1 < pA2)
    {
        printf("O maior endereço é %p da variável 2", pA2);
    }
    else
    {
        printf("O maior endereço é %p da variável 1", pA1);
    }

return 0;
}
