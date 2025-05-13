#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados de uma carta (cidade)
struct Carta {
    char estado[50];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional; // Calculada como população/área
};

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *carta, int numero) {
    printf("\n===== CADASTRO DA CARTA %d =====\n", numero);
    
    printf("Digite o estado: ");
    scanf(" %[^\n]", carta->estado);
    
    printf("Digite o código da carta: ");
    scanf("%d", &carta->codigo);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome);
    
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB (em milhões R$): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    // Cálculo da densidade populacional
    if (carta->area > 0) {
        carta->densidade_populacional = carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }
}

// Função para exibir os dados de uma carta
void exibirCarta(struct Carta carta) {
    printf("\n===== DADOS DA CARTA =====\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %d\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_populacional);
}

// Função para comparar as cartas e determinar a vencedora
void compararCartas(struct Carta carta1, struct Carta carta2) {
    printf("\n===== COMPARAÇÃO DAS CARTAS =====\n");
    
    // Escolha do atributo para comparação (pode ser alterado conforme necessário)
    int atributo = 1; // 1: População, 2: Área, 3: PIB, 4: Pontos Turísticos, 5: Densidade Populacional
    
    printf("Atributo escolhido para comparação: ");
    
    if (atributo == 1) {
        printf("População\n");
        
        if (carta1.populacao > carta2.populacao) {
            printf("A carta %s venceu com %d habitantes!\n", carta1.nome, carta1.populacao);
        } else if (carta2.populacao > carta1.populacao) {
            printf("A carta %s venceu com %d habitantes!\n", carta2.nome, carta2.populacao);
        } else {
            printf("Empate! Ambas as cartas têm %d habitantes.\n", carta1.populacao);
        }
    } else if (atributo == 2) {
        printf("Área\n");
        
        if (carta1.area > carta2.area) {
            printf("A carta %s venceu com %.2f km²!\n", carta1.nome, carta1.area);
        } else if (carta2.area > carta1.area) {
            printf("A carta %s venceu com %.2f km²!\n", carta2.nome, carta2.area);
        } else {
            printf("Empate! Ambas as cartas têm %.2f km².\n", carta1.area);
        }
    } else if (atributo == 3) {
        printf("PIB\n");
        
        if (carta1.pib > carta2.pib) {
            printf("A carta %s venceu com R$ %.2f milhões!\n", carta1.nome, carta1.pib);
        } else if (carta2.pib > carta1.pib) {
            printf("A carta %s venceu com R$ %.2f milhões!\n", carta2.nome, carta2.pib);
        } else {
            printf("Empate! Ambas as cartas têm R$ %.2f milhões.\n", carta1.pib);
        }
    } else if (atributo == 4) {
        printf("Pontos Turísticos\n");
        
        if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
            printf("A carta %s venceu com %d pontos turísticos!\n", carta1.nome, carta1.pontos_turisticos);
        } else if (carta2.pontos_turisticos > carta1.pontos_turisticos) {
            printf("A carta %s venceu com %d pontos turísticos!\n", carta2.nome, carta2.pontos_turisticos);
        } else {
            printf("Empate! Ambas as cartas têm %d pontos turísticos.\n", carta1.pontos_turisticos);
        }
    } else if (atributo == 5) {
        printf("Densidade Populacional\n");
        
        // Para densidade populacional, o menor valor vence
        if (carta1.densidade_populacional < carta2.densidade_populacional) {
            printf("A carta %s venceu com %.2f hab/km²!\n", carta1.nome, carta1.densidade_populacional);
        } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
            printf("A carta %s venceu com %.2f hab/km²!\n", carta2.nome, carta2.densidade_populacional);
        } else {
            printf("Empate! Ambas as cartas têm %.2f hab/km².\n", carta1.densidade_populacional);
        }
    }
}

int main() {
    // Declaração das variáveis para as duas cartas
    struct Carta carta1, carta2;
    
    printf("===== SUPER TRUNFO - PAÍSES =====\n");
    printf("Bem-vindo ao jogo de comparação de cartas!\n");
    
    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibição dos dados das cartas
    printf("\n===== CARTAS CADASTRADAS =====\n");
    printf("\nCarta 1:");
    exibirCarta(carta1);
    
    printf("\nCarta 2:");
    exibirCarta(carta2);
    
    // Comparação das cartas
    compararCartas(carta1, carta2);
    
    return 0;
}