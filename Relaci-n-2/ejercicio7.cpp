/*Implementa una función insertar(P, pos, x) que inserte un elemento en una pila P en la posición pos.
La pila debe quedar como estaba antes de insertar el elemento (salvo por el nuevo elemento)*/

#include <stack>
#include <string>
#include <iostream>
using namespace std;
template <typename T>;
void insertar(stack<T> P, int pos, T x){
  int tope=P.size();//la guardamos ahora porque va a variar
  if(pos <= tope){ //está dentro del espacio (el igual es para insertarlo al final de la pila)
  stack<T> aux;
  bool insertado=false;

  for(int i=0;i <= tope && !insertado;i++){
    if(i < pos && !(i == pos)){  //no ha insertado el elemento,guarda los otros en la aux;
      aux.push(P.top());
      P.pop();
    }
    else //inserta el elemento
        P.push(x);
    } //fin del for
  for(int j=0 ;j< aux.empty();j++){  //metemos los que había en aux
      P.push(aux.top());
      aux.pop();
    }

  }
}
