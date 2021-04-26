/* Implementación de QuickSort en C++ */
#include <bits/stdc++.h>
using namespace std;

// Una función de utilidad para intercambiar dos elementos.
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* Esta función toma el último elemento como pivote, coloca
el elemento pivote en su posición correcta en ordenados
matriz, y coloca todos más pequeños (más pequeños que pivote)
a la izquierda del pivote y todos los elementos mayores a la derecha
de pivote */
int partition (int arr[], int menor, int mayor)
{
	int pivot = arr[mayor]; // pivot
	int i = (menor - 1); // Índice de elemento más pequeño e indica la posición correcta del pivote encontrado hasta ahora
	for (int j = menor; j <= mayor - 1; j++)
	{
		// Si el elemento actual es más pequeño que el pivote
		if (arr[j] < pivot)
		{
			i++; // índice de incremento del elemento más pequeño
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[mayor]);
	return (i + 1);
}

/* La función principal que implementa QuickSort
arr [] -> Array a ordenar,
bajo -> Índice de inicio,
alto -> índice de finalización */
void quickSort(int arr[], int menor, int mayor)
{
	if (menor < mayor)
	{
		/* pi es índice de partición, arr [p] es ahora
en el lugar correcto */
		int pi = partition(arr, menor, mayor);

		// Ordene los elementos por separado antes
		// partición y después de la partición
		quickSort(arr, menor, pi - 1);
		quickSort(arr, pi + 1, mayor);
	}
}

/* Función para imprimir un array */
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

