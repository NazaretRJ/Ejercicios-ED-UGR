/* Implementa un TDA cola usando como representación dos pilas. */

/* Solución: una pila serála intermedia, es decir para que al sacar los datos
diera en el orden que debería,tenemos que volcarlos en un recipiente,
este será la pila intermedia */

#include<stack>
#include <iostream>

using namespace std;
template <typename T>
class Cola_de_pilas{
private:

  stack<T> pila;
  stack<T> pila_intermedia;

  void meter_datos_pila_intermedia() {
    while( !pila.empty() ){
      pila_intermedia.push( pila.top() );
      pila.pop();

    }
  }
  void meter_datos_pila(){
    while( !pila_intermedia.empty() ){
      pila.push( pila_intermedia.top() );
      pila_intermedia.pop();
    }
  }

public:
  Cola_de_pilas<T>(){}

  Cola_de_pilas<T>(Cola_de_pilas<T> & y){
    pila=y.pila;
  }

  Cola_de_pilas<T> operator=(const Cola_de_pilas &y){
    if(this != &y ){
      pila=y.pila;
      pila_intermedia=y.pila_intermedia;
    }
    return *this;
  }

  void push(const  T &v ){
    //metemos los datos antiguos en la pila intermedia
    meter_datos_pila_intermedia();
    //metemos el dato
    pila_intermedia.push(v);
    //volvemos a volcar los datos
    meter_datos_pila();
  }
  void pop(){
    pila.pop();
  }
  T front(){
      return pila.front();
  }
  T back(){
    T dato;
    meter_datos_pila_intermedia();
    //sacamos el dato
    dato=pila_intermedia.front();
    //volvemos a volcar los datos
    meter_datos_pila();
  }
  bool empty(){
    return pila.empty();
  }
  int size(){
    return pila.size();
  }
  bool operator<(const queue<T> &orig){
    bool menor=false;
    if( orig.size() > pila.size() )
      menor=true;
    else{
      if( aux.size() == pila_intermedia.size() ){
        queue<T> aux=orig;
        pila_intermedia=pila;
        for(int i=0;i<pila_intermedia.size() && !menor ;i++){
          if( pila_intermedia.top() < orig.front() )
            menor=true;
          else{
            aux.pop();
            pila_intermedia.pop();
          }
        }
      }
    }
  }
  bool operator==(const queue<T> &orig){
    if( !(pila<orig.pila) && !(orig.pila<pila ) ) //implica que son iguales
      return true;
    else
      return false;
  }
};


int main(){
  //vamos a poner a prueba los métodos
Cola_de_pilas<int> prueba,prueba_iguales,prueba_no_iguales;
const int CENTINELA=-1;
int n;
while(n!=CENTINELA){
  cout<<"numero: \n";
  cin>>n;
  prueba.push(n);
}


prueba_iguales=prueba;

if(prueba==prueba_iguales)
  cout<<"Son iguales\n"<<endl;
else
  cout<<"Son diferentes\n"<<endl;

n=0;
while(n!=CENTINELA){
  cout<<"numero: \n";
  cin>>n;
  prueba_no_iguales.push(n);
}

if(prueba==prueba_no_iguales)
  cout<<"la segunda vez son iguales\n"<<endl;
else
  cout<<"La segunda vez son diferentes\n"<<endl;

if(prueba<prueba_no_iguales)
  cout << "prueba es menor\n" << endl;
else
  cout << "prueba es mayor \n " << endl;


}
