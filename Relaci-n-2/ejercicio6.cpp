/*Dada una matriz que representa un laberinto, construye una función que determine si se puede llegar
desde la entrada hasta la salida. Esta matriz tendrá una ’E’ en la entrada, una ’S’ en la salida, un ’0’
en las casillas por las que se pueda pasar y un ’1’ en las que no. No se puede ir en diagonal.*/
pila de pares con las casillas
por las que pasamos no son validas
marcar sobre matriz por las que pasamos
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
const int MURO=1;
const int PISADA=-1;
const int LIBRE=0;
const char ENTRADA='E';
const char SALIDA='S';

  stack< vector <int>  > guarda_pasos;

bool puedes_avanzar(const vector<int> &matriz ,unsigned int n_filas ,unsigned int n_columnas ){
    if( ( matriz[fila][columna] == LIBRE || matriz[fila][columna] == PISADA ) && fila < n_filas && columna < n_columnas  )
      return true;
    else
      return false;
}
/*si la casilla anterior y la siguiente a la que estas estan pisadas subimos una fila*/

/*Almacenaremos en una pila los valores de las casillas por las que pasamos.*/
void laberinto(vector &matriz ,unsigned int n_filas ,unsigned int n_columnas){

  for(unsigned int i=0;i< n_filas;){
    for(unsigned int j=0;j< n_columnas;){
      if( puedes_avanzar(matriz[i][j+1],n_filas,n_columnas) ){ //vemos si podemos avanzar a la siguiente casilla
        matriz[i][j]=PISADA; //indicamos que hemos pasado por ahí
        guarda_pasos.push(matriz[i][j]);
        j++;
      }
      else { //retrocede
        vector< vector <int> > anterior = guarda_pasos.top();
        if(anterior == PISADA && matriz[i][j+1] == PISADA && puedes_avanzar(matriz[i+1][j],n_filas,n_columnas) ) //deberiamos subir una fila
          i++;
        else
          if( puedes_avanzar(matriz[i+1][j],n_filas,n_columnas) )//no podemos avanzar columnas,avanzamos una fila
            i++;
          else //no puedes avanzar fila,ni columna,vuelves columna atrás
            if( puedes_avanzar(matriz[i][j-1],n_filas,n_columnas) )
              j--;
            else //no puedes avanzar fila,ni columnas,vuelves fila atrás
              i--;
      }


    }
  }

}
