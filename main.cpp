#include <iostream>
#include <iomanip>
using namespace std;

void  llenarDatos(int ** matriz, int filas, int col);
void  imprimir(int ** matriz, int filas, int col);
int elMayor(int ** matriz, int filas, int col);

int main()
{ int filas, col;

  srand(time(nullptr));
  cout << "Filas: ";
  cin >> filas;
  cout << "Columnas : ";
  cin >> col;

  int **matriz=nullptr;

  matriz = new int*[filas];
  for(int f=0; f<filas; f++)
    matriz[f] = new int[col];

  llenarDatos(matriz, filas, col);
  imprimir(matriz, filas, col);
  cout << "El mayor elemento es : " << elMayor(matriz, filas, col) << "\n";
  //--- se libera la memoria
  for(int f=0; f<filas; f++)
    delete []matriz[f];
  delete []matriz;
  matriz= nullptr;

  return 0;
}

void llenarDatos(int ** matriz, int filas, int col)
{
  for(int f=0; f<filas; f++)
    for(int c=0; c<col; c++)
      matriz[f][c] = rand() % 100;
}

void  imprimir(int ** matriz, int filas, int col)
{
  for(int f=0; f<filas; f++)
  {
    for(int c=0; c<col; c++)
      cout << setw(5) << matriz[f][c];
    cout << "\n";
  }
}

int elMayor(int ** matriz, int filas, int col)
{ int mayor=matriz[0][0];

  for(int f=0; f<filas; f++)
    for(int c=0; c<col; c++)
      if(matriz[f][c] > mayor)
        mayor = matriz[f][c];
  return mayor;
}