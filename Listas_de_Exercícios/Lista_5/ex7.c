/*7) Elabore uma função que receba duas strings como parâmetros e verifique se a segunda
string ocorre dentro da primeira. Use aritmética de ponteiros para acessar os caracteres
das strings.*/

#include<stdio.h>

void comparar_strings(char *str1, char *str2)
{
    char *inicio = str1;

    while(*str1 != '\0')
    {
        char *vtp1 = str1;
        char *vtp2 = str2;

        while(*vtp1 == *vtp2 && *vtp2 != '\0')
        {
            vtp1++;
            vtp2++;
        }
        if(*vtp2 == '\0')
        {
            printf("A string \"%s\" ocorre dentro de \"%s\".\n", str2, inicio);
            return;
        }
        str1++;
    }
    printf("A string \"%s\" NÃO ocorre dentro de \"%s\".\n", str2, inicio);
    
}

int main()
{
    char string1[50];
    char string2[50];

    printf("Insira um texto qualquer: \n");
    scanf(" %[^\n]", string1);

    printf("Insira outro texto qualquer: \n");
    scanf(" %[^\n]", string2);

    comparar_strings(string1, string2);

return 0;
}