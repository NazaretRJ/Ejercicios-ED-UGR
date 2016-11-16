/* Construye una función a la que se se le pase una pila P de tipo T y dos elementos x,y de tipo T y que
modifique la pila de forma que todas las veces que aparezca x se substituya por y (quedando la pila en
el mismo estado en el que estaba anteriormente). Para este ejercicio no se podrán utilizar iteradores.*/

#include <iostream>
#include <stack>
using namespace std;

template <typename T>;

void Sustituir(st<T>, T x, T y){
	stack<T> aux;
	while(!st.empty()){	//cuando no esté vacía
		if(st.top() == x)	//si el elemento es x,metemos y
			aux.push( y );
		else							//si no,metemos el elemento que había.
			aux.push( st.pop() );
	}


	st=aux;

}
