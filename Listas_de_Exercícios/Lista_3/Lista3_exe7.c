/*7) Faça uma função que retorne o ponteiro para um vetor de N elementos inteiros alocados
dinamicamente. O array deve ser preenchido com valores de 0 a N − 1.*/

#include <stdio.h>
#include <stdlib.h>

int* criarVetor(int n)
{
    int *vetor = (int *) malloc(n * sizeof(int));

    if (vetor == NULL)
    {
        printf("Erro ao alocar memória.\n");
    }

    for (int i = 0; i < n; i++)
    {
        vetor[i] = i;
    }

    return vetor;
}

int main()
{
    int n;
    int *vetor;

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    vetor = criarVetor(n);

    printf("Vetor criado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}
