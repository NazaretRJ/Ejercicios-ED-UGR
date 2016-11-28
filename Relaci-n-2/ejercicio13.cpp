/*Implementa una cola con prioridad que contenga strings y de la que salgan primero las cadenas de
caracteres que tengan más vocales y que en caso de igualdad salgan por orden alfabético.*/

#include<string>
#include<iostream>
#include<ctype.h> //para tolower
#include<queue>
using namespace std;


bool vocal(char ch){
  bool es;
  ch=tolower(ch);
  switch (ch) {
    case 'a':
      es=true;
    break;

    case 'e':
      es=true;
    break;

    case 'i':
      es=true;
    break;

    case 'o':
      es=true;
    break;

    case 'u':
      es=true;
    break;

    default:
      es=false;
    break;

    return es;
  }
}

int contar_vocales(const string &aux){
  int vocales=0;
  for(int i=0;i < aux.size();i++){
    es_vocal=vocal(aux[i]);
    if(es_vocal)
      vocales++;
  }
  return vocales;
}

}
class comp{
  public:
    bool operator(string& a,string& b){
      int a_vocales=0;
      int b_vocales=0;

        a_vocales=contar_vocales(a);
        b_vocales=contar_vocales(b);
        if(a_vocales == b_vocales){
          /*Tenemos que tener en cuenta que en la tabla ASCII las mayusculas y las minisculas tienen distinto orden*/
            if(a[0] <= 'A'&& a[0] >= 'Z') //no es mayuscula
              tolower(a[0]);
            if(b[0] <= 'A'&& b[0] >= 'Z')
              tolower(b[0]);
            bool menor=false;
            if(a < b)
              menor=true;
            return menor;
        }
        else{
            if(a_vocales < b_vocales)
              return a < b;
            else
              return a > b;
        }
    }

};


int main(){
  priority_queue<string,vector<string>, comp > pq;
  string a="Colacao";
  string b="Hola";

  pq.push(b);
  pq.push(a);

  while( !pq.empty() ){
    cout<<pq.front();
    pq.pop();
  }
