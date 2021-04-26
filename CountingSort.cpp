#include<iostream>
#include<algorithm>
using namespace std;
void mostrar(int *arreglo, int size) {
   for(int i = 1; i<=size; i++)
      cout << arreglo[i] << " ";
   cout << endl;
}
int getMax(int arreglo[], int size) {
   int max = arreglo[1];
   for(int i = 2; i<=size; i++) {
      if(arreglo[i] > max)
         max = arreglo[i];
   }
   return max; //Encontramos el maximo numero en el arreglo
}
void countSort(int *arreglo, int size) {
   int output[size+1];
   int max = getMax(arreglo, size);
   int count[max+1];     //creamos el arreglo de conteo con el numero maximo+1
   for(int i = 0; i<=max; i++)
      count[i] = 0;     //inicializamos ese arreglo con ceros
   for(int i = 1; i <=size; i++)
      count[arreglo[i]]++;     //aumentamos el recuento de numeros en el arreglo de conteo.
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];     //encontramos la frecuencia cumulativa sumando las posiciones i + (i-1)
   for(int i = size; i>=1; i--) {
      output[count[arreglo[i]]] = arreglo[i];
      count[arreglo[i]] -= 1; //decrecemos la cuenta para numeros iguales 
   }
   for(int i = 1; i<=size; i++) {
      arreglo[i] = output[i]; //colocamos el arreglo ordenado en el arreglo original
   }
}
int main() {
   int n;
   cout << "Cantidad de numeros: ";
   cin >> n;
   int arr[n+1];       //creamos un array con los elementos dados
   cout << "Elementos:" << endl;
   for(int i = 1; i<=n; i++) {
      cin >> arr[i];
   }
   cout << "Sin ordenar: ";
   mostrar(arr, n);
   countSort(arr, n);
   cout << "Ordenado: ";
   mostrar(arr, n);
}