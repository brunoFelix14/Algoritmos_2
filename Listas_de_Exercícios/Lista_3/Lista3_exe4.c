/*4) Elabore um programa que leia do usuário o tamanho de um vetor a ser lido. Em seguida,
faça a alocação dinâmica desse vetor. Por fim, leia o vetor do usuário e o imprima.*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int tamanho;

    printf("\nInsira o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *) calloc(tamanho, sizeof(int));

    if(vetor == NULL)
    {
        printf("Erro ao alocar memória!\n");
    }

    printf("Vetor alocado!\n");

    for(int i = 0; i < tamanho; i++)
    {
        printf("\nInsira um valor para o elemento %d do vetor: ", i);
        scanf("%d", &vetor[i]);
    }

        for(int i = 0; i < tamanho; i++)
    {
        printf("\nElemento %d do vetor: %d", i, vetor[i]);
    }

    free(vetor);

return 0;
}