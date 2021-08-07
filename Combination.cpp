//Combination
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int n,r;
    long double fact = 1.0;
    long double fact2 = 1.0;
    long double fact3 = 1.0;

    cout << "Formula Combination : nCr = n!/(n-r)!r! = " <<endl;
    cout << "Enter a positive integer for n object: ";
    cin >> n;
    cout << "Enter a positive integer for r object: ";
    cin >> r;

    if (n < 0)
        cout << "Error! Factorial of a negative number doesn't exist.";
    else {
        for(int i = 1; i <= n; ++i) {
            fact *= i;
        }
        for(int j = 1; j <= n-r; ++j){
            fact2 *= j;
        }
        for(int k = 1; k <= r; ++k){
            fact3 *= k;
        }
        cout << "Factorial of " << n << " = " << fact<<endl;
        cout << "Factorial of " << n-r << " = " << fact2<<endl;
        cout << "Factorial of " << r << " = " << fact3<<endl;
        cout << "nCr = n!/(n-r)!r! = " << n << "!/( " <<n-r<<")!"<<r<<"! = "<< fact/(fact2*fact3)<<endl;
    }

    return 0;

}
