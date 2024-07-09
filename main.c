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
        if (atv == 1)
        {
            encerrar ();
            break;
        }
        else
        {
            if (menuSelecao == 1)
            {
                fflush (stdin);
                lerString (string);
                validacao (string, &atv);
                if (atv == 1)
                {
                    encerrar ();
                    break;
                }
                converter (string, vet);
                converterBinarioEmDecimal (string, vet);
                printf ("\nDigite x para sair ou c para continuar\n");
                scanf ("%c", &sair);
            }
            else if (menuSelecao == 2)
            {
                fflush (stdin);
                lerNumber (&number, &atv);
                if (atv == 1)
                {
                    encerrar ();
                    break;
                }
                converterDecimalEmBinario (vet, vet2, number, &tam);
                imprimirConversaoDb (tam, vet2, number);
            }
        }
    }
}

void lerMenuSelecao (int *menuSelecao, int *atv)
{
    printf ("Selecione as op��es a seguir:\n1. Converter bin�rio em decimal.\n2. Converter decimal em bin�rio\n");
    scanf ("%d", menuSelecao);

    if (!(*menuSelecao >= 1 && *menuSelecao <= 2))
    {
        printf ("\nSelecione um menu v�lido!\n");
        *atv = 1;
    }
}

void lerString (char string [MAX])
{
    printf ("Insira o n�mero bin�rio!\n");
    fgets (string, MAX, stdin);

    if (strlen (string) < MAX)
    {
        string [strlen (string) -1] = '\0';
    }
}

void validacao (char string [MAX], int *atv)
{
    int x;
    for (x = 0; x < strlen (string); x ++)
    {
        if (string [x] >= '0' && string [x] <= '9')
        {
            if ((string [x] - '0' < 0) || (string [x] - '0' > 1))
            {
                printf ("Nenhum d�gito bin�rio pode ser negativo ou maior que 1!\n");
                *atv = 1;
                break;

            }
        }
        else
        {
            printf ("Os d�gitos bin�rios s� podem ser n�meros e positivos!");
            *atv = 1;
            break;
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

    printf ("\nO n�mero bin�rio %s em decimal � dado por: %d\n", string, soma);
}

void lerNumber (int *number, int *atv)
{
    printf ("Insira o n�mero:\t");
    scanf ("%d", number);
    if (*number < 0)
    {
        printf ("O n�mero n�o pode ser negativo!\n");
        *atv = 1;
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
    printf ("O n�mero %d em base bin�ria, �: ", number);
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
