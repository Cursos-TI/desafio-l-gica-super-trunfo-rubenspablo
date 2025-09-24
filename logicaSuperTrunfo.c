// super_trunfo_um_duelo.c
// Um único confronto: sorteio decide quem escolhe o atributo (se CPU, escolhe aleatório).
// Usa if/else, switch e operador ternário.
// Compilar: gcc super_trunfo_um_duelo.c -o super_trunfo
// Executar : ./super_trunfo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned)time(NULL));

    // ----- CARTA 1 (Jogador) -----
    char estado1[40], cidade1[50];
    char letra1;
    int  codigo1;
    int  pop1;
    float area1;
    float pib1;   // em bilhões
    int  pts1;

    float dens1, pcap1;
    double sp1;

    // ----- CARTA 2 (CPU aleatória) -----
    const char* estados[] = {"RN","CE","PE","BA","SP","RJ","MG","PR"};
    const char* cidades[] = {"Mossoro","Fortaleza","Natal","Recife","Salvador","SaoPaulo","Rio","Curitiba"};
    int nE = 8, nC = 8;

    const char* estado2;
    const char* cidade2;
    char letra2;
    int  codigo2;
    int  pop2;
    float area2;
    float pib2;   // em bilhões
    int  pts2;

    float dens2, pcap2;
    double sp2;

    int opc = 0;
    printf("#### SUPER TRUNFO — UM DUELO ####\n");
    printf("1 - Jogar\n2 - Instrucoes\n3 - Sair\nOpcao: ");
    scanf("%d", &opc);

    if (opc == 2) {
        printf("\nINSTRUCOES:\n");
        printf("- Voce preenche a Carta 1.\n");
        printf("- A Carta 2 e do computador, com valores aleatorios.\n");
        printf("- Um sorteio decide quem escolhe o atributo da disputa (se CPU ganhar, escolhe aleatorio).\n");
        printf("- Compara uma vez e mostra o vencedor.\n");
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

    dens1  = (float)pop1 / area1;
    pcap1  = (pop1 > 0) ? (pib1 * 1000000000.0f) / (float)pop1 : 0.0f; // bilhoes -> R$
    sp1    = (double)pop1 + area1 + pib1 + pts1 + (1.0 / dens1) + pcap1;

    // ===== Geração da CPU =====
    estado2 = estados[rand() % nE];
    cidade2 = cidades[rand() % nC];
    letra2  = 'A' + (rand() % 8);
    codigo2 = 1 + (rand() % 4);

    pop2  = 10000 + (rand() % 20000000);   // 10 mil .. 20 mi
    area2 = 10.0f + (rand() % 120001);     // ~10 .. 120 mil km2
    pib2  = 1.0f + (rand() % 500);         // 1 .. 500 bi
    pts2  = rand() % 51;                   // 0..50

    dens2 = (float)pop2 / area2;
    pcap2 = (pop2 > 0) ? (pib2 * 1000000000.0f) / (float)pop2 : 0.0f;
    sp2   = (double)pop2 + area2 + pib2 + pts2 + (1.0 / dens2) + pcap2;

    // ===== Mostra cartas =====
    printf("\n===== CARTAS =====\n");
    printf("Carta 1 (Jogador)\n");
    printf(" Estado: %s | Cidade: %s | Codigo: %c%02d\n", estado1, cidade1, letra1, codigo1);
    printf(" Populacao: %d | Area: %.2f | PIB: %.2f bi | Pontos: %d\n", pop1, area1, pib1, pts1);
    printf(" Densidade: %.2f | PIB per capita: R$ %.2f | SuperPoder: %.2f\n", dens1, pcap1, sp1);

    printf("\nCarta 2 (CPU)\n");
    printf(" Estado: %s | Cidade: %s | Codigo: %c%02d\n", estado2, cidade2, letra2, codigo2);
    printf(" Populacao: %d | Area: %.2f | PIB: %.2f bi | Pontos: %d\n", pop2, area2, pib2, pts2);
    printf(" Densidade: %.2f | PIB per capita: R$ %.2f | SuperPoder: %.2f\n\n", dens2, pcap2, sp2);

    // ===== Sorteio de quem escolhe o atributo =====
    int atributo = 0;
    int sorteio = rand() % 2; // 0 = Jogador escolhe, 1 = CPU escolhe
    if (sorteio == 0) {
        printf("Voce ganhou o sorteio! Escolha o atributo:\n");
        printf("1-Populacao | 2-Area | 3-PIB | 4-Pontos | 5-Densidade | 6-PIB per capita | 7-Super Poder\n");
        printf("Atributo: ");
        scanf("%d", &atributo);
    } else {
        atributo = 1 + (rand() % 7);
        printf("CPU ganhou o sorteio e escolheu o atributo: %d\n", atributo);
    }

    // ===== Um único confronto =====
    int vencedor = 0; // 1 = jogador, 2 = cpu, 0 = empate

    switch (atributo) {
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
        case 4: // Pontos turisticos (MAIOR vence)
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
            printf("Atributo invalido. Nao houve confronto.\n");
            return 0;
    }

    // ===== Resultado final =====
    (vencedor == 1) ? printf("VENCEDOR FINAL: JOGADOR!\n")
    : (vencedor == 2) ? printf("VENCEDOR FINAL: CPU!\n")
                      : printf("RESULTADO FINAL: EMPATE!\n");

    return 0;
}
