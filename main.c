#include <stdio.h>
#include <string.h> 
//criar hora que 
struct hora {
    int horas,
    minutos;
};

//struct para a data que a compra foi feita
struct data {
    int day, 
    month, 
    year;
    
    struct hora hora_compra;
};

//struct para os produtos que serão vendidos
struct produto {
    int id;
    char nome[15];
    float valor;
    int popularidade;
};

//struct para as compras dos produtos
struct compra {
    struct produto produto;
    struct data data;
};

//função criadora de produtos
void criar_produto(int id, char nome[], float valor){
    
    struct produto c;
    
    c.id = id;
    c.valor = valor;
    strcpy(c.nome, nome);
    
    printf("Novo produto\n %d\t %s\t %f", c.id, c.nome, c.valor);
    
}

//função principal
int main() {
    int lista_produtos[5];
    
    struct compra compra_feita;
    
    criar_produto(1, "sopa", 3.5);
    
    

    return 0;
}
