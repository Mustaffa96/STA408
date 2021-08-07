#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int i,j,k,n;
    cout<<"Formula for Mean (Discrete Probability Distribution): M = X . P(X)"<<endl;
    cout<<"\nEnter the no. of data pairs to be entered:\n";        //To find the size of arrays
    cin>>n;
    double x[n],y[n],a,b;
    cout<<"\nEnter the Outcome,X values:\n";                //Input x-values
    for (i=0;i<n;i++)
        cin>>x[i];
    cout<<"\nEnter the Probability,P(X) values:\n";                //Input x-values
    for (i=0;i<n;i++)
        cin>>y[i];
    double xsum=0,allxsum=0, ysum=0,xysum=0,allysum=0,allxysum=0, x2sum=0, x2ysum=0;                //variables for sums/sigma of xi
    for (i=0;i<n;i++)
    {
        xsum=xsum+x[i];                        //
        allxsum=xsum;
        ysum=ysum+y[i];
        allysum=ysum;
        x2sum=x2sum+pow(x[i],2);
        xysum=xysum+x[i]*y[i];
        allxysum=xysum;
        x2ysum=x2ysum+pow(x[i],2)*y[i];

    }
    cout<<"\n";
        cout<<"S.no"<<setw(5)<<"X"<<setw(8)<<"P(X)"<<setw(8)<<"X^2"<<setw(8)<<"X.P(X)"<<setw(8)<<"X^2.P(X)"<<endl;
    cout<<"------------------------------------------------------------------------------\n";
       for (i=0;i<n;i++)
        cout<<i+1<<"."<<setw(5)<<x[i]<<setw(12)<<y[i]<<setw(8)<<pow(x[i],2)<<setw(10)<<x[i]*y[i]<<setw(10)<<pow(x[i],2)*y[i]<<endl;
    cout<<"\n";
    cout<<"Mean = SumX*P(X) = "<<xysum<<endl;
    a = x2ysum-pow(xysum,2);
    b = sqrt(a);
    cout<<"Variance = Sum[X^2*P(X] - Mean^2 = "<<x2ysum<<" - "<<pow(xysum,2)<<" = "<<a<<endl;
    cout<<"Standard Distribution = Mean^1/2 = "<<b<<endl;

    return 0;

}
