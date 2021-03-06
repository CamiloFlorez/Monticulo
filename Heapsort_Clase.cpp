#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Left(int i);//funcion para determinar hijo izquierdo 
int Right(int i);//funcion para determinar hijo derecho

//EN ESTA SECCI�N DE CONSTRUYE LA CLASE
class Monticulo{
      private://atributos privados para que no puedan ser modificados por el usuario
              int *pA;  //puntero donde arranca mi vector
			  int LHeap, i;//longitud del vector y nodo
              
      public:
             Monticulo(int &_pA,int _LHeap); //clase 
             void Max_Heapify(int &_pA,int _LHeap,int _i);//m�todos
             void Build_Heap(int &_pA,int _LHeap);
             void Heapsort(int &_pA, int _LHeap);
            };
            
//EN ESTE PASO SE INICIALIZA LA CLASE             
Monticulo::Monticulo(int &_pA,int _LHeap){
	
                       pA=&_pA;
                       LHeap=_LHeap;
                       //i=_i;
                                };
                       
//SE PROCEDE A DEFINIR LOS M�TODOS INCLUIDOS EN LA CLASE MONT�CULO:


void Monticulo::Max_Heapify(int &_pA,int _LHeap,int _i){
	
   	int L,R,M,largest;
	L=Left(_i);
	R=Right(_i);
	
		
	if (L<=_LHeap-1 && *(&_pA+L)>*(&_pA+_i)){       
		largest=L;
		
	}
		else{
		
		largest=_i;
	}
		
					
	if (R<=_LHeap-1 && *(&_pA+R)>*(&_pA+largest)){
		largest=R;
	}
				
	
	if (largest!=_i){
		
		M=*(&_pA+_i);
		*(&_pA+_i)=*(&_pA+largest);
		*(&_pA+largest)=M ;
		
	Max_Heapify(_pA,_LHeap,largest);
		
	}
}

void Monticulo::Build_Heap(int &_pA,int _LHeap){
	int i;
	
	for (i=floor((_LHeap-1)/2);i>=0;--i){
		
		
		Max_Heapify(_pA,_LHeap,i);
	}
	
	
}     

void Monticulo::Heapsort(int &_pA,int _LHeap){
	
	int i;
	int M;
	int LH;
	LH=_LHeap;
	Build_Heap(_pA,_LHeap);
	for (i=_LHeap-1;i>=1;--i){
		M=*(&_pA);
		*(&_pA)=*(&_pA+i);
		*(&_pA+i)=M;
		LH=LH-1;
		Max_Heapify(_pA,LH,0);
	}

}





int main(){
//DECLARACI�N DE LAS VARIABLES GLOBALES	
	
	int i;
  	int LHeap;
  	int Padre;
  	int Izq;
  	int Der;
  	int *pA;
  	
    printf("Ingrese el tamano del vector a ordenar \n");
	scanf("%d",&LHeap);
	
	int A[LHeap];
	
   	printf ("Ingrese el arreglo a ordenar: \n");
   	
  	for (i=0;i<LHeap;i++){
  		printf("A(%d)=\n",i);
  		scanf("%d",&A[i]);
  		
	  }
	  
	  	  
	  pA=&A[0];
	  
	  Monticulo R=Monticulo(*pA,LHeap);//AQU� SE CREA EL OBJETO R DE LA CLASE MONTICULO
	  
	  R.Heapsort(*pA,LHeap);//AQU� SE APLICA EL M�TODO Heapsort AL OBJETO R
	
	printf ("El Monticulo es igual a \n");
   	
  	for (i=0;i<LHeap;i++){
  		printf("A(%d)=%d \n",i,A[i]);
  		
	  }
	
	
	
	
	
}




int Left(int i){
	int k;
	
	k=2*i+1;
	
	return k;
}
	

int Right(int i){
	int k;
	
	k=2*i+2;
	
	return k;
}
 
