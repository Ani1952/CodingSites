#include <bits/stdc++.h>

using namespace std;

class Car
{
public:
    string id;
    int x, y;
    Car(string id, int, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist() const
    {
        return x * x + y * y;
    }
};

class compare
{
public:
    bool operator()(Car a, Car b)
    {
        return a.dist() < b.dist();
    }
};

void print(vector<Car> cars, int k)
{

    priority_queue<Car, vector<Car>, compare> Sort(cars.begin(), cars.begin() + k);

    for (int i = k; i < cars.size(); i++)
    {
        auto car = cars[i];

        if (car.dist()<Sort.top().dist()){
            Sort.pop();
            Sort.push(car);
        }
    }

    while(!Sort.empty()){
        cout<<Sort.top().id<<endl;
        Sort.pop();
    }
}

int main()
{
 int N,K;
	cin>>N>>K;

	string id;
	int x,y;

	vector<Car> cars;

	for(int i=0;i<N;i++){
		cin>> id>>x>>y;
		Car car(id,x,y);
		cars.push_back(car);
	}
    print(cars,K);
    return 0;
}