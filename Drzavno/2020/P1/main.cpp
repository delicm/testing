#include <iostream>
#include <map>

using namespace std;

int main()
{
    int S;
    cin >> S;
    bool m[S]; int r = 0;

    for(int a = 0; a*a < S; a++)
    {
        for(int b = 0; a*a+b*b<S; b++)
        {
            if(!m[a*a+b*b])
            {
                m[a*a+b*b] = 1;
                r++;
            }
        }
    }

    cout << r;

    return 0;
}
