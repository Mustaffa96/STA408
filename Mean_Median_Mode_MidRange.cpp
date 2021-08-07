#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int i,j,k,n, temp;
    cout<<"\nEnter the no. of data pairs to be entered:\n";        //To find the size of arrays
    cin>>n;
    double x[n],a,b;
    cout<<"\nEnter the x-axis values:\n";                //Input x-values
    for (i=0;i<n;i++)
        cin>>x[i];

    double xsum=0,allxsum=0, xb;                //variables for sums/sigma of xi
    for (i=0;i<n;i++)
    {
        xsum=xsum+x[i];                        //
        allxsum=xsum;

    }

    cout<<"S.no"<<setw(5)<<"x"<<endl;
    cout<<"--------------------------\n";
       for (i=0;i<n;i++)
        cout<<i+1<<"."<<setw(8)<<x[i]<<endl;

    xb = allxsum/n;
    cout<<"Mode,Xbar = "<<allxsum<<"/"<<n<<endl;
    cout<<"Mode,Xbar = "<<xb<<endl;

    	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(x[i]>x[j])
			{
				temp = x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
	}

    cout<<"\n ";
	//print sorted array elements
	cout<<"Sorted (Ascending Order) Array elements:"<<endl;
	for(i=0;i<n;i++)
		cout<<x[i]<<"\t";


	double median;
    if(n%2==0) {
        median = (x[(n-1)/2]+x[((n-1)/2)+1])/2; // median finding
        cout<<"\n";
        cout<<"median = "<<median<<endl;
    }
    else {
        median = x[(n)/2];
        cout<<"\n";
        cout<<"median = "<<median<<endl;
    }

    int number = x[0];
    int mode = number;
    int count = 1;
    int countMode = 1;

for (int i=1; i<n; i++)
{
      if (x[i] == number)
      { // count occurrences of the current number
         ++count;
      }
      else
      { // now this is a different number
            if (count > countMode)
            {
                  countMode = count; // mode is the biggest ocurrences
                  mode = number;
            }
           count = 1; // reset count for the new number
           number = x[i];
  }
}

cout << "mode : " << mode <<" because it occur "<<countMode<<" times"<< endl;

    int min, max;
    double mr;
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
    mr = (min+max)/2;
    cout<<"Mid Range = ("<<min<<" + "<<max<<")/2"<<endl;
    cout<<"Mid Range = "<<mr;

    return 0;
}
