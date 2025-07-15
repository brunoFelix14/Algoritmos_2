/*15) Escreva uma função que receba como parâmetro dois vetores, A e B, de tamanho N
cada. A função deve retornar o ponteiro para um vetor C de tamanho N alocado
dinamicamente, em que C[i] = A[i] * B[i].*/

#include <stdio.h>
#include <stdlib.h>

int* multiplicarVetores(int *a, int *b, int n)
{
    int *c = (int *) malloc(n * sizeof(int));

    if (c == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] * b[i];
    }

    return c;
}

int main()
{
    int n;
    int *a, *b, *c;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    a = (int *) malloc(n * sizeof(int));
    b = (int *) malloc(n * sizeof(int));

    if (a == NULL || b == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos do vetor A:\n");
    for (int i = 0; i < n; i++)
    {
        printf("A[%d]: ", i);
        scanf("%d", &a[i]);
    }

    printf("Digite os elementos do vetor B:\n");
    for (int i = 0; i < n; i++)
    {
        printf("B[%d]: ", i);
        scanf("%d", &b[i]);
    }

    c = multiplicarVetores(a, b, n);

    printf("Vetor C (A * B):\n");
    for (int i = 0; i < n; i++)
    {
        printf("C[%d] = %d\n", i, c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}
