/*8) Crie uma função que receba dois parâmetros: um vetor e um valor do mesmo tipo do
vetor. A função deverá preencher os elementos de vetor com esse valor. Não utilize
índices para percorrer o vetor, apenas aritmética de ponteiros.*/

#include <stdio.h>

void preencher(int vetor[], int num)
{
    int *elementos = vetor;
    printf("\nVetor preenchido com esse valor: ");
    for(int i = 0; i < num; i++)
    {  
       *(elementos + i) = num;
       printf("[%d] ", *(elementos+i));

    }

}

int main()
{
    int numero;

    printf("Insira um valor: \n");
    scanf("%d", &numero);
    
    int vet[5];

    preencher(vet, numero);


return 0;
}
