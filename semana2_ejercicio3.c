#include<stdio.h>
#define N 100

void printelementos(int elementos[N], int maxelem){
	int i=0;
	
	printf("\n--------------------\n");
	printf("lista de elementos");
	printf("\n--------------------\n\n");
	
	for(i=0; i<maxelem; i++){
		
		printf("El elemento %d tine %d elementos\n",i, elementos[i]);
	}
}
void printelementos2(int elementos2[N], int maxelem){
	int i=0;
	
	printf("\n--------------------\n");
	printf("lista de elementos 2");
	printf("\n--------------------\n\n");
	
	for(i=0; i<maxelem; i++){
		
		printf("El elemento %d tine %d elementos\n",i, elementos2[i]);
	}
}

void validar(int elementos[N], int elementosmax[N], int maxelem){
	int i;
	for(i=0; i < maxelem; i++){
		if(elementos[i] > elementosmax[i]){
			elementos[i]=elementosmax[i];
			
		}	
	}
}

void validar2(int elementos2[N], int elementosmax[N], int maxelem){
	int i;
	for(i=0; i < maxelem; i++){
		if(elementos2[i] > elementosmax[i]){
			elementos2[i] = elementosmax[i];
		}	
	}
}

void combinarInv(int elementos[N], int elementos2[N], int elementosmax[N], int maxelem, int elementoscombi[N] ){
	int i, aux, aux2;
	
	for(i=0; i < maxelem; i++){
		elementos[i] = aux;
		elementos2[i] = aux2;
		elementoscombi[i] = aux + aux2 ;
	}
	
	for(i=0; i < maxelem; i++){
		if(elementoscombi[i] > elementosmax[i]){
			
			elementoscombi[i]=elementosmax[i];	
		}	
	}
	
}

void printelementoscombi(int elementoscombi[N], int maxelem){
	int i=0;
	
	printf("\n--------------------\n");
	printf("lista de inventarios combinados");
	printf("\n--------------------\n\n");
	
	for(i=0; i<maxelem; i++){
		
		printf("El elemento %d tine %d elementos\n",i, elementoscombi[i]);
	}
}

void printelementosact(int elementoscombi[N], int maxelem){
	int i=0;
	
	printf("\n--------------------\n");
	printf("lista de elementos actualizada");
	printf("\n--------------------\n\n");
	
	for(i=0; i<maxelem; i++){
		
		printf("El elemento %d tine %d elementos\n",i, elementoscombi[i]);
	}
}



int main(){
	
	int elementos[N];
	int i, maxelem;
	int opcion;
	int eleccion;

	
	printf("Indique el numero del elementos maximo: o 0 para usar el maximo de 100:");
	scanf("%d",&maxelem);
	
	int elementos2[maxelem], elementosmax[maxelem], elementoscombi[maxelem];
	
	
	for(i=0;i<maxelem;i++){
		
        elementos[i] = 0;
        elementos2[i] = 0;
        elementosmax[i] = 0;
        elementoscombi[i]=0;
	}
	
	for(i=0;i<maxelem;i++){
		
		printf("Indique la cantidad del item %d:",i);
		scanf("%d",&elementos[i]);
		printf("Indique el maximo de este elemento:");
		scanf("%d",&elementosmax[i]);
		printf("\n");
	}
	
	validar(elementos, elementosmax, maxelem);
	
	printelementos(elementos, maxelem);
	
	printf("\nSegundo inventario\n");
	
	for(i=0;i<maxelem;i++){
		
		printf("Indique la cantidad del item %d:",i);
		scanf("%d",&elementos2[i]);
	}
	
	validar2(elementos2, elementosmax, maxelem);
	printelementos2(elementos2, maxelem);
		
	//combinarInv(elementos, elementos2, elementosmax, maxelem, elementoscombi);
	int aux,aux2;
	for(i=0; i < maxelem; i++){
		aux = elementos[i];
		//printf("---------------%d\n",aux);
		aux2 = elementos2[i];
		//printf("---------------%d\n",aux2);
		elementoscombi[i] = aux + aux2 ;
	}
	
	for(i=0; i < maxelem; i++){
		if(elementoscombi[i] > elementosmax[i]){
			
			elementoscombi[i]=elementosmax[i];	
		}	
	}
	
	printelementoscombi(elementoscombi, maxelem);
	
	printf("\n-----Opciones-----\n");
	printf("[1]Agregar\n[2]Eliminar\n");
	printf("Que accion va a realizar:");
	scanf("%d",&opcion);
	
	if(opcion == 1){
		
		printf("A cual elemento deseea agregar:");
		scanf("%d",&eleccion);
		while(eleccion <= 0 && eleccion >= maxelem){
			printf("ingrese un valor valido\n");
			printf("A cual elemento deseea agregar:");
			scanf("%d",&eleccion);
		}
		
		int a;
		a = elementoscombi[eleccion];
		elementoscombi[eleccion] = a + 1;
		
		if(elementoscombi[eleccion] > elementosmax[eleccion]){
			elementoscombi[eleccion] = elementosmax[eleccion];
		}
		//debo agregar q se cree otro array +1 
		printelementosact(elementoscombi, maxelem);
	}
	
	if(opcion == 2){
		
		printf("A cual elemento deseea eliminar:");
		scanf("%d",&eleccion);
		while(eleccion <= 0 && eleccion >= maxelem){
			printf("ingrese un valor valido\n");
			printf("A cual elemento deseea eliminar:");
			scanf("%d",&eleccion);
		}
		
		int b;
		b = elementoscombi[eleccion];
		elementoscombi[eleccion] = b - 1;
		printelementosact(elementoscombi, maxelem);
	}
	
	
	return 0;
}
