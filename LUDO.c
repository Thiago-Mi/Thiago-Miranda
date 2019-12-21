#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <math.h>

#include <locale.h>

// Função para rolagem de dado aleatoriamente.
// criação de 3 dados para corresponderem com as regras do jogo.
// Verificação da repetição dos dados e anulação dos mesmos se a repetição for dado 1: 6 dado 2: 6 dado 3: 6.
// print dos dados sorteados na tela.
void dado(int *d1, int *d2, int *d3){
	
	srand(time(NULL));
	
	*d1=rand()%6+1;
	
	
	if(*d1 == 6){
		*d2=rand()%6+1;
	}
	else{
		printf("\n Dado 1: %d, Dado 2: %d, Dado 3: %d \n", *d1, *d2, *d3);
		
	}
		if(*d2 == 6){
		*d3=rand()%6+1;
		if(*d3 == 6){
		*d1 = 0;
		}
		}
	
	
		
		if(*d3 == 0 && *d2 != 0){
			printf("\n\n Dado 1: %d, Dado: 2a %d. \n", *d1,*d2);
			
		}
		if(*d3 != 0 && *d2 != 0 && *d1 == 6){
			printf("\n\n Dado 1: %d, Dado 2b: %d.\n",*d2,*d3);
			
		}
		
}

// função para comer peças.
// Coleta da função que contém as peças separadamente por jogador, a peça selecionada para ser jogada e o numero de jogadores.
// comparação da peça jogada pelo jogador com as peças dos outros jogadores.
// anulação da peça do outro jogador se ela for equivalente ao dados do jogador coletado.
void voltarparabase(int n_peca[][4],int n, int pecajogada, int i){
	int m,j;
	for(m=0;m<i;m++){
			
			for(j = 0;j<4;j++){
				/* testes para ver se a peça está junta de outra peça).*/
				if(j=0){
				
				if(n_peca[n][pecajogada-1] - 13 == n_peca[1][j]  && n!= m ){
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 26 == n_peca[2][j]  && n!= m){
				
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 39 == n_peca[3][j]  && n!= m){
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[n][j] = 0;
				continue;
				}
				
				}
				
				if(j=1){
				
				if(n_peca[n][pecajogada-1] - 13 == n_peca[2][j]  && n!= m ){
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 26 == n_peca[3][j]  && n!= m){
				
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 39 == n_peca[0][j]  && n!= m){
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[n][j] = 0;
				continue;
				}
				
				}
				if(j=2){
				
				if(n_peca[n][pecajogada-1] - 13 == n_peca[3][j]  && n!= m ){
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 26 == n_peca[0][j]  && n!= m){
				
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 39 == n_peca[1][j]  && n!= m){
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[n][j] = 0;
				continue;
				}
				
				}
				if(j=3){
				
				if(n_peca[n][pecajogada-1] - 13 == n_peca[0][j]  && n!= m ){
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 26 == n_peca[1][j]  && n!= m){
				
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 39 == n_peca[2][j]  && n!= m){
				printf("\n Jogador %d comeu uma peça. \n\n Peça %d do jogador %d foi devolvida à base.",n,j, m);
				n_peca[n][j] = 0;
				continue;
				}
				
				}
			}
	}
		
		
}

// função para a peça chegar o objetivo de cada peça.
// se a peça chegar no seu objetivo ela será considerada uma peça indisponível para proximas jogadas por um comando de repetição na função main.
// como todas as peças são vetores não compartilhados diretamente cada uma pode começar e terminar com as casas do mesmo valor não importando de qual jogador ela é.
int retafinal(int n_peca[][4],int n,int pecajogada,int *m, int dado){
		int j;
		if((n_peca[j][pecajogada-1] += dado) > 57){
			n_peca[j][pecajogada-1] -= dado;
			return (*m=0);
		}
		
		
		for(j=0;j<n;j++){
		
			if( n_peca[n][pecajogada-1] >= 51){
		
			n_peca[j][pecajogada-1] += dado;
			*m = n_peca[j][pecajogada-1];
			
				if(*m== 57 || *m <57){
				return (*m);
				}
					if(*m>57){
					n_peca[j][pecajogada-1] -= dado;
					}
			}
		}
				
	}


int main(){
	// comando para habilitar caracteres da lingua portuguesa.
	setlocale(LC_ALL,"");
	// Criação do ponteiro do tipo arquivo para armazenar as jogadas.
	FILE *p;
	// Abertura do arquivo para o registro das jogadas com a função somente de escrita.
	p = fopen("Jogadas do ludo.txt","w");
	// teste de abertura do arquivo, se não for possivel ele ser aberto o programa será fechado.
	if(p==NULL){
		printf("\n ERRO ao abrir o arquivo.");
		exit(1);
		fclose(p);
		return 0;
	}
	//criação de uma variável para dar título ao arquivo.
	char arquivo[100] = " Jogo de Ludo.\n";
	//Escrita do conteúdo da variavel no arquivo.
	fputs(arquivo,p);
		// Criação das variáveis inteiras necessarias do programa.	
		int i=1,n,m,aux[4],j,testador=0,aux2=0,aux3[4];
		// Atribuição de 0 para os valores do vetor auxiliar 3 com finalidade de terminar a reprodução do jogo nas circunstancias certas. 
		for(m=0;m<4;m++){
			aux3[m] = 0;
		}
		// Comando de repetição para conter o numero de jogadores com uma restrição minima de jogadores.
		while(i<2){
			printf("\n Digite o numero de jogadores: ");
			scanf("%d", &i);
			if(i<2){
				printf("\n Numero de jogadores invalido.");
			}
		}
		

		
	
		
	
	//Criação de um ponteiro de ponteiro e de uma variável para as peças que serão jogadas.
	
	int **n_peca, pecajogada;
	
	// Atribuição das peças para cada jogador por meio da alocação de memoria usando a variável do numero de jogadores fornecida pelo teclado anteriormente.
	// Valor de todas as peças de começo será 0.
	
	n_peca = (int**)malloc(i*sizeof(int*));
	
	for(n=0;n<i;n++){
	n_peca[n] = (int*)malloc(4*sizeof(int));
	}
	for(n=0;n<i;n++){
		for(m=0;m<4;m++){
		
	n_peca[n][m] = 0;
		}
	}

	// Criação de uma variável para simbolizar o fim do jogo.
	
	int fim = 0; 
	// Comando de repetição que rodará o jogo com a variável para simbolizar o fim do jogo.
	while(fim == 0){
		// comando para limpar a tela.
		system("cls");
		// print do jogador e sua escrita no arquivo. 
		for(n=0;n<i;n++){
		
		printf("\n\n Jogador %d  ", n+1);
		
		fprintf(p,"\n\n Jogador %d", n+1);
		//Criação das variáveis dos dados.
		int d1 = 0,d2 = 0, d3 = 0;
		// Utilização da função dos dados para alterar as variáveis.
		dado(&d1,&d2,&d3);
		// Escrita do resultado dos dados no arquivo, juntamente com o teste dos dados.
		fprintf(p,"\n\n Dado 1: %d, Dado 2: %d, Dado 3: %d \n", d1, d2, d3);
		if(d1==0){
			printf("\n\n Três 6 repetidos nos dados, pulou a vez.\n\n");
			fprintf(p,"\n\n Pulou a vez\n\n");
			printf("\n Pulou a vez.\n\n");
			system("pause");
			continue; // passa a vez pelo comando de repetição se forem sorteados 3 dados com valor 6.
		}
		
		//teste para a saida de peças pelas regras do jogo ludo.
		
		
				if(d1<6 && n_peca[n][0] == 0 && n_peca[n][1]==0 && n_peca[n][2]==0 && n_peca[n][3] == 0){
					printf("\n Para sair com uma peça de sua base é necessario tirar pelo menos um 6.\n\n ");
					fprintf(p,"\n\n Pulou a vez\n\n");
					printf("\n Pulou a vez.\n\n");
					system("pause");
					system("cls");
					// se for barrado a saida de peças será passada a vez pelo comando de repetição.
					continue;
				}
				// Print do valor de cada peça.
			printf("\n\n Valor de cada peça.\n\n Peça 1: %d. Peça 2: %d. Peça 3: %d. Peça 4: %d.\n",n_peca[n][0],n_peca[n][1],n_peca[n][2],n_peca[n][3]);
			// Jogada das peças dependente do valor dos dados.
		while(d1 != 0 || d2 != 0 || d3 != 0){
			// variável de teste das peças é zerada no comando de repetição logo antes do seu uso.
			testador=0;
		
			printf("\n Peças que podem ser selecionadas (se houver somente uma ela será jogada automaticamentea): ");
			// Utilização de um comando de repetição para verificar todas as 4 peças.
		
		for(m=0;m<4;m++){
			aux[m]=0;
			
			if(n_peca[n][m] != 0){
				printf(" %d", m+1);
				aux[m]=1;
				testador++;
				}
				// Verificação da legalidade do movimento das peças dependente do valor dos dados por meio da logica.
				else if(n_peca[n][m]==0 && d2!=0 && d1!= 0 && n_peca[n][m] < 57){
					printf(" %d", m+1);
					aux[m]=1;
					testador++;
				}
				else if(n_peca[n][m]==0 && d2 == 6 && d3 ==0 && n_peca[n][m] < 57){
					printf(" %d", m+1);
					aux[m]=1;
					testador++;
				}
		}
		//alteração de uma peça automaticamente se só houver a validade de sua jogada.
		if(testador == 1){
			for(m=0;m<4;m++){
				if(aux[m] == 1){
					if(d1==0 && d2!= 0 && d3 == 0){
						//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
					retafinal(n_peca,n,pecajogada,&aux2,d2);
					n_peca[n][m]+= d2;
					
					d2 = 0;
					continue;
					}
					if(d1!= 0 && d2 == 0 && d3 == 0){
						//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
					retafinal(n_peca,n,pecajogada,&aux2,d1);
					n_peca[n][m]+= d1;
					
					d1 = 0;
					continue;
					}
					if(d1== 0 && d2 == 0 && d3 != 0){
					//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
					retafinal(n_peca,n,pecajogada,&aux2,d3);
					n_peca[n][m]+= d3;
					
					d3 = 0;
					continue;
					}
					if(d1!= 0 && d2 != 0 && d3 == 0){
						//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
					retafinal(n_peca,n,pecajogada,&aux2,d1+d2);
					n_peca[n][m]+= d1+d2;
					
					
					d1 = 0;
					d2 = 0;
					continue;
					}
					if(d1== 0 && d2 != 0 && d3 != 0){
						//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
					retafinal(n_peca,n,pecajogada,&aux2,d3+d2);
					n_peca[n][m]+= d3+d2;
					
					if(aux2 == 57)
					n_peca[n][m]=57;
					d3 = 0;
					d2 = 0;

					continue;
					}	
				}
			}
			//print na tela de cada peça do jogador depois de sua jogada se tiver ocorrido nesse comando.
			printf("\n\n Valor de cada peça do jogador %d.\n\n Peça 1: %d. Peça 2: %d. Peça 3: %d. Peça 4: %d.\n\n",n+1,n_peca[n][0],n_peca[n][1],n_peca[n][2],n_peca[n][3]);
			system("pause");
			continue;
		}
		printf("\n\n Peça: ");
		scanf("%d", &pecajogada);
		
		

		
		//Teste para ver se a peça selecionada é valida.
		// se não for válida é requisitado outra entrada de dados até q a peça seja válida.
		
		while(aux[pecajogada-1] != 1){
			printf("\n Jogada invalida.\n\n");
			printf("\n\n Digite uma das peças validas.\n\n Peças que podem ser selecionadas: ");
			for(m=0;m<4;m++){
			aux[m]=0;
			
			if(n_peca[n][m] != 0){
				printf(" %d", m+1);
				aux[m]=1;
			}
			
				else if(n_peca[n][m]==0 && d2!=0 && d1 == 6 || d2 == 6){
					printf(" %d", m+1);
					aux[m]=1;	
				}
				
			}
			scanf("%d", &pecajogada);
		}
		// sequencia de comparações para modificar a peça dependendo de cada situação dos dados jogados.
		
		if(d1 != 0 && d2==0 && d3==0 && testador >1){
			//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d1);
			n_peca[n][pecajogada-1] += d1;
			
			continue;
		}
		if(d1 != 0 && d2==0 && d3==0 && testador ==1){
			//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d1);
			n_peca[n][pecajogada-1] += d1;
			
			continue;
		}
		if(d1==0 && d3==0 && d2 != 0 && testador ==1){
			//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d2);
			n_peca[n][pecajogada-1] += d2;
			
			continue;
		}
		if(d2==0 && d1==0 && d3 != 0 && testador ==1){
			//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d3);
			n_peca[n][pecajogada-1] += d3;
			
			continue;
		}
		// testes para o print dos dados sorteados pelo jogador para ele escolher qual dado será usado para cada peça.
		if(d2!= 0 && d3==0 && testador > 1){
		
			printf("\n Escolha o VALOR do dado. ");
			
			if(d3 == 0 && d2 != 0 && testador > 1){
			printf("\n\n Dado 1: %d, Dado 2: %d. \n", d1,d2);
			}
		}
		
		if(d3 != 0 && testador > 1){
			printf("\n Escolha o VALOR do dado. ");
			printf("\n\n Dado 2: %d, Dado 3: %d.\n",d2,d3);
		}
		
		if(testador ==1 && d2 != 0 && d3 == 0){
			//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d1+d2);
			n_peca[n][pecajogada-1] += d1+d2;
			
			continue;
		}
		
		if(testador ==1 && d2 != 0 && d3 != 0){
			//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d2+d3);
			n_peca[n][pecajogada-1] += d2+d3;
			
			continue;
		}
		
		
		scanf("%d", &j);
		
		if(j==d1 && n_peca[n][pecajogada-1] != 0 || d1 == 6){
			//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d1);
		n_peca[n][pecajogada-1] += d1;
		
		d1=0;
		}
		if(j==d2 && n_peca[n][pecajogada-1] != 0 || d2 == 6){
			//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d2);
		n_peca[n][pecajogada-1] += d2;
		
		d2=0;
		}
		if(j==d3 && n_peca[n][pecajogada-1] != 0 || d3 == 6){
			//utilização da função de termino das peças toda fez que ela é alterada para verificar sua "pontuação" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d3);
		n_peca[n][pecajogada-1] += d3;
		
		d3=0;
		}
		//Depois do movimento da peça é utilizado a função voltarparabase para verificar se havia uma peça  de outro jogador naquela posição e se houver ela é retornada para a sua base.
		voltarparabase(n_peca,n,pecajogada-1,i);
		
		// Fim da sequencia de modificação das peças 
		
		
	}
	//print do valor de cada peça do jogador depois de sua jogada.
		printf("\n\n Valor de cada peça do jogador %d.\n\n Peça 1: %d. Peça 2: %d. Peça 3: %d. Peça 4: %d.\n\n",n+1,n_peca[n][0],n_peca[n][1],n_peca[n][2],n_peca[n][3]);
		system("cls");
		// checagem de cada peça dos jogadores, se todas as peças de um jogador forem pontuadas o jogo acaba.
		
		for(m=0;m<i;m++){
			for(j=0;j<4;j++){
			if(n_peca[m][j] == 57){
				aux3[m] +=1;
			}
			}
			if(aux3[m] == 4)
			fim = 1;
		}
	
	
	
		
		
		

		//print das peças do jogador depois de sua jogada completa.
		fprintf(p,"\n\n Valor de cada peça do jogador %d Depois da jogada.\n\n Peça 1: %d. Peça 2: %d. Peça 3: %d. Peça 4: %d.\n\n",n+1,n_peca[n][0],n_peca[n][1],n_peca[n][2],n_peca[n][3]);

		}
		
	}
	// termino dos ponteiros criados.
	free(*n_peca);
	free(m);
	// Fechamento do arquivo depois do termino da partida com todos os dados salvos.
	fclose(p);
	return 0;
}
