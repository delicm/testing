#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main()
{
    cin >> n;
    int a, b, x;
    cin >> a >> b;

    x = 60*a+b;
    int y[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        y[i] = a*60+b;
    }

    sort(y, y+n);
    int mark = n;
    for(int i = 0; i < n; i++)
    {
        if(x < y[i])
        {
            mark = i;
            break;
        }
    }

    cout << n-mark;

    return 0;
}
