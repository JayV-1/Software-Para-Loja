
#include <stdio.h>

//struct para os produtos que serão vendidos
struct produto(){
    int id;
    char nome[15];
    float preço;
    int popularidade;
}

struct compra(){
    struct produto;
}

int main()
{
    int lista_produtos[5];

    return 0;
}
