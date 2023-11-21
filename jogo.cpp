#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Declara��o das fun��es
int Menu();
int obterQuantidadeJogadores();
int escolherNumeroAleatorio();
void exibirCreditos();
int Dicas();
int receberPalpites(int quantidadeJogadores);

// Vari�veis globais
int tentativa, tentativasRestantes = 4; // Alterei para 5 tentativas
int quantidadeJogadores;
int numeroPensado;
int numeros[] = {47, 5, 49, 25, 78, 77, 76, 36, 54, 87, 22, 55, 28, 6, 44, 92, 4, 72, 94, 75, 99, 38, 90, 7, 89, 60, 32, 97, 48, 82};

// Fun��o para escolher um n�mero aleat�rio da lista
int escolherNumeroAleatorio() {
    // Inicializa a semente do gerador de n�meros aleat�rios
    srand((unsigned int)time(NULL));

    // Calcula o �ndice aleat�rio
    int indice = rand() % (sizeof(numeros) / sizeof(numeros[0]));

    // Retorna o n�mero correspondente ao �ndice
    return numeros[indice];
}

// Fun��o para exibir os cr�ditos
void exibirCreditos() {
    printf("Os desenvolvedores desse jogo s�o: \n Luis Henrique Ancores Paiva; \n Jonathan Vituriano;\n Luis Henrique Ara�jo;\n Gabriel Negromonte;\n Thiago Fernandes\n.");
    printf("\nPressione Enter para voltar ao menu...\n");

    // Aguarda a tecla Enter ser pressionada
    while (getchar() != '\n');
    getchar(); // Pega o Enter do usu�rio
}

// Fun��o para obter a quantidade de jogadores
int obterQuantidadeJogadores() {
    setlocale(0, "Portuguese");

    int quantidade;
        printf("Digite a quantidade de jogadores (entre 2 e 4): ");
        scanf ("%d", &quantidade);

    do {

        if (quantidade < 2 || quantidade > 4) {
            printf("Por favor, escolha um n�mero entre 2 e 4.\n");
        }

    } while (quantidade < 2 || quantidade > 4);

    return quantidade;
}

int receberPalpites(int quantidadeJogadores) {
    int palpite;

        do {
    		for (int i = 1; i <= quantidadeJogadores; ++i) {
        	printf("\nJogador %d, � a sua vez.\n", i);
            printf("Digite o seu palpite: ");
            scanf("%d", &palpite);
            
            if (palpite == numeroPensado) {
                printf("Parab�ns, Jogador %d! Seu palpite est� correto.\n", i);
                return 0;
            } else {
                printf("Jogador %d, o seu palpite est� incorreto. Tente novamente.\n", i);
                tentativasRestantes--;

                if (tentativasRestantes > 0) {
                    printf("Tentativas restantes: %d\n", tentativasRestantes);
                    Dicas();
                } else {
                    printf("Suas tentativas acabaram. O n�mero correto era %d.\n", numeroPensado);
                    return 0;
                }
            }
    	}
    } while (1);
}

// Fun��o principal do jogo
int main() {
    setlocale(0, "Portuguese");

    int option; // Inicializa a vari�vel option

    // Chama a fun��o Menu() primeiro
    option = Menu();

    // Chama as outras fun��es depois
    if (option == 1) {
        quantidadeJogadores = obterQuantidadeJogadores();
        numeroPensado = escolherNumeroAleatorio();
        receberPalpites(quantidadeJogadores);
    } else if (option == 2) {
        exibirCreditos();
        // N�o precisa de mais nada aqui, pois exibirCreditos() j� cuida de tudo
        return 0;
    } else if (option == 3) {
        printf("Voc� escolheu sair do jogo. Tem certeza que quer sair?.\n 1. SIM\n 2.N�O\n");
        int optionExt;
        scanf("%d", &optionExt);
        if (optionExt == 1) {
            printf("Jogo Desligando...");
            exit(0);
        } else if (optionExt == 2) {
            printf("�������������\n");
        } else {
            printf("Op��o inv�lida. Tente novamente.\n");
        }
        return 0;
    } else {
        printf("Op��o inv�lida. Tente novamente.\n");
        return 0;
    }

    if (tentativasRestantes == 0) {
        printf("Suas tentativas acabaram. O n�mero correto era %d.\n", numeroPensado);
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

        printf("\n\nEscolha uma op��o: \n 1. Jogar\n 2. Cr�ditos\n 3. Sair\n");
        scanf("%d", &option);

        if (option == 1) {
            printf("Voc� escolheu jogar.\n");
            break;
        } else if (option == 2) {
            exibirCreditos();
            // N�o precisa de break aqui, pois queremos que o usu�rio pressione Enter antes de voltar ao menu
        } else if (option == 3) {
            printf("Voc� escolheu sair do jogo, tem certeza que quer sair?.\n 1. SIM\n 2.N�O\n");
            scanf("%d", &optionExt);
            if (optionExt == 1) {
                printf("Jogo Desligando...");
                exit(0);
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

int Dicas(){
	if (tentativa > numeroPensado || tentativa < numeroPensado){
		if (  numeroPensado == 47) {
	        if (tentativasRestantes == 3) {
	            printf("1� Eu sou um n�mero primo.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2� A sua dica � 7 mais o n�mero que estou pensando multiplicado por 5 � igual a 242 (7 + n * 5 = 242).\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3� O c�lculo 48 + 6 / 2 - 4 � igual ao n�mero pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4� O c�lculo 40 + 7 � igual ao n�mero pensado.\n");
	   		}
	    }
	    // Dicas para o n�mero 5
	    else if (  numeroPensado == 5) {
	        if (tentativasRestantes == 3) {
	            printf("1� O n�mero pensado est� entre 0 e 223.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2� Eu sou um n�mero primo.\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3� O resultado da soma de dois n�meros primos consecutivos � o n�mero pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4� 7 - 2 � igual ao n�mero pensado.\n");
	        }
	    }
	    // Dicas para o n�mero 49
	    else if (  numeroPensado == 49) {
	        if (tentativasRestantes == 3) {
	            printf("1� O n�mero pensado � um quadrado perfeito.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2� O n�mero pensado est� entre 9 e 338.\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3� 94 - 9 * 5 � igual ao n�mero pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4� 54 - 5 � igual ao n�mero pensado.\n");
	        }
	    }
	    // Dicas para o n�mero 25
	    else if (  numeroPensado == 25) {
	        if (tentativasRestantes == 3) {
	            printf("1� O n�mero pensado � um quadrado perfeito.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2� O c�lculo 118 - n%% = 88.5 em que n � o n�mero pensado.\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3� 12 + 3 * 4 + 1 � igual ao n�mero pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4� 5 * 5 � igual ao n�mero pensado.\n");
	        }
	    }
	    // Dicas para o n�mero 78
	    else if (  numeroPensado == 78) {
	        if (tentativasRestantes == 3) {
	            printf("1� 189 - n * 2 = 33 em que n � o n�mero pensado.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2� O n�mero pensado est� entre 0 e 83.\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3� n / 2 + 5 = 44 em que n � igual ao n�mero pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4� 70 + 8 � igual ao n�mero pensado.\n");
	        }
	    }
	    // Dicas para o n�mero 77
	    else if (  numeroPensado == 77) {
	        if (tentativasRestantes == 3) {
	            printf("1� A raiz quadrada do n�mero pensado � aproximadamente 8.78.\n");
	        } else if (tentativasRestantes == 2) {
	            printf("2� O n�mero pensado fica entre 70 e 189.\n");
	        } else if (tentativasRestantes == 1) {
	            printf("3� n / 5 = 15.4 em que n � igual ao n�mero pensado.\n");
	        } else if (tentativasRestantes == 0) {
	            printf("4� 75 + 2 � igual ao n�mero pensado.\n");
	        }
		}
		
		else if(  numeroPensado == 76) {
		    if (tentativasRestantes == 3)
		        printf("1� o n�mero pensado � par\n");
		    else if (tentativasRestantes == 2)
		        printf("2� a raiz quadrada do n�mero pensado � aproximadamente 8.7\n");
		    else if (tentativasRestantes == 1)
		        printf("3� o n�mero pensado dividido por 2 � igual a 38\n");
		    else if (tentativasRestantes == 0)
		        printf("4� o n�mero pensado mais 10 � igual a 86\n");
		}
		
		else if (  numeroPensado ==  36) {
		    if (tentativasRestantes == 3)
		        printf("1� o n�mero pensado est� entre 0 e 37\n");
		    else if (tentativasRestantes == 2)
		        printf("2� o n�mero pensado mais 2 multiplicado por 7 � igual a 50 (n+2*7)\n");
		    else if (tentativasRestantes == 1)
		        printf("3� o n�mero pensado dividido por 4 � igual a 9\n");
		    else if (tentativasRestantes == 0)
		        printf("4� o n�mero pensado � igual a 30+6\n");
		}
		
		else if (  numeroPensado ==  54) {
		    if (tentativasRestantes == 3)
		        printf("1� o n�mero pensado fica entre 1 e 60\n");
		    else if (tentativasRestantes == 2)
		        printf("2� a raiz quadrada do n�mero pensado � aproximadamente 7.34\n");
		    else if (tentativasRestantes == 1)
		        printf("3� o n�mero pensado dividido por 2 � igual a 27\n");
		    else if (tentativasRestantes == 0)
		        printf("4� o n�mero escolhido � igual a 50+4\n");
		}
		
		else if(  numeroPensado ==  87) {
		    if (tentativasRestantes == 3)
		        printf("1� o n�mero pensado � �mpar\n");
		    else if (tentativasRestantes == 2)
		        printf("2� o n�mero pensado em algarismo romano � representado por LXXXVII\n");
		    else if (tentativasRestantes == 1)
		        printf("3� o n�mero pensado multiplicado por 2 � igual a 174\n");
		    else if (tentativasRestantes == 0)
		        printf("4� o n�mero pensado � igual a 80+7\n");
		}
		
		else if (  numeroPensado ==  22) {
		    if (tentativasRestantes == 3)
		        printf("1� o n�mero pensado � par\n");
		    else if (tentativasRestantes == 2)
		        printf("2� o n�mero pensado � igual ao n�mero at�mico do tit�nio\n");
		    else if (tentativasRestantes == 1)
		        printf("3� o n�mero pensado est� entre 20 e 25\n");
		    else if (tentativasRestantes == 0)
		        printf("4� o n�mero pensado � igual 20+2\n");
			}
	
		/* para o n�mero 55 */
		else if (  numeroPensado == 55)
		{
		    if (tentativasRestantes == 3)
		        printf("1� o n�mero pensado � o d�cimo primeiro n�mero da sequ�ncia de Fibonacci.\n");
		    else if (tentativasRestantes == 2)
		        printf("2� � o n�mero total de cartas de um baralho mais 3.\n");
		    else if (tentativasRestantes == 1)
		        printf("3� o n�mero pensado multiplicado por 2 � igual a 110.\n");
		    else if (tentativasRestantes == 0)
		        printf("4� o n�mero pensado � igual a 50+5.\n");
		}
		
		/* para o n�mero 28 */
		else if (  numeroPensado == 28)
		{
		    if (tentativasRestantes == 3)
		        printf("1� o n�mero pensado � um n�mero perfeito.\n");
		    else if (tentativasRestantes == 2)
		        printf("2� o n�mero pensado � igual ao n�mero at�mico do n�quel.\n");
		    else if (tentativasRestantes == 1)
		        printf("3� o n�mero pensado � igual ao n�mero de dias do m�s de fevereiro, exceto em anos bissextos.\n");
		    else if (tentativasRestantes == 0)
		        printf("4� o n�mero pensado � igual a 30-2.\n");
		}
		
		/* para o n�mero 6 */
		else if (  numeroPensado == 6){
		    if (tentativasRestantes == 3)
		        printf("1� o n�mero pensado est� entre 0 e 100.\n");
		    else if (tentativasRestantes == 2)
		        printf("2� o n�mero pensado � um n�mero perfeito.\n");
		    else if (tentativasRestantes == 1)
		        printf("3� o n�mero pensado em algarismo romano � representado por VI.\n");
		    else if (tentativasRestantes == 0)
		        printf("4� o n�mero pensado � igual a 3+3.\n");
		}
		
		/* para o n�mero 44 */
		else if (  numeroPensado == 44){
		    if (tentativasRestantes == 3)
		        printf("1� o n�mero pensado � igual ao n�mero at�mico do rub�dio.\n");
		    else if (tentativasRestantes == 2)
		        printf("2� o n�mero pensado est� entre 20 e 68.\n");
		    else if (tentativasRestantes == 1)
		        printf("3� o n�mero pensado multiplicado por 2 � igual a 88.\n");
		    else if (tentativasRestantes == 0)
		        printf("4� o n�mero pensado � igual a 40+4.\n");
		}
		
		/* para o n�mero 92 */
		else if (  numeroPensado == 92){
		    if (tentativasRestantes == 3)
		        printf("1� o n�mero pensado est� entre 0 e 100.\n");
		    else if (tentativasRestantes == 2)
		        printf("2� o n�mero pensado em algarismo romano � representado por XCII.\n");
		    else if (tentativasRestantes == 1)
		        printf("3� o n�mero pensado dividido por 2 � igual a 46.\n");
		    else if (tentativasRestantes == 0)
		        printf("4� o n�mero pensado � igual a 90+2.\n");
		}
			
		/* para o n�mero 4 */
		
		else if (  numeroPensado == 4)
		    if (tentativasRestantes == 3)
				printf ("1� o n�mero pensado � um n�mero par\n");
			else if (tentativasRestantes == 2)
				printf ("2� o n�mero pensado � o n�mero de esta��es do ano\n");
			else if (tentativasRestantes == 1)
				printf ("3� o n�mero pensado � igual a 8 dividido por 2\n");
			else if (tentativasRestantes == 0)
		    	printf ("4� o n�mero pensado � igual a 2+2\n");
		    
		else if (  numeroPensado == 72){
	        if (tentativasRestantes == 3)
	            printf ("1� o n�mero pensado est� entre 0 e 190\n");
	        else if (tentativasRestantes == 2)
	            printf ("2� o resultado do c�lculo 18+9*6 � igual ao n�mero pensado\n");
	        else if (tentativasRestantes == 1)
	            printf ("3� o n�mero pensado dividido por 5 � igual a 14.4\n");
	    	else if (tentativasRestantes == 0);
	            printf ("4� o n�mero pensado � igual a 70+2\n");	
		}
	            
		else if (  numeroPensado == 94)
	        if (tentativasRestantes == 3)
	            printf ("1� o n�mero escolhido est� entre 0 e 94\n");
	        else if (tentativasRestantes == 2)
	            printf ("2� a raiz c�bica do n�mero escolhido � aproximadamente 4.55\n");
	        else if (tentativasRestantes == 1)
	            printf ("3� o n�mero pensado dividido por 2 � igual a 47\n");
	        else if (tentativasRestantes == 0)
	            printf ("4� o n�mero escolhido � igual a 92+2\n");
	            
		else if (  numeroPensado == 75)
	        if (tentativasRestantes == 3)
	            printf ("1� o n�mero escolhido est� entre 5 e 76\n");
	        else if (tentativasRestantes == 2)
	            printf ("2� a raiz quadrada do n�mero pensado � aproximadamente 8.66\n");
	        else if (tentativasRestantes == 1)
	            printf ("3� 100-25%=N\n");
	        else if (tentativasRestantes == 0)
	            printf ("4� o n�mero escolhido � igual a 80-5\n");
	            
		else if (  numeroPensado == 99)
	        if (tentativasRestantes == 3)
	            printf ("1� Se multiplicar o n�mero pensado por qualquer n�mero inteiro de um d�gito, a soma dos d�gitos do resultado ser� 18.\n");
	        else if (tentativasRestantes == 2)
	            printf ("2� o n�mero pensado � um n�mero �mpar\n");
	        else if (tentativasRestantes == 1)
	            printf ("3� o n�mero pensado em algarismo romano � representado por XCIX\n");
	        else if (tentativasRestantes == 0)
	            printf ("4� o n�mero pensado � igual a 90+9\n");
	            
		else if (  numeroPensado == 38)
	        if (tentativasRestantes == 3)
	            printf ("1� o n�mero pensado est� entre 0 e 50\n");
	        else if (tentativasRestantes == 2)
	            printf ("2� 50-24%=n em que n � igual ao n�mero pensado\n");
	        else if (tentativasRestantes == 1)
	            printf ("3� o n�mero pensado � o nome de um revolver\n");
	        else if (tentativasRestantes == 0)
	            printf ("4� o n�mero pensado � igual a 40-2\n");
	    
		else if (  numeroPensado == 90)
	        if (tentativasRestantes == 3)
	            printf ("1� o n�mero pensado � um n�mero par e divis�vel por 2, 3, 5, 6, 9, 10, 15, 18, 30, 45 e por ele mesmo\n");
	        else if (tentativasRestantes == 2)
	            printf ("2� o n�mero pensado est� entre 0 e 101\n");
	        else if (tentativasRestantes == 1)
	            printf ("3� o n�mero pensado � igual ao n�mero de graus que um �ngulo reto mede\n");
	        else if (tentativasRestantes == 0)
	            printf ("4� o n�mero pensado � igual a 100-10\n");
	            
		else if (  numeroPensado == 7) {
	        if (tentativasRestantes == 3)
	            printf("O n�mero pensado � um n�mero �mpar.\n");
	        else if (tentativasRestantes == 2)
	            printf("O n�mero pensado � o n�mero de dias de uma semana.\n");
	        else if (tentativasRestantes == 1)
	            printf("O n�mero pensado � o n�mero da camisa do jogador Cristiano Ronaldo.\n");
	        else if (tentativasRestantes == 0)
	            printf("O n�mero pensado � igual a 5 + 2.\n");
	            
	    } else if (  numeroPensado == 89) {
	        if (tentativasRestantes == 3)
	            printf("O n�mero pensado � um n�mero primo.\n");
	        else if (tentativasRestantes == 2)
	            printf("O n�mero pensado em algarismo romano � representado por LXXXIX.\n");
	        else if (tentativasRestantes == 1)
	            printf("O n�mero pensado multiplicado por 2 � igual a 178.\n");
	        else if (tentativasRestantes == 0)
	            printf("O n�mero pensado � igual a 80 + 9.\n");
	            
	    } else if (  numeroPensado == 60) {
	        if (tentativasRestantes == 3)
	            printf("O n�mero pensado � par.\n");
	        else if (tentativasRestantes == 2)
	            printf("O n�mero pensado est� entre 30 e 60.\n");
	        else if (tentativasRestantes == 1)
	            printf("O n�mero pensado � igual ao n�mero de minutos em 1 hora.\n");
	        else if (tentativasRestantes == 0)
	            printf("O n�mero pensado � igual a 50 + 10.\n");
	            
	    } else if (  numeroPensado == 32) {
	        if (tentativasRestantes == 3)
	            printf("O n�mero pensado � par.\n");
	        else if (tentativasRestantes == 2)
	            printf("A raiz quadrada do n�mero pensado � aproximadamente 5.65.\n");
	        else if (tentativasRestantes == 1)
	            printf("O n�mero pensado � o n�mero de um m�s comercial mais 2.\n");
	        else if (tentativasRestantes == 0)
	            printf("O n�mero pensado � igual a 30 + 2.\n");
	            
	    } else if (  numeroPensado == 97) {
	        if (tentativasRestantes == 3)
	            printf("O n�mero pensado � um n�mero primo.\n");
	        else if (tentativasRestantes == 2)
	            printf("O n�mero pensado em algarismo romano � representado por XCVII.\n");
	        else if (tentativasRestantes == 1)
	            printf("O n�mero pensado multiplicado por 2 � igual a 194.\n");
	        else if (tentativasRestantes == 0)
	            printf("O n�mero pensado � igual a 90 + 7.\n");
	            
	    } else if (  numeroPensado == 48) {
	        if (tentativasRestantes == 3)
	            printf("O n�mero pensado � igual ao n�mero at�mico do c�dmio, um elemento qu�mico da tabela peri�dica.\n");
	        else if (tentativasRestantes == 2)
	            printf("A raiz quadrada do n�mero pensado � aproximadamente 6.93.\n");
	        else if (tentativasRestantes == 1)
	            printf("O n�mero pensado � o n�mero de horas em 2 dias.\n");
	        else if (tentativasRestantes == 0)
	            printf("O n�mero pensado � igual a 50 - 2.\n");
	            
		} else if (  numeroPensado == 82){
	        if (tentativasRestantes == 3)
	            printf("o n�mero pensado est� entre 5 e 90.\n");
	        else if (tentativasRestantes == 2)
	            printf("O n�mero pensado em algarismo romano � representado por LXXXII.\n");
	        else if (tentativasRestantes == 1)
	            printf("O n�mero pensado dividido por 2 � igual a 41.\n");
	        else if (tentativasRestantes == 0)
	            printf("O n�mero pensado � igual 80 + 2.\n");
			}
		}
	}

