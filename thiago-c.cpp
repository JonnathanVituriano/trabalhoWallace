#include <stdio.h>
#include <locale.h>

int obterQuantidadeJogadores() {
    setlocale(LC_ALL, "Portuguese");
    int quantidadeJogadores;

    do {
        printf("Digite a quantidade de jogadores (entre 1 e 4): ");
        scanf("%d", &quantidadeJogadores);

        if (quantidadeJogadores < 1 || quantidadeJogadores > 4) {
            printf("Por favor, escolha um número entre 1 e 4.\n");
        }

    } while (quantidadeJogadores < 1 || quantidadeJogadores > 4);

    return quantidadeJogadores;
}

void receberPalpites(int quantidadeJogadores) {
    int palpite;

    printf("\nCada jogador, por favor, dê o seu palpite:\n");

    for (int i = 1; i <= quantidadeJogadores; ++i) {
        printf("Jogador %d, digite o seu palpite: ", i);
        scanf("%d", &palpite);

        printf("Palpite do Jogador %d: %d\n", i, palpite);
    }
}

int main() {
    int qtdJogadores = obterQuantidadeJogadores();

    receberPalpites(qtdJogadores);

    return 0;
}
