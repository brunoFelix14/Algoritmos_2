/*2) Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do
teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.*/

#include<stdio.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int var1;
    int var2;

    printf("Insira o valor para um inteiro: ");
    scanf("%d", &var1);

    printf("\nInsira outro valor para um inteiro: ");
    scanf("%d", &var2);

    printf("\nEndereço do primeiro inteiro: %p", &var1);
    printf("\nEndereço do segundo inteiro: %p\n", &var2);

    if(&var1 > &var2)
    {
        printf("O maior endereço é %p do primeiro inteiro cujo valor é %d!", &var1, var1);
    }
    else
    {
        printf("O maior endereço é %p do segundo inteiro cujo valor é %d!", &var2, var2);
    }
return 0;
}
