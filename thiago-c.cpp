#include <stdio.h>
#include <locale.h>

float obterQuantidadeJogadores() {
	
	setlocale(LC_ALL, "Portuguese");
    float quantidadeJogadores;

    do {
        printf("Digite a quantidade de jogadores (entre 1 e 4): ");
        scanf("%f", &quantidadeJogadores);

        if (quantidadeJogadores < 1 || quantidadeJogadores > 4) {
            printf("Por favor, escolha um número entre 1 e 4.\n");
        }

    } while (quantidadeJogadores < 1 || quantidadeJogadores > 4);

    return quantidadeJogadores;
}

void receberPalpites(float quantidadeJogadores) {
    float palpite;

    printf("\nCada jogador, por favor, dê o seu palpite:\n");

    for (float i = 1; i <= quantidadeJogadores; ++i) {
        printf("Jogador %.0f, digite o seu palpite: ", i);
        scanf("%f", &palpite);


        printf("Palpite do Jogador %.0f: %.2f\n", i, palpite);
    }
}

int main() {
    float qtdJogadores = obterQuantidadeJogadores();

    receberPalpites(qtdJogadores);



    return 0;
}

