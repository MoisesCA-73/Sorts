/* Implementaci�n de QuickSort en C++ */
#include <bits/stdc++.h>
using namespace std;

// Una funci�n de utilidad para intercambiar dos elementos.
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Esta funci�n toma el �ltimo elemento como pivote, coloca
el elemento pivote en su posici�n correcta en ordenados
matriz, y coloca todos m�s peque�os (m�s peque�os que pivote)
a la izquierda del pivote y todos los elementos mayores a la derecha
de pivote */
int partition (int arr[], int menor, int mayor)
{
	int pivot = arr[mayor]; // pivot
	int i = (menor - 1); // �ndice de elemento m�s peque�o e indica la posici�n correcta del pivote encontrado hasta ahora
	for (int j = menor; j <= mayor - 1; j++)
	{
		// Si el elemento actual es m�s peque�o que el pivote
		if (arr[j] < pivot)
		{
			i++; // �ndice de incremento del elemento m�s peque�o
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[mayor]);
	return (i + 1);
}

/* La funci�n principal que implementa QuickSort
arr [] -> Array a ordenar,
bajo -> �ndice de inicio,
alto -> �ndice de finalizaci�n */
void quickSort(int arr[], int menor, int mayor)
{
	if (menor < mayor)
	{
		/* pi es �ndice de partici�n, arr [p] es ahora
en el lugar correcto */
		int pi = partition(arr, menor, mayor);

		// Ordene los elementos por separado antes
		// partici�n y despu�s de la partici�n
		quickSort(arr, menor, pi - 1);
		quickSort(arr, pi + 1, mayor);
	}
}

/* Funci�n para imprimir un array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Array Ordenado: \n";
	printArray(arr, n);
	return 0;
}

