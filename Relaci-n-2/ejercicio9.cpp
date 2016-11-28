/*Un tipo ventana es un tipo de dato que permite insertar un elemento, mover derecha, mover izquierda,
borrar elemento y que se implementa usando dos pilas. Implementa ese tipo de dato con las operacio-
nes comentadas.*/
#include<stack>
using namespace std;
template <typename T>
class ventana{
  private:
    /*Digamos que en izquierda están las leidas y en las derecha las que no*/
    stack<T> izquierda,derecha;
  public:
    void insertar(T elemento){
      izquierda.push(elemento);
    }
    /*Borramos el elemento de la izquierda*/
    void borrarElemento(T elemento){
      if(izquierda.size() != 0){  //hay elementos
        bool borrado=false;
        stack<T> aux;
        for(int i=0;i<izquierda.size() && !borrado;i++){
          if(aux.top() != elemento)
            aux.push( izquierda.top() );
          izquierda.pop();
        }
        izquierda=aux;
      }
    }
    void moverDerecha(){
      derecha.push( izquierda.top() );
      izquierda.pop();
    }

    void moverIzquierda(){
      izquierda.push( derecha.top() );
      derecha.pop();
    }

}; 
