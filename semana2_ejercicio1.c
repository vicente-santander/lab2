#include<stdio.h>
#define N 100

void printelementos(int elementos[N], int maxelem){
	int i=0;
	
	printf("\nlista de elementos\n");
	
	for(i=0; i<maxelem; i++){
		
		printf("El elemento %d tine %d elementos\n",i, elementos[i]);
	}
}

int main(){
	
	int elementos[N];
	int i, maxelem; 

	
	printf("Indique el numero del elementos maximo:");
	scanf("%d",&maxelem);
	
	for(i=0;i<maxelem;i++){
		
        elementos[i] = 0;
	}
	
	for(i=0;i<maxelem;i++){
		
		printf("Indique la cantidad del item %d:",i);
		scanf("%d",&elementos[i]);
	}

	
	printelementos(elementos, maxelem);
	
	
		
	return 0;
}
