/*Se llama expresión en postfijo a una expresión matemática en la que cada operación aparece con sus
dos operandos seguidos por el operador. Por ejemplo: 2 3 + 5 * Escribe un programa que evalue una
expresión en postfijo.*/
#include <stack>
#include <string>
#include <iostream>

using namespace std;
stack<float> pila;

bool sumar(){
  float n,m;
  n=pila.top();
  pila.pop();
  m=pila.top();
  pila.pop();
  bool vacia=pila.empty(); //se hace aquí porque el resultado siempre se almacena en la pila.
  pila.push(n+m);
  return vacia;
}

bool restar(){
  float n,m;
  n=pila.top();
  pila.pop();
  m=pila.top();
  pila.pop();
  bool vacia=pila.empty();
  pila.push(m-n); //m fue el primero en entrar
  return vacia;
}

bool multiplicar(){
  float n,m;
  n=pila.top();
  pila.pop();
  m=pila.top();
  pila.pop();
  bool vacia=pila.empty();
  pila.push(n*m);
  return vacia;
}

bool dividir(){
  float n,m;
  n=pila.top();
  pila.pop();
  m=pila.top();
  pila.pop();
  bool vacia=pila.empty();
  pila.push(m/n);
  return vacia;

}

bool elevar(){
  float n,m,j;
  j=0.0;
  n=pila.top();
  pila.pop();
  m=pila.top();
  pila.pop();

  bool vacia=pila.empty();
  for(int i=0;i<n;i++){
    j=m*m+j;
  }
  pila.push(j);
  return vacia;

}

int main(){
  string expresion="53^2*2/9+";
  string* ptr=NULL;
  bool acabado=false;

  for(int i=0;i<expresion.size() && !acabado;i++){

     switch (expresion[i]) {
       case '+':
         acabado=sumar();
       break;

       case '-':
         acabado=restar();
       break;

       case '*':
         acabado=multiplicar();
       break;

       case '/':
         acabado=dividir();
       break;

       case '^':
        acabado=elevar();

       default:
         float n = stof(expresion[i],&ptr);
         pila.push(n);
         acabado=false;
       break;
     }
  }
  cout<<"Resultado: "<<pila.top()<<endl;


}
