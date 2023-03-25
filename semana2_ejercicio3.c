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
	printf("lista de elementos 2"); 
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
	for(i=0;i<maxelem;i++){ 
		if(elementoscombi[i]<= -1){
			printf("*****************************\n");
		}else{
			printf("El elemento %d tine %d elementos\n",i, elementoscombi[i]); 
		}
	} 
}

void printadd(int add[N], int maxelem){ 
	int i=0; 
 
	printf("\n--------------------\n");
	printf("lista de elementos actualizada"); 
	printf("\n--------------------\n\n"); 
	for(i=0;i<maxelem;i++){ 
		printf("El elemento %d tine %d elementos\n",i, add[i]); 
	} 
} 
  
  
  
int main(){ 
 
	int elementos[N]; 
	int i, maxelem; 
	int opcion; 
	int eleccion; 
	  
	
	printf("Indique el numero del elementos maximo o 0 para usar el maximo de 100:"); 
	scanf("%d",&maxelem); 
 
	while(maxelem == 0){
		printf("Indique un valor valido de elementos maximos o 0 para usar el maximo de 100:"); 
		scanf("%d",&maxelem);
	}
	if(maxelem == 0){
    maxelem = N;
	}
 
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
		while(elementos[i]<=-1){
    		printf("Indique una cantidad valida del item %d:",i); 
			scanf("%d",&elementos[i]);
		}
		printf("Indique el maximo de este elemento:"); 
		scanf("%d",&elementosmax[i]); 
		while(elementosmax[i] <= -1){
			printf("Indique un valor maximo valido de este elemento:"); 
			scanf("%d",&elementosmax[i]); 
		}
		printf("\n"); 
	}  
	validar(elementos, elementosmax, maxelem); 
	printelementos(elementos, maxelem); 

	printf("\nSegundo inventario\n"); 
	
	for(i=0;i<maxelem;i++){ 

		printf("Indique la cantidad del item %d:",i); 
		scanf("%d",&elementos2[i]); 
 
		while(elementos2[i] <= -1){
     		printf("Indique una cantidad valida del item %d:",i); 
			scanf("%d",&elementos2[i]); 
		}
	} 

	validar2(elementos2, elementosmax, maxelem); 
	printelementos2(elementos2, maxelem); 
	
	//combinarInv(elementos, elementos2, elementosmax, maxelem, elementoscombi); 
	int aux,aux2;
	 
	for(i=0; i < maxelem; i++){ 
		aux	= elementos[i]; 
		//printf("---------------%d\n",aux); 
		aux2=elementos2[i]; 
 		//printf("---------------%d\n",aux2); 
		elementoscombi[i] = aux + aux2; 
	} 
	 
	for(i=0; i < maxelem; i++){ 
		if(elementoscombi[i] > elementosmax[i]){
			elementoscombi[i]=elementosmax[i];
		}
	} 
 
	printelementoscombi(elementoscombi, maxelem);
	
	int k=1;
	while(k==1){
	
		printf("\n-----Opciones-----\n"); 
		printf("[1]Agregar\n[2]Eliminar\n[3]Fin\n"); 
		printf("Que accion va a realizar:"); 
		scanf("%d",&opcion); 
		
		if(opcion==3){
			k=0;
		}
		
		if(opcion == 1){ 
		 
			printf("A cual elemento deseea agregar:"); 
			scanf("%d",&eleccion); 
			
			while(eleccion < 0 || eleccion > maxelem ){ 
				printf("ingrese un valor valido\n"); 
				printf("A cual elemento deseea agregar:"); 
				scanf("%d",&eleccion); 
			}
			
			if(eleccion == maxelem){
				maxelem=maxelem+1;
				int add[maxelem];
				
				for(i=0;i<maxelem;i++){
					int au;
					au=elementoscombi[i];
					add[i]=au;
					add[eleccion]=1;
					printadd(add, maxelem);
				}
			}
			else{
				
				int a;
				a = elementoscombi[eleccion]; 
				elementoscombi[eleccion] = a + 1; 
				
				if(elementoscombi[eleccion] > elementosmax[eleccion]){ 
					elementoscombi[eleccion] = elementosmax[eleccion]; 
				} 
				//debo agregar q se cree otro array +1 
				printelementosact(elementoscombi, maxelem);	
			
			}
		}
		
		if(opcion == 2){ 
			printf("A cual elemento deseea eliminar:"); 
			scanf("%d",&eleccion); 
			while(eleccion < 0 || eleccion >  maxelem){ 
				printf("Ingrese un valor valido\n"); 
				printf("A cual elemento deseea eliminar:"); 
				scanf("%d",&eleccion); 
			} 
			 
			int b; 
			b=elementoscombi[eleccion];
			elementoscombi[eleccion] = b-1;
			printelementosact(elementoscombi, maxelem);
		}
	}
	
	return 0; 
 }
