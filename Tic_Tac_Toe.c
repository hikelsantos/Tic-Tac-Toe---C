#include <stdio.h>
#include <stdlib.h>

int vitoria(char *c)
{
  int contador, aux = 0, result = 0;

  for (contador = 1; contador <= 3; contador++) //Verificar todas as linhas
  {
    if (c[aux] == c[aux + 1] && c[aux] == c[aux + 2])
    {
      if (c[aux] == 'X')
        result = 1;
      else
        result = 2;
    }
    aux += 3;
  }

  aux = 0;
  for (contador = 1; contador <= 3; contador++) //Verificar todas as colunas
  {
    if (c[aux] == c[aux + 3] && c[aux] == c[aux + 6])
    {
      if (c[aux] == 'X')
        result = 1;
      else
        result = 2;
    }
    aux += 1;
  }

  if (c[0] == c[4] && c[0] == c[8]) // Verificar '\'
  {
    if (c[0] == 'X')
      result = 1;
    else
      result = 2;
  }
  if (c[2] == c[4] && c[2] == c[6]) //Verificar '/'
  {
    if (c[2] == 'X')
      result = 1;
    else
      result = 2;
  }

  return result;
}

int busca(char escolha, char *c)
{
  int auxiliar;

  if (escolha == 'a' && c[0] != 'X' && c[0] != '0')
    auxiliar = 0;
  else if (escolha == 'b' && (c[1] != 'X' && c[1] != '0'))
    auxiliar = 1;
  else if (escolha == 'c' && (c[2] != 'X' && c[2] != '0'))
    auxiliar = 2;
  else if (escolha == 'd' && (c[3] != 'X' && c[3] != '0'))
    auxiliar = 3;
  else if (escolha == 'e' && (c[4] != 'X' && c[4] != '0'))
    auxiliar = 4;
  else if (escolha == 'f' && (c[5] != 'X' && c[5] != '0'))
    auxiliar = 5;
  else if (escolha == 'g' && (c[6] != 'X' && c[6] != '0'))
    auxiliar = 6;
  else if (escolha == 'h' && (c[7] != 'X' && c[7] != '0'))
    auxiliar = 7;
  else if (escolha == 'i' && (c[8] != 'X' && c[8] != '0'))
    auxiliar = 8;
  else
    auxiliar = 9;

  return auxiliar;
}
int main()
{

  char c[9];
  char escolha;
  int voltar, auxtermino = 0, termino = 0, ibusca = 0;

  do
  {
    c[0] = 'a';
    c[1] = 'b';
    c[2] = 'c';
    c[3] = 'd';
    c[4] = 'e';
    c[5] = 'f';
    c[6] = 'g';
    c[7] = 'h';
    c[8] = 'i';
    auxtermino = 0;
    termino = 0;
    ibusca = 0;

    for (int volta = 1; volta <= 10 && auxtermino == 0; volta++)
    {
      auxtermino = termino;
      printf("|-------------------------------|\n|\t\t\t\t|\n");
      printf("|\t     |     |      \t|\n");
      printf("|\t  %c  |  %c  |  %c  \t|\n", c[0], c[1], c[2]);
      printf("|\t_____|_____|_____\t|\n");
      printf("|\t     |     |      \t|\n");
      printf("|\t  %c  |  %c  |  %c  \t|\n", c[3], c[4], c[5]);
      printf("|\t_____|_____|_____\t|\n");
      printf("|\t     |     |      \t|\n");
      printf("|\t  %c  |  %c  |  %c  \t|\n", c[6], c[7], c[8]);
      printf("|\t     |     |      \t|\n");

      printf("|\t\t\t\t|\n|\t\t\t\t|\n|-------------------------------|\n|\t");
      if (auxtermino == 0 && volta < 10)
        printf("Choose a house: ");
      else if (auxtermino == 1)
        printf(" Player 'X' won ");
      else if (auxtermino == 2)
        printf(" Player '0' won ");
      else
        printf("      Draw      ");
      printf("\t|\n|-------------------------------|\n");
      if (auxtermino == 0 && volta < 10)
        printf("\t-----> ");

      do
      {
        scanf("%c", &escolha);
        ibusca = busca(escolha, c);

        for (int aux = 0; aux <= 9; aux++)
        {
          if (ibusca == aux)
          {
            if ((volta % 2) == 0)
            {
              c[aux] = 'X';
            }
            else if ((volta % 2) != 0)
            {
              c[aux] = '0';
            }
          }
        }
      } while (ibusca >= 9 && auxtermino == 0 && volta < 10);

      termino = vitoria(c);

      if (auxtermino == 0 && volta < 10)
        system("cls");
    }
    printf("\n\n0 - Quit\n1 - Return\n");
    scanf("%d", &voltar);
    system("cls");
  } while (voltar != 0);
  return 0;
}