/*
 *  El Camionero con Prisa
 *  Daniel Roa
 *  A01021960
 *  Entrega: 4 de octubre del 2019
 *
 *  Complejidad del algoritmo: O(n)
 *
 *  Este algoritmo fue obtenido de: https://www.geeksforgeeks.org/number-of-refills-to-complete-the-journey-of-n-km/
 *
 *  La solución a este problema se realizó utilizando programación ávida,
 *  debido a que se esta buscando la solución mas óptima para que el conductor
 *  pueda pasar por las paradas requeridas y, de tal manera, poder abastecer el
 *  tanque en las paradas especificadas.
 *  Lo que va a realizar el algoritmo es, sumar las distancias recorridas usando
 *  el ciclo while para que no se exceda de la distancia total y, posteriormente,
 *  hacer la suma de las distancias.
 */
#include <iostream>
#include <stdio.h>

using namespace std;

int ParadaForzosa(int recorrido, int distancia, int paradas, int gas[]){

  int contDistancia = 0;    //Contador de distancia
  int alfa = 0;           //contador A
  int beta = 0;           //contador B

  while (contDistancia < recorrido) {

    if (alfa < paradas && gas[beta] <= (contDistancia + distancia)) {
      contDistancia = gas[beta];
      beta++;
    } //fin loop if en la que se suma la distancia recorrida
    else{
      contDistancia += distancia;
    }

    if (contDistancia < recorrido) {
      alfa++;
    }

  }//fin while

  cout << "Deberá detenerse " << alfa << " veces" << endl;

  return 0;
};

int main() {

  int recorrido;    //distancia total a recorrer
  int dist;         //distancia que puede recorrer entre gasolineras
  int paradas;      //cantidad de gasolineras en las que deberá parar
  int petrol;       //valor de las paradas

  cout << "Inserta la cantidad total a recorrer." << '\n';
  cin >> recorrido;
  cout << '\n';

  cout << "Cuál es la distancia que puede recorrer el camión sin parar?" << '\n';
  cin >> dist;
  cout << '\n';

  cout << "Cuántas gasolineras hay?" << '\n';
  cin >> paradas;
  cout << '\n';

  int gas[paradas];

  cout << "Inserta los km. donde se encuentran las gasolineras." << '\n';

  for (int i = 0; i < paradas; i++) {

    cout << "Parada #" << i << '\n';
    cin >> paradas;
    cout << '\n';

    gas[paradas];
  }

  ParadaForzosa(recorrido, dist, paradas, gas);

  return 0;
}
