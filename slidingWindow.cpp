#include <bits/stdc++.h>

using namespace std;

int slide(int *arr, int n, int k)
{

    int i, j, Max, c;
    Max = 0;
    for (i = 0; i < n - k + 1; i++)
    {
        c = 0;
        for (j = 0; j < k; j++)
            c = c + arr[i + j];
        Max = max(Max, c);
    }
    return Max;
}

int windowSlide(int *arr, int n, int k)
{

    queue<int> q;
    int i, j, Max, c;
    Max = 0;
    for (i = 0; i < n - k + 1; i++)
    {
        c = 0;
        for (j = 0; j < k; j++)
            q.push(arr[i + j]);
        while (!q.empty())
        {
            c = c + q.front();
            q.pop();
        }
        Max = max(Max, c);
    }
    return Max;
}

int main()
{

    int arr[] = {9, 3, 4, 5, 1, 7, 8, 2, 6, 0};
    cout << slide(arr, 10, 3) << "    " << windowSlide(arr, 10, 3) << endl;

    return 0;
}