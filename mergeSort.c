#include <stdio.h>
#define TAMANHO 15

void printVetor(int v[],int inicio,int fim,int nivel,char* function,int flagprint){
	if(flagprint<1)return;

	printf("%s",function);
	int i;
	for(i=0;i<=nivel;i++){
		printf("    ");
	}
	for(i=inicio;i<=fim;i++){
		printf("[%d] ",v[i]);
	}
	printf("\n");
}


int* merge(int v[],int inicio,int meio,int fim,int nivel,int flagprint){
	printVetor(v,inicio,fim,nivel,"mergeini",flagprint);
	int  u[10];
	int a = inicio;
	int b = meio+1;
	int i;
	for(i=inicio;a<=meio && b<=fim;i++){
		if(v[a]<=v[b]){
			u[i]=v[a];a++;
		}else{
			u[i]=v[b];b++;
		}
		printVetor(u,inicio,i,nivel,"merge1  ",flagprint);
	}

	while(a<=meio){
		u[i++]=v[a++];
		printVetor(u,inicio,i-1,nivel,"merge2  ",flagprint);
	}
	while(b<=fim){
		u[i]=v[b];i++;b++;
		printVetor(u,inicio,i-1,nivel,"merge3  ",flagprint);
	}
	for(i=inicio;i<=fim;i++)
		v[i]=u[i];
	printVetor(v,inicio,fim,nivel,"mergefim",flagprint);

	return v;
}

int* mergeSort(int v[], int inicio,int fim,int nivel,int flagprint){
	printVetor(v,inicio,fim,nivel,"sortini ",flagprint);
	int meio=(inicio+fim)/2;
	if(inicio<fim){
		mergeSort(v,inicio,meio,nivel+1,flagprint);
		mergeSort(v,meio+1,fim,nivel+1,flagprint);
		merge(v,inicio,meio,fim,nivel+1,flagprint);
	}
	printVetor(v,inicio,fim,nivel,"sortfim ",flagprint);

} 


int indexOf(int v[],int inicio,int fim,int valor,int nivel,int flagprint){//BuscaBinaria
	if(flagprint)printf("Entrada IndexOf inicio/fim = %d/%d\n",inicio,fim);
	if(inicio>fim)return -1;
	printVetor(v,inicio,fim,nivel,"indexOfIni",flagprint);
	int meio=(inicio+fim)/2;	
if(flagprint)printf("inicio=%d | fim=%d | meio v[%d]=%d\n",inicio,fim,meio,v[meio],flagprint);
	if(v[meio]==valor)return meio;
	if(valor<v[meio])
		return indexOf(v,inicio,meio,valor,nivel+1,flagprint);
	return indexOf(v,meio+1,fim,valor,nivel+1,flagprint);

}

void mainBuscaBinaria(int v[],int flagprint){
	int valor;
	printVetor(v,0,TAMANHO-1,0,"mainini ",1);
	printf("Digite o valor cujo indice deseja descobrir: ");
	scanf("%d",&valor);
	printf("indexOf(%d)=%d\n",valor,indexOf(v,0,TAMANHO-1,valor,0,flagprint));
}
void mainMergeSort(int v[],int flagprint){
	printVetor(v,0,TAMANHO-1,0,"mainini ",1);
	mergeSort(v,0,TAMANHO-1,1,flagprint);
	printVetor(v,0,TAMANHO-1,0,"mainfim ",1);
}


void main(){
	int v[16]={5,3,1,7,6,8,2,4,0,2,8,12,6,9,11,16};
	mainMergeSort(v,0);
	mainBuscaBinaria(v,1);
}
