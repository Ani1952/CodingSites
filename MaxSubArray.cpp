#include <bits/stdc++.h>

using namespace std;

void Slide(vector<int> a, int k=3)
{

    int n = a.size();

    deque<int> Q(k);

    int i;

    for (i = 0; i < k; i++)
    {

        while (!Q.empty() && a[i] > a[Q.back()])
        {
            Q.pop_back();
        }

        Q.push_back(i);
    }

    for (; i < n; i++)
    {
        cout << a[Q.front()] << " ";

        while (!Q.empty() and Q.front() <= i - k)
        {
            Q.pop_front();
        }
        while (!Q.empty() && a[i] >= a[Q.back()])
        {
            Q.pop_back();
        }

        Q.push_back(i);
    }

    cout << a[Q.front()];
}

int main()
{
    vector <int> v={6,4,9,2,3,4,1,9,7,4,7,3,8,9,1,6};

    Slide(v);

    return 0;
}