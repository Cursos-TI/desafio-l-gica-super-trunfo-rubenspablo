// super_trunfo_duelo_sorteio.c
// Um duelo: jogador escolhe 1 atributo, CPU escolhe outro aleatório,
// sorteio decide qual atributo vale, e então comparamos.
// Compilar: gcc super_trunfo_duelo_sorteio.c -o super_trunfo
// Executar : ./super_trunfo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned)time(NULL));

    // ---- Carta 1 (Jogador) ----
    char estado1[40], cidade1[50];
    char letra1;
    int  codigo1;
    int  pop1;
    float area1;
    float pib1;   // bilhões
    int  pts1;

    float dens1, pcap1;
    double sp1;

    // ---- Carta 2 (CPU) ----
    const char* estados[] = {"AL","CE","PE","BA","SP","RJ","MG","PR"};
    const char* cidades[] = {"Maceio","Fortaleza","Natal","Recife","Salvador","SaoPaulo","Rio","Curitiba"};
    int nE = 8, nC = 8;

    const char* estado2;
    const char* cidade2;
    char letra2;
    int  codigo2;
    int  pop2;
    float area2;
    float pib2;   // bilhões
    int  pts2;

    float dens2, pcap2;
    double sp2;

    int opc = 0;
    printf("#### SUPER TRUNFO — DUELO COM SORTEIO DE ATRIBUTO ####\n");
    printf("1 - Jogar\n2 - Instrucoes\n3 - Sair\nOpcao: ");
    scanf("%d", &opc);

    if (opc == 2) {
        printf("\nINSTRUCOES:\n");
        printf("- Voce preenche a Carta 1.\n");
        printf("- A Carta 2 (CPU) e gerada aleatoriamente.\n");
        printf("- Voce escolhe um atributo; a CPU escolhe outro aleatorio.\n");
        printf("- Um sorteio entre os dois atributos decide qual vale.\n");
        printf("- Compara e mostra o vencedor.\n");
        return 0;
    } else if (opc == 3) {
        printf("Saindo...\n");
        return 0;
    } else if (opc != 1) {
        printf("Opcao invalida.\n");
        return 0;
    }

    // ===== Entrada do jogador =====
    printf("\n--- Carta 1 (Jogador) ---\n");
    printf("Estado: ");
    scanf(" %39[^\n]", estado1);
    printf("Cidade: ");
    scanf(" %49[^\n]", cidade1);

    printf("Letra do codigo [A..H]: ");
    scanf(" %c", &letra1);

    printf("Numero do codigo [1..4]: ");
    scanf("%d", &codigo1);
    if (codigo1 < 1) codigo1 = 1;
    if (codigo1 > 4) codigo1 = 4;

    printf("Populacao (hab): ");
    scanf("%d", &pop1);
    if (pop1 < 1) pop1 = 1;

    printf("Area (km2): ");
    scanf("%f", &area1);
    if (area1 <= 0) area1 = 1.0f;

    printf("PIB (em bilhoes de R$): ");
    scanf("%f", &pib1);
    if (pib1 < 0) pib1 = 0.0f;

    printf("Pontos turisticos: ");
    scanf("%d", &pts1);
    if (pts1 < 0) pts1 = 0;

    // Derivados
    dens1  = (float)pop1 / area1;
    pcap1  = (pop1 > 0) ? (pib1 * 1000000000.0f) / (float)pop1 : 0.0f; // bilhões -> R$
    sp1    = (double)pop1 + area1 + pib1 + pts1 + (1.0 / dens1) + pcap1;

    // ===== CPU aleatória =====
    estado2 = estados[rand() % nE];
    cidade2 = cidades[rand() % nC];
    letra2  = 'A' + (rand() % 8);
    codigo2 = 1 + (rand() % 4);

    pop2  = 10000 + (rand() % 20000000);
    area2 = 10.0f + (rand() % 120001);
    pib2  = 1.0f + (rand() % 500);
    pts2  = rand() % 51;

    dens2 = (float)pop2 / area2;
    pcap2 = (pop2 > 0) ? (pib2 * 1000000000.0f) / (float)pop2 : 0.0f;
    sp2   = (double)pop2 + area2 + pib2 + pts2 + (1.0 / dens2) + pcap2;

    // ===== Mostrar cartas (cada dado em uma linha) =====
    printf("\n===== CARTA 1 (JOGADOR) =====\n");
    printf("Estado: %s\n", estado1);
    printf("Cidade: %s\n", cidade1);
    printf("Codigo: %c%02d\n", letra1, codigo1);
    printf("Populacao: %d\n", pop1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bi R$\n", pib1);
    printf("Pontos turisticos: %d\n", pts1);
    printf("Densidade: %.2f hab/km2\n", dens1);
    printf("PIB per capita: R$ %.2f\n", pcap1);
    printf("SuperPoder: %.2f\n", sp1);

    printf("\n===== CARTA 2 (CPU) =====\n");
    printf("Estado: %s\n", estado2);
    printf("Cidade: %s\n", cidade2);
    printf("Codigo: %c%02d\n", letra2, codigo2);
    printf("Populacao: %d\n", pop2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bi R$\n", pib2);
    printf("Pontos turisticos: %d\n", pts2);
    printf("Densidade: %.2f hab/km2\n", dens2);
    printf("PIB per capita: R$ %.2f\n", pcap2);
    printf("SuperPoder: %.2f\n\n", sp2);

    // ===== Escolhas de atributo =====
    int atrJog = 0, atrCPU = 0, atrEscolhido = 0;
    printf("Escolha seu atributo:\n");
    printf("1-Populacao\n2-Area\n3-PIB\n4-Pontos\n5-Densidade (MENOR vence)\n6-PIB per capita\n7-Super Poder\n");
    printf("Seu atributo: ");
    scanf("%d", &atrJog);

    atrCPU = 1 + (rand() % 7);
    printf("CPU escolheu aleatoriamente o atributo: %d\n", atrCPU);

    // ===== Sorteio entre os dois atributos =====
    atrEscolhido = (rand() % 2 == 0) ? atrJog : atrCPU;
    printf("\nAtributo sorteado para valer no duelo: %d\n", atrEscolhido);

    // ===== Duelo único =====
    // vencedor: 1 = jogador, 2 = cpu, 0 = empate
    int vencedor = 0;

    switch (atrEscolhido) {
        case 1: // Populacao (MAIOR vence)
            (pop1 > pop2) ? (printf("Jogador venceu (Populacao)!\n"), vencedor=1)
                          : (pop2 > pop1) ? (printf("CPU venceu (Populacao)!\n"), vencedor=2)
                                          : (printf("Empate em Populacao!\n"), vencedor=0);
            break;
        case 2: // Area (MAIOR vence)
            (area1 > area2) ? (printf("Jogador venceu (Area)!\n"), vencedor=1)
                            : (area2 > area1) ? (printf("CPU venceu (Area)!\n"), vencedor=2)
                                              : (printf("Empate em Area!\n"), vencedor=0);
            break;
        case 3: // PIB (MAIOR vence)
            (pib1 > pib2) ? (printf("Jogador venceu (PIB)!\n"), vencedor=1)
                          : (pib2 > pib1) ? (printf("CPU venceu (PIB)!\n"), vencedor=2)
                                          : (printf("Empate em PIB!\n"), vencedor=0);
            break;
        case 4: // Pontos (MAIOR vence)
            (pts1 > pts2) ? (printf("Jogador venceu (Pontos)!\n"), vencedor=1)
                          : (pts2 > pts1) ? (printf("CPU venceu (Pontos)!\n"), vencedor=2)
                                          : (printf("Empate em Pontos!\n"), vencedor=0);
            break;
        case 5: // Densidade (MENOR vence)
            (dens1 < dens2) ? (printf("Jogador venceu (Densidade MENOR)!\n"), vencedor=1)
                            : (dens2 < dens1) ? (printf("CPU venceu (Densidade MENOR)!\n"), vencedor=2)
                                              : (printf("Empate em Densidade!\n"), vencedor=0);
            break;
        case 6: // PIB per capita (MAIOR vence)
            (pcap1 > pcap2) ? (printf("Jogador venceu (PIB per capita)!\n"), vencedor=1)
                            : (pcap2 > pcap1) ? (printf("CPU venceu (PIB per capita)!\n"), vencedor=2)
                                              : (printf("Empate em PIB per capita!\n"), vencedor=0);
            break;
        case 7: // Super Poder (MAIOR vence)
            (sp1 > sp2) ? (printf("Jogador venceu (Super Poder)!\n"), vencedor=1)
                        : (sp2 > sp1) ? (printf("CPU venceu (Super Poder)!\n"), vencedor=2)
                                      : (printf("Empate em Super Poder!\n"), vencedor=0);
            break;
        default:
            printf("Atributo invalido. Duelo cancelado.\n");
            return 0;
    }

    // ===== Resultado final =====
    (vencedor == 1) ? printf("VENCEDOR FINAL: JOGADOR!\n")
    : (vencedor == 2) ? printf("VENCEDOR FINAL: CPU!\n")
                      : printf("RESULTADO FINAL: EMPATE!\n");

    return 0;
}
