#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"");
	int jogador1, jogador2;

    printf("Jogador 1, escolha 1 ou 2: ");
    scanf("%d", &jogador1);

    printf("Jogador 2, escolha 1 ou 2: ");
    scanf("%d", &jogador2);

    if ((jogador1 == 1 && jogador2 == 2) || (jogador1 == 2 && jogador2 == 1)) {
        if (jogador1 == 1) {
            printf("Guardião: Jogador 1 venceu, jogador 2 você vai ser isolado desses portões!\n");
        } else {
            printf("Guardião: Jogador 2 venceu, jogador 1 você vai ser isolado desses portões!\n");
        }
    } else {
        printf("Empate!\n");
    }

    return 0;
}
