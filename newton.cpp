#include <bits/stdc++.h>
using namespace std;

int n, coount=0;
double x[100], y[100][100],approxres[100],sumx=0,sumy=0,trueres[100];

double productTerm(int i,double value)
{
    double product = 1;
    for (int j = 0; j < i; j++)
    {
        product = product * (value - x[j]);
    }
    return product;
}

void dividedDifferenceTable()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);

        }
    }
}

double applyFormula(double value)
{
    double sum = y[0][0];
    for (int i = 1; i < n; i++)
    {
      sum = sum + (productTerm(i, value) * y[0][i]);
    }
    return sum;
}


int main()
{
    cout<<"Enter number of data : ";
    cin>>n;
    cout<<"Enter the saturation concentration of dissolved oxygen in water as a function of temperature and chloride concentration:  "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i][0];
        sumx=sumx+x[i];
        sumy=sumy+y[i][0];
    }
    dividedDifferenceTable();

    cout<<"T_degC temperature in degree Celsius\tDissolved Oxygen (mg/L) for temperature (degree Celsius) and concentration of Chloride C=10 g/L"<<endl;

    double approxx,truex;
    double value=40,h=5;
    while(value<=70)
    {
        approxx=applyFormula(value);
        approxres[coount]=approxx;

        printf("%.2f\t\t\t\t\t%f\n",value,approxx);
        coount++;
        value=value+h;
    }

    cout<<"\nFunction\t\t\t\t\t  Value\n";

    double summ=0;

    for(int i=0;i<n;i++)
    {
        summ=summ+pow((y[i][0]-approxres[i]),2);
    }
    printf("Mean Squared Error (MSE)\t\t\t %f\n",summ/n);
    printf("A0 \t\t\t\t\t\t %f\n",y[0][0]);
    printf("A1 \t\t\t\t\t\t %f\n",y[0][1]);
    printf("A2 \t\t\t\t\t\t %f\n",y[0][2]);
    printf("A3 \t\t\t\t\t\t %f\n",y[0][3]);
    return 0;
}


