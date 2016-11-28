/*Usando una pila y una cola, implementa una función que compruebe si un string es un palı́ndromo.*/
#include<string>
#include<queue>
#include<stack>
#include<iostream>

using namespace std;
/*Sabemos que en la pila se meterá al revés a diferencia que en la cola */
bool palindromo(const string& s){
  queue<char> cola;
  stack<char>pila;
  bool diferente = false;

  for(int i=0;i<s.size();i++){
      pila.push( s[i] );
      cola.push( s[i] );
  }

  while(pila.size()!= 0 && diferente == false){
    if( pila.top() != cola.front() )
      diferente=true;
    pila.pop();
    cola.pop();
  }
  return diferente;
}

int main(){
  string prueba="mala";
  bool es_palindromo=palindromo(prueba);

  if(es_palindromo)
    cout<<"Es palindromo"<<endl;
  else
    cout<<"No es palindromo"<<endl;

}
