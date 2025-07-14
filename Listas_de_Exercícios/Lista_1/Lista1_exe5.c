//5 - Faça um procedimento que recebe por parâmetro o tempo de duração de uma fábrica expressa em segundos e imprima esse tempo em horas, minutos e segundos.
#include<stdio.h>
#include<locale.h>

void tempo(int segundos)
{
  int hor, min, segundo, resto;
  
  hor = segundos / 3600;
  resto = segundos % 3600;
  min = resto / 60;
  segundo = resto % 60;
  
  printf("\nTempo em horas: %d hora(s)", hor);

  printf("\nTempo em minutos: %d minuto(s)", min);
  
  printf("\nTempo em segundos: %d segundo(s)", segundo);
}

int main()
{
  setlocale(LC_ALL, "");
  int seg;
  
  printf("\n-----------------------------------------------------Fábrica Expressa-----------------------------------------------------\n");
  printf("\nInsira o tempo em segundos: ");
  scanf("%d", &seg);
  
  tempo(seg);
  
  return 0;
}
