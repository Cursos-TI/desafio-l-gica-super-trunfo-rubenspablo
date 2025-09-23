#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    // jogo do Super Trunfo Novato
    // as variaveis foram declaradas juntas das duas cartas
    int opcao;
    char estado1[40], estado2[40];
    char codigo1[10], codigo2[10];
    char cidade1[50], cidade2[50];
    char letra1, letra2;
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;
    float densidade1, densidade2;
    float pibPercapta1, pibPercapta2;
    double SuperPoder1, SuperPoder2; // Variáveis para o Super Poder
    

    printf("#### Seja bem vindo ao Super Trunfo ####\n");
    printf("Aqui esta o menu de opções:\n");
    printf("1 - Jogar\n");
    printf("2 - Instruções\n");
    printf("3 - Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
         // Apresentação do jogo
    printf("\n**** SUPER TRUNFO ****\n");
    printf("Olá jogador, seja bem vindo ao Super Trunfo! Um Mundo de disputas e guerras.\n");
    printf("Onde cada jogador enfrenta desafios jamais vistos, e batalhas épicas são vistas a todo o momento.\n");
    printf("Para esse desafio teremos que montar suas cartas desafiadoras.\n");
    printf("Você terá direito a duas cartas inicialmente.\n");
    printf("Então seja inteligente nas suas escolhas e boa sorte.\n\n");


    //carta 01
    //escolha do Estado
    printf("Vamos começar com a primeira carta.\n\n");
    printf("Escolha seu estado.\n");
    scanf(" %[^\n]", estado1);

    //escolha da letra
    printf("Escolha uma letra indicando o inicio do codigo da sua carta entre A - H\n");
    scanf(" %c", &letra1);
    printf("A Letra escolhida por você foi %c \n", letra1);

    //escolha do código numerico
    printf("Agora vamos digitar um codigo para juntar com a letra que você ja escolheu\n");
    printf("Então vamos lá digite o codigo, os números seram de 01 à 04\n");
    scanf("%s", codigo1);

    // resultado do código
    printf("Sua carta tem o codigo = %c%s\n", letra1, codigo1);

    //escolha da cidade
    printf("Agora vamos preencher os dados da sua carta\n");
    printf("Qual o nome da sua cidade?\n");
    scanf(" %[^\n]", cidade1);

    //população da cidade
    printf("Qual a sua população?\n");
    scanf("%d", &populacao1);

    //área demográfica da cidade
    printf("Qual a sua área em Km²?\n");
    scanf("%f", &area1);

    //O PIB da cidade
    printf("Qual o seu PIB em Bilhões de Reais (so precisa escrever os numeros)?\n");
    scanf("%f", &pib1);

    //pontos turísticos da cidade
    printf("Quantos pontos turísticos tem sua cidade?\n");
    scanf("%d", &pontos1);
    printf("\n===Parabens você acaba de concluir sua primeira carta!===\n\n");

    // Calculo da Densidade Demográfica
    densidade1 = (float) populacao1 / area1;

    //Calculo do pib percapta
    pibPercapta1 = (float) pib1 / populacao1;

    // Calculo do Super Poder
    SuperPoder1 = populacao1 + area1 + pib1 + pontos1 + (1 / densidade1) + pibPercapta1;


    // Carta 02
    printf("Vamos começar com a segunda carta.\n");
    printf("Lembre-se seja inteligente nas escolhas\n\n");

    // escolha do estado 2
    printf("Escolha seu estado.\n");
    scanf(" %[^\n]", estado2);

    //escolha da letra
    printf("Escolha uma letra indicando o inicio do codigo da sua carta entre A - H\n");
    scanf(" %c", &letra2);
    printf("A Letra escolhida por você foi %c\n", letra2);

    //escolha do código numerico 2
    printf("Agora vamos digitar um codigo para juntar com a letra que você ja escolheu\n");
    printf("Então vamos lá digite o codigo, os números seram de 01 à 04\n");
    scanf("%s", codigo2);

    // resultado do código 2
    printf("Sua carta tem o codigo = %c%s\n", letra2, codigo2);

    //preenchimento cidade 2
    printf("Agora vamos preencher os dados da sua carta\n");
    printf("Qual o nome da sua cidade?\n");
    scanf(" %[^\n]", cidade2);

    //população da cidade 2
    printf("Qual a sua população?\n");
    scanf("%d", &populacao2);

    //área demográfica da cidade 2
    printf("Qual a sua área em Km²?\n");
    scanf("%f", &area2);

    //O PIB da cidade 2
    printf("Qual o seu PIB em Bilhões de Reais (so precisa escrever os numeros)?\n");
    scanf("%f", &pib2);

    //pontos turísticos da cidade 2
    printf("Quantos pontos turísticos tem sua cidade?\n");
    scanf("%d", &pontos2);
    printf("\n===Parabens você acaba de concluir sua segunda carta!===\n\n");

    // Calculo da Densidade Demográfica 2
    densidade2 = (float) populacao2 / area2;
    //calculo do pib percapta 2
    pibPercapta2 = (float) pib2 / populacao2; 

    // Calculo do Super Poder 2 (agora usando variáveis já calculadas)
    SuperPoder2 = populacao2 + area2 + pib2 + pontos2 + (1 / densidade2) + pibPercapta2;

    printf("Agora vamos ver o resultado de suas cartas\n\n");


    // resultado final

    printf("Carta 01\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %c%s\n", letra1, codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %d de habitantes.\n", populacao1);
    printf("Área: %.2f Km².\n", area1);
    printf("PIB: %.2f bilhões de Reais.\n", pib1);
    printf("Pontos turísticos: %d\n", pontos1);
    printf("Densidade Demográfica: %.2f habitantes por Km².\n", densidade1);
    printf("PIB Per Capta: %.2f bilhões de Reais por habitante.\n\n", pibPercapta1);
    printf("Super Poder: %.2f\n\n", SuperPoder1);

    printf("Carta 02\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %c%s\n", letra2, codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %d de habitantes.\n", populacao2);
    printf("Área: %.2f Km²\n", area2);
    printf("PIB: %.2f bilhões de Reais\n", pib2);
    printf("Pontos turísticos: %d\n", pontos2);
    printf("Densidade Demográfica: %.2f habitantes por Km²\n", densidade2);
    printf("PIB Per Capta: %.2f bilhões de Reais por habitante\n\n", pibPercapta2);
    printf("Super Poder: %.2f\n\n", SuperPoder2);

    // escolha do atributo da carta para comparação
    printf("Escolha o atributo que você quer comparar entre as cartas:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("6 - PIB Per Capta\n");
    printf("7 - Super Poder\n");
    printf("Digite o número do atributo desejado para competição entre as cartas: ");
    int atributo;
    scanf("%d", &atributo);
    switch (atributo) {
    case 1:
         printf("Você escolheu comparar a População.\n");
         if (populacao1 > populacao2) {
            printf("A carta 1 tem a maior população: %d habitantes.\n", populacao1);
        } else if (populacao1 < populacao2) {
            printf("A carta 2 tem a maior população: %d habitantes.\n", populacao2);
        } else {
            printf("As duas cartas têm a mesma população: %d habitantes.\n", populacao1);  
        }
        break;
    case 2:
        printf("Você escolheu comparar a Área.\n");
        if (area1 > area2) {
            printf("A carta 1 tem a maior área: %.2f Km².\n", area1);
        } else if (area1 < area2) {
            printf("A carta 2 tem a maior área: %.2f Km².\n", area2);
        } else {
            printf("As duas cartas têm a mesma área: %.2f Km².\n", area1);  
        }
        break;
    case 3:
        printf("Você escolheu comparar o PIB.\n");
        if (pib1 > pib2) {
            printf("A carta 1 tem o maior PIB: %.2f bilhões de Reais.\n", pib1);
        } else if (pib1 < pib2) {
            printf("A carta 2 tem o maior PIB: %.2f bilhões de Reais.\n", pib2);
        } else {
            printf("As duas cartas têm o mesmo PIB: %.2f bilhões de Reais.\n", pib1);  
        }
        break;
    case 4:
        printf("Você escolheu comparar os Pontos Turísticos.\n");
        if (pontos1 > pontos2) {
            printf("A carta 1 tem mais pontos turísticos: %d pontos.\n", pontos1);
        } else if (pontos1 < pontos2) {
            printf("A carta 2 tem mais pontos turísticos: %d pontos.\n", pontos2);
        } else {
            printf("As duas cartas têm o mesmo número de pontos turísticos: %d pontos.\n", pontos1);  
        }
        break;
    case 5:
        printf("Você escolheu comparar a Densidade Demográfica.\n");
        if (densidade1 > densidade2) {
            printf("A carta 2 vence com a menor densidade: %.2f habitantes por Km².\n", densidade2);
        } else if (densidade1 < densidade2) {
            printf("A carta 1 vence com a menor densidade: %.2f habitantes por Km².\n", densidade1);
        } else {
            printf("As duas cartas têm a mesma densidade demográfica: %.2f habitantes por Km².\n", densidade1);  
        }
        break;
    case 6:
        printf("Você escolheu comparar o PIB Per Capta.\n");
        if (pibPercapta1 > pibPercapta2) {
            printf("A carta 1 tem o maior PIB Per Capta: %.2f bilhões de Reais por habitante.\n", pibPercapta1);
        } else if (pibPercapta1 < pibPercapta2) {
            printf("A carta 2 tem o maior PIB Per Capta: %.2f bilhões de Reais por habitante.\n", pibPercapta2);
        } else {
            printf("As duas cartas têm o mesmo PIB Per Capta: %.2f bilhões de Reais por habitante.\n", pibPercapta1);  
        }
        break;
    case 7:
        printf("Você escolheu comparar o Super Poder.\n");
        if (SuperPoder1 > SuperPoder2) {
            printf("A carta 1 é a vencedora com o maior Super Poder: %.2f\n", SuperPoder1);
        } else if (SuperPoder1 < SuperPoder2) {
            printf("A carta 2 é a vencedora com o maior Super Poder: %.2f\n", SuperPoder2);
        } else {
            printf("As duas cartas têm o mesmo Super Poder: %.2f\n", SuperPoder1);  
        }
        break;
    }
        break;  
    case 2:
        printf("Instruções do Jogo:\n");
        printf("1. Você terá direito a duas cartas, cada uma representando uma cidade com diversos atributos.\n");
        printf("2. Cada carta terá os seguintes atributos: Estado, Código, Cidade, População, Área, PIB, Pontos Turísticos, Densidade Demográfica, PIB Per Capta e Super Poder.\n");
        printf("3. Após criar suas cartas, você poderá escolher um atributo para comparar entre as duas cartas.\n");
        printf("4. O objetivo é ter a carta com o maior valor no atributo escolhido.\n");
        printf("5. Seja estratégico na escolha do atributo para maximizar suas chances de vitória!\n");
        printf("6. Divirta-se e boa sorte!\n");
        break;
    case 3:
        printf("Saindo do jogo. Até a próxima!\n");
        break;
    default:
        printf("Opção inválida. Por favor, escolha uma opção válida.\n");
        break;

}

    return 0;
}
