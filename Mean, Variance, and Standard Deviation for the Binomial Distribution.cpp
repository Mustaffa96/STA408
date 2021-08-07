//Mean, Variance, and Standard Deviation for the Binomial Distribution
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){

    double n,p,q,mw,v,sd;
    cout<<"Please insert value of n: "<<endl;
    cin>>n;
    cout<<"Please insert value of p: "<<endl;
    cin>>p;
    cout<<"Please insert value of n: "<<endl;
    cin>>q;

    mw = n*p;
    v = n*p*q;
    sd = sqrt(v);

    cout<<"Mean = n.p = "<<n<<"x"<<p<<" = "<<mw<<endl;
    cout<<"Variance = n.p.q = "<<n<<" x "<<p<<" x "<<q<<" = "<<v<<endl;
    cout<<"Standard Deviation = (n.p.q)^1/2 = ("<<n<<" x "<<p<<" x "<<q<<")^1/2 = "<<sd<<endl;


return 0;
}
