#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float H, U, D;
    float F;
    int T;
    while(scanf("%f %f %f %f", &H, &U, &D, &F), H!=0)
    {
        float f = F/100;
        if((U+f*U/2-D)*(U+f*U/2-D) < 2 * (-f*U)*(D-H))
        {
            cout << "failure on day " << (int)(1/f+0.5) << endl;
        }
        else{
        T = (int)((-(U+f*U/2-D)-sqrt((U+f*U/2-D)*(U+f*U/2-D) - 2 * (-f*U)*(D-H)))/(-f*U) + 0.5);
        cout << "success on day " << T << endl;
        }
    }
    return 0;
}
