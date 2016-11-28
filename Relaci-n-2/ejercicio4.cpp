/* Implementa el TDA pila usando dos colas. ¿Qué orden de eficiencia tienen las operaciones push y
pop?*/
#include <queue>
#include <stack>
#include<iostream>

using namespace std;

template <typename T>
/*Tenemos dos colas, una la auxiliar y otra la que emularia la pila */

class pila_de_colas{
private:
  queue<T> cola_auxiliar;
  queue<T> cola;
  void meter_datos_cola_auxiliar() {
    while( !cola.empty() ){
      cola_auxiliar.push( cola.front() );
      cola.pop();

    }
  }
  void meter_datos_cola(){
    while( !cola_auxiliar.empty() ){
      cola.push( cola_auxiliar.front() );
      cola_auxiliar.pop();
    }
  }
public:
  pila_de_colas<T>(){
  }

  pila_de_colas<T>(const pila_de_colas &y){
    cola=y.cola;
	
  }

  pila_de_colas operator=(pila_de_colas &y){
    if(this!=&y){
      cola=y.cola;
    }
    return *this;
  }

  void push(const T &v){ //O(n)
    meter_datos_cola_auxiliar();//O(n)
    cola_auxiliar.push(v);//O(1)
    meter_datos_cola();//O(n)
  }
  void pop(){ //O(1)
    cola.pop();
  }

  T top(){
    return  cola.front();
  }

  bool empty(){
    return cola.empty();
  }

  unsigned int size(){
    return cola.size();
  }

  bool  operator<(const stack<T> &b){
    bool menor=false;
    if( b.size() > cola.size() )
      menor=true;
    else{
      if( b.size() == cola.size() ){
          cola_auxiliar=cola;
          queue<T> aux=b;
          for(int i=0;i<cola_auxiliar.size() && !menor;i++){
            if(cola_auxiliar.front() < aux.top())
              menor=true;
            else{
              cola_auxiliar.pop();
              aux.pop();
            }
          }
      }
    }
  return menor;
  }

  bool operator==(const stack<T> &b){
    if(!(b<cola) && !(cola<b)) //si no tubiera el ! debería devolver false
      return true;
    else
      return false;
  }

};

int main(){
pila_de_colas<int> prueba,aux;
const int CENTINELA=-1;
int n;
while(n!=CENTINELA){
  cout<<"numero: \n";
  cin>>n;
  prueba.push(n);
}
aux=prueba;


if(aux==prueba)
	cout<<"iguales"<<"primer dato: "<<aux.top()<<endl;
else
	cout<<"diferentes"<<endl;

n=0;
while(n!=CENTINELA){
  cout<<"numero: \n";
  cin>>n;
  aux.push(n);
}

if(aux<prueba)
	cout<<"prueba menor"<<endl;
else{
	if(aux==prueba)
		cout<<"iguales"<<endl;
	else
		cout<<"prueba mayor"<<endl;

}

}
