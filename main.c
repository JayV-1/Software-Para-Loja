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
    float preço;
    int popularidade;
};

//struct para as compras dos produtos
struct compra {
    struct produto produto_compra;
    struct data data_compra;
    
};

//
int main() {
    int lista_produtos[5];
    
    struct compra compras;

    return 0;
}
