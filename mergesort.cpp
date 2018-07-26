#include<iostream>
using namespace std;

void Merge(int A[],int p, int centro,int r){     //esta funcion mezcla dos arrays I(izquierda) Y D(Derecha), p=0 y r=tamaño de A-1
    int i,j,k;
	int n1=centro-p+1;       //n1 is el tamaño del array I
    int n2=r-centro;               //n2 es el tamaño del array D
    int I[n1],D[n2];

	for(i=0;i<n1;i++){      //el array I toma los elementos a la izquierda del array A[](desde 0 hasta el centro)
		I[i]=A[p+i];
	}

	for(j=0;j<n2;j++){      //el array D toma los elementos a la derecha del array A(desde centro hasta el ultimo elemento)
		D[j]=A[centro+j+1];
	}

	i=0,j=0;

	for(k=p;i<n1&&j<n2;k++){  //mientras que los arrays I y D contengan variales por comparar se ejecutara el for
		if(I[i]<D[j])       //si el elemento del array I es menor que el de D entonces esste I[i] sube a A[k]
		{
			A[k]=I[i++];
		}
		else            //si no el D[j] sube a A[k]
		{
			A[k]=D[j++];
		}
	}
                //en caso de que los elementos a comparar de alguno de los dos arrays se terminen
	while(i<n1)          //si a I[] le quedan elementos entonces estos suben a el array A[]
	{
		A[k++]=I[i++];
	}

	while(j<n2)         //si a D[] le quedan elementos estos suben a A[]
	{
		A[k++]=D[j++];
	}
}

void MergeSort(int A[],int p,int r)    //divide el array A[] hasta que quede solo un elemento en el array
{
	int centro;         //centro para cada division del array

	if(p<r)         //se detiene cuando el tamaño es menor a 2(cuando no sepuede dividir mas)
	{
		centro=(p+r)/2;                 //determina el centro en cada division
		MergeSort(A,p,centro);               //mergesort parael lado izquierdo
		MergeSort(A,centro+1,r);             //mergesort para el lado derecho
		Merge(A,p,centro,r);                 //merge para mezclar ambos lados
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

	MergeSort(A,0,tam-1);

	for(int i=0;i<tam;i++){
		cout<<A[i]<<" ";
	}

	cout<<endl;
}
