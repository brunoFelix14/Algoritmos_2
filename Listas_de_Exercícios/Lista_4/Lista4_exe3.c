/*3) Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X
e Y). Em seguida, declare e leia do teclado dois pontos e exiba a distância entre eles.*/

#include<stdio.h>
#include<math.h>

struct ponto1
{
    int posX;
    int posY;
};

struct ponto2
{
    int posX;
    int posY;
};

int main()
{
    struct ponto1 ponto1;
    printf("Insira o valor de X para o primeiro ponto: ");
    scanf("%d", &ponto1.posX);

    printf("\nInsira o valor de Y para o primeiro ponto: ");
    scanf("%d", &ponto1.posY);

    struct ponto2 ponto2;
    printf("\nInsira o valor de X para o segundo ponto: ");
    scanf("%d", &ponto2.posX);

    printf("\nInsira o valor de Y para o segundo ponto ponto: ");
    scanf("%d", &ponto2.posY);

    int diferenca1 = ponto2.posX - ponto1.posX;
    int diferenca2 = ponto2.posY - ponto1.posY;
    
    int distancia = sqrt((diferenca1 * diferenca1) + (diferenca2 * diferenca2));

    printf("\n A distancia entre os pontos é: %d", distancia);

return 0;
}