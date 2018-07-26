#include <iostream>
using namespace std;
int particion(int A[], int inicio, int fin){    //
    int temp;
    int pivot = A[fin];     //el pivote sera el ultimo elemento del array
    int pIndice = inicio;   //el indice del pivote inicialmente sera el primer elemento, que futuramente quedara despues de los menores que pivote
    for(int i = inicio; i<fin; i++){
        if(A[i]<=pivot){    //si A[i] < que el pivote ->intercambiarde lugar al elemento menor que el pivote con pIndice
            temp = A[i];
            A[i] = A[pIndice];
            A[pIndice] = temp;
            pIndice++;      //cuando se intercambia elelemento menor a la derecha, el indice de PIndice se incrementa

        }
    }       /*cuando el buble termina los elementos menores que el pivote entan a la
    izquierda de pIndice y solo queda intercambiar a pIndice y pivote */
    temp = A[pIndice];
    A[pIndice] = A[fin];
    A[fin] = temp;

    return pIndice;     //retorna el indice del pivote
}
void QuickSort(int A[], int inicio,int fin){
    if(inicio<fin){     //mientras elindice inicial sea < que el final
        int pIndice = particion(A, inicio, fin);    //la particion devuelve indice del pivote(pIndice)
        QuickSort(A, inicio, pIndice-1);    //division para los elementos menores que elpivote(izquierda)
        QuickSort(A, pIndice+1,fin);        //division para los mayores que el pivote(derecha)
    }
}
int main(){
    int tam;

	cout<<"Ingrese la cantidad de elementos :";
    cin>>tam;

	int A[tam];

	cout<<"Ingrese los lementos del array :";
    for(int i=0;i<tam;i++){
		cin>>A[i];
	}

	QuickSort(A,0,tam-1);

	for(int i=0;i<tam;i++){
		cout<<A[i]<<" ";
	}

	cout<<endl;
}
