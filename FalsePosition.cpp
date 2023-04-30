#include<stdio.h>
#include<math.h>

double f (float x){
return (x*x*x-x-1);
}

int main()
{
float d,y;
int iteration = 0;
float a=1,b=2;
float c;
if (f(a)*f(b) > 0)
{
printf ("Wrong Guess!!");
}
printf("Itr\\t\\troot\\t\\t\\terror\\n");
do{

        d = c;
    c=a-((f(a)-(b-a))/(f(b)-f(a)));


    if (f(a)*f(c)<0){
        b=c;
    }
    else
       {
         a=c;
       }

    iteration = iteration +1;
    printf("%d\\t\\t%f\\t%f\\n", iteration,c,fabs(d-c));



}while(fabs(d-c)>=0.0001);

printf("\\n Root = %f", c);
printf("\\n Abs Error = %f", (d-c));




printf("\\n Iteration number = %d", iteration);
}
