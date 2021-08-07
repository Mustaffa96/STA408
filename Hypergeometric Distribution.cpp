//Hypergeometric Distribution
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){

    long double fact1=1.0,fact2=1.0,fact3=1.0,fact4=1.0,fact5=1.0,fact6=1.0,fact7=1.0,fact8=1.0,fact9=1.0;
    int a,b,n,x;
    double h;
    cout<<"Formula for the Hypergeometric Distribution , P(X) = (aCx * bCn-x) / a+bCn "<<endl;
    cout<<"\n";
    cout<<"Please insert value of a: "<<endl;
    cin>>a;
    cout<<"Please insert value of b: "<<endl;
    cin>>b;
    cout<<"Please insert value of n: "<<endl;
    cin>>n;
    cout<<"Please insert value of X: "<<endl;
    cin>>x;
    if (n < 0 && x < 0)
        cout << "Error! Factorial of a negative number doesn't exist.";
    else {
        for(int i = 1; i <= a; ++i) {
            fact1 *= i;
        }
        for(int j = 1; j <= a-x; ++j){
            fact2 *= j;
        }
        for(int k = 1; k <= x; ++k){
            fact3 *= k;
        }
        for(int p = 1; p <= b; ++p){
            fact4 *= p;
        }
        for(int q = 1; q <= b-(n-x); ++q){
            fact5 *= q;
        }
        for(int r = 1; r <= n-x; ++r){
            fact6 *= r;
        }
        for(int d = 1; d <= a+b; ++d){
            fact7 *= d;
        }
        for(int e = 1; e <= (a+b)-n; ++e){
            fact8 *= e;
        }
        for(int f = 1; f <= n; ++f){
            fact9 *= f;
        }
        cout<<"\n";
        cout<<"P(X) = ("<<a<<"C"<<x<<" * "<<b<<"C"<<n-x<<") / ("<<a+b<<"C"<<n<<")"<<endl;
        cout<<"P(X) = "<<fact1/(fact2*fact3)<<" * "<<fact4/(fact5*fact6)<<" / "<<fact7/(fact8*fact9)<<endl;
        h = ((fact1/(fact2*fact3)) * (fact4/(fact5*fact6))) / (fact7/(fact8*fact9));
        cout<<"P(X) = "<<h<<endl;
    }
        return 0;

}

