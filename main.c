#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#define MAX 100

void lerMenuSelecao (int *menuSelecao, int *atv);
void lerString (char string [MAX]);
void validacao (char string [MAX], int *atv);
void converter (char string [MAX], int vet [MAX]);
void converterBinarioEmDecimal (char string [MAX], int vet [MAX]);
void lerNumber (int *number, int *atv);
void converterDecimalEmBinario (int vet [MAX], int vet2 [MAX], int number, int *tam);
void imprimirConversaoDb (int tam, int vet1 [MAX], int number);
void encerrar ();

int main ()
{
    setlocale (LC_ALL, "Portuguese");
    char string [MAX];
    int vet [MAX], vet2 [MAX];
    int atv = 0;
    char sair = 's';
    int number;
    int menuSelecao;
    int tam;

    while (sair != 'x')
    {
        lerMenuSelecao (&menuSelecao, &atv);
        switch (menuSelecao)
        {
            case 1:
                fflush (stdin);
                lerString (string);
                validacao (string, &atv);
                while (atv == 1)
                {
                    fflush (stdin);
                    lerString (string);
                    validacao (string, &atv);
                }
                converter (string, vet);
                converterBinarioEmDecimal (string, vet);
                printf ("\nDigite x para sair ou c para continuar\n");
                scanf ("%c", &sair);
            break;
            case 2:
                fflush (stdin);
                lerNumber (&number, &atv);
                while (atv == 1)
                {
                    fflush (stdin);
                    lerNumber (&number, &atv);
                }
                converterDecimalEmBinario (vet, vet2, number, &tam);
                imprimirConversaoDb (tam, vet2, number);
                printf ("\nDigite x para sair ou c para continuar\n");
                fflush (stdin);
                scanf ("%c", &sair);
            break;
            default:
                printf ("\nSelecione um menu válido!\n");
        }
    }
}

void lerMenuSelecao (int *menuSelecao, int *atv)
{
    printf ("Selecione as opções a seguir:\n1. Converter binário em decimal.\n2. Converter decimal em binário.\n");
    scanf ("%d", menuSelecao);
}

void lerString (char string [MAX])
{
    printf ("\nDigite um número binário!\n");
    fgets (string, MAX, stdin);

    if (strlen (string) < MAX)
    {
        string [strlen (string) -1] = '\0';
    }
}

void validacao (char string [MAX], int *atv) // arrummar
{
    int x;
    for (x = 0; x < strlen (string); x ++)
    {
        if ((string [x] - '0' < 0) || (string [x] - '0' > 1))
        {
            printf ("\nInsira um número binário válido!\n");
            *atv = 1;
            break;
        }
        else
        {
            *atv = 0;
        }
    }
}

void converter (char string [MAX], int vet [MAX])
{
    int y;
    for (y = 0; y < strlen (string); y ++)
    {
        vet [y] = string [y] - '0';
    }
}

void converterBinarioEmDecimal (char string [MAX], int vet [MAX])
{
    int z, j;
    int soma = 0;
    j = strlen (string) -1;
    for (z = 0; z < strlen (string); z ++)
    {
        vet [j] = vet [j] * pow (2, z);
        j --;
    }

    for (z = 0; z < strlen (string); z ++)
    {
        soma = soma + vet [z];
    }

    printf ("\nO número binário %s em decimal é dado por: %d\n", string, soma);
}

void lerNumber (int *number, int *atv)
{
    printf ("\nInsira um número decimal:\t");
    scanf ("%d", number);
    if (*number < 0)
    {
        printf ("\nO número não pode ser negativo!\n");
        *atv = 1;
    }
    else
    {
        *atv = 0;
    }
}

void converterDecimalEmBinario (int vet [MAX], int vet2 [MAX], int number, int *tam)
{
    int quociente = number;
	int resto;
    int x = 0, y;
    while (quociente != 0)
    {
        resto = quociente % 2;
        quociente = quociente / 2;
        vet [x] = resto;
        x++;
    }
    *tam = x;
    for (y = 0; y < *tam; y ++)
    {
        vet2 [y] = vet [*tam-1-y];
        x --;
    }
}

void imprimirConversaoDb (int tam, int vet2 [MAX], int number)
{
    int j;
    printf ("\nO número %d em base binária, é: ", number);
    for (j = 0; j < tam; j ++)
    {
        printf ("%d", vet2 [j]);
    }
    printf ("\n\n");
}

void encerrar ()
{
    char sair = 'a';
    do
    {
        printf ("\nDigite x para sair!\n");
        fflush (stdin);
        scanf ("%c", &sair);
    }while (sair != 'x');
}
