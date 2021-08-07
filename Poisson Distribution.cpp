//Poisson Distribution
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){

    double lm,p;
    int x;
    long double fact = 1.0;
    double e = 2.7183;
    cout<<"Formula for the Poisson Distribution :"<<endl;
    cout<<"P(X;lambda) = ((e^lambda)*(lambda^X))/X!"<<endl;
    cout<<"\n";
    cout<<"Please insert mean number of occurrences per unit, lambda"<<endl;
    cin>>lm;
    cout<<"Please insert exact probability, X"<<endl;
    cin>>x;
    cout<<"\n";
    cout<<"P("<<x<<";"<<lm<<") = ("<<e<<"^-"<<lm<<")*("<<lm<<"^"<<x<<")/"<<x<<"!"<<endl;
    if (x < 0)
        cout << "Error! Factorial of a negative number doesn't exist.";
    else {
        for(int i = 1; i <= x; ++i) {
            fact *= i;
        }
        p = (pow(e,-lm)*pow(lm,x))/fact;
       cout<<"P("<<x<<";"<<lm<<") = "<<p<<endl;
    }
return 0;
}
