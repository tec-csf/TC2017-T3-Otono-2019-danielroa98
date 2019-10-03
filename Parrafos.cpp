/*
 *  La División en Párrafos
 *  Daniel Roa
 *  A01021960
 *  Entrega: 4 de octubre del 2019
 */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define INF INT_MAX

int ImprimeSolucion(int sol[], int tam);

void Parrafos(int oracion[], int tam, int espacio){

  int espacioEX[tam+1][tam+1];  //numero de espacios extras
  int costo[tam+1][tam+1];      //costo de la linea
  int costTot[tam+1];           //costo óptimo
  int sol[tam+1];               //impresión de solución

  int cont, i;

  for (cont = 0; cont < tam; cont++)
  {
    espacioEX[cont][cont] = espacio - oracion[cont-1];
    for (i = cont+1; i <= tam; i++)
      espacioEX[cont][i] = espacioEX[cont][i-1] - oracion[i-1] - 1;
    
  }

  for (cont = 1; cont <= tam; i++)
  {
    for (i = cont; i <= tam; i++)
    {
      if (espacioEX[cont][i] < 0)
        costo[cont][i] = INF;
      else if (i == cont && espacioEX[cont][i] >= 0)
        costo[cont][i] = 0;  
      else
        costo[cont][i] = espacioEX[cont][i] * espacioEX[cont][i];
      
    }
    
  }

  costTot[0] = 0;
  for (i = 0; i <= tam; i++)
  {
    costTot[i] = INF;
    for (cont = 1; cont <= i; cont++)
    {
      if (costTot[cont-1] != INF && costo[cont][i] != INF && (costTot[cont-1] + costo[cont][i] < costTot[i]))
      {
        costTot[i] = costTot[cont - 1] + costo[cont][i];
        sol[i] = cont;
      }
      
    }
    
  }
  ImprimeSolucion(sol, tam);
  
}

int ImprimeSolucion(int sol[], int tam){

  int x;
  if (sol[tam] == 1)
    x = 1;
  else
    x = ImprimeSolucion(sol, sol[tam]-1) + 1;
  
  cout << "No. línea " << x << ": de la palabra (no.) " << sol[tam] << " a " << tam << endl;

  return x;

}

int main() {

  int oracion[] = {3,2,2,5};
  int tam = sizeof(oracion) / sizeof(oracion[0]);
  int espacio = 6;

  Parrafos(oracion, tam, espacio);

  return 0;
}
