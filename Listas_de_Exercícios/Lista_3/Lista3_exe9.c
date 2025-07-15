/*9) Crie uma função que receba uma string e retorne o ponteiro para essa string invertida*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inverterString(char *str)
{
    int tamanho = strlen(str);
    char *invertida = (char *) malloc((tamanho + 1) * sizeof(char));

    if (invertida == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++)
    {
        invertida[i] = str[tamanho - 1 - i];
    }

    invertida[tamanho] = '\0';

    return invertida;
}

int main()
{
    char texto[100];
    char *resultado;

    printf("Digite uma string: ");
    scanf(" %[^\n]", texto);

    resultado = inverterString(texto);

    printf("String invertida: %s\n", resultado);

    free(resultado);
    return 0;
}
