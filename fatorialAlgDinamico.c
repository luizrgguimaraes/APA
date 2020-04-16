#include <stdlib.h>
#include <stdio.h>

#define MAX 100

int fat[MAX];
int i =0;
void inicializarfat(){
	for(int i=0;i<MAX;i++){
		fat[i]=0;
	}
}

long long int fatorial(long long int n){
	if(n==0)return 1;
	if(fat[n]>0)return fat[n];
	i++;
	return fat[n] = n*fatorial(n-1);
}



int main(int argc, char *argv[]){
	//int x = atoi(argv[1]);
	int x;
	inicializarfat();
	int ret;
	while(1){
		i=0;
		printf("Digite um numero maior que 0: ");
		scanf("%d",&x);
		if(!x)break;
		ret=fatorial(x);
		printf("Fatorial de %d = %llu (%d iteracoes)\n",x,ret,i);
	}
	return 0;
}
