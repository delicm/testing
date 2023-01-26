#include <iostream>
#include <cmath>

using namespace std;

pair<bool, pair<int, int>> check(int n, int a, int deg)
{
    int cnt=0;
    while(n%a==0)
    {
        cnt++;
        n = n/a;
    }
    if(n!= pow(a+1, deg-cnt)) return make_pair(0,make_pair(1,1));
    return make_pair(1,make_pair(a,cnt));
}

int main()
{
    long long n; cin >> n;

    int m = log(n)/log(2);

    if(pow(2,m) == n)
    {
        cout << -1;
        return 0;
    }

    pair<bool, pair<int, int>> a[m+1];
    int cnt = 0;

    for(int i = 1; i <= m; i++)
    {
        float q = (float)1/i;
        long long t = pow(n, q);
        a[i] = check(n, t, i);
        if(a[i].first) cnt++;
    }

    cout << cnt << endl;
    for(int i = 1; i <= m; i++)
    {
        if(a[i].first)
        {
            cout << i << " ";
            for(int j = 0; j < a[i].second.second; j++)
            {
                cout << a[i].second.first << " ";
            }
            for(int j = 0; j < i-a[i].second.second; j++)
            {
                cout << a[i].second.first+1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
