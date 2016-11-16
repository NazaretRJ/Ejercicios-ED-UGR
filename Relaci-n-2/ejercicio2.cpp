/*Implementa un función para determinar si una expresión contenida en un string tiene una configuración de paréntesis correcta.
Debe tener un orden lineal.*/
#include<string>
#include<stack>
#include <iostream>
using namespace std;

bool parentesis_bien(const string &s){
  stack<char> pila;
  bool bien=true;
  for(int i=0; i<s.size();i++){
     if(s[i] == '(' || s[i] == ')'){
          pila.push(s[i]);
     }
  }

  for(int i=0;i<=pila.size() && bien != false ;i++){
    if(i%2 == 0){     //posiciones pares de la pila
      bien = (pila.top() == ')' );
      pila.pop();
    }
  }
  return bien;
}


int main(){

  string prueba= "hola(nombre)";
  bool bien;
  bien=parentesis_bien(prueba);

  if(bien== true)
    cout<<"bien \n";
  else
    cout<<"mal \n";

}
