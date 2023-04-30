#include<bits/stdc++.h>
using namespace std;
long double fx(int func[],int n,double x)
{
    long double result = func[n];
    for(int i=n-1;i>=0;i--)
    {
        result = result*x + func[i];
    }
    return result;
}
void derivative(int func[],int n,int der[])
{
    for(int i=n;i>=1;i--)
    {
        der[i-1] = func[i] * i;
    }
}

int main()
{
    cout<<setprecision(8)<<fixed;
    cout<<"Enter the total no. of power::: ";
    int n;
    cin>>n;
    int poly[n+1];
    int der[n];
    cout<<"Enter the co-efficients of the polynomial:"<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<"x^"<<i<<"::";
        cin>>poly[i];
    }
    cout<<"The polynomial is :::  ";
    for(int i=n;i>=0;i--)
    {
        if(i!=n && poly[i]>=0)
            cout<<"+";
        cout<<poly[i]<<"x^"<<i<<" ";
    }
    cout<<"Intital a---->";
    long double a;
    cin>>a;
    cout<<"Intital b---->";
    long double b;
    cin>>b;
    cout<<"Tolerable error---->";
    long double e;
    cin>>e;
    cout<<"Increment size ds---->";
    long double ds;
    cin>>ds;
    long double x1,x2;
    derivative(poly,n,der);
    long double cond2 = (b * fx(der,n-1,b))/fx(poly,n,b);
    //if(cond2>1)
    //{
    //    cout<<"System is ill conditioned";
    //    exit(0);
    //}
    //else
    //    cout<<"System is well conditioned"<<endl;
    cout<<"itr     Root No.   Value of Root"<<endl;
    int rootNo = 1;
    do
    {
        //cout<<"Here"<<endl;
        int itr = 0;
        x1 = a;
        x2 = a + ds;
        if((fx(poly,n,x1)*fx(poly,n,x2))>0)
        {
            //cout<<"x1 = "<<x1<<" x2 = "<<x2<<endl;
            //cout<<"fx1 = "<<fx(poly,n,x1)<<" fx2 = "<<fx(poly,n,x2)<<endl;
            a = x2;
            continue;
        }
        long double xr,err;
        do
        {
            //cout<<"Here2"<<endl;
            xr = (x1+x2)/2;
            if((fx(poly,n,x1)*fx(poly,n,xr))<0)
                x2=xr;
            else
                x1=xr;

            err = fabs((x2-x1)/x2);
            itr++;
        }
        while(err>=e);
        cout<<itr<<"       "<<rootNo++<<"        "<<xr<<endl;
        a = x2;
    }while(x2<b);
    return 0;
}

