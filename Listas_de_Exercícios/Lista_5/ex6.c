/*6) Crie um programa que contenha um array com cinco elementos inteiros. Leia esse array
do teclado e imprima o endereço das posições contendo valores pares.*/

#include<stdio.h>

int main()
{
    int array[5];
    
    for(int i = 0; i < 5; i++)
    {
        printf("Insira o valor para o elemento %d: \n", i);
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        if(array[i] % 2 == 0)
        {
            int *par = &array[i];
            printf("O elemento %d é par! E seu endereço é: %p\n", i, par);
        }
    }
    
return 0;
}