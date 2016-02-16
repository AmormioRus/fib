#include <iostream>
//#include <QTime>
#include <cmath>
using namespace std;

//int fib(int k)
//{
//return k<2?1:fib(k-2)+fib(k-1);
//}

void fib2(int k,int& ck,int& ck1)

{
    if(k<2)
    {
      ck=ck1=1  ;

    }
    else
    {
        fib2(k-1, ck1, ck);
     ck+=ck1;
    }
}

int fib2a(int k)
{
    int ck, ck1;
    fib2(k,ck,ck1);
    return ck;
}



bool realRoots(int a, int b, int c, double& x1, double& x2)
{

    double D = double(b)*b/(4*a*a)- double(c)/a;

    if (D<0)
    {
        return false;
    }
    else
    {
        x1 = - double(b)/(2*a)+sqrt(D);
        x2 = - double(b)/(2*a)-sqrt(D);
        return true;
    }

}

bool identify(double x, int& a, int& b, int& c)
{
    int N=10;
    const double tolerance = 1e-6;
    for (a=-N; a<=N; ++a)
        for (b=-N; b<=N; ++b)
            for (c=-N; c<=N; ++c)
            {
                double x1, x2;
                if (realRoots(a,b,c, x1, x2))
                {
                    if (fabs(x1-x)<tolerance)
                        return true;
                    if (fabs(x2-x)<tolerance)
                        return true;
                }
            }
    return false;
}

double limfib()
{
    const double tolerance = 1e-8;
    double r = 0;
    for (int k=1; ; ++k)
    {
        int ck, ck1;
        fib2(k,ck,ck1);
        double rk = double (ck) / ck1;
     if (fabs(r-rk)<tolerance)
         return rk;

     r=rk;
    }
}


int main()
{

//    double x1, x2;
//    if (realRoots( 1, -5, 6, x1, x2))
//        cout <<x1<< endl <<x2<< endl;
//    else
//        cout <<"No roots"<< endl;

//    cout<<fib2a(8)<<endl;
//    int ck, ck1;
//    fib2(8, ck, ck1);
//    cout <<ck<<endl;
    cout<<limfib()<<endl;
    int a,b,c;
    if (identify(limfib(),a,b,c))
        cout<<a<<endl<<b<<endl<<c<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}


