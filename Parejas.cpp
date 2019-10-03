/*
 *  Las Parejas Estables
 *  Daniel Roa
 *  A01021960
 *  Entrega: 4 de octubre del 2019
 */
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define n 4

bool PrefH1(int preferencia[2*n][n], int m, int h, int h1){

  for (int i = 0; i < n; i++)
  {
    if (preferencia[m][i] == h1)
      return true;
    
    if(preferencia[m][i] == h)
      return false;
    
  }
  

}

void RelacionEstable(int preferencia[2*n][n]){

  int parejaFemina[n];
  bool hombreSoltero[n];

  memset(parejaFemina, -1, sizeof(parejaFemina));
  memset(hombreSoltero, false, sizeof(hombreSoltero));
  int cont = n;

  while (cont > 0)
  {
    int y;
    for (y = 0; y < n; y++)
      if (hombreSoltero[y] == false)
        break;

    for (int i = 0; i < n && hombreSoltero[y] == false; i++)
    {
      int wamen = preferencia[y][i];

      if (parejaFemina[wamen - n] == -1)
      {
        parejaFemina[wamen-n] = y;
        hombreSoltero[y] = true;
        cont--;
      }

      else{
        int semental = parejaFemina[wamen-n];

        if (PrefH1(preferencia, wamen, y, semental) == false)
        {
          parejaFemina[wamen-n] = y;
          hombreSoltero[y] = true;
          hombreSoltero[semental] = false;
        }
        
      }
      
    }
    
  }
  
  cout << "Mujeres Hombres" << endl; 
	for (int i = 0; i < n; i++) 
	cout << " " << i+n << "\t" << parejaFemina[i] << endl; 

}

int main() {

  int preferencia[2*n][n] = { {7, 5, 6, 4}, 
		{5, 4, 6, 7}, 
		{4, 5, 6, 7}, 
		{4, 5, 6, 7}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
	}; 
  RelacionEstable(preferencia);

  return 0;
}
