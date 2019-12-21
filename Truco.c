#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>






typedef struct carta{
	int nipe; 									// Paus 4, Copas 3, Espadas 2, Ouro 1;
	int numero; 								//4, 5, 6, 7, Q, J, K, A, 2, 3 -> 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.
	int zap; 									// Ordenado em sequencia crescente de força.
}carta;




typedef struct baralho_pilha{ 					// Struct para o baralho.
	
	carta *elemento;
	struct baralho_pilha *anterior;
	carta cartao[40];
	
}baralho;

baralho* ini(){
	
	baralho* p = (baralho*)malloc(sizeof(baralho));
	return p;
}

typedef struct jogador{ 						// Struct para os jogadores.
	
	int pontos[10];
	int rodadas;
	int rodadas_vencidas;
	int vidas;
	char nome;
	carta mao[5];
	
}jogador;

jogador* ini_j(){ 								// Função para iniciar a struct jogadores.
	
	jogador* p = (jogador*)malloc(sizeof(jogador));
	return p;

}


void shuffle(baralho *p) {
												// função para embaralhar o baralho. 
	srand(time(NULL)); 
	int i,j,tmp,n,tmp2;							// Inicio das variaveis
	n=0;
	j=0;
												// Atribuição das cartas em sequencia numerica
	for(i=1;i<41;i++){
												//repetição dos numeros na atribuição.
	p->cartao[i-1].numero=n;
	p->cartao[i-1].nipe=j+1;
	j++;
												//limitação de 4 numeros repetidos pela atribuição para mudar de numero.
	if(i%4==0){
		n++;
		j=0;
	}
}
												// Começo do embaralhar das cartas.
    for (i = 39; i > 0; i--) {
    											// Um laço de repetição.
        j = rand()%i; 							// Aleatorização de j para fazer a troca dos numeros pelo indice aleatório.
        tmp = p->cartao[j].numero;
        tmp2 = p->cartao[j].nipe;
        										//Variaveis auxiliares para conter os valores.
        p->cartao[j].numero = p->cartao[i].numero;
        p->cartao[j].nipe = p->cartao[i].nipe;
        p->cartao[j].zap = 0;
         
        p->cartao[i].numero = tmp;
		p->cartao[i].nipe = tmp2;
		p->cartao[i].zap = 0;
												// alteração dos dois valores pelos seus indices.
		
												// Começo da atribuição das cartas zap pelo seu numero e nipe com um if para comparação.
		if(p->cartao[i].numero==3 && p->cartao[i].nipe==4){ 
			p->cartao[i].zap=4;
		}
		if(p->cartao[i].numero==6 && p->cartao[i].nipe==3){
			p->cartao[i].zap=3;
		}
		if(p->cartao[i].numero==0 && p->cartao[i].nipe==2){
			p->cartao[i].zap=2;
		}
		if(p->cartao[i].numero==6 && p->cartao[i].nipe==1){
			p->cartao[i].zap=1;
		}   
    }

}

int maior(carta p, carta n){
												//Função para testar a carta com o maior valor.
	if(p.numero == n.numero){
		if(p.zap>n.zap){
			return 1;
		}
		else{
			return 2;
		}
	}
	else{
		if(p.numero>n.numero && n.zap==0 || n.zap<p.zap){
			return 1;
		}
		else{
			return 2;
		}
	}
	
}

	



int main(){
	
		FILE *r;
												// Abertura do arquivo para o registro do jogo com a função somente de escrita.
	r = fopen("Jogo de Truco.txt","w");
												// teste de abertura do arquivo, se não for possivel ele ser aberto o programa será fechado.
	if(r==NULL){
		printf("\n ERRO ao abrir o arquivo.");
		exit(1);
		fclose(r);
		return 0;
	}
												//criação de uma variável para dar título ao arquivo.
	char arquivo[100] = " Jogo de Truco.\n";
												//Escrita do conteúdo da variavel no arquivo.
	fputs(arquivo,r);
												//Utilização da biblioteca para possibilitar o uso da linguagem portuguesa com acentos.
	setlocale(LC_ALL, "Portuguese");
												//Nomeação das variaveis que serão usadas no codigo.
	int n_jo;									// Variavel para o numero de jogadores.
	int n;
	int m;
												//Variaveis auxiliar para laços de repetição.
												
	int rodada; 								//Variavel para contabilizar o numero de rodadas.
	int partida; 								// Variavel para contabilizar o numero da partida.
	baralho *t;									//Criação do ponteiro para representar as cartas.
	jogador *jogadores; 						//Criação do ponteiro para representar os jogadores.
	int *aux_jogada;							//Criação de um ponteiro auxiliar.
	int aux,auxj1, auxj2; 						//variaveis auxiliares.
	aux = 0;
	auxj1=0;
	t =	ini(); 									//Iniciação do ponteiro do baralho.
	
	printf("\n REGRAS: \n\n 1 - Numero minimo de jogadores 2, numero maximo de jogadores 8.\n 2 - A sequencia dos nipes sera representada por numeros: Paus (4), Copas (3), Espadas (2), Ouro (1).\n\n  3 - As cartas serão representadas por numeros em ordem crescente de força: 4, 5, 6, 7, Q, J, K, A, 2, 3 -> 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.");
	printf("\n\n 4 - Ao final de cada rodada, na vez do último jogador dizer quantas rodadas fará, este deve contabilizar a quantidade que cada um dos jogadores anteriormente disse que fariam, de modo que a quantidade que este último jogador fará somada ao somatório dos demais jogadores, não pode ser exatamente a mesma quantidade de cartas daquela rodada.\n");
	printf("\n Digite o numero de jogadores: ");
	fprintf(r,"\n REGRAS: \n\n 1 - Numero minimo de jogadores 2, numero maximo de jogadores 8.\n 2 - A sequencia dos nipes sera representada por numeros: Paus (4), Copas (3), Espadas (2), Ouro (1).\n 3 - As cartas serão representadas por numeros em ordem crescente de força: 4, 5, 6, 7, Q, J, K, A, 2, 3 -> 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.");
	fprintf(r,"\n 4 - Ao final de cada rodada, na vez do último jogador dizer quantas rodadas fará, este deve contabilizar a quantidade que cada um dos jogadores anteriormente disse que fariam, de modo que a quantidade que este último jogador fará somada ao somatório dos demais jogadores, não pode ser exatamente a mesma quantidade de cartas daquela rodada.\n");
	fprintf(r,"\n Digite o numero de jogadores: ");
	scanf("%d", &n_jo);
	fprintf(r,"%d", n_jo);
	while(n_jo<2||n_jo>8){ 						//teste para o numero de jogadores.
		
		printf("\n Numero invalido.");
		printf("\n Digite o numero de jogadores: ");
		
		scanf("%d", &n_jo);
		
	}
	shuffle(t); 								//embaralho das cartas por meio da função shuffle e do ponteiro do baralho.
		fflush(stdin);
		aux_jogada = (int*)malloc(n_jo*sizeof(int)); 
												//Atribuição do indice para o ponteiro auxiliar por meio da alocação de memoria.
		jogadores = (jogador*)malloc(n_jo*sizeof(jogador));
												//Atribuição do indice para o ponteiro dos jogadores por meio da alocação de memoria.
		
		rodada = 5;
		for(n=0;n<n_jo;n++){
			jogadores[n].vidas = 5;//Definindo o numero de vidas de cada jogador
		}
			for(partida = 0; partida<10;partida++){ 
												// Começo do jogo.
				rodada = 5;
				auxj1 = 0;
				shuffle(t);
				if(partida<5){
					rodada = rodada - partida;
					aux = rodada;
				}
				if(partida>=5){
					rodada = partida - rodada+1;
					aux = rodada;
				}
				for(m=0;m<n_jo;m++){ 
					printf("\n\n Cartas do Jogador %d: ", m+1);
					fprintf(r,"\n\n Cartas do Jogador %d: ", m+1);
					jogadores[m].rodadas_vencidas = 0;
					
					aux = m*rodada;
					for(n=0;n<rodada;n++){
												// Distribuição das cartas embaralhadas para os jogadores, por meio do numero de rodadas.
						jogadores[m].mao[n].numero = t->cartao[aux].numero;
						jogadores[m].mao[n].nipe = t->cartao[aux].nipe;
						jogadores[m].mao[n].zap= t->cartao[aux].zap;
						printf("\n Numero: %d, Nipe: %d, Zap: %d", jogadores[m].mao[n].numero+1, jogadores[m].mao[n].nipe, jogadores[m].mao[n].zap);
						fprintf(r,"\n Numero: %d, Nipe: %d, Zap: %d", jogadores[m].mao[n].numero+1, jogadores[m].mao[n].nipe, jogadores[m].mao[n].zap);
						aux++;
					}
					printf("\n\n Jogador numero %d digite quantas rodadas serão vencidas: ",m+1); 
					fprintf(r,"\n\n Jogador numero %d digite quantas rodadas serão vencidas: ",m+1);
												//Atribuição do numero de rodadas vencidas fornecida pelo jogador.
					scanf("%d", &jogadores[m].rodadas);
					fprintf(r,"%d",jogadores[m].rodadas);
					auxj1+=jogadores[m].rodadas;
					while(jogadores[m].rodadas > rodada){
												//teste de validade da atribuição
							printf("\n Numero invalido.\n Numero maior que a quantidade de cartas na rodada.");
							printf("\n Jogador numero %d digite quantas rodadas serão vencidas: ",m+1);
							scanf("%d", &jogadores[m].rodadas);
					}
					if(m==n_jo-1){
						while(auxj1>=n_jo*rodada){
												//teste de validade da atribuição
							auxj1-=jogadores[m].rodadas;
							printf("\n Numero invalido (Regra 4).\n");
							printf("\n Jogador numero %d digite quantas rodadas serão vencidas: ",m+1);
							scanf("%d", &jogadores[m].rodadas);
							auxj1+=jogadores[m].rodadas;
						}
					}
					printf("\n ");
					system("pause");
				}
		printf("\n\n\n PARTIDA %d \n\n\n", partida+1);
		fprintf(r,"\n\n\n PARTIDA %d \n\n\n", partida+1);
		while(rodada>0){ 						// Seleção das cartas pelos jogadores para sua jogada em um looping para as rodadas seguintes.
			for(n=0;n<n_jo;n++){
				printf("\n\n Jogador %d selecione uma carta: ", n+1);
				fprintf(r,"\n\n Jogador %d selecione uma carta: ", n+1);
				for(m=0;m<rodada;m++){
					printf("\n Carta %d: Numero %d Nipe: %d, Zap: %d ", m+1,jogadores[n].mao[m].numero + 1,jogadores[n].mao[m].nipe, jogadores[n].mao[m].zap);
					fprintf(r,"\n Carta %d: Numero %d Nipe: %d, Zap: %d ", m+1,jogadores[n].mao[m].numero + 1,jogadores[n].mao[m].nipe, jogadores[n].mao[m].zap);	
				}
				scanf("%d", &aux_jogada[n]);
				fprintf(r,"%d", aux_jogada[n]);
				while(aux_jogada[n] > rodada || aux_jogada[n] < 0){
												// Laço de repetição para verificar se a carta existe.
					printf("\n Carta invalida. \n Selecione uma das cartas acima.");
					scanf("%d", &aux_jogada[n]);
				}
												// Comparação entre as cartas jogadas para ver a maior.
				if(n==0){
					auxj1 = n;
					auxj2 = aux_jogada[n]-1;
				}
				if(n>=1)
				if( maior(jogadores[n].mao[aux_jogada[n]-1], jogadores[auxj1].mao[auxj2]) == 1){
					auxj1 = n;
					auxj2 = aux_jogada[n]-1;
				}
				
			}
			printf("\n\n Jogador %d venceu a rodada. ", auxj1+1);
			fprintf(r,"\n\n Jogador %d venceu a rodada. ", auxj1+1);
												// Demostrar o jogador vencedor da rodada por meio da comparação anterior.
			jogadores[auxj1].rodadas_vencidas++;
			for(n=0;n<n_jo;n++){
												//Exclusão das cartas já jogadas pelos jogadores.
				jogadores[n].mao[aux_jogada[n]-1].numero = -1;
				
					if(jogadores[n].mao[aux_jogada[n]].numero!= -1){
					
						for(m=aux_jogada[n];m<rodada;m++){
							
								jogadores[n].mao[m-1].numero = jogadores[n].mao[m].numero;
								jogadores[n].mao[m-1].nipe = jogadores[n].mao[m].nipe;
								jogadores[n].mao[m-1].zap = jogadores[n].mao[m].zap;
						}	
					
					}
			}
			
			
				

		rodada--; 								// Decremento da variavel para mudar tanto a rodada quanto a quantidada de cartas que serão distribuidas.
	}
	printf("\n Vidas dos jogadores: ");
	fprintf(r,"\n Vidas dos jogadores: ");
												//Testes para contabilizar a vida dos jogadores.
	for(n=0;n<n_jo;n++){
			if(jogadores[n].rodadas_vencidas != jogadores[n].rodadas){
				jogadores[n].vidas--;
			}
			if(jogadores[n].rodadas_vencidas == aux && jogadores[n].rodadas != aux ){
				jogadores[n].vidas--;
			}
			printf("\n\n Jogador %d: %d \n", n+1,jogadores[n].vidas);
			fprintf(r,"\n\n Jogador %d: %d \n", n+1,jogadores[n].vidas);
			if(jogadores[n].vidas== 0){
			n_jo--; 							// Decremento do numero de jogadores.
			printf("\n Jogador %d foi eliminado.", n+1);
			fprintf(r,"\n Jogador %d foi eliminado.", n+1);
			if(n_jo<2){
				printf("\n Jogador %d foi o ganhador.", n);
				fprintf(r,"\n Jogador %d foi o ganhador.", n);
				return 0; 						// Termino do jogo quando só restar um jogador com vidas.
			}
		}
		}
		
		
}
	fclose(r); // Fechamento do arquivo para gravação.
	return 0;
	
}
