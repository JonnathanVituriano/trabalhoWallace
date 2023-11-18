#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para escolher um número aleatoriamente de uma lista
float escolherAleatorio(float lista[], int tamanho) {
    int indice = rand() % tamanho;
    return lista[indice];
}

float main() {
    // Inicialize a semente para a função rand() usando o tempo atual
    srand(time(NULL));

    // Lista de números
    float numeros[] = {47,5,49,25,78,77,72,94,75,99,78,38,90,82,55,6,44,92,4,7,89,60,32,97,48,94,76,13,36,54,87,
	22,20,30,36,33,28,87,68,70,85,27,33,25,20,37,93,57,41,70,14,63,5,45,41,23,20,8,13,25,67,69,93,34,96,85,16,7,4,4,29,
	76,82,22,12,60,84,30,99,15,77,14,94,27,24,53,64,5,48,96,83,52,45,38,46,72,28,93,27,2,59,1,32,20,42,8,94,64,15,11,25,
	29,4,78,26,99,55,56,11,17,85,57,55,42,62,27,6,29,100,44,79,46,3,53,88,97,59,95,87,88,34,84,99,81,51,62,87,31,70,13,
	61,15,62,97,22,5,22,65,5,8,88,3,46,74,71,100,43,91,80,95,34,93,83,67,70,81,37,74,36,39,12,18,55,46,75,14,78,20,48,
	77,30,94,47,93,12,6,54,15,95,70};

    // Tamanho da lista
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    // Escolha um número aleatório e imprima
    float numeroEscolhido = escolherAleatorio(numeros, tamanho);
}

