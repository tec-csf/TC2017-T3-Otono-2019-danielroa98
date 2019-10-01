/*
 *  El Camionero con Prisa
 *  Daniel Roa
 *  A01021960
 *  Entrega: 4 de octubre del 2019
 */

#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

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

  cout << "Inerta la cantidad total a recorrer." << '\n';
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
  } //NOTA, se pide añadir un valor de mas, falta debuggearlo
    //en el case que no se pueda, se deberá escribir 0 en el valor adicional

  ParadaForzosa(recorrido, dist, paradas, gas);

  return 0;
}
