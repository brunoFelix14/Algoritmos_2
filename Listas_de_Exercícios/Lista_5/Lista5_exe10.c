/*10) Considere a seguinte declaração: int a, *b, **c, ***d. Escreva um programa que leia
a variável a e calcule e exiba o dobro, o triplo e o quádruplo desse valor utilizando apenas
os ponteiros b, c e d. O ponteiro b deve ser usado para calcular o dobro, c, o triplo, e d, o
quádruplo.*/

#include<stdio.h>

int main()
{
    int a, *b, **c, ***d;

    printf("Insira um valor: ");
    scanf("%d", &a);

    b = &a;
    c = &b;
    d = &c; 

    int x2 = (*b) * 2;
    int x3 = (**c) * 3;
    int x4 = (***d) * 4;

    printf("\n O dobro desse valor é: %d", x2);
    printf("\n O triplo desse valor: %d", x3);
    printf("\n O quadruplo desse valor: %d", x4);

return 0;
}
