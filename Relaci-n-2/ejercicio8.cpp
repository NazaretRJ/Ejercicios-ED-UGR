/*Implementa una función insertar(Q, pos, x) que inserte un elemento en una cola Q en la posición pos.
La cola debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)*/

#include <queue>
#include<iostream>

using namespace std;
/* Vamos a suponer que cuenta la posicion desde 0 */
template <typename T>

void insertar(queue<T>&  Q,int pos,T x){
  int n=Q.size();
  if(pos == n){//quiere insertar al final
    Q.push(x);
  }
  else{
    queue<T> aux;
    for(int i=0;i <= n;i++){ //si no ponemos el igual,no mete el último
      if(i != pos){
        aux.push( Q.front() );
        Q.pop();
      }
      else
        aux.push(x);

    }
    while( !aux.empty() ){  //volvemos a meterla en la cola
      Q.push( aux.front() );
      aux.pop();
    }

  }
}

int main(){
  queue<int> cola;
  int tope,i,x;
  i=0;
  cout<<"tope:" <<endl;
  cin>>tope;
  while(i!=tope){
    cout<<"numero: "<<endl;
    cin>>x;
    cola.push(x);
    i++;
  }
   insertar(cola,3,4);
   cout<<"cola"<<endl;
   while( !cola.empty() ){
     cout<<cola.front()<<" "<<endl;
     cola.pop();
   }

 }
