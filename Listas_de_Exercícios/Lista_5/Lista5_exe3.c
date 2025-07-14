/*3) Crie um programa que contenha um array de float com 10 elementos. Imprima o
endereço de cada posição desse array*/

#include<stdio.h>
#include<locale.h>

int main()
{
    float array[10];

    for(int i = 0; i < 10; i++)
    {
        printf("Endereço do elemento %d: %p\n", i, &array[i]);
    }

return 0;
}
