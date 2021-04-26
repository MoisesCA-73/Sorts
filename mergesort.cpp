//Merge Sort

#include <iostream>

using namespace std;

int* add(int *arr, int x, int &n)
{
    int* aux = new int[n+1];
    for (int  i = 0; i < n; i++)
    {
        aux[i] = arr[i];
    }
    aux[n] = x;
    n++;
    return aux;
}

int* remove(int *arr, int &n)
{
    int* aux = new int[n-1];
    for (int  i = 0; i < n-1; i++)
    {
        aux[i] = arr[i+1];
    }
    n--;
    return aux;
}

int* merge(int *arr1, int n1, int *arr2, int n2)
{
    int n3 = 0;
    int* arr3 = new int [n3];

    while(n1 > 0 && n2 > 0)
    {
        if(arr1[0] > arr2[0])
        {
            arr3 = add(arr3,arr2[0],n3);
            arr2 = remove(arr2,n2);
        }
        else
        {
            arr3 = add(arr3,arr1[0],n3);
            arr1 = remove(arr1,n1);
        }
    }

    while(n1 > 0)
    {
        arr3 = add(arr3,arr1[0],n3);
        arr1 = remove(arr1,n1);
    }
    while(n2 > 0)
    {
        arr3 = add(arr3,arr2[0],n3);
        arr2 = remove(arr2,n2);
    }

    return arr3;
}

int* merge_sort(int *arr, int &n)
{
    if(n == 1)
    {
        return arr;
    }
    int n1,n2;
    n1 = n/2;
    if (n%2 == 0)
    {  
        n2 = n/2;
    }
    else
    {
        n2 = (n/2)+1;
    }
    int* arr1 = new int [n1];
    int* arr2 = new int [n2];
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = arr[i+n1];
    }

    arr1 = merge_sort(arr1,n1);
    arr2 = merge_sort(arr2,n2);

    return merge(arr1,n1,arr2,n2);

}

int main()
{
    int n;
    cout << "Array de cuantos elementos?: ";
    cin >> n;
    cout << endl;
    int* array = new int [n];
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese elemento " << i+1 << ": ";
        cin >> array[i];
    }
    int *array_sorted = merge_sort(array,n);
    cout << "\nARREGLO ORDENADO:\n";
    for (int i = 0; i < n; i++)
    {
        cout << array_sorted[i] << " ";
    }

}