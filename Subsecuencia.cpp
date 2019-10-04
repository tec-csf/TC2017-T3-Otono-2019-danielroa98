/*
 *  Subsecuencia Común Máxima
 *  Daniel Roa
 *  A01021960
 *  Entrega: 4 de octubre del 2019
 *
 *  Complejidad del algoritmo: O(m*n)
 *
 *  Este algoritmo fue obtenido de: https://www.geeksforgeeks.org/longest-common-substring-dp-29/
 *
 *  Este es un algoritmo dinámico debido a que va a estar separando los caracteres que se
 *  encuentran dentro de los arreglos creados, una vez separados, las funciones for e if
 *  se encargará de comparar los valores que se encuentra dentro de cada uno y, como es
 *  más fácil utilizar caracteres, está descomponiendo las posiciones de cada carácter.
 *  Es importante mencionar, se utilizó apuntadores para poder acceder al valor almacenado
 *  en la memoria en lugar del id. de la dirección de la memoria.
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void EncontrarSubstring(char* subA, char* subB, int x, int y){

  int subT[x+1][y+1];   //donde se almacenarán los valores
  int tam = 0;          //inicio contador
  int reng, col;

  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      if (i == 0 || j == 0) {
        subT[i][j] = 0;

      }
        else if (subA[i-1] == subB[j-1]) {
          subT[i][j] = subT[i-1][j-1] + 1;
          if (tam < subT[i][j]) {
            tam = subT[i][j];
            reng = i;
            col = j;
          }
        }
        else{
          subT[i][j] = 0;
        }
    }
  }

  if (tam == 0) {
    cout << "No hay un substring en común";
    return;
  }

  char* subFinal = (char*)malloc((tam+1) * sizeof(char));

  while (subT[reng][col] != 0) {
    subFinal[--tam] = subA[reng - 1];

    reng --;
    col--;
  }

  int subFinalNo = strlen(subFinal);

  cout << "El substring mas grande es '" << subFinal << "' contiene " << subFinalNo << " caracteres." << endl;
};

int main() {

  char subA[] = "Esta es una oración de prueba, esperemos que funcione.";
  char subB[] = "Esta es una oración demo, a ver si sirve.";

  int x = strlen(subA);
  int y = strlen(subB);

  EncontrarSubstring(subA, subB, x, y);

  return 0;
}
