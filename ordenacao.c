#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5

//Função Quick Short para ordernar.
void Ordenacao(int a[], int esq, int dir) {
    int i = esq;
    int j = dir;
    int temp = a[(esq + dir) / 2]; // Escolhendo o elemento do meio como pivô
    int aux;

    while (i <= j) 
	{
        while (a[i] > temp) 
		{
            i++;
        }
        while (a[j] < temp) 
		{
            j--;
        }
        if (i <= j)
		{
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            i++;
            j--;
        }
    }

    if (esq < j) 
	{
        Ordenacao(a, esq, j);
    }
    if (i < dir) 
	{
        Ordenacao(a, i, dir);
    }
}

int main(void) 
{
   // FILE *arq;
	int vetor[MAX];
    int i; 

    system("CLS");
    setlocale(LC_ALL, "Portuguese");
    
   /* arq = fopen("teste.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    } */

    printf("\n Inserindo valores no Array\n");
    for (i = 0; i < MAX; i++) 
	{
        printf("\n Posição %d | Digite um número: \n", i);
        scanf("%d", &vetor[i]);
    }

    printf("\n\n");
    system("PAUSE");
    system("CLS");

    Ordenacao(vetor, 0, MAX - 1);

    printf("\nValores Ordenados:\n");
    for (i = 0; i < MAX; i++) 
	{
        printf("\nPosição: %d | Número: %d \n", i, vetor[i]);
    }
    printf("\n\n");

    system("PAUSE");
    return 0;
}
