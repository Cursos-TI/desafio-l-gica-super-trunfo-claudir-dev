#include <stdio.h>

// variáveis globais da carta
char estado[50], cidade[50];
int populacao, turismo;
float area, pib, densidade, pib_per_capita;

// variaveis para a segunda carta
char estado2[50], cidade2[50];
int populacao2, turismo2;
float area2, pib2, densidade2, pib_per_capita2;

// variaveis para pontuação
int pontos_carta1 = 0;
int pontos_carta2 = 0;

void calculo () {
    densidade = (float) populacao / area;
    pib_per_capita = (float) pib / populacao;
    printf("A densidade populacional da sua cidade é de %.2f hab/km²\n", densidade);
    printf("O PIB per capita da sua cidade é de %.2f R$\n\n", pib_per_capita);
}   

void calculo2 () {
    densidade2 = (float) populacao2 / area2;
    pib_per_capita2 = (float) pib2 / populacao2;
    printf("A densidade populacional da sua cidade é de %.2f hab/km²\n", densidade2);
    printf("O PIB per capita da sua cidade é de %.2f R$\n\n", pib_per_capita2);
}


void ler_dados() {
    printf("Digite o estado: ");
    scanf("%s", estado);

    printf("Digite a cidade: ");
    scanf("%s", cidade);

    printf("Digite a populacao: ");
    scanf("%d", &populacao);

    printf("Digite a area: ");
    scanf("%f", &area);

    printf("Digite o pib: ");
    scanf("%f", &pib);

    printf("Quantos pontos turisticos a cidade possui?: ");
    scanf("%d", &turismo);

    printf("\n--- Carta criada com sucesso! ---\n\n");

    printf("Estado: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f R$\nTurismo: %d\n",
           estado, cidade, populacao, area, pib, turismo);

    calculo();
}

 

void ler_dados2() {
    printf("Digite o estado: ");
    scanf("%s", estado2);

    printf("Digite a cidade: ");
    scanf("%s", cidade2);

    printf("Digite a populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a area: ");
    scanf("%f", &area2);

    printf("Digite o pib: ");
    scanf("%f", &pib2);

    printf("Quantos pontos turisticos a cidade possui?: ");
    scanf("%d", &turismo2);

    printf("\n--- Carta criada com sucesso! ---\n\n");

    printf("Estado: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f R$\nTurismo: %d\n",
           estado2, cidade2, populacao2, area2, pib2, turismo2);
    calculo2();
}


void comparacao() {
    if(populacao > populacao2) {
        printf("Populacão: %s: %d carta 1 venceu\n", cidade, populacao);
        pontos_carta1++;
    } else if(populacao < populacao2) {
        printf("População: %s: %d carta 2 venceu\n", cidade2, populacao2);
        pontos_carta2++;
    } else {
        printf("População: Empate\n");
    }

    if(area > area2) {
        printf("Área: carta 1 venceu\n");
        pontos_carta1++;
    } else if(area < area2) {
        printf("Área: carta 2 venceu\n");
        pontos_carta2++;
    } else {
        printf("Área: Empate\n");
    }

    if(pib > pib2) {
        printf("PIB: carta 1 venceu\n");
        pontos_carta1++;
    } else if (pib < pib2) {
        printf("PIB: carta 2 venceu\n");
        pontos_carta2++;
    } else {
        printf("PIB: Empate\n");
    }

    if(turismo > turismo2) {
        printf("Turismo: carta 1 venceu\n");
        pontos_carta1++;
    } else if (turismo < turismo2) {
        printf("Turismo: carta 2 venceu\n");
        pontos_carta2++;
    } else {
        printf("Turismo: Empate\n");
    }

    if (densidade < densidade2){
        printf("Densidade: carta 1 venceu\n");
        pontos_carta1++;
    } else if(densidade > densidade2) {
        printf("Densidade: carta 2 venceu\n");
        pontos_carta2++;
    } else {
        printf("Densidade: Empate\n");
    }

    if (pib_per_capita > pib_per_capita2) {
        printf("PIB per capita: carta 1 venceu\n");
        pontos_carta1++;
    } else if (pib_per_capita < pib_per_capita2) {
        printf("PIB per capita: carta 2 venceu\n");
        pontos_carta2++;
    } else {
        printf("PIB per capita: Empate\n");
    }

    printf("\n--- Placar ---\n\n");

    printf("Carta 1: %d pontos\n", pontos_carta1);
    printf("Carta 2: %d pontos\n\n", pontos_carta2);

    printf("\n--- resutlado final ---\n\n");

    if(pontos_carta1 > pontos_carta2) {
        printf("Carta 1 venceu!\n");
    } else if (pontos_carta1 < pontos_carta2) {
        printf("Carta 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }
}

int main() {
    printf("--- Bem vindo ao Super Trunfo de Cidades ---\n\n");
    printf("Vamos criar a primeira carta:\n\n");
    ler_dados();
    printf("\nAgora, vamos criar a segunda carta:\n\n");
    ler_dados2();
    comparacao();
    return 0;
}