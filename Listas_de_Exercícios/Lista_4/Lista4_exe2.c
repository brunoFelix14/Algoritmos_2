/*2) Crie uma estrutura para representar as coordenadas de um ponto no plano (posições X
e Y). Em seguida, declare e leia do teclado um ponto e exiba a distância dele até a origem
das coordenadas, isto é, a posição (0,0).*/

#include<stdio.h>
#include<math.h>

struct pontos
{
    int posX;
    int posY;
};

int main()
{
    struct pontos ponto;
    printf("Insira o valor do ponto X: ");
    scanf("%d", &ponto.posX);

    printf("\nInsira o valor do ponto Y: ");
    scanf("%d", &ponto.posY);

    int distancia = sqrt((ponto.posX * ponto.posX) + (ponto.posY * ponto.posY));

    printf("\nA distancia desse ponto até a origem é: %d", distancia);

return 0;
}
