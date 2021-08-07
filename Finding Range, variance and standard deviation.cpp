//Finding Range, variance and standard deviation
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int i,j,k,n ;
    cout<<"\nEnter the no. of data pairs to be entered:\n";        //To find the size of arrays
    cin>>n;
    double x[n],s,s2;
    cout<<"\nEnter the x-axis values:\n";                //Input x-values
    for (i=0;i<n;i++)
        cin>>x[i];

    double xsum=0,allxsum=0,x2sum=0,allx2sum=0;                //variables for sums/sigma of xi
    for (i=0;i<n;i++)
    {
        xsum=xsum+x[i];                        //
        allxsum=xsum;
        x2sum=x2sum+pow(x[i],2);
        allx2sum=x2sum;

    }
        cout<<"S.no"<<setw(5)<<"x"<<setw(5)<<"x^2"<<endl;
        cout<<"--------------------------\n";
       for (i=0;i<n;i++)
        cout<<i+1<<"."<<setw(8)<<x[i]<<setw(8)<<pow(x[i],2)<<endl;

    int min, max;
    double r;
        for(i=0; i<n; i++)
    // Assume first element as maximum and minimum
    max = x[0];
    min = x[0];
    //Find maximum and minimum in all array elements.
    for(i=1; i<n; i++)
    {
    // If current element is greater than max
        if(x[i] > max)
            max = x[i];
        // If current element is smaller than min
        if(x[i] < min)
            min = x[i];
    }
    // Print maximum and minimum element
    cout<<"\nMaximum element =" << max <<endl;
    cout<<"Minimum element =" << min <<endl;
    r = max-min;
    cout<<"Range = ("<<max<<" - "<<min<<")"<<endl;
    cout<<"Range = "<<r;
    cout<<"\n";
    cout<<"Variance(s^2) = (SumX^2 - ((SumX)^2-n)/(n-1))"<<endl;
    cout<<"Variance(s^2) = ("<<allx2sum<<" - "<<allxsum<<"^2 / "<<n<<"/("<<n<<"-1)"<<endl;
    s2 = (allx2sum - (pow(allxsum,2)/n))/(n-1);
    cout<<"Variance(s^2) = "<<s2<<endl;
    cout<<"\n"<<endl;
    cout<<"standard deviation = square root(variance)"<<endl;
    s = sqrt(s2);
    cout<<"standard deviation = "<<s<<endl;
return 0;
}
