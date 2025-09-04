#include <stdio.h>   // Biblioteca padrão de entrada/saída (printf, scanf, etc)
#include <string.h>  // Biblioteca para manipulação de strings (strcpy)

// Variáveis globais para carta 1
char pais[50];       // Nome do país da carta 1
int populacao, turismo;  
float pib, area, densidade;  

// Variáveis globais para carta 2
char pais2[50];      // Nome do país da carta 2
int populacao2, turismo2;
float area2, pib2, densidade2;

// Funções que apenas imprimem o menu de atributos disponíveis
void populacao_escolher() {printf("1 - População\n");}
void area_escolher() {printf("2 - Área\n");}
void pib_escolher() {printf("3 - PIB\n");}
void turismo_escolher() {printf("4 - Pontos turísticos\n");}
void densidade_escolher() {printf("5 - Densidade demográfica\n\n");}

// Função para preencher os dados da carta 1
void carta1 () {
    printf("\n--- Primeira carta ---\n");

    printf("Digite o nome do país: ");
    scanf("%s", pais);   // Lê o nome do país (sem espaço)

    printf("Digite a população: ");
    scanf("%d", &populacao);

    printf("Digite a área: ");
    scanf("%f", &area);

    printf("Digite o PIB: ");
    scanf("%f", &pib);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &turismo);

    densidade = (float)populacao / area; // Calcula a densidade (hab/km²)
}

// Função para o usuário escolher quais atributos serão comparados
int escolher(int *escolha_usario1, int *escolha_usario2) {
    // Array de ponteiros para funções (cada índice chama uma função que imprime opção)
    void (*opcoes[5]) () = {populacao_escolher, area_escolher, pib_escolher,turismo_escolher, densidade_escolher};

    printf("\n\n-- Escolha qual atributo da carta 1 para comparar com a carta 2 --\n\n");

    for (int i = 0; i < 5; i++) {  // Mostra todas as opções
        opcoes[i]();
    }

    printf("Digite o número da opção desejada: ");
    scanf("%d", escolha_usario1);

    // Remove a opção já escolhida, para não aparecer na segunda escolha
    opcoes[*escolha_usario1 - 1] = NULL;

    printf("\n\n-- Escolha qual atributo da carta 2 para comparar com a carta 1  --\n\n");

    for (int i = 0; i < 5; i++) {   // Mostra as opções restantes
        if(opcoes[i] != NULL) {
            opcoes[i]();
        }
    }

    printf("Digite o número da opção desejada: ");
    scanf("%d", escolha_usario2);

    if (*escolha_usario2 == *escolha_usario1) { // Evita repetir o mesmo atributo
        printf("\n Esta opção já foi escolhida\n");
    }
}

// Função para preencher os dados da carta 2
void carta2 () {
    printf("\n--- Segunda carta ---\n");

    printf("Digite o nome do país: ");
    scanf("%s", pais2);

    printf("Digite a população: ");
    scanf("%d", &populacao2);

    printf("Digite a área: ");
    scanf("%f", &area2);

    printf("Digite o PIB: ");
    scanf("%f", &pib2);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &turismo2);

    densidade2 = (float)populacao2 / area2; // Calcula densidade da carta 2
}

// Função para retornar o valor do atributo escolhido de cada carta
float pegarAtributo(int escolha, int carta) {
    if (carta == 1) { // Se for carta 1
        if (escolha == 1) return populacao;
        if (escolha == 2) return area;
        if (escolha == 3) return pib;
        if (escolha == 4) return turismo;
        if (escolha == 5) return densidade;
    } else {          // Se for carta 2
        if (escolha == 1) return populacao2;
        if (escolha == 2) return area2;
        if (escolha == 3) return pib2;
        if (escolha == 4) return turismo2;
        if (escolha == 5) return densidade2;
    }
    return 0; 
}

int main () {
    int opcao, opcao2;      // Guardam as opções escolhidas pelo usuário
    char atributo1[40];     // Nome do atributo da carta 1
    char atributo2[40];     // Nome do atributo da carta 2

    carta1();   // Preenche dados da carta 1
    carta2();   // Preenche dados da carta 2
    escolher(&opcao, &opcao2); // Usuário escolhe atributos para comparar

    // Transforma o número escolhido em texto (para exibir depois)
    if (opcao == 1) strcpy(atributo1, "População");
    else if (opcao == 2) strcpy(atributo1, "Área");
    else if (opcao == 3) strcpy(atributo1, "PIB");
    else if (opcao == 4) strcpy(atributo1, "Turismo");
    else strcpy(atributo1, "Densidade");

    if (opcao2 == 1) strcpy(atributo2, "População");
    else if (opcao2 == 2) strcpy(atributo2, "Área");
    else if (opcao2 == 3) strcpy(atributo2, "PIB");
    else if (opcao2 == 4) strcpy(atributo2, "Turismo");
    else strcpy(atributo2, "Densidade");
    
    // Pega os valores reais dos atributos escolhidos
    float valor1 = pegarAtributo(opcao, 1); // Carta 1
    float valor2 = pegarAtributo(opcao2, 2); // Carta 2

    // Exibe a comparação
    printf("\n--- Comparação ---\n");
    printf("Carta 1 (%s - %s): %.2f\n", pais, atributo1, valor1);
    printf("Carta 2 (%s - %s): %.2f\n", pais2, atributo2, valor2);

    // Decide o vencedor
    if (valor1 > valor2) {
        printf("➡ Carta 1 venceu!\n");
    } else if (valor1 < valor2) {
        printf("➡ Carta 2 venceu!\n");
    } else {
        printf("➡ Empate!\n");
    }

    return 0; // Fim do programa
}
