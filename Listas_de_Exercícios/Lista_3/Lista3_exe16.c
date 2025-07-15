/*16) Escreva uma função que receba como parâmetro uma matriz A contendo N linhas e
N colunas, e um vetor B de tamanho N. A função deve retornar o ponteiro para um vetor
C de tamanho N alocado dinamicamente, em que C é o produto da matriz A pelo vetor B.*/
#include <stdio.h>
#include <stdlib.h>

int* multiplicarMatrizVetor(int **a, int *b, int n)
{
    int *c = (int *) malloc(n * sizeof(int));

    if (c == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        c[i] = 0;
        for (int j = 0; j < n; j++)
        {
            c[i] += a[i][j] * b[j];
        }
    }

    return c;
}

int main()
{
    int n;
    int **a, *b, *c;

    printf("Digite o tamanho da matriz (N x N): ");
    scanf("%d", &n);

    a = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *) malloc(n * sizeof(int));
    }

    b = (int *) malloc(n * sizeof(int));

    if (a == NULL || b == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Digite os elementos do vetor B:\n");
    for (int i = 0; i < n; i++)
    {
        printf("B[%d]: ", i);
        scanf("%d", &b[i]);
    }

    c = multiplicarMatrizVetor(a, b, n);

    printf("Resultado (vetor C = A x B):\n");
    for (int i = 0; i < n; i++)
    {
        printf("C[%d] = %d\n", i, c[i]);
    }

    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}
