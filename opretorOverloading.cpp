#include <bits/stdc++.h>

using namespace std;

class Complex
{
public:
    int r,i;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        r=v1;
        i=v2;
    }
};

Complex operator+(const Complex& a, const Complex& b) { 
    return { a.r + b.r, a.i + b.i };
}

ostream & operator<<(ostream &os,const Complex x){
    return os<<x.r<<(x.i>0?'+':'-')<<'i'<<x.i;
}

int main()
{
 Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;

return 0;
}