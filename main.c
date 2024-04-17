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
struct produto criar_produto(int id, char nome[], float valor){
    
    struct produto c;
    
    c.id = id;
    c.valor = valor;
    strcpy(c.nome, nome);
    
    //printf("Novo produto:\n %d\t %s\t %.2f\n", c.id, c.nome, c.valor);
    
    return c;
}

//função principal
int main() {
    char *produtos_nome[] = {"sopa", "gato"};
    float produtos_valor[] = {3.5, 45.5};
    int produtos_qtd = sizeof(produtos_nome) / sizeof(produtos_nome[0]);
    
    struct produto produtos_tds[produtos_qtd]; // Array para armazenar os produtos
    
    printf("Novo produto:\n");
    printf("---------------------\n");
    
    for (int i = 0; i < produtos_qtd; i++) {
        produtos_tds[i] = criar_produto(i, produtos_nome[i], produtos_valor[i]);
        printf("| %d   %s   R$ %.2f  |\n", produtos_tds[i].id, produtos_tds[i].nome, produtos_tds[i].valor);
    }
    
    printf("--------------------\n");

    return 0;
}
