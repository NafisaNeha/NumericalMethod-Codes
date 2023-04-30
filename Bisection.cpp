#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

float f(float x)
{
    return (x*x)- 4*(x)- 10;
}
int main()
{
    float a, b, c, ab_error, re_error, preRoot;
    int count=0;
    int i=1;

    cout<<"Enter the lower and upper bounds: "<<endl;
    cin>> a >> b;

    if(f(a)*f(b)>0)
    {
        cout<<"No root"<<endl;
    }
    else
    {
        do{
            c = (a+b)/2;
            ab_error = abs(c - preRoot);
            re_error = abs((ab_error)/c);

            if(f(c)==0)
            {
                break;
            }
            if(f(a)*f(c)<0)
            {
                count++;
                cout<< i++ <<" Iteration: " << "Root: " << c <<" Absolute error: "<<ab_error<<" Relative error: "<< re_error<< endl;
                b=c;

            }
            else
            {
                count++;
                cout<< i++ <<" Iteration: " << "Root: " << c <<" Absolute error: "<<ab_error<<" Relative error: "<< re_error<<endl;
                a=c;
            }
            preRoot=c;

        }while(fabs(f(c))>0.001);


        cout<<"Number of iterations: "<< count << endl;
        cout<<"The approximate root is: " <<c<<endl;
        cout<<"The Absolute Error: " <<ab_error<<endl;
        cout<<"The Relative Error: " <<re_error<<endl;


    }
    return 0;
}

