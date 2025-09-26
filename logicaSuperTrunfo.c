#include <stdio.h>
#include <string.h>


// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.


// Estrutura das cartas
struct Carta {
    char estado;
    char codigo[4];
    char nome_cidade[50];
    unsigned long int populacao;
    int pontos_turisticos;
    float densidade_p;
    float inverso_densidade; 
    float area;
    float pib;
    float pibpc; 
    float super_poder; 
};

int main() {
    struct Carta carta1, carta2;
    int escolha1, escolha2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    float soma_c1, soma_c2;
    const char *nome_atributo1, *nome_atributo2;

    printf("\n");

    // Cadastro da Primeira Carta
    printf("--- Cadastro da Primeira Carta ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    printf("Codigo da carta(01 - 04): ");
    scanf(" %s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %49[^\n]", carta1.nome_cidade);
    printf("Populacao da cidade: ");
    scanf(" %lu", &carta1.populacao);
    printf("Area da cidade(Km2): ");
    scanf(" %f", &carta1.area);
    printf("PIB da cidade: ");
    scanf(" %f", &carta1.pib);
    printf("Numero de pontos turisticos: ");
    scanf(" %d", &carta1.pontos_turisticos);

    // Calculos para a Carta 1
    carta1.densidade_p = (carta1.area > 0) ? (float)carta1.populacao / carta1.area : 0;
    carta1.pibpc = (carta1.populacao > 0) ? carta1.pib / (float)carta1.populacao : 0;
    carta1.inverso_densidade = (carta1.densidade_p > 0) ? 1.0f / carta1.densidade_p : 0;
    carta1.super_poder = (float)carta1.populacao + carta1.area + carta1.pib + (float)carta1.pontos_turisticos + carta1.pibpc + carta1.inverso_densidade;

    // Imprimindo os valores definidos da carta1
    printf("Carta 1\n Estado: %c\n Código: %c%s\n Nome da cidade: %s\n População: %lu\n Densidade Populacional: %.2f\n Área: %.2fKm2\n PIB: %.2fBilhões de reais\n PIB per Capita: %.2f\nPontos turísticos: %d", carta1.estado, carta1.estado, carta1.codigo, carta1.nome_cidade, carta1.populacao, carta1.densidade_p, carta1.area, carta1.pib, carta1.pibpc, carta1.pontos_turisticos);

    // Cadastro da Segunda Carta
    printf("\n--- Cadastro da Segunda Carta ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    printf("Codigo da carta(01 - 04): ");
    scanf(" %s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %49[^\n]", carta2.nome_cidade);
    printf("Populacao da cidade: ");
    scanf(" %lu", &carta2.populacao);
    printf("Area da cidade(Km2): ");
    scanf(" %f", &carta2.area);
    printf("PIB da cidade: ");
    scanf(" %f", &carta2.pib);
    printf("Numero de pontos turisticos: ");
    scanf(" %d", &carta2.pontos_turisticos);

    // Calculos para a Carta 2
    carta2.densidade_p = (carta2.area > 0) ? (float)carta2.populacao / carta2.area : 0;
    carta2.pibpc = (carta2.populacao > 0) ? carta2.pib / (float)carta2.populacao : 0;
    carta2.inverso_densidade = (carta2.densidade_p > 0) ? 1.0f / carta2.densidade_p : 0;
    carta2.super_poder = (float)carta2.populacao + carta2.area + carta2.pib + (float)carta2.pontos_turisticos + carta2.pibpc + carta2.inverso_densidade;

    // Imprimindo os valores definidos da carta2
    printf("Carta 2\n Estado: %c\n Código: %c%s\n Nome da cidade: %s\n População: %lu\n Densidade Populacional: %.2f\n Área: %.2fKm2\n PIB: %.2fBilhões de reais\n PIB per Capita: %.2f\n Pontos turísticos: %d\n", carta2.estado, carta2.estado, carta2.codigo, carta2.nome_cidade, carta2.populacao, carta2.densidade_p, carta2.area, carta2.pib, carta2.pibpc, carta2.pontos_turisticos);
    printf("\n");
    // Exibindo o resultado da batalha
    printf("\n--- Batalha Super Trunfo ---\n");
    
    // Escolha do Primeiro Atributo
    do {
        printf("\nEscolha o PRIMEIRO atributo para a batalha:\n");
        printf("(1). Populacao\n(2). Area\n(3). PIB\n(4). Pontos Turisticos\n(5). Densidade Demografica\n(6). PIB per Capita\n(7). Super Poder\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha1);
        if (escolha1 < 1 || escolha1 > 7) {
            printf("Opcao invalida! Por favor, escolha um numero de 1 a 7.\n");
        }
    } while (escolha1 < 1 || escolha1 > 7);

    // Atribuicao de valores para o primeiro atributo usando switch
    switch (escolha1) {
        case 1: nome_atributo1 = "Populacao"; valor1_c1 = (float)carta1.populacao; valor1_c2 = (float)carta2.populacao; break;
        case 2: nome_atributo1 = "Area"; valor1_c1 = carta1.area; valor1_c2 = carta2.area; break;
        case 3: nome_atributo1 = "PIB"; valor1_c1 = carta1.pib; valor1_c2 = carta2.pib; break;
        case 4: nome_atributo1 = "Pontos Turisticos"; valor1_c1 = (float)carta1.pontos_turisticos; valor1_c2 = (float)carta2.pontos_turisticos; break;
        case 5: nome_atributo1 = "Densidade Demografica"; valor1_c1 = carta1.densidade_p; valor1_c2 = carta2.densidade_p; break;
        case 6: nome_atributo1 = "PIB per Capita"; valor1_c1 = carta1.pibpc; valor1_c2 = carta2.pibpc; break;
        case 7: nome_atributo1 = "Super Poder"; valor1_c1 = carta1.super_poder; valor1_c2 = carta2.super_poder; break;
    }

    // Escolha do Segundo Atributo (menu dinâmico)
    do {
        printf("\nEscolha o SEGUNDO atributo para a batalha:\n");
        // Menu dinamico para nao mostrar a opcao ja escolhida
        if (escolha1 != 1) { printf("(1). Populacao\n"); }
        if (escolha1 != 2) { printf("(2). Area\n"); }
        if (escolha1 != 3) { printf("(3). PIB\n"); }
        if (escolha1 != 4) { printf("(4). Pontos Turisticos\n"); }
        if (escolha1 != 5) { printf("(5). Densidade Demografica\n"); }
        if (escolha1 != 6) { printf("(6). PIB per Capita\n"); }
        if (escolha1 != 7) { printf("(7). Super Poder\n"); }
        
        printf("Sua escolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 < 1 || escolha2 > 7 || escolha1 == escolha2) {
            printf("Opcao invalida! Escolha um atributo diferente do primeiro.\n");
        }
    } while (escolha2 < 1 || escolha2 > 7 || escolha1 == escolha2);
    
    // Atribuicao de valores para o segundo atributo usando switch
    switch (escolha2) {
        case 1: nome_atributo2 = "Populacao"; valor2_c1 = (float)carta1.populacao; valor2_c2 = (float)carta2.populacao; break;
        case 2: nome_atributo2 = "Area"; valor2_c1 = carta1.area; valor2_c2 = carta2.area; break;
        case 3: nome_atributo2 = "PIB"; valor2_c1 = carta1.pib; valor2_c2 = carta2.pib; break;
        case 4: nome_atributo2 = "Pontos Turisticos"; valor2_c1 = (float)carta1.pontos_turisticos; valor2_c2 = (float)carta2.pontos_turisticos; break;
        case 5: nome_atributo2 = "Densidade Demografica"; valor2_c1 = carta1.densidade_p; valor2_c2 = carta2.densidade_p; break;
        case 6: nome_atributo2 = "PIB per Capita"; valor2_c1 = carta1.pibpc; valor2_c2 = carta2.pibpc; break;
        case 7: nome_atributo2 = "Super Poder"; valor2_c1 = carta1.super_poder; valor2_c2 = carta2.super_poder; break;
    }
    
    // Exibir os valores individuais
    printf("\n--- Detalhes da Batalha ---\n");
    printf("Atributo 1: %s\n", nome_atributo1);
    printf("  %s: %.2f\n", carta1.nome_cidade, valor1_c1);
    printf("  %s: %.2f\n", carta2.nome_cidade, valor1_c2);
    
    printf("\nAtributo 2: %s\n", nome_atributo2);
    printf("  %s: %.2f\n", carta1.nome_cidade, valor2_c1);
    printf("  %s: %.2f\n", carta2.nome_cidade, valor2_c2);
    
    // Comparar individualmente e exibir qual venceu
    printf("\n--- Resultados Individuais ---\n");
    
    // Logica para o primeiro atributo
    if (escolha1 == 5) { // Densidade Demografica (menor vence)
        printf("%s: %s venceu!\n", nome_atributo1, (valor1_c1 < valor1_c2) ? carta1.nome_cidade : carta2.nome_cidade);
    } else { // Maior vence
        printf("%s: %s venceu!\n", nome_atributo1, (valor1_c1 > valor1_c2) ? carta1.nome_cidade : carta2.nome_cidade);
    }

    // Logica para o segundo atributo
    if (escolha2 == 5) { // Densidade Demografica (menor vence)
        printf("%s: %s venceu!\n", nome_atributo2, (valor2_c1 < valor2_c2) ? carta1.nome_cidade : carta2.nome_cidade);
    } else { // Maior vence
        printf("%s: %s venceu!\n", nome_atributo2, (valor2_c1 > valor2_c2) ? carta1.nome_cidade : carta2.nome_cidade);
    }

    // Comparar as somas e decidir o vencedor da rodada
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;
    
    printf("\n--- Vencedor da Rodada ---\n");
    printf("Soma %s: %.2f\n", carta1.nome_cidade, soma_c1);
    printf("Soma %s: %.2f\n", carta2.nome_cidade, soma_c2);
    
    if (soma_c1 > soma_c2) {
        printf("\nParabéns! %s venceu a rodada com a maior soma!\n", carta1.nome_cidade);
    } else if (soma_c2 > soma_c1) {
        printf("\nQue pena! %s venceu a rodada com a maior soma!\n", carta2.nome_cidade);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}