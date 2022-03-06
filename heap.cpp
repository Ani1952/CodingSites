#include <bits/stdc++.h>

using namespace std;

void heapify(int i,vector<int> v)
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        int minidx = i;
        if (left < v.size() and v[left] > v[minidx])
        {
            minidx = left;
        }
        if (right < v.size() and v[right] > v[minidx])
        {
            minidx = right;
        }

        if (v[minidx] != v[i])
        {
            swap(v[i], v[minidx]);
            heapify(minidx,v);
        }
    }

int main()
{

vector<int> v={15,5,20,1,17,10,30};

for(auto x:v){
    cout<<x<<" ";
}

heapify(v.size()/2-1,v);
cout<<endl;
for(auto x:v){
    cout<<x<<" ";
}

return 0;
}