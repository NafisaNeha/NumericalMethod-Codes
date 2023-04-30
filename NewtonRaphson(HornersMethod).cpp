#include<bits/stdc++.h>
using namespace std;
float f1,x1;

float horner(float arr[],int n, float x)
{
    float result = arr[n];

    for (int i=n; i>0; i--)
    {
        result = result*x + arr[i];
    }
    return (float)result;
}

int main()
{
    int counter=1;
    int n;
    float xo=5;
    float e=0.001;
    cout<<"ENTER THE TOTAL NO. OF POWER ::: " ;
    cin>>n;
    float arr[n+1];
    for(int i=0 ;i<=n ;i++)
    {
        cout<<"x^"<<i<<":: ";
        cin>>arr[i];
    }
    int n1=sizeof(arr)/sizeof(arr[0]);
    cout<<"The polynomial is ::: ";

    for(int i=n ;i>=0 ;i--)
    {
        if(i!=n && arr[i]>=0)
        {
            cout<<"+";
        }
        cout<<arr[i]<<"x^"<<i<<" ";
    }
    cout<<endl;
    float arr_dev[n];
    for(int i=0 ;i<n ;i++)
    {
        cout<<"x^"<<i<<":: ";
        cin>>arr_dev[i];
    }
    int n2=sizeof(arr_dev)/sizeof(arr_dev[0]);
    cout<<"INTIAL XO----> "<<xo<<endl;
    do{
        if(horner(arr_dev,n2,xo)==0.0)
        {
            cout << "Mathematical error: "<< endl;
        }
        x1=xo-(horner(arr,n1,xo)/horner(arr_dev,n2,xo));
        cout << counter << " No. iteration: "<< x1<<endl;
        counter++;
        xo=x1;

        f1=horner(arr,n1,x1);

    }while(f1>e);
    cout << "Root is: "<< x1 << endl;

    return 0;
}

