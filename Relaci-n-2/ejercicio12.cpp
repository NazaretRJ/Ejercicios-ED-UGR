/*Implementa una cola con prioridad que contenga strings y de la que salgan primero las cadenas de
caracteres más largas y que en caso de igualdad salgan por orden alfabético.*/

#include<string>
#include<iostream>
#include<queue>
using namespace std;

class comp{
  public:
    bool operator(string& a,string& b){
      bool menor=true;
      if(a.size() < b.size())
        menor=false;
      else{
        if( a.size() > b.size() )
          menor=true;
        else {//iguales
        /*Tenemos que tener en cuenta que en la tabla ASCII las mayusculas y las minisculas tienen distinto orden*/
          if(a[0] <= 'A'&& a[0] >= 'Z') //no es mayuscula
            tolower(a[0]);
          if(b[0] <= 'A'&& b[0] >= 'Z')
            tolower(b[0]);
          if(a < b)
            menor=false;
          return menor;
        }

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
