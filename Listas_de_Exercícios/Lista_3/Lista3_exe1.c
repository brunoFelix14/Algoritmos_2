/*1) Escreva um programa que mostre o tamanho em byte que cada tipo de dados ocupa na
memória: char, int, float, double*/

#include <stdio.h>
int main()
{
  int inti = sizeof(int);
  float flut = sizeof(float);
  char cha = sizeof(char);
  double dubo = sizeof(double);

  printf("Tamanho de uma variável do tipo int: %d", inti);
  printf("\nTamanho de uma variável do tipo float: %f", flut);
  printf("\nTamanho de uma variável do tipo char: %d", cha);
  printf("\nTamanho de uma variável do tipo double: %f", dubo);

  return 0;
}
