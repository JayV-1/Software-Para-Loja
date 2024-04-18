#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <locale.h>
//#include <time.h> 

// Struct para a data da compra
struct data {
    int min;
    int hora;
    int dia;
    int mes; 
    int ano;
    
};

// Struct para os produtos que serão vendidos
struct produto {
    int id;
    char nome[100];
    float valor;
    int quantidade;
    int popularidade;
};

struct compras {
    struct data data;
    struct produto produtos[90];
    float valor;
};

struct dados_diarios {
    struct data data;
    struct compras compras;
    float faturamento;
    char melhor_produto[100];
    char pior_produto[100];
};

struct dados_mensais {
    struct data data;
    struct dados_diarios diario[1];
};

struct dados_anuais {
    struct dados_mensais mensal[12];
};



/*numero aleatorio
float num_random(int lower, int upper, int n) { 
    n = (rand() % (upper - lower + 1)) + lower;
    return n;
};*/

// Função criadora de produtos
struct produto criar_produto(int id, char nome[], float valor){
    
    struct produto c;
    
    c.id = id;
    c.valor = valor;
    strcpy(c.nome, nome);
    
    return c;
}

//imprimir lista de produtos
void listar_produtos(struct produto produtos_tds[], int produtos_qtd){
    
    char *produtos_nome[] = {"Men's denim shorts",
    "Cotton cargo shorts",
    "Polyester sports shorts",
    "Men's twill shorts",
    "Linen women's shorts",
    "Linen women's blazer",
    "Corduroy blazer",
    "Slim fit tailored blazer",
    "Casual cotton blazer",
    "Men's corduroy blazer",
    "Printed cropped blouse",
    "Long sleeve blouse",
    "Off-shoulder blouse",
    "High-neck knit blouse",
    "Cropped knit blouse",
    "Slim fit social shirt",
    "Women's denim shirt",
    "Silk women's shirt",
    "Men's linen casual shirt",
    "Men's polo shirt",
    "Basic t-shirt",
    "Printed t-shirt",
    "Men's tank top",
    "Tie-dye unisex t-shirt",
    "Cotton unisex t-shirt",
    "Skinny jeans",
    "Sweatpants",
    "Men's cargo pants",
    "Women's tailored pants",
    "Women's flare pants",
    "Silk women's chemise",
    "Women's wool coat",
    "Sports windbreaker jacket",
    "Unisex windbreaker jacket",
    "Unisex bomber jacket",
    "Synthetic leather jacket",
    "Fitness leggings with print",
    "Hooded sweatshirt",
    "Front print sweatshirt",
    "Pantacourt jumpsuit",
    "Denim jumpsuit",
    "Basic men's tank top",
    "Midi pleated skirt",
    "Black pencil skirt",
    "Denim shorts",
    "Floral dress",
    "Long party dress",
    "Floral summer dress",
    "Short party dress",
    "Black sheath dress"}; //lista de produtos
    float produtos_valor[] = {79.90, 59.90, 49.90, 69.90, 89.90, 159.90, 179.90, 199.90, 129.90, 179.90,
        39.90, 49.90, 59.90, 79.90, 69.90, 119.90, 79.90, 129.90, 99.90, 79.90,
        29.90, 39.90, 29.90, 49.90, 29.90, 99.90, 69.90, 89.90, 149.90, 89.90,
        79.90, 129.90, 109.90, 89.90, 119.90, 199.90, 49.90, 69.90, 79.90, 169.90,
        119.90, 19.90, 89.90, 59.90, 59.90, 149.90, 249.90, 89.90, 129.90, 99.90}; // lista de preços

    //definir a quantidade de produtos que vamos criar
    //int produtos_qtd = sizeof(produtos_nome) / sizeof(produtos_nome[0]);
    
    //struct produto produtos_tds[produtos_qtd]; // Array para armazenar os produtos
    
    // Preenche o array de produtos
    for (int i = 0; i < produtos_qtd; i++) {
        produtos_tds[i] = criar_produto(i+1, produtos_nome[i], produtos_valor[i]);
    }
    
    // Imprime os produtos
    printf("\n\t\t\tLista de produtos:\n\n");
    printf("==============================================================\n");
    printf("|| id | nome | Valor (R$) ||\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < produtos_qtd; i++) {
        printf("|| %d | %-40s | R$ %.2f ||\n", produtos_tds[i].id, produtos_tds[i].nome, produtos_tds[i].valor);
    }
    printf("==============================================================\n");
}

//Função que lida com as compras
void handler_compra(struct produto produtos_tds[], int produtos_qtd, struct compras compra, int dia){
    int id_pedido;
    int quantidade;
    int quantidade_total;
    int valor_total;
    int flag;
    int num = 0;
    int data_info[5] = {2024, 12, 30, 23, 59};
    int data_random[4];
    
    //struct compras compra;
    
    //listar os produtos
    printf("\n\n");
    listar_produtos(produtos_tds, produtos_qtd);
    printf("\n\n");
    
    
    for(int i = 0; i < 30; i++){
        printf("\t\tQual produto voce quer levar?\t(digite o id do produto que gostaria de levar)\n~> ");
        scanf("%d", &id_pedido);
        
        printf("\t\tQuantos voce quer levar?\n~> ");
        scanf("%d", &quantidade);
        
        compra.produtos[i] = produtos_tds[id_pedido -1];
        compra.produtos[i].quantidade = quantidade;
        compra.produtos[i].popularidade += quantidade;
        
        printf("\n\n\t~~~~~~Carrinho~~~~~~~\n");
        
        for(int j = 0; j <= i; j++){
            
            printf("|| %d | %-40s | R$ %.2f unidade | %d un.| R$%.2f ||\n", 
            compra.produtos[j].id, compra.produtos[j].nome, 
            compra.produtos[j].valor, 
            compra.produtos[j].quantidade, 
            compra.produtos[j].valor * compra.produtos[j].quantidade);
            
            quantidade_total += compra.produtos[i].quantidade;
            compra.valor += compra.produtos[i].valor * compra.produtos[i].quantidade;
        }
        
        
        printf("\n\tQuer comprar mais?\ty(1) | n(0)\n~>");
        scanf("%d", &flag);
        produtos_qtd = i+1;
        if (flag == 0){
            
            break;
        }
        
    }
    
    if (quantidade_total >= 3){
        compra.valor = compra.valor * 9/10;
    }
    
    printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~Checkout~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|| nome | Valor (R$) | Quantidade | Valor parcial|\n");
    for(int j = 0; j < produtos_qtd; j++){
        
        printf("|| %-40s | R$ %.2f unidade | %d un.| R$%.2f ||\n", 
        compra.produtos[j].nome, 
        compra.produtos[j].valor, 
        compra.produtos[j].quantidade, 
        compra.produtos[j].valor * compra.produtos[j].quantidade);
    }
    
    printf("Total: R$%.2f\t", compra.valor);
    
    for (int i = 0; i < 4; i++){
            data_random[i] = (rand() % (data_info[i+1] - 0 + 1)) + 0;
    }
    
    compra.data.ano = 2024;
    compra.data.mes = data_random[0];
    compra.data.dia = data_random[1];
    compra.data.hora = data_random[2];
    compra.data.min = data_random[3];
    
    printf("Data: %d/%d/%d %d:%d\n\n", 
        compra.data.dia,
        compra.data.mes,
        compra.data.ano,
        compra.data.hora,
        compra.data.min);
        
        //return compra;
}

//Função que lida com input do usuario
void handler_usuario(int lista[]){
    
    printf("aa");
    
    int op;
    int produtos_qtd = 50;
    struct produto produtos_tds[produtos_qtd];
    struct compras compra;
    struct dados_diarios nove;
    struct dados_mensais Abril;
    
    printf(
    "\nOi, o que deseja fazer?\n\n"
    "\t[1]-Realizar compra\n"
    "\t[2]-Relatótio diario\n"
    "\t[3]-Relatório mensal\n"
    "\t[4]-Sair\n"
    "~> ");
    scanf("%d", &op);
    
    switch (op){
        case 1:
            
            for(int i = 0; i < 49; i++){
                int resp;
                    
    		    //fazer a compra
    		    handler_compra(produtos_tds, produtos_qtd, compra, i);
    		    printf("Obrigado pela compra, gostaria de comprar mais?\n~> ");
    		    scanf("%d", &resp);
    		    //printf("%f", compra.valor);
    		    
    		    if(resp == 0){
    		            break;
    		    }
            }
            
		    //voltar para o menu
		    handler_usuario(lista);
		    break;
	    
	    case 2:
	        printf("\n\n");
		    printf("Work in Progress...");
		    printf("\n\n");
		    
		    //voltar para o menu
	        handler_usuario(lista);
	        break;

	    case 3:
	        printf("\n\n");
            printf("Work in Progress...");
            printf("\n\n");
            handler_usuario(lista);
            break;
        
        case 4:
            break;
    }
    
}

//Função para controlar dados de compras
void controle_compras(){
    
}



//Função principal
int main() {
    int lista_diaria[1];
    
    setlocale(LC_ALL, "Portuguese");
    printf("aa");
    
    handler_usuario(lista_diaria);

    return 0;
}