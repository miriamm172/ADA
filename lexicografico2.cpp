#include<iostream>
#include <string.h>
using namespace std;
int main(){
    int n = 5;
    char e[] = {'a','b','a','a','b'}, aux, mayor;
    char s[n];  //array para guardar el resultado
    for(int i=0; i<5; i++){ //selecciona el mayor elemento del array e
        if(e[i]>mayor){
            mayor = e[i];
        }
    }
    s[0] = e[0];    //el primer elemento de e sera el primero de s

    for(int i=1;i<n;i++){   //recorre el array e desde el segundo elemento
            if(e[i]>=mayor){ //si es <= que el mayor(B) se coloca adelante por lo tanto el array se recorre una posicion a la derecha
                aux = e[i]; //un aux toma el valor
                for(int j=n-1; j>=0; j--){  //el array se recorre
                    s[j] = s[j-1];
                }
                s[0] = aux; //el nuevo elemento en la posicion 0 es aux
            }
            else{   //si es menor que el mayor entonces el elemeto se coloca al final
                s[i] = e[i];
            }
    }
    for(int i= 0; i<n; i++){    //imprime el array resultante
        cout<<s[i]<<"  ";
    }
}
