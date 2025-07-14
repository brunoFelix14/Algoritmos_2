/*11) Escreva um programa que contenha uma estrutura representando uma data válida.
Essa estrutura deve conter os campos dia, mês e ano. Em seguida, leia duas datas e
armazene nessa estrutura. Calcule e exiba o número de dias que decorreram entre as duas
datas.*/

#include <stdio.h>
#include <stdlib.h>

struct Data 
{
    int dia;
    int mes;
    int ano;
};

int diasDoMes(int mes) 
{
    if (mes == 2)
    {
        return 28;
    }
        
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30;
    }
        
    else
    {
        return 31;
    }     
}

int contarDias(struct Data d) 
{
    int total = 0;

    for (int i = 1; i < d.ano; i++)
        total += 365;

    for (int i = 1; i < d.mes; i++)
        total += diasDoMes(i);

    total += d.dia;

    return total;
}

int main() {
    struct Data d1, d2;

    printf("Digite a primeira data (dia mes ano): ");
    scanf("%d %d %d", &d1.dia, &d1.mes, &d1.ano);

    printf("Digite a segunda data (dia mes ano): ");
    scanf("%d %d %d", &d2.dia, &d2.mes, &d2.ano);

    int dias1 = contarDias(d1);
    int dias2 = contarDias(d2);

    int diferenca = abs(dias1 - dias2);

    printf("A diferença entre as datas é de %d dias.\n", diferenca);

    return 0;
}