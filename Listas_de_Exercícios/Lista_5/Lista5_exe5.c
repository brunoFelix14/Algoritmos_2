/*5) Crie um programa que contenha um array de inteiros com cinco elementos. Utilizando
apenas aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada valor
lido.*/

#include<stdio.h>

int main()
{
    int array[5] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++)
    {
        int *dobrar = &array[i];
        *dobrar = *dobrar * 2;
        printf("Valor %d dobrado: %d\n", i, *dobrar);
    }

return 0;
}
