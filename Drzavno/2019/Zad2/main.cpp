#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;

    pair<int, int> x[n];

    for(int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        x[i-1] = {max(abs(a), abs(b)), i};
    }

    sort(x, x+n);

    for(int i = 0; i < n; i++)
    {
        if(x[i].first < i+1)
        {
            cout << -1;
            return 0;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << x[i].second << " ";
    }

    return 0;
}
