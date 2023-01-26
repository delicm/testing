#include <iostream>

using namespace std;

int main()
{
    double H, U, F, D;
    int T=0;
    while(scanf("%lf %lf %lf %lf", &H, &U, &D, &F), H!=0)
    {
            double h = U;
            double u = U;
            T = 1;
            while(h > 0 && h < H)
            {
                h-= D;
                u = u - F*U/100;
                h = h + max(0.0, u);
                T++;
            }
            if(h <= 0) {cout << "failure on day " << T << endl;}
            else{cout << "success on day " << T << endl;}
    }
    return 0;
}
