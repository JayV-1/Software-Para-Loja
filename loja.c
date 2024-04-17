#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct{
    char nome[40];
    int dia;
    
}comprador;

typedef struct{
    int cod;
    char nomeprod[40];
    float preco;
    int quant;
    int punit;
    int nvendas;
}produto;

typedef struct{
    char nome[40];
    int dia;
    int cod;
    char nomeprod[40];
    float preco;
    int quant;
    int punit;
    int nvendas;
}venda;

int main(){
    setlocale(LC_ALL, "Portuguese");
    comprador cliente;
    
    int op;
    printf("Olá, qual operação você deseja fazer?\n [1]-Venda\n [2]-Relatótio diario\n [3]-Relatório mensal");
    scanf("%d", &op);
    
    switch (op){
        case 1:
            
            printf("Qual seu nome?");
            scanf("%c", &cliente.nome);
            
            
		    printf("O que você deseja comprar?");
		    
		    FILE *arq;
		    arq = fopen("loja_roupa.dat", "a+b");
		    
		    fwrite(&cliente.nome, sizeof(char), 40, arq);
		    
		    fclose (arq);
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
    

