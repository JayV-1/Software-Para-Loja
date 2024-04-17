#include <stdio.h>
#include <string.h>
#include <locale.h>

// Criar hora
struct hora {
    int horas,
    minutos;
};

// Struct para a data da compra
struct data {
    int day, 
    month, 
    year;
    
    struct hora hora_compra;
};

// Struct para os produtos que serão vendidos
struct produto {
    int id;
    char nome[100];
    float valor;
    int popularidade;
};

// Função criadora de produtos
struct produto criar_produto(int id, char nome[], float valor){
    
    struct produto c;
    
    c.id = id;
    c.valor = valor;
    strcpy(c.nome, nome);
    
    return c;
}

int main() {
    
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
    int produtos_qtd = sizeof(produtos_nome) / sizeof(produtos_nome[0]);
    
    setlocale(LC_ALL, "Portuguese");
    
    struct produto produtos_tds[produtos_qtd]; // Array para armazenar os produtos
    
    // Preenche o array de produtos
    for (int i = 0; i < produtos_qtd; i++) {
        produtos_tds[i] = criar_produto(i+1, produtos_nome[i], produtos_valor[i]);
    }
    
    // Imprime os produtos
    printf("Lista de produtos:\n");
    printf("--------------------\n");
    for (int i = 0; i < produtos_qtd; i++) {
        printf("|| %d | %-40s | R$ %.2f ||\n", produtos_tds[i].id, produtos_tds[i].nome, produtos_tds[i].valor);
    }
    printf("--------------------\n");

    return 0;
}
