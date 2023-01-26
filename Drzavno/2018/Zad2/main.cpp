#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;

    if(n%3 == 0)
    {
        cout << n/3*7;
        return 0;
    }
    if(n%3 == 1)
    {
        if(n==1)
        {
            cout << 0; return 0;
        }
        cout << (n/3-1)*7+4;
        return 0;
    }
    if(n%3 == 2)
    {
        cout << (n/3)*7+1;
        return 0;
    }

    return 0;
}
