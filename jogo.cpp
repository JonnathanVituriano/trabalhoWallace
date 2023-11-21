#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Declaração das funções
int Menu();
int obterQuantidadeJogadores();
int escolherNumeroAleatorio();
void exibirCreditos();
int Dicas();
int receberPalpites(int quantidadeJogadores);

// Variáveis globais
int tentativa, tentativasRestantes = 4; // Alterei para 5 tentativas
int quantidadeJogadores;
int numeroPensado;
int numeros[] = {47, 5, 49, 25, 78, 77, 76, 36, 54, 87, 22, 55, 28, 6, 44, 92, 4, 72, 94, 75, 99, 38, 90, 7, 89, 60, 32, 97, 48, 82};

// Função para escolher um número aleatório da lista
int escolherNumeroAleatorio() {
    // Inicializa a semente do gerador de números aleatórios
    srand((unsigned int)time(NULL));

    // Calcula o índice aleatório
    int indice = rand() % (sizeof(numeros) / sizeof(numeros[0]));

    // Retorna o número correspondente ao índice
    return numeros[indice];
}

// Função para exibir os créditos
void exibirCreditos() {
    printf("Os desenvolvedores desse jogo são: \n Luis Henrique Ancores Paiva; \n Jonathan Vituriano;\n Luis Henrique Araújo;\n Gabriel Negromonte;\n Thiago Fernandes\n.");
    printf("\nPressione Enter para voltar ao menu...\n");

    // Aguarda a tecla Enter ser pressionada
    while (getchar() != '\n');
    getchar(); // Pega o Enter do usuário
}

// Função para obter a quantidade de jogadores
int obterQuantidadeJogadores() {
    setlocale(0, "Portuguese");

    int quantidade;
        printf("Digite a quantidade de jogadores (entre 2 e 4): ");
        scanf ("%d", &quantidade);

    do {

        if (quantidade < 2 || quantidade > 4) {
            printf("Por favor, escolha um número entre 2 e 4.\n");
        }

    } while (quantidade < 2 || quantidade > 4);

    return quantidade;
}

int receberPalpites(int quantidadeJogadores) {
    int palpite;

        do {
    		for (int i = 1; i <= quantidadeJogadores; ++i) {
        	printf("\nJogador %d, é a sua vez.\n", i);
            printf("Digite o seu palpite: ");
            scanf("%d", &palpite);
            
            if (palpite == numeroPensado) {
                printf("Parabéns, Jogador %d! Seu palpite está correto.\n", i);
                return 0;
            } else {
                printf("Jogador %d, o seu palpite está incorreto. Tente novamente.\n", i);
                tentativasRestantes--;

                if (tentativasRestantes > 0) {
                    printf("Tentativas restantes: %d\n", tentativasRestantes);
                    Dicas();
                } else {
                    printf("Suas tentativas acabaram. O número correto era %d.\n", numeroPensado);
                    return 0;
                }
            }
    	}
    } while (1);
}

// Função principal do jogo
int main() {
    setlocale(0, "Portuguese");

    int option; // Inicializa a variável option

    // Chama a função Menu() primeiro
    option = Menu();

    // Chama as outras funções depois
    if (option == 1) {
        quantidadeJogadores = obterQuantidadeJogadores();
        numeroPensado = escolherNumeroAleatorio();
        receberPalpites(quantidadeJogadores);
    } else if (option == 2) {
        exibirCreditos();
        // Não precisa de mais nada aqui, pois exibirCreditos() já cuida de tudo
        return 0;
    } else if (option == 3) {
        printf("Você escolheu sair do jogo. Tem certeza que quer sair?.\n 1. SIM\n 2.NÃO\n");
        int optionExt;
        scanf("%d", &optionExt);
        if (optionExt == 1) {
            printf("Jogo Desligando...");
            exit(0);
        } else if (optionExt == 2) {
            printf("—————————————\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
        return 0;
    } else {
        printf("Opção inválida. Tente novamente.\n");
        return 0;
    }

    if (tentativasRestantes == 0) {
        printf("Suas tentativas acabaram. O número correto era %d.\n", numeroPensado);
    }

    return 0;
}

int Menu() {
    setlocale(0, "Portuguese");	
    int option, optionExt;

    while (1) {
        printf("  ___ ___ ___ ___ ___ ___   ___    ___   ___     ___ _   _  _   ___ ___ ___   _   ___\n");
        printf(" / __| __/ __| _ \\ __|   \\ / _ \\  |   \\ / _ \\   / __| | | |/_\\ | _ \\   \\_ _| /_\\ / _ \\\n");
        printf(" \\__ \\ _| (_ |   / _|| |) | (_) | | |) | (_) | | (_ | |_| / _ \\|   / |) | | / _ \\ (_) |\n");
        printf(" |___/___\\___|_|_\\___|___/ \\___/  |___/ \\___/   \\___|\\___/_/ \\_\\_|_\\___/___/_/ \\_\\___/ \n");

        printf("\n\nEscolha uma opção: \n 1. Jogar\n 2. Créditos\n 3. Sair\n");
        scanf("%d", &option);

        if (option == 1) {
            printf("Você escolheu jogar.\n");
            break;
        } else if (option == 2) {
            exibirCreditos();
            // Não precisa de break aqui, pois queremos que o usuário pressione Enter antes de voltar ao menu
        } else if (option == 3) {
            printf("Você escolheu sair do jogo, tem certeza que quer sair?.\n 1. SIM\n 2.NÃO\n");
            scanf("%d", &optionExt);
            if (optionExt == 1) {
                printf("Jogo Desligando...");
                exit(0);
            } else if (optionExt == 2) {
                printf("—————————————\n");
            } else {
                printf("Opção inválida. Tente novamente.\n");
            }
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return option; // Retorne a opção escolhida pelo usuário
}

int Dicas(){
	if (tentativa > numeroPensado || tentativa < numeroPensado){
		if (  numeroPensado == 47) {
	        if (tentativasRestantes == 3) {
	            printf("1ª Eu sou um número primo.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2ª A sua dica é 7 mais o número que estou pensando multiplicado por 5 é igual a 242 (7 + n * 5 = 242).\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3ª O cálculo 48 + 6 / 2 - 4 é igual ao número pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4ª O cálculo 40 + 7 é igual ao número pensado.\n");
	   		}
	    }
	    // Dicas para o número 5
	    else if (  numeroPensado == 5) {
	        if (tentativasRestantes == 3) {
	            printf("1ª O número pensado está entre 0 e 223.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2ª Eu sou um número primo.\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3ª O resultado da soma de dois números primos consecutivos é o número pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4ª 7 - 2 é igual ao número pensado.\n");
	        }
	    }
	    // Dicas para o número 49
	    else if (  numeroPensado == 49) {
	        if (tentativasRestantes == 3) {
	            printf("1ª O número pensado é um quadrado perfeito.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2ª O número pensado está entre 9 e 338.\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3ª 94 - 9 * 5 é igual ao número pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4ª 54 - 5 é igual ao número pensado.\n");
	        }
	    }
	    // Dicas para o número 25
	    else if (  numeroPensado == 25) {
	        if (tentativasRestantes == 3) {
	            printf("1ª O número pensado é um quadrado perfeito.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2ª O cálculo 118 - n%% = 88.5 em que n é o número pensado.\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3ª 12 + 3 * 4 + 1 é igual ao número pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4ª 5 * 5 é igual ao número pensado.\n");
	        }
	    }
	    // Dicas para o número 78
	    else if (  numeroPensado == 78) {
	        if (tentativasRestantes == 3) {
	            printf("1ª 189 - n * 2 = 33 em que n é o número pensado.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2ª O número pensado está entre 0 e 83.\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3ª n / 2 + 5 = 44 em que n é igual ao número pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4ª 70 + 8 é igual ao número pensado.\n");
	        }
	    }
	    // Dicas para o número 77
	    else if (  numeroPensado == 77) {
	        if (tentativasRestantes == 3) {
	            printf("1ª A raiz quadrada do número pensado é aproximadamente 8.78.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2ª O número pensado fica entre 70 e 189.\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3ª n / 5 = 15.4 em que n é igual ao número pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4ª 75 + 2 é igual ao número pensado.\n");
	        }
		}
		
		else if(  numeroPensado == 76) {
		    if (tentativasRestantes == 3)
		        printf("1ª o número pensado é par\n");
		    else if (tentativasRestantes == 2)
		        printf("2ª a raiz quadrada do número pensado é aproximadamente 8.7\n");
		    else if (tentativasRestantes == 1)
		        printf("3ª o número pensado dividido por 2 é igual a 38\n");
		    else if (tentativasRestantes == 0)
		        printf("4ª o número pensado mais 10 é igual a 86\n");
		}
		
		else if (  numeroPensado ==  36) {
		    if (tentativasRestantes == 3)
		        printf("1ª o número pensado está entre 0 e 37\n");
		    else if (tentativasRestantes == 2)
		        printf("2ª o número pensado mais 2 multiplicado por 7 é igual a 50 (n+2*7)\n");
		    else if (tentativasRestantes == 1)
		        printf("3ª o número pensado dividido por 4 é igual a 9\n");
		    else if (tentativasRestantes == 0)
		        printf("4ª o número pensado é igual a 30+6\n");
		}
		
		else if (  numeroPensado ==  54) {
		    if (tentativasRestantes == 3)
		        printf("1ª o número pensado fica entre 1 e 60\n");
		    else if (tentativasRestantes == 2)
		        printf("2ª a raiz quadrada do número pensado é aproximadamente 7.34\n");
		    else if (tentativasRestantes == 1)
		        printf("3ª o número pensado dividido por 2 é igual a 27\n");
		    else if (tentativasRestantes == 0)
		        printf("4ª o número escolhido é igual a 50+4\n");
		}
		
		else if(  numeroPensado ==  87) {
		    if (tentativasRestantes == 3)
		        printf("1ª o número pensado é ímpar\n");
		    else if (tentativasRestantes == 2)
		        printf("2ª o número pensado em algarismo romano é representado por LXXXVII\n");
		    else if (tentativasRestantes == 1)
		        printf("3ª o número pensado multiplicado por 2 é igual a 174\n");
		    else if (tentativasRestantes == 0)
		        printf("4ª o número pensado é igual a 80+7\n");
		}
		
		else if (  numeroPensado ==  22) {
		    if (tentativasRestantes == 3)
		        printf("1ª o número pensado é par\n");
		    else if (tentativasRestantes == 2)
		        printf("2ª o número pensado é igual ao número atômico do titânio\n");
		    else if (tentativasRestantes == 1)
		        printf("3ª o número pensado está entre 20 e 25\n");
		    else if (tentativasRestantes == 0)
		        printf("4ª o número pensado é igual 20+2\n");
			}
	
		/* para o número 55 */
		else if (  numeroPensado == 55)
		{
		    if (tentativasRestantes == 3)
		        printf("1ª o número pensado é o décimo primeiro número da sequência de Fibonacci.\n");
		    else if (tentativasRestantes == 2)
		        printf("2ª é o número total de cartas de um baralho mais 3.\n");
		    else if (tentativasRestantes == 1)
		        printf("3ª o número pensado multiplicado por 2 é igual a 110.\n");
		    else if (tentativasRestantes == 0)
		        printf("4ª o número pensado é igual a 50+5.\n");
		}
		
		/* para o número 28 */
		else if (  numeroPensado == 28)
		{
		    if (tentativasRestantes == 3)
		        printf("1ª o número pensado é um número perfeito.\n");
		    else if (tentativasRestantes == 2)
		        printf("2ª o número pensado é igual ao número atômico do níquel.\n");
		    else if (tentativasRestantes == 1)
		        printf("3ª o número pensado é igual ao número de dias do mês de fevereiro, exceto em anos bissextos.\n");
		    else if (tentativasRestantes == 0)
		        printf("4ª o número pensado é igual a 30-2.\n");
		}
		
		/* para o número 6 */
		else if (  numeroPensado == 6){
		    if (tentativasRestantes == 3)
		        printf("1ª o número pensado está entre 0 e 100.\n");
		    else if (tentativasRestantes == 2)
		        printf("2ª o número pensado é um número perfeito.\n");
		    else if (tentativasRestantes == 1)
		        printf("3ª o número pensado em algarismo romano é representado por VI.\n");
		    else if (tentativasRestantes == 0)
		        printf("4ª o número pensado é igual a 3+3.\n");
		}
		
		/* para o número 44 */
		else if (  numeroPensado == 44){
		    if (tentativasRestantes == 3)
		        printf("1ª o número pensado é igual ao número atômico do rubídio.\n");
		    else if (tentativasRestantes == 2)
		        printf("2ª o número pensado está entre 20 e 68.\n");
		    else if (tentativasRestantes == 1)
		        printf("3ª o número pensado multiplicado por 2 é igual a 88.\n");
		    else if (tentativasRestantes == 0)
		        printf("4ª o número pensado é igual a 40+4.\n");
		}
		
		/* para o número 92 */
		else if (  numeroPensado == 92){
		    if (tentativasRestantes == 3)
		        printf("1ª o número pensado está entre 0 e 100.\n");
		    else if (tentativasRestantes == 2)
		        printf("2ª o número pensado em algarismo romano é representado por XCII.\n");
		    else if (tentativasRestantes == 1)
		        printf("3ª o número pensado dividido por 2 é igual a 46.\n");
		    else if (tentativasRestantes == 0)
		        printf("4ª o número pensado é igual a 90+2.\n");
		}
			
		/* para o número 4 */
		
		else if (  numeroPensado == 4)
		    if (tentativasRestantes == 3)
				printf ("1ª o número pensado é um número par\n");
			else if (tentativasRestantes == 2)
				printf ("2ª o número pensado é o número de estações do ano\n");
			else if (tentativasRestantes == 1)
				printf ("3ª o número pensado é igual a 8 dividido por 2\n");
			else if (tentativasRestantes == 0)
		    	printf ("4ª o número pensado é igual a 2+2\n");
		    
		else if (  numeroPensado == 72){
	        if (tentativasRestantes == 3)
	            printf ("1ª o número pensado está entre 0 e 190\n");
	        else if (tentativasRestantes == 2)
	            printf ("2ª o resultado do cálculo 18+9*6 é igual ao número pensado\n");
	        else if (tentativasRestantes == 1)
	            printf ("3ª o número pensado dividido por 5 é igual a 14.4\n");
	    	else if (tentativasRestantes == 0);
	            printf ("4ª o número pensado é igual a 70+2\n");	
		}
	            
		else if (  numeroPensado == 94)
	        if (tentativasRestantes == 3)
	            printf ("1ª o número escolhido está entre 0 e 94\n");
	        else if (tentativasRestantes == 2)
	            printf ("2ª a raiz cúbica do número escolhido é aproximadamente 4.55\n");
	        else if (tentativasRestantes == 1)
	            printf ("3ª o número pensado dividido por 2 é igual a 47\n");
	        else if (tentativasRestantes == 0)
	            printf ("4ª o número escolhido é igual a 92+2\n");
	            
		else if (  numeroPensado == 75)
	        if (tentativasRestantes == 3)
	            printf ("1ª o número escolhido está entre 5 e 76\n");
	        else if (tentativasRestantes == 2)
	            printf ("2ª a raiz quadrada do número pensado é aproximadamente 8.66\n");
	        else if (tentativasRestantes == 1)
	            printf ("3ª 100-25%=N\n");
	        else if (tentativasRestantes == 0)
	            printf ("4ª o número escolhido é igual a 80-5\n");
	            
		else if (  numeroPensado == 99)
	        if (tentativasRestantes == 3)
	            printf ("1ª Se multiplicar o número pensado por qualquer número inteiro de um dígito, a soma dos dígitos do resultado será 18.\n");
	        else if (tentativasRestantes == 2)
	            printf ("2ª o número pensado é um número ímpar\n");
	        else if (tentativasRestantes == 1)
	            printf ("3ª o número pensado em algarismo romano é representado por XCIX\n");
	        else if (tentativasRestantes == 0)
	            printf ("4ª o número pensado é igual a 90+9\n");
	            
		else if (  numeroPensado == 38)
	        if (tentativasRestantes == 3)
	            printf ("1ª o número pensado está entre 0 e 50\n");
	        else if (tentativasRestantes == 2)
	            printf ("2ª 50-24%=n em que n é igual ao número pensado\n");
	        else if (tentativasRestantes == 1)
	            printf ("3ª o número pensado é o nome de um revolver\n");
	        else if (tentativasRestantes == 0)
	            printf ("4ª o número pensado é igual a 40-2\n");
	    
		else if (  numeroPensado == 90)
	        if (tentativasRestantes == 3)
	            printf ("1ª o número pensado é um número par e divisível por 2, 3, 5, 6, 9, 10, 15, 18, 30, 45 e por ele mesmo\n");
	        else if (tentativasRestantes == 2)
	            printf ("2ª o número pensado está entre 0 e 101\n");
	        else if (tentativasRestantes == 1)
	            printf ("3ª o número pensado é igual ao número de graus que um ângulo reto mede\n");
	        else if (tentativasRestantes == 0)
	            printf ("4ª o número pensado é igual a 100-10\n");
	            
		else if (  numeroPensado == 7) {
	        if (tentativasRestantes == 3)
	            printf("O número pensado é um número ímpar.\n");
	        else if (tentativasRestantes == 2)
	            printf("O número pensado é o número de dias de uma semana.\n");
	        else if (tentativasRestantes == 1)
	            printf("O número pensado é o número da camisa do jogador Cristiano Ronaldo.\n");
	        else if (tentativasRestantes == 0)
	            printf("O número pensado é igual a 5 + 2.\n");
	            
	    } else if (  numeroPensado == 89) {
	        if (tentativasRestantes == 3)
	            printf("O número pensado é um número primo.\n");
	        else if (tentativasRestantes == 2)
	            printf("O número pensado em algarismo romano é representado por LXXXIX.\n");
	        else if (tentativasRestantes == 1)
	            printf("O número pensado multiplicado por 2 é igual a 178.\n");
	        else if (tentativasRestantes == 0)
	            printf("O número pensado é igual a 80 + 9.\n");
	            
	    } else if (  numeroPensado == 60) {
	        if (tentativasRestantes == 3)
	            printf("O número pensado é par.\n");
	        else if (tentativasRestantes == 2)
	            printf("O número pensado está entre 30 e 60.\n");
	        else if (tentativasRestantes == 1)
	            printf("O número pensado é igual ao número de minutos em 1 hora.\n");
	        else if (tentativasRestantes == 0)
	            printf("O número pensado é igual a 50 + 10.\n");
	            
	    } else if (  numeroPensado == 32) {
	        if (tentativasRestantes == 3)
	            printf("O número pensado é par.\n");
	        else if (tentativasRestantes == 2)
	            printf("A raiz quadrada do número pensado é aproximadamente 5.65.\n");
	        else if (tentativasRestantes == 1)
	            printf("O número pensado é o número de um mês comercial mais 2.\n");
	        else if (tentativasRestantes == 0)
	            printf("O número pensado é igual a 30 + 2.\n");
	            
	    } else if (  numeroPensado == 97) {
	        if (tentativasRestantes == 3)
	            printf("O número pensado é um número primo.\n");
	        else if (tentativasRestantes == 2)
	            printf("O número pensado em algarismo romano é representado por XCVII.\n");
	        else if (tentativasRestantes == 1)
	            printf("O número pensado multiplicado por 2 é igual a 194.\n");
	        else if (tentativasRestantes == 0)
	            printf("O número pensado é igual a 90 + 7.\n");
	            
	    } else if (  numeroPensado == 48) {
	        if (tentativasRestantes == 3)
	            printf("O número pensado é igual ao número atômico do cádmio, um elemento químico da tabela periódica.\n");
	        else if (tentativasRestantes == 2)
	            printf("A raiz quadrada do número pensado é aproximadamente 6.93.\n");
	        else if (tentativasRestantes == 1)
	            printf("O número pensado é o número de horas em 2 dias.\n");
	        else if (tentativasRestantes == 0)
	            printf("O número pensado é igual a 50 - 2.\n");
	            
		} else if (  numeroPensado == 82){
	        if (tentativasRestantes == 3)
	            printf("o número pensado está entre 5 e 90.\n");
	        else if (tentativasRestantes == 2)
	            printf("O número pensado em algarismo romano é representado por LXXXII.\n");
	        else if (tentativasRestantes == 1)
	            printf("O número pensado dividido por 2 é igual a 41.\n");
	        else if (tentativasRestantes == 0)
	            printf("O número pensado é igual 80 + 2.\n");
			}
		}
	}

