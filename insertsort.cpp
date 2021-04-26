#include<iostream>
using namespace std;
void mostrar(int *array, int tam) {
   for(int i = 0; i<tam; i++)
      cout << array[i] << " ";
   cout << endl;
}
void insertionSort(int *array, int tam) {
   int key, j;
   for(int i = 1; i<tam; i++) {
      key = array[i];
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key;   //insertar en el lugar correcto
   }
}
int main() {
   int n;
   cout << "Ingrese numero de elementos: ";
   cin >> n;
   int arr[n]; 
   cout << "Ingrese elementos: " << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array antes de ordenar: ";
   mostrar(arr, n);
   insertionSort(arr, n);
   cout << "Array despues de ordenar: ";
   mostrar(arr, n);
}
