/*5) Faça um programa que leia um valor inteiro N não negativo. Se o valor de N for
inválido, o usuário deverá digitar outro até que ele seja válido (ou seja, positivo). Em
seguida, leia um vetor V contendo N posições de inteiros, em que cada valor deverá ser
maior ou igual a 2. Esse vetor deverá ser alocado dinamicamente.*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num;

    do
    {
        printf("Insira um numero: ");
        scanf("%d", &num);
    } while (num < 0);

    int *vetor = (int *) calloc(num, sizeof(int));

     if(vetor == NULL)
    {
        printf("Erro ao alocar memória!\n");
    }

    for(int i = 0; i < num; i++)
    {
     do {
            printf("\nInsira o valor para a posição %d do vetor: ", i);
            scanf("%d", &vetor[i]);

        if(vetor[i] < 2)
        {
            printf("Condição inválida, tente novamente.\n");
        }
    } while(vetor[i] < 2);
    }

    for(int i = 0; i < num; i++)
    {
        printf("\nElemento %d do vetor: %d", i, vetor[i]);
    }
    
    free(vetor);
return 0;
}