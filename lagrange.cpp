#include<bits/stdc++.h>
using namespace std;
using namespace std;

double lagrange(int n,double x[],double y[],double xp)
{
    double yp = 0;
    for(int i=1; i<=n; i++)
    {
        double p=1;
        for(int j=1; j<=n; j++)
        {
            if(i!=j)
            {
                p = p* (xp - x[j])/(x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
    }
    return yp;
}

int main()
{
    double x[100], y[100], xp, yp=0, p;
    int i,j,n;

    /* Input Section */
    cout<<"Enter number of data: ";
    cin>>n;
    cout<<"Enter data:"<< endl;
    for(i=1; i<=n; i++)
    {
        cout<<"x["<< i<<"] = ";
        cin>>x[i];
        cout<<"y["<< i<<"] = ";
        cin>>y[i];
    }
    cout<<"T_degc     Oxygen level"<<endl;
    for(int i=10;i<=70;i+=5)
    {
        cout<<i<<"      "<<lagrange(4,x,y,i)<<endl;
    }
    return 0;
}
