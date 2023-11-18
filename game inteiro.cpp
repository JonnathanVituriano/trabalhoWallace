#include <stdio.h>
#include <locale.h>
#include "Jonnathan.h"

int Menu();  // Declara��o da fun��o Menu()

void exibirCreditos() {
    printf("Os desenvolvedores desse jogo s�o: \n Luis Henrique Ancores Paiva; \n Jonathan Vituriano;\n Luis Henrique Ara�jo;\n Gabriel Negromonte;\n Thiago Fernandes\n.");
    printf("\nPressione Enter para voltar ao menu...\n");

    // Aguarda a tecla Enter ser pressionada
    while (getchar() != '\n');
    getchar(); // Pega o Enter do usu�rio
}

int obterQuantidadeJogadores() {
    setlocale(0, "Portuguese");
    int quantidadeJogadores;

    do {
        printf("Digite a quantidade de jogadores (entre 2 e 4): ");

        // Verifica se a entrada � um n�mero inteiro
        if (scanf("%d", &quantidadeJogadores) != 1) {
            printf("Entrada inv�lida. Por favor, insira um n�mero inteiro.\n");

            // Limpa o buffer de entrada
            while (getchar() != '\n');
            
            continue;  // Reinicia o loop para pedir a entrada novamente
        }

        if (quantidadeJogadores < 2 || quantidadeJogadores > 4) {
            printf("Por favor, escolha um n�mero entre 2 e 4.\n");
        }

    } while (quantidadeJogadores < 2 || quantidadeJogadores > 4);

    return quantidadeJogadores;
}

void receberPalpites(int quantidadeJogadores) {
    if (quantidadeJogadores > 1) {
        int palpite;

        printf("\nCada jogador, por favor, d� o seu palpite:\n");

        for (int i = 1; i <= quantidadeJogadores; ++i) {
            do {
                printf("Jogador %d, digite o seu palpite: ", i);

                // Verifica se a entrada � um n�mero inteiro
                if (scanf("%d", &palpite) != 1) {
                    printf("Entrada inv�lida. Por favor, insira um n�mero inteiro.\n");

                    // Limpa o buffer de entrada
                    while (getchar() != '\n');
                    
                    continue;  // Reinicia o loop para pedir a entrada novamente
                }

                break;  // Sai do loop quando a entrada � v�lida
            } while (1);

            printf("Palpite do Jogador %d: %d\n", i, palpite);
        }
    } else {
        printf("Desculpe, n�o � poss�vel iniciar o jogo com apenas um jogador.\n");
    }
}

int main() {
    int qtdJogadores;
    int option; // Inicialize a vari�vel option

    // Chama a fun��o Menu() primeiro
    option = Menu();

    // Chama as outras fun��es depois
    if (option == 1) {
        qtdJogadores = obterQuantidadeJogadores();
        receberPalpites(qtdJogadores);
    }

    return 0;
}

int Menu() {
    setlocale(0, "Portuguese");
    int option, optionExt;
            
    while (1) {
		printf("                                    _____  ___    ___      ____\n");
	    printf("|\\      |  |     | |\\           /| |      |   \\  /   \\   /\n");
	    printf("| \\     |  |     | | \\         / | |      |    ||     | |\n");
	    printf("|  \\    |  |     | |  \\       /  | |____  |___/ |     |  \\____\n");
	    printf("|   \\   |  |     | |   \\     /   | |      |\\    |     |       \\\n");
	    printf("|    \\  |  |     | |    \\   /    | |      | \\   |     |        |\n");
	    printf("|     \\ |   \\___/  |     \\ /     | |_____ |  \\   \\___/   _____/\n");
	    printf("  _____           _____   _____   _____    _________  ___     ____\n");
	    printf(" /       |     | /       |     \\ |       |     |     /   \\   /\n");
	    printf("|        |     ||        |      ||       |     |    |     | |\n");
	    printf(" \\____   |     | \\____   |_____/ |____   |     |    |     |  \\____\n");
	    printf("      \\  |     |      \\  |       |       |     |    |     |       \\\n");
	    printf("       | |     |       | |       |       |     |    |     |        |\n");
	    printf(" _____/   \\___/  _____/  |       |_____  |     |     \\___/   _____/\n");

        printf("\n\nEscolha uma op��o: \n 1. Jogar\n 2. Cr�ditos\n 3. Sair\n");
        scanf("%d", &option);

        if (option == 1) {
            printf("Voc� escolheu jogar.\n");
            // AQUI FICARIA O C�DIGO DO GAME 
            break;
        } else if (option == 2) {
            exibirCreditos();
            // N�o precisa de break aqui, pois queremos que o usu�rio pressione Enter antes de voltar ao menu
        } else if (option == 3) {
            printf("Voc� escolheu sair do jogo, tem certeza que quer sair?.\n 1. SIM\n 2.N�O\n");
            scanf("%d", &optionExt);
            if (optionExt == 1) {
            	printf ("Jogo Desligando...");
                break;
            } else if (optionExt == 2) {
                printf("�������������\n");
            } else {
                printf("Op��o inv�lida. Tente novamente.\n");
            }
        } else {
            printf("Op��o inv�lida. Tente novamente.\n");
        }
    }

    return option; // Retorne a op��o escolhida pelo usu�rio
}
