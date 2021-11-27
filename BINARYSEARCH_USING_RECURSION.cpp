#include <stdio.h>
int binarySearch(int arr[], int left, int right, int x)
{
    if (right >= 1)
    {
        int mid = left + (right - 1) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}
int main()
{
    int arr[] = {2, 4, 8, 9, 10, 13, 54, 87, 97, 1002, 4646};
    int n = sizeof(arr) / sizeof(arr[0]);
    int element = 54;
    int index = binarySearch(arr, 0, n - 1, element);
    (index != -1) ? printf("THE ELELMENT IS %d AT POSITION %d", element, index) : printf("NOT FOUND");

    return 0;
}