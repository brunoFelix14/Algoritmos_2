/*9) Crie uma função que receba como parâmetro um vetor e o imprima. Não utilize índices
para percorrer o vetor, apenas aritmética de ponteiros.*/

#include<stdio.h>

void imprimir_vetor(int vetor[], int tamanho)
{
    int *p = vetor;
    for(int i = 0; i < tamanho; i++)
    {
        printf("[%d] ", *(p + i));
    }
}

int main()
{
    int vet[] = {1, 2, 3, 4, 5};
    int tam = sizeof(vet) / sizeof(vet[0]);

    imprimir_vetor(vet, tam);

return 0;
}
