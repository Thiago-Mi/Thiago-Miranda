#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>



void selecao(int a[], int n, int *contador_de_modificacoes, int *contador_de_chaves);

void insercao(int a[], int n,int *contador_de_modificacoes,int *contador_de_chaves);

void bubblesort(int a[], int n,int *contador_de_chaves,int *contador_de_movimentacoes);
void troca(int *a, int *b);

void mergesort(int a[], int n, int *contador_de_modificacoes, int *contador_de_chaves);
void intercala(int a[], int n, int *contador_de_modificacoes, int *contador_de_chaves);

void quicksort(int e, int d, int a[],int *contador_de_modificacoes, int *contador_de_chaves);
void partilhar(int e, int d, int *i, int *j, int a[],int *contador_de_modificacoes, int *contador_de_chaves);

//Inicio das funcoes de ordenaçao

int main(){
	setlocale(LC_ALL,"Portuguese");
    int i,m,contador_de_movimentacoes,contador_de_chaves; //variaveis auxiliares para loopings e catadores
    clock_t ti,tf; //variaveis que serao usadas para controlar o tempo gasto na ordenacao
    double tempo; //variavel que armazenara a diferenca entre o tempo final e o tempo inicial gasto na ordenacao
    srand(time(NULL)); // inicializa um gerador de numeros aleatorios que sera usado na funcao de embaralhar o arranjo
    int *v;  // ponteiro para o arranjo na memoria que sera alocado com tamanho n
	int q; // Usado para testar todas as possibilidades dos algorítmos
    int n; // variavel que conterá o tamanho do arranjo
    int t; // variavel que conterá o tipo de ordenação do arranjo
	
    printf(" \n Digite o tamanho do arranjo: ");
    scanf("%d", &n);
    v = (int *) malloc(n*sizeof(int)); //alocacao de memoria para o vetor

    int n_funcao; // Variavel para controlar qual funcao de ordenaçao será utilizada				 
    printf("\n Digite qual funcao de ordenação será utilizada(0-seleção, 1-inserção, 2- bubblesort, 3-mergesort, 4-quicksort): ");
	scanf("%d", &n_funcao);
	
	int exibir; //Variavel para controlar a exibição ou não do vetor antes e depois da ordenação.
	int n_exi;
	printf("\n Digite 1 para exibir o vetor antes e depois da ordenação, digite 0 para não exibir: ");
	scanf("%d", &exibir);
	
    for(t=1;t<5;t++){
	
		if(t==1){
	    	for (i=0; i<n; i++){
	        	v[i] = rand() % n + 1;	// armazenamento de numeros entre 1 e n no vetor.
	    	}
		}
		else if(t==2){
			for(i=0;i<n;i++){
				v[i]= i+1; // armazenamento de numeros ordenados entre 1 e n(incluso) no vetor;
			}
		}
		else if(t==3){
			for(i=0;i<n*0.9;i++){
				v[i]= i+1;	// Armazenamento de numeros ordenados entre 1 e 90%n(incluso) no vetor;
			}
			for(i;i<n;i++){
				v[i] = rand() % 10+i; // Aleatorizar os ultimos 10% dos numeros a serem armazenados
				if(v[i]>n){
					v[i] = rand() % 10+i; //Teste para redefinir valores maiores que n;
					i--;
				}
			}
		}
		else if(t==4){
			for(i=0;i<n;i++){
				v[i]  = n-i; // numeros ordenados inversamente entre n e 1;
			}
		}
		if(exibir==1){
			printf("\n Vetor antes da ordenação: ");
			for(n_exi = 0;n_exi<n;n_exi++){
				printf(" %d,",v[n_exi]);
			}
		}
        ti = clock();
        // Chamada da função de ordenação selecionada anteriormente;
		// Em cada função é passado dois valores por referencia, contador_de_movimentacoes e contador_de_chaves
		// Cada um deles é modificado diferentemente dependendo da função de ordenação implementada						 
        	if(n_funcao == 0){	
        		selecao(v,n,&contador_de_movimentacoes,&contador_de_chaves);
			}
			else if(n_funcao == 1){
				insercao(v,n,&contador_de_movimentacoes,&contador_de_chaves);

			}
			else if(n_funcao ==2){
				bubblesort(v,n,&contador_de_chaves,&contador_de_movimentacoes);
			}
			else if(n_funcao == 3){
				mergesort(v,n,&contador_de_movimentacoes,&contador_de_chaves);

			}
			else if(n_funcao == 4){
				quicksort(0,n-1,v,&contador_de_movimentacoes,&contador_de_chaves);
				}
				
				
				
		tf = clock();// Termina de medir tempo
		tempo = ( (double) (tf - ti) ) / CLOCKS_PER_SEC;
		if(exibir==1){
			printf("\n Vetor depois da ordenação: ");
			for(n_exi = 0;n_exi<n;n_exi++){
				printf(" %d,",v[n_exi]);
			}
		}
		printf("\n Tempo para ordenar %d elementos pelo metodo (%d): %f. \n", n, n_funcao, tempo);
        printf("\n Numero de modificações: %d \n Numero de chaves: %d. \n", contador_de_movimentacoes, contador_de_chaves);
	}

        //libera a memoria gasta
        free(v);
        return 0;
}


void troca(int *a, int *b){ // Função para trocar o valor de dois numeros entre suas variaveis.
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

	
void bubblesort(int a[], int n,int *contador_de_chaves,int *contador_de_movimentacoes){

	int i,j; // Variaveis de indice
	*contador_de_movimentacoes = 0; // Inicio dos valores de variaveis contadoras como 0 para começar a contagem
	*contador_de_chaves = 0;
	for(i=0;i<n-1;i++){
		
		for(j=i+1;j<n;j++){

			if(a[i]>a[j] && i!=j){ 	// Comparação entre dois valores sendo que o a[i] é fixo no comando de repetição j
									// assim a[j] é percorrido e comparado com o a[i] até que o if seja verdadeiro ou o j seja equivalente ao n
				troca(&a[i],&a[j]); // Troca das variaveis a[i] e a[j] ordenando-as
				i--;				// Decremento de i para ocorrer um novo teste com o numero ordenado anteriormente 
				*contador_de_chaves+=1; //soma das variaveis contadoras para qualificação do codigo
				*contador_de_movimentacoes+=4;
				break;           // Break para terminar o comando de repetição for de j e voltar no comando for de i
			}
			*contador_de_chaves+=1;//soma das variaveis contadoras para qualificação do codigo
		}
		*contador_de_chaves+=1;//soma das variaveis contadoras para qualificação do codigo
	}

}

void intercala(int a[], int n, int *contador_de_modificacoes, int *contador_de_chaves){
	int meio,i,j,k;
	int *aux = (int*)malloc(n*(sizeof(int)));
	meio =n/2;
	i=0;
	j=meio;
	k=0;
	while(j<n && i<meio){
		if(a[i]<a[j]){       // Testa se o numero intermediário com o numero a[i]
			aux[k]=a[i];
			i++;	
			*contador_de_modificacoes+=2;
			*contador_de_chaves+=1;//soma das variaveis contadoras para qualificação do codigo
		}
		else{
			
			aux[k]=a[j]; 
			j++;
			*contador_de_modificacoes+=2;
			*contador_de_chaves+=1;//soma das variaveis contadoras para qualificação do codigo
		}
		k++;
		*contador_de_modificacoes+=1;//soma das variaveis contadoras para qualificação do codigo
	}
		if(i==meio){
			*contador_de_chaves+=1;//soma das variaveis contadoras para qualificação do codigo
			while(j<n){
				aux[k]=a[j];
				k++;
				j++;
				*contador_de_chaves+=1;
				*contador_de_modificacoes+=3;//soma das variaveis contadoras para qualificação do codigo
			}
		}
		else{
			*contador_de_chaves+=1;
			while(i<meio){
				aux[k]=a[i];
				i++;
				k++;
				*contador_de_chaves+=1;
				*contador_de_modificacoes+=3;//soma das variaveis contadoras para qualificação do codigo
			}
			
		}
	int m;
	for(m=0;m<n;m++){
		a[m]=aux[m];
		*contador_de_modificacoes+=1;
		*contador_de_chaves+=1;
	}
	free(aux);
	
}

void mergesort(int a[], int n, int *contador_de_modificacoes, int *contador_de_chaves){
	
	int meio;
	*contador_de_chaves = 0;
	*contador_de_modificacoes = 0;
	if(n>1){
		meio=n/2;
		mergesort(a,meio,contador_de_modificacoes,contador_de_chaves);
		mergesort(a+meio,n-meio,contador_de_modificacoes,contador_de_chaves);;
		intercala(a,n,contador_de_modificacoes,contador_de_chaves);
	}	
	
}

//quicksort
void partilhar(int e, int d, int *i, int *j, int a[],int *contador_de_modificacoes, int *contador_de_chaves){
	*i=e;
	*j=d;
	int x, temp;
	x=a[(*i+(*j))/2];
	*contador_de_modificacoes+=3;

		do{
			
			while(x>a[*i]){
				++(*i);
			*contador_de_modificacoes+=1;
			*contador_de_chaves+=1;
			}
			
			while(x<a[*j]){
				--(*j);
			*contador_de_modificacoes+=1;
			*contador_de_chaves+=1;
			}
				
			if(*i<=*j){
				temp=a[*i];
				a[*i]=a[*j];
				a[*j]=temp;
				++(*i);
				--(*j);
				*contador_de_modificacoes+=5;
				*contador_de_chaves+=1;
			}
		*contador_de_chaves+=1;		
		}while(*i<=*j);
}

void quicksort(int e, int d, int a[],int *contador_de_modificacoes, int *contador_de_chaves){
	int i;
	int j;
	*contador_de_modificacoes+=2;
	partilhar(e,d,&i,&j,a,contador_de_modificacoes,contador_de_chaves);
	if(e<j){
		quicksort(e,j,a,contador_de_modificacoes,contador_de_chaves);
		*contador_de_chaves+=1;
	}
	if(i<d){
		quicksort(i,d,a,contador_de_modificacoes,contador_de_chaves);
			*contador_de_chaves+=1;
	}
}




void insercao(int a[], int n,int *contador_de_modificacoes,int *contador_de_chaves){
	int i, j; // indices
	int x; // elemento

	*contador_de_modificacoes = 0;//inicio das variaveis contadoras para qualificação do codigo
	*contador_de_chaves = 0;
	
	for(i=1;i<n;i++){//para cada posição a partir de i=1
	
		x = a[i];
		j = i-1;
	    
	    
		while(x<a[j] && j>=0){//organiza o elemento na posição ordenada

			a[j+1]=a[j]; //Troca o elemento 1
			j--;
			*contador_de_modificacoes += 2;
			*contador_de_chaves+=1;
			}
			a[j+1] = x;
			*contador_de_modificacoes += 3;
			*contador_de_chaves+=1;
		}
		
;
	}
	

	
void selecao(int a[], int n, int *contador_de_modificacoes, int *contador_de_chaves){
	
	int i, j, min; // indices
	int x; // elemento 
	
	*contador_de_chaves = 0;//inicio das variaveis contadoras para qualificação do codigo
	*contador_de_modificacoes = 0;
	for(i=0;i<n-1;i++){
		// Procura o menor elemento entre i+1 e n e ele é armazenado em i
		min = i;
		*contador_de_modificacoes+=1;				//soma das variaveis contadoras para qualificação do codigo
		*contador_de_chaves+=1;						
		for(j=i+1;j<n;j++){
			
			if(a[j]< a[min]){
				min = j; // mínimo é o j
				*contador_de_modificacoes+=1;//soma das variaveis contadoras para qualificação do codigo
				*contador_de_chaves+=1;
			}
			*contador_de_chaves+=1;//soma das variaveis contadoras para qualificação do codigo
		}
		//troca a[i] com a[min]
		x= a[min];
		a[min] = a[i];
		a[i] = x;
		*contador_de_modificacoes += 3;//soma das variaveis contadoras para qualificação do codigo
			*contador_de_chaves+=1;
	}
}
