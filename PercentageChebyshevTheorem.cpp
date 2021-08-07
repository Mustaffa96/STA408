//Program finding percentage value between 2 points and 1 given mean using Chebyshev's Theorem//

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double x1, x2, mn, sd, k, p1, p2, z1, z2;

int main()
{
  cout<<"Please insert mean: "<<endl;
  cin>>mn;
  cout<<"Please insert standard deviation: "<<endl;
  cin>>sd;
  cout<<"Please insert first value: "<<endl;
  cin>>x1;
  cout<<"Please insert second value: "<<endl;
  cin>>x2;
  z1=(x1-mn)/sd;
  z2=(x2-mn)/sd;
  cout<<"Z = (X - Mew)/ sigma => ("<<x1<<" - "<<mn<<")/"<<sd<<" => "<<z1<<endl;
  cout<<"Z = (X - Mew)/ sigma => ("<<x2<<" - "<<mn<<")/"<<sd<<" => "<<z2<<endl;
  cout<<"Thus, the Z-score fall between ("<<z1<<"<Z<"<<z2<<"). That is k = "<<z2<<endl;
  k = z2;
  p1=1-(1/pow(k,2));
  cout<<"Percentage between value "<<x1<<" and "<<x2<<" = (1-1/k^2)"<<endl;
  cout<<"Percentage between value "<<x1<<" and "<<x2<<" = (1-1/"<<k<<"^2)"<<endl;
  cout<<"\t\t\t\t = "<<p1<<endl;
  double rounded = std::floor((p1 * 100) + .5) / 100;
  cout<<"\t\t\t\t = "<<rounded<<"(Rounding 2 decimal places)"<<endl;
  p2= rounded * 100;
  cout<<"   \t\t"<<rounded<<" x 100% = "<<p2<<"%"<<endl;
  cout<<"Hence, the required percentage is "<<p2<<"%"<<endl;

  return 0;
}
