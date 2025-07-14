/*4) Crie uma estrutura chamada Retângulo. Essa estrutura deverá conter o ponto superior
esquerdo e o ponto inferior direito do retângulo. Cada ponto é definido por uma estrutura
Ponto, a qual contém as posições X e Y. Faça um programa que declare e leia uma
estrutura Retângulo e exiba a área e o comprimento da diagonal e o perímetro desse
retângulo.*/

#include <stdio.h>
#include <math.h>

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

    // Leitura dos pontos corretamente
    printf("\nInsira o ponto X do canto superior esquerdo: ");
    scanf("%d", &retangulo.superiorE.posx);

    printf("Insira o ponto Y do canto superior esquerdo: ");
    scanf("%d", &retangulo.superiorE.posy);

    printf("Insira o ponto X do canto inferior direito: ");
    scanf("%d", &retangulo.inferiorD.posx);

    printf("Insira o ponto Y do canto inferior direito: ");
    scanf("%d", &retangulo.inferiorD.posy);

    int base = retangulo.inferiorD.posx - retangulo.superiorE.posx;
    int altura = retangulo.superiorE.posy - retangulo.inferiorD.posy;

    int area = base * altura;
    int perimetro = 2 * (base + altura);
    float diagonal = sqrt(pow(base, 2) + pow(altura, 2));

    printf("\nÁrea do retângulo: %d", area);
    printf("\nComprimento da diagonal: %.2f", diagonal);
    printf("\nPerímetro do retângulo: %d\n", perimetro);

    return 0;
}
