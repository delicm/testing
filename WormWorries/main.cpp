#include <iostream>

using namespace std;

int n, m, k;

int H(int x, int y, int z)
{
    int t;
    cout << "? " << x << " " << y << " " << z << endl;
    cin >> t;
    return t;
}

void terminate(int x, int y, int z)
{
    cout << "! " << x << " " << y << " " << z << endl;
    exit(0);
}

int main()
{
    int q;
    cin >> n >> m >> k >> q;

    if(m == 1 && k == 1)
    {
        int l = 1, r = n;
        int x, y;
        //int vall, valr;
        while(l < r-1)
        {
            int a = (l+r)/2;
            x = H(a, 1, 1);
            y = H(a-1, 1, 1);
            if(x >= y) l = a;
            else r = a-1;
        }
        if(l == r-1)
        {
            if(x>y) terminate(r, 1, 1);
            else terminate(l, 1, 1);
        }
        if(l == r) terminate(l, 1, 1);
    }

    return 0;
}
