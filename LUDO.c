#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <math.h>

#include <locale.h>

// Fun��o para rolagem de dado aleatoriamente.
// cria��o de 3 dados para corresponderem com as regras do jogo.
// Verifica��o da repeti��o dos dados e anula��o dos mesmos se a repeti��o for dado 1: 6 dado 2: 6 dado 3: 6.
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

// fun��o para comer pe�as.
// Coleta da fun��o que cont�m as pe�as separadamente por jogador, a pe�a selecionada para ser jogada e o numero de jogadores.
// compara��o da pe�a jogada pelo jogador com as pe�as dos outros jogadores.
// anula��o da pe�a do outro jogador se ela for equivalente ao dados do jogador coletado.
void voltarparabase(int n_peca[][4],int n, int pecajogada, int i){
	int m,j;
	for(m=0;m<i;m++){
			
			for(j = 0;j<4;j++){
				/* testes para ver se a pe�a est� junta de outra pe�a).*/
				if(j=0){
				
				if(n_peca[n][pecajogada-1] - 13 == n_peca[1][j]  && n!= m ){
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 26 == n_peca[2][j]  && n!= m){
				
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 39 == n_peca[3][j]  && n!= m){
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[n][j] = 0;
				continue;
				}
				
				}
				
				if(j=1){
				
				if(n_peca[n][pecajogada-1] - 13 == n_peca[2][j]  && n!= m ){
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 26 == n_peca[3][j]  && n!= m){
				
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 39 == n_peca[0][j]  && n!= m){
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[n][j] = 0;
				continue;
				}
				
				}
				if(j=2){
				
				if(n_peca[n][pecajogada-1] - 13 == n_peca[3][j]  && n!= m ){
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 26 == n_peca[0][j]  && n!= m){
				
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 39 == n_peca[1][j]  && n!= m){
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[n][j] = 0;
				continue;
				}
				
				}
				if(j=3){
				
				if(n_peca[n][pecajogada-1] - 13 == n_peca[0][j]  && n!= m ){
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 26 == n_peca[1][j]  && n!= m){
				
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[m][j] = 0;
				continue;
				}
				if(n_peca[n][pecajogada-1] - 39 == n_peca[2][j]  && n!= m){
				printf("\n Jogador %d comeu uma pe�a. \n\n Pe�a %d do jogador %d foi devolvida � base.",n,j, m);
				n_peca[n][j] = 0;
				continue;
				}
				
				}
			}
	}
		
		
}

// fun��o para a pe�a chegar o objetivo de cada pe�a.
// se a pe�a chegar no seu objetivo ela ser� considerada uma pe�a indispon�vel para proximas jogadas por um comando de repeti��o na fun��o main.
// como todas as pe�as s�o vetores n�o compartilhados diretamente cada uma pode come�ar e terminar com as casas do mesmo valor n�o importando de qual jogador ela �.
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
	// Cria��o do ponteiro do tipo arquivo para armazenar as jogadas.
	FILE *p;
	// Abertura do arquivo para o registro das jogadas com a fun��o somente de escrita.
	p = fopen("Jogadas do ludo.txt","w");
	// teste de abertura do arquivo, se n�o for possivel ele ser aberto o programa ser� fechado.
	if(p==NULL){
		printf("\n ERRO ao abrir o arquivo.");
		exit(1);
		fclose(p);
		return 0;
	}
	//cria��o de uma vari�vel para dar t�tulo ao arquivo.
	char arquivo[100] = " Jogo de Ludo.\n";
	//Escrita do conte�do da variavel no arquivo.
	fputs(arquivo,p);
		// Cria��o das vari�veis inteiras necessarias do programa.	
		int i=1,n,m,aux[4],j,testador=0,aux2=0,aux3[4];
		// Atribui��o de 0 para os valores do vetor auxiliar 3 com finalidade de terminar a reprodu��o do jogo nas circunstancias certas. 
		for(m=0;m<4;m++){
			aux3[m] = 0;
		}
		// Comando de repeti��o para conter o numero de jogadores com uma restri��o minima de jogadores.
		while(i<2){
			printf("\n Digite o numero de jogadores: ");
			scanf("%d", &i);
			if(i<2){
				printf("\n Numero de jogadores invalido.");
			}
		}
		

		
	
		
	
	//Cria��o de um ponteiro de ponteiro e de uma vari�vel para as pe�as que ser�o jogadas.
	
	int **n_peca, pecajogada;
	
	// Atribui��o das pe�as para cada jogador por meio da aloca��o de memoria usando a vari�vel do numero de jogadores fornecida pelo teclado anteriormente.
	// Valor de todas as pe�as de come�o ser� 0.
	
	n_peca = (int**)malloc(i*sizeof(int*));
	
	for(n=0;n<i;n++){
	n_peca[n] = (int*)malloc(4*sizeof(int));
	}
	for(n=0;n<i;n++){
		for(m=0;m<4;m++){
		
	n_peca[n][m] = 0;
		}
	}

	// Cria��o de uma vari�vel para simbolizar o fim do jogo.
	
	int fim = 0; 
	// Comando de repeti��o que rodar� o jogo com a vari�vel para simbolizar o fim do jogo.
	while(fim == 0){
		// comando para limpar a tela.
		system("cls");
		// print do jogador e sua escrita no arquivo. 
		for(n=0;n<i;n++){
		
		printf("\n\n Jogador %d  ", n+1);
		
		fprintf(p,"\n\n Jogador %d", n+1);
		//Cria��o das vari�veis dos dados.
		int d1 = 0,d2 = 0, d3 = 0;
		// Utiliza��o da fun��o dos dados para alterar as vari�veis.
		dado(&d1,&d2,&d3);
		// Escrita do resultado dos dados no arquivo, juntamente com o teste dos dados.
		fprintf(p,"\n\n Dado 1: %d, Dado 2: %d, Dado 3: %d \n", d1, d2, d3);
		if(d1==0){
			printf("\n\n Tr�s 6 repetidos nos dados, pulou a vez.\n\n");
			fprintf(p,"\n\n Pulou a vez\n\n");
			printf("\n Pulou a vez.\n\n");
			system("pause");
			continue; // passa a vez pelo comando de repeti��o se forem sorteados 3 dados com valor 6.
		}
		
		//teste para a saida de pe�as pelas regras do jogo ludo.
		
		
				if(d1<6 && n_peca[n][0] == 0 && n_peca[n][1]==0 && n_peca[n][2]==0 && n_peca[n][3] == 0){
					printf("\n Para sair com uma pe�a de sua base � necessario tirar pelo menos um 6.\n\n ");
					fprintf(p,"\n\n Pulou a vez\n\n");
					printf("\n Pulou a vez.\n\n");
					system("pause");
					system("cls");
					// se for barrado a saida de pe�as ser� passada a vez pelo comando de repeti��o.
					continue;
				}
				// Print do valor de cada pe�a.
			printf("\n\n Valor de cada pe�a.\n\n Pe�a 1: %d. Pe�a 2: %d. Pe�a 3: %d. Pe�a 4: %d.\n",n_peca[n][0],n_peca[n][1],n_peca[n][2],n_peca[n][3]);
			// Jogada das pe�as dependente do valor dos dados.
		while(d1 != 0 || d2 != 0 || d3 != 0){
			// vari�vel de teste das pe�as � zerada no comando de repeti��o logo antes do seu uso.
			testador=0;
		
			printf("\n Pe�as que podem ser selecionadas (se houver somente uma ela ser� jogada automaticamentea): ");
			// Utiliza��o de um comando de repeti��o para verificar todas as 4 pe�as.
		
		for(m=0;m<4;m++){
			aux[m]=0;
			
			if(n_peca[n][m] != 0){
				printf(" %d", m+1);
				aux[m]=1;
				testador++;
				}
				// Verifica��o da legalidade do movimento das pe�as dependente do valor dos dados por meio da logica.
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
		//altera��o de uma pe�a automaticamente se s� houver a validade de sua jogada.
		if(testador == 1){
			for(m=0;m<4;m++){
				if(aux[m] == 1){
					if(d1==0 && d2!= 0 && d3 == 0){
						//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
					retafinal(n_peca,n,pecajogada,&aux2,d2);
					n_peca[n][m]+= d2;
					
					d2 = 0;
					continue;
					}
					if(d1!= 0 && d2 == 0 && d3 == 0){
						//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
					retafinal(n_peca,n,pecajogada,&aux2,d1);
					n_peca[n][m]+= d1;
					
					d1 = 0;
					continue;
					}
					if(d1== 0 && d2 == 0 && d3 != 0){
					//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
					retafinal(n_peca,n,pecajogada,&aux2,d3);
					n_peca[n][m]+= d3;
					
					d3 = 0;
					continue;
					}
					if(d1!= 0 && d2 != 0 && d3 == 0){
						//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
					retafinal(n_peca,n,pecajogada,&aux2,d1+d2);
					n_peca[n][m]+= d1+d2;
					
					
					d1 = 0;
					d2 = 0;
					continue;
					}
					if(d1== 0 && d2 != 0 && d3 != 0){
						//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
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
			//print na tela de cada pe�a do jogador depois de sua jogada se tiver ocorrido nesse comando.
			printf("\n\n Valor de cada pe�a do jogador %d.\n\n Pe�a 1: %d. Pe�a 2: %d. Pe�a 3: %d. Pe�a 4: %d.\n\n",n+1,n_peca[n][0],n_peca[n][1],n_peca[n][2],n_peca[n][3]);
			system("pause");
			continue;
		}
		printf("\n\n Pe�a: ");
		scanf("%d", &pecajogada);
		
		

		
		//Teste para ver se a pe�a selecionada � valida.
		// se n�o for v�lida � requisitado outra entrada de dados at� q a pe�a seja v�lida.
		
		while(aux[pecajogada-1] != 1){
			printf("\n Jogada invalida.\n\n");
			printf("\n\n Digite uma das pe�as validas.\n\n Pe�as que podem ser selecionadas: ");
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
		// sequencia de compara��es para modificar a pe�a dependendo de cada situa��o dos dados jogados.
		
		if(d1 != 0 && d2==0 && d3==0 && testador >1){
			//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d1);
			n_peca[n][pecajogada-1] += d1;
			
			continue;
		}
		if(d1 != 0 && d2==0 && d3==0 && testador ==1){
			//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d1);
			n_peca[n][pecajogada-1] += d1;
			
			continue;
		}
		if(d1==0 && d3==0 && d2 != 0 && testador ==1){
			//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d2);
			n_peca[n][pecajogada-1] += d2;
			
			continue;
		}
		if(d2==0 && d1==0 && d3 != 0 && testador ==1){
			//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d3);
			n_peca[n][pecajogada-1] += d3;
			
			continue;
		}
		// testes para o print dos dados sorteados pelo jogador para ele escolher qual dado ser� usado para cada pe�a.
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
			//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d1+d2);
			n_peca[n][pecajogada-1] += d1+d2;
			
			continue;
		}
		
		if(testador ==1 && d2 != 0 && d3 != 0){
			//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d2+d3);
			n_peca[n][pecajogada-1] += d2+d3;
			
			continue;
		}
		
		
		scanf("%d", &j);
		
		if(j==d1 && n_peca[n][pecajogada-1] != 0 || d1 == 6){
			//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d1);
		n_peca[n][pecajogada-1] += d1;
		
		d1=0;
		}
		if(j==d2 && n_peca[n][pecajogada-1] != 0 || d2 == 6){
			//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d2);
		n_peca[n][pecajogada-1] += d2;
		
		d2=0;
		}
		if(j==d3 && n_peca[n][pecajogada-1] != 0 || d3 == 6){
			//utiliza��o da fun��o de termino das pe�as toda fez que ela � alterada para verificar sua "pontua��o" no jogo.
			retafinal(n_peca,n,pecajogada,&aux2,d3);
		n_peca[n][pecajogada-1] += d3;
		
		d3=0;
		}
		//Depois do movimento da pe�a � utilizado a fun��o voltarparabase para verificar se havia uma pe�a  de outro jogador naquela posi��o e se houver ela � retornada para a sua base.
		voltarparabase(n_peca,n,pecajogada-1,i);
		
		// Fim da sequencia de modifica��o das pe�as 
		
		
	}
	//print do valor de cada pe�a do jogador depois de sua jogada.
		printf("\n\n Valor de cada pe�a do jogador %d.\n\n Pe�a 1: %d. Pe�a 2: %d. Pe�a 3: %d. Pe�a 4: %d.\n\n",n+1,n_peca[n][0],n_peca[n][1],n_peca[n][2],n_peca[n][3]);
		system("cls");
		// checagem de cada pe�a dos jogadores, se todas as pe�as de um jogador forem pontuadas o jogo acaba.
		
		for(m=0;m<i;m++){
			for(j=0;j<4;j++){
			if(n_peca[m][j] == 57){
				aux3[m] +=1;
			}
			}
			if(aux3[m] == 4)
			fim = 1;
		}
	
	
	
		
		
		

		//print das pe�as do jogador depois de sua jogada completa.
		fprintf(p,"\n\n Valor de cada pe�a do jogador %d Depois da jogada.\n\n Pe�a 1: %d. Pe�a 2: %d. Pe�a 3: %d. Pe�a 4: %d.\n\n",n+1,n_peca[n][0],n_peca[n][1],n_peca[n][2],n_peca[n][3]);

		}
		
	}
	// termino dos ponteiros criados.
	free(*n_peca);
	free(m);
	// Fechamento do arquivo depois do termino da partida com todos os dados salvos.
	fclose(p);
	return 0;
}




