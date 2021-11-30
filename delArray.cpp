#include <bits/stdc++.h>

using namespace std;

void display(int arr[],int size)
{
   
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int del(int arr[], int index,int size)
{
    int i;
    if (index >= size)
    {
       
        cout << "Array Out Of Bounds" << endl;
        
        return size;
    }

    else
    {
        for (i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
       size--;
       return size;
    }
}
int main()
{
    int arr[] = {2, 4, 5, 7, 8, 9};
    int n;
    cin >> n;
    int size=6;
    size=del(arr, n,size);
    display(arr,size);

    return 0;
}