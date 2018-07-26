#include <iostream>
using namespace std;
int main(){
    int moneda[5]={1, 2, 5, 18, 20};
    int aux;
    for(int i=0; i<5; i++){     //el array se ordena de mayor a menor
        for(int j=0; j<5; j++){
            if(moneda[j]<moneda[j+1]){
                aux = moneda[j];
                moneda[j] = moneda[j+1];
                moneda[j+1] = aux;
            }
        }
    }
    int entregar=36;

    int m20=0, m18=0, m5=0, m2=0, m1=0;     //cantidad de monedas inicializadas a 0
                        //como 20 y 18 son numeros muy cercanos se aplica un if a m20 y m18 para ver cual de los dos es mejor usar
    if(entregar>=moneda[0]){
        m20 = entregar/moneda[0];   //cantidad de monedas de 20 que se pueden usar
        if(m20<=1){     //si la cantidad es <=1 entonces ya no se usan monedas de 20
            m20 = 0;
        }else{
            entregar = entregar%moneda[0];  // si la cantidad es > a 1 entonces lo nuevo que se tiene que entregar es el resto
        }
    }
    if(entregar>=moneda[1]){    //moneda de18
        m18 = entregar/moneda[1];   //si la cantidad es <=1 entonces ya no se usan monedas de 18
        if(m18<=1){
            m18 = 0;
        }else{
            entregar = entregar%moneda[1];
        }
    }
    if(entregar>=moneda[2]){    //moneda de 5
        m5 = entregar/moneda[2];
        entregar= entregar%moneda[2];
    }
    if(entregar>=moneda[3]){    //moneda de 2
        m2 = entregar/moneda[3];
        entregar= entregar%moneda[3];
    }
    if(entregar>=moneda[4]){    //moneda de 1
        m1 = entregar/moneda[4];
        entregar= entregar%moneda[4];
    }
    //imprime la cantidad de monedas usadas
    cout<<"Monedas de "<<moneda[0]<<" : "<<m20<<endl;
    cout<<"Monedas de "<<moneda[1]<<" : "<<m18<<endl;
    cout<<"Monedas de "<<moneda[2]<<" : "<<m5<<endl;
    cout<<"Monedas de "<<moneda[3]<<" : "<<m2<<endl;
    cout<<"Monedas de "<<moneda[4]<<" : "<<m1<<endl;


}
