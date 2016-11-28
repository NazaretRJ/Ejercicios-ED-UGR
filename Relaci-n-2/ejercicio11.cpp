/*Implementa una cola con prioridad de un tipo struct con (apellidos, nombre, prioridad) de forma que
los datos salgan de acuerdo a ese tercer campo prioridad.*/
#include<string>
#include<iostream>
#include<queue>
using namespace std;

struct persona {
  string apellidos;
  string nombre;
  int prioridad;
};

class comp{
  public:
    bool operator(persona a,persona b){
      if(a.prioridad < b.prioridad)
        return a < b;
      else{
        if( a.prioridad > b.prioridad )
          return a > b;
        else
          return a == b;
      }
    }
};

ostream &operator <<(ostream &os,const persona &a){
    os<<a.nombre<<" "<<a.apellidos<<" "<<a.prioridad;
    return os;
}

int main(){
  persona pepi;
  pepi.apellidos="Garcia";
  pepi.nombre= "Pepi";
  pepi.prioridad=4;

  persona Manu;

  Manu.apellidos="Fernandez";
  Manu.nombre="Manuel"
  Manu.prioridad=2;

  priority_queue<persona,vector<persona>, comp > pq;
  pq.push(pepi);
  pq.push(Manuel);

  while( !pq.empty() ){
    cout<<pq.front();
    pq.pop();
  }


}
