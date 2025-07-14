/*5) Usando a estrutura Retângulo do exercício anterior, faça um programa que declare e
leia uma estrutura Retângulo e um Ponto, e informe se esse ponto está ou não dentro do
retângulo.*/
#include <stdio.h>

struct Ponto 
{
    int posx;
    int posy;
};

struct Retangulo
{
    struct Ponto superiorE;
    struct Ponto inferiorD;
};

int main() 
{
    struct Retangulo retangulo;
    struct Ponto ponto;

    printf("\nInsira o ponto X do canto superior esquerdo: ");
    scanf("%d", &retangulo.superiorE.posx);

    printf("Insira o ponto Y do canto superior esquerdo: ");
    scanf("%d", &retangulo.superiorE.posy);

    printf("Insira o ponto X do canto inferior direito: ");
    scanf("%d", &retangulo.inferiorD.posx);

    printf("Insira o ponto Y do canto inferior direito: ");
    scanf("%d", &retangulo.inferiorD.posy);

    printf("\nInsira o ponto X a ser verificado: ");
    scanf("%d", &ponto.posx);

    printf("Insira o ponto Y a ser verificado: ");
    scanf("%d", &ponto.posy);

    if (ponto.posx >= retangulo.superiorE.posx && ponto.posx <= retangulo.inferiorD.posx && ponto.posy <= retangulo.superiorE.posy && ponto.posy >= retangulo.inferiorD.posy)
    {
        printf("\nO ponto (%d, %d) está dentro do retângulo.\n", ponto.posx, ponto.posy);
    }
    else
    {
        printf("\nO ponto (%d, %d) está fora do retângulo.\n", ponto.posx, ponto.posy);
    }

    return 0;
}
