#include <bits/stdc++.h>

using namespace std;

int n, k, r;

int main()
{
    cin >> n >> k >> r;
    int dnk[n];
    for(int i = 0; i < n; i++)
        cin >> dnk[i];

    vector <int> a;
    a.resize(n, -1);

    int temp[n];

    for(int i = 0; i < r; i++)
    {
        int nu, no;
        cin >> nu >> no;

        vector <int> last;
        last.resize(n+1, 0);
        last[0] = -1;

        if(dnk[0] == nu) temp[0] = 1;
        else temp[0] = 0;

        if(dnk[0] == nu && no <= 1) a[0] = max(a[0], 1);
        else a[0] = INT_MAX;

        for(int j = 1; j < n; j++)
        {
            if(dnk[j] == nu)
            {
                temp[j] = temp[j-1]+1;
                if(temp[j] >= no) a[j] = max(a[j], j-last[temp[j]-no]);
                else a[j] = INT_MAX;
                last[temp[j]] = j;
            }
            else
            {
                temp[j] = temp[j-1];
                last[temp[j]] = j;
                if(temp[j] >= no) a[j] = a[j] = max(a[j], j-last[temp[j]-no]);
                else a[j] = INT_MAX;
            }

        }
    }

    int sol = INT_MAX;
    for(int i = 0; i < n; i++)
        sol = min(sol, a[i]);

    if(sol != INT_MAX) cout << sol;
    else cout << "impossible";

    return 0;
}
