#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

typedef struct comprador{
    char nome[40];
    int dia;
    char dado;
};

typedef struct produto{
    int cod;
    char nomeprod[40];
    float preco;
    int quant;
    int punit;
    int nvendas;
};

void nova_venda(FILE *arq){
	struct comprador cliente;
		printf("\nQual seu nome?");
        scanf("%s", cliente.nome);
        
        gets(cliente.nome);
        
        cliente.dado = fputs(cliente.nome, arq);
        if (cliente.dado == EOF){
        	printf("erro na abertura");
		} else {
			printf("dados cadastrados");
		}
		
        
}
int main(){
	FILE *arq;
    setlocale(LC_ALL, "Portuguese");
    struct comprador cliente;
    
    int op;
    printf("Olá, qual operação você deseja fazer?\n [1]-Venda\n [2]-Relatótio diario\n [3]-Relatório mensal");
    scanf("%d", &op);
    
    switch (op){
        case 1:
            arq = fopen("teste.txt", "a");
            if (arq == NULL) {
        		printf("ERRO! na abertura");
			}
            nova_venda(arq);
            fclose(arq);
            
            arq = fopen("teste.txt", "r");
            
            fclose(arq);
            
		    
	    break;
	    
	    case 2:
		    printf("2");
	    break;

	    case 3:
		    printf("3");
	    break;
    }        

    return 0;
}
