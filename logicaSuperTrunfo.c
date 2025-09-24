// super_trunfo_duelo_apresentacao.c
// Um duelo: jogador escolhe 1 atributo, CPU escolhe outro aleatório,
// sorteio decide qual atributo vale, e então comparamos.
// Usa apenas if/else, switch e operador ternário.
// Compilar: gcc super_trunfo_duelo_apresentacao.c -o super_trunfo
// Executar : ./super_trunfo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned)time(NULL));

    // ===== Variáveis Carta 01 (Jogador) =====
    char estado1[40], cidade1[50];
    char letra1;
    char codigo1[10];      // string como no seu código original ("01".."04")
    int  populacao1;
    float area1;
    float pib1;            // em bilhões de R$
    int  pontos1;
    float densidade1;
    float pibPercapta1;    // R$ por habitante
    double SuperPoder1;

    // ===== Variáveis Carta 02 (CPU) =====
    const char* estados[] = {"AL","CE","PE","BA","SP","RJ","MG","PR"};
    const char* cidades[] = {"Maceio","Fortaleza","Natal","Recife","Salvador","SaoPaulo","Rio","Curitiba"};
    int nE = 8, nC = 8;

    const char* estado2;
    const char* cidade2;
    char letra2;
    char codigo2_str[4];
    int  populacao2;
    float area2;
    float pib2;
    int  pontos2;
    float densidade2;
    float pibPercapta2;
    double SuperPoder2;

    // ===== Apresentação (mantida do seu código) =====
    printf("**** SUPER TRUNFO ****\n");
    printf("Olá jogador, seja bem vindo ao Super Trunfo! Um Mundo de disputas e guerras.\n");
    printf("Onde cada jogador enfrenta desafios jamais vistos, e batalhas épicas são vistas a todo o momento.\n");
    printf("Para esse desafio teremos que montar suas cartas desafiadoras.\n");
    printf("Você terá direito a duas cartas inicialmente.\n");
    printf("Então seja inteligente nas suas escolhas e boa sorte.\n\n");

    // ===== Carta 01 (Jogador) — perguntas exatamente como você mandou =====
    printf("Vamos começar com a primeira carta.\n\n");
    printf("Escolha seu estado.\n");
    scanf(" %[^\n]", estado1);

    printf("Escolha uma letra indicando o inicio do codigo da sua carta entre A - H\n");
    scanf(" %c", &letra1);
    printf("A Letra escolhida por você foi %c \n", letra1);

    printf("Agora vamos digitar um codigo para juntar com a letra que você ja escolheu\n");
    printf("Então vamos lá digite o codigo, os números seram de 01 à 04\n");
    scanf("%9s", codigo1);

    printf("Sua carta tem o codigo = %c%s\n", letra1, codigo1);

    printf("Agora vamos preencher os dados da sua carta\n");
    printf("Qual o nome da sua cidade?\n");
    scanf(" %[^\n]", cidade1);

    printf("Qual a sua população?\n");
    scanf("%d", &populacao1);

    printf("Qual a sua área em Km²?\n");
    scanf("%f", &area1);

    printf("Qual o seu PIB em Bilhões de Reais (so precisa escrever os numeros)?\n");
    scanf("%f", &pib1);

    printf("Quantos pontos turísticos tem sua cidade?\n");
    scanf("%d", &pontos1);
    printf("\n===Parabens você acaba de concluir sua primeira carta!===\n\n");

    // Derivados Carta 01
    if (area1 <= 0) area1 = 1.0f;                 // evita divisão por zero
    if (populacao1 < 1) populacao1 = 1;
    if (pontos1 < 0) pontos1 = 0;
    if (pib1 < 0) pib1 = 0.0f;

    densidade1   = (float)populacao1 / area1;
    pibPercapta1 = (float)(pib1 * 1000000000.0f) / (float)populacao1; // bilhões -> R$
    SuperPoder1  = populacao1 + area1 + pib1 + pontos1 + (1.0f / densidade1) + pibPercapta1;

    // ===== Carta 02 (CPU) — geração aleatória simples =====
    estado2   = estados[rand() % nE];
    cidade2   = cidades[rand() % nC];
    letra2    = 'A' + (rand() % 8);
    {
        int cod = 1 + (rand() % 4);
        codigo2_str[0] = '0' + (cod / 10);
        codigo2_str[1] = '0' + (cod % 10);
        codigo2_str[2] = '\0';
    }
    populacao2 = 10000 + (rand() % 20000000);  // 10 mil .. 20 mi
    area2      = 10.0f + (rand() % 120001);    // ~10 .. 120 mil km²
    pib2       = 1.0f + (rand() % 500);        // 1 .. 500 bi
    pontos2    = rand() % 51;                  // 0..50

    densidade2   = (float)populacao2 / area2;
    pibPercapta2 = (float)(pib2 * 1000000000.0f) / (float)populacao2;
    SuperPoder2  = populacao2 + area2 + pib2 + pontos2 + (1.0f / densidade2) + pibPercapta2;

    // ===== Exibir cartas, um dado por linha =====
    printf("===== CARTA 01 (JOGADOR) =====\n");
    printf("Estado: %s\n", estado1);
    printf("Cidade: %s\n", cidade1);
    printf("Codigo: %c%s\n", letra1, codigo1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bi R$\n", pib1);
    printf("Pontos turisticos: %d\n", pontos1);
    printf("Densidade: %.2f hab/km2\n", densidade1);
    printf("PIB per capita: R$ %.2f\n", pibPercapta1);
    printf("SuperPoder: %.2f\n\n", SuperPoder1);

    printf("===== CARTA 02 (CPU) =====\n");
    printf("Estado: %s\n", estado2);
    printf("Cidade: %s\n", cidade2);
    printf("Codigo: %c%s\n", letra2, codigo2_str);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bi R$\n", pib2);
    printf("Pontos turisticos: %d\n", pontos2);
    printf("Densidade: %.2f hab/km2\n", densidade2);
    printf("PIB per capita: R$ %.2f\n", pibPercapta2);
    printf("SuperPoder: %.2f\n\n", SuperPoder2);

    // ===== Escolhas de atributo =====
    int atributoJog = 0, atributoCPU = 0, atributoValendo = 0;

    printf("Escolha seu atributo para competir:\n");
    printf("1-Populacao\n2-Area\n3-PIB\n4-Pontos\n5-Densidade (MENOR vence)\n6-PIB per capita\n7-Super Poder\n");
    printf("Seu atributo: ");
    scanf("%d", &atributoJog);

    atributoCPU = 1 + (rand() % 7);
    printf("CPU escolheu aleatoriamente o atributo: %d\n", atributoCPU);

    // ===== Sorteio entre os dois atributos =====
    atributoValendo = (rand() % 2 == 0) ? atributoJog : atributoCPU;
    printf("\nAtributo sorteado para valer no duelo: %d\n\n", atributoValendo);

    // ===== Confronto único =====
    // vencedor: 1 = jogador, 2 = cpu, 0 = empate
    int vencedor = 0;

    switch (atributoValendo) {
        case 1: // População (MAIOR vence)
            (populacao1 > populacao2) ? (printf("Jogador venceu (Populacao)!\n"), vencedor=1)
                                      : (populacao2 > populacao1) ? (printf("CPU venceu (Populacao)!\n"), vencedor=2)
                                                                  : (printf("Empate em Populacao!\n"), vencedor=0);
            break;
        case 2: // Área (MAIOR vence)
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
            (pontos1 > pontos2) ? (printf("Jogador venceu (Pontos)!\n"), vencedor=1)
                                : (pontos2 > pontos1) ? (printf("CPU venceu (Pontos)!\n"), vencedor=2)
                                                      : (printf("Empate em Pontos!\n"), vencedor=0);
            break;
        case 5: // Densidade (MENOR vence)
            (densidade1 < densidade2) ? (printf("Jogador venceu (Densidade MENOR)!\n"), vencedor=1)
                                      : (densidade2 < densidade1) ? (printf("CPU venceu (Densidade MENOR)!\n"), vencedor=2)
                                                                  : (printf("Empate em Densidade!\n"), vencedor=0);
            break;
        case 6: // PIB per capita (MAIOR vence)
            (pibPercapta1 > pibPercapta2) ? (printf("Jogador venceu (PIB per capita)!\n"), vencedor=1)
                                          : (pibPercapta2 > pibPercapta1) ? (printf("CPU venceu (PIB per capita)!\n"), vencedor=2)
                                                                          : (printf("Empate em PIB per capita!\n"), vencedor=0);
            break;
        case 7: // Super Poder (MAIOR vence)
            (SuperPoder1 > SuperPoder2) ? (printf("Jogador venceu (Super Poder)!\n"), vencedor=1)
                                        : (SuperPoder2 > SuperPoder1) ? (printf("CPU venceu (Super Poder)!\n"), vencedor=2)
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
