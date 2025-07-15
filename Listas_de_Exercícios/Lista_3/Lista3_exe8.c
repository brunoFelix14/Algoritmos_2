/*8) Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne o
ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou igual
a zero, um ponteiro nulo deverá ser retornado.*/

#include <stdio.h>
#include <stdlib.h>

int* criarVetor(int n)
{
    if (n <= 0)
    {
        return NULL;
    }

    int *vetor = (int *) malloc(n * sizeof(int));

    if (vetor == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
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

    if (vetor == NULL)
    {
        printf("Valor inválido. Nenhum vetor foi criado.\n");
    }
    else
    {
        printf("Vetor criado com sucesso!\n");

        for (int i = 0; i < n; i++)
        {
            vetor[i] = i;
            printf("%d ", vetor[i]);
        }
        printf("\n");

        free(vetor);
    }

    return 0;
}
