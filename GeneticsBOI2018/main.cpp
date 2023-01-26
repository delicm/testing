#include <bits/stdc++.h>

using namespace std;

int n, k, m;

vector <vector <char>> v;

int diff(vector <char> a, vector <char> b) // O(M)
{
    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        if(a[i] != b[i]) cnt++;
    }
    return cnt;
}

void bash()
{
    vector <bool> kTrue;
    kTrue.resize(n+1, 1);
    int sol = 1;

    for(int i = 1; i <= n; i++)
    {
        //if(kTrue[i] == 0) continue;
        for(int j = i+1; j <= n; j++)
        {
            if(diff(v[i], v[j]) != k)
            {
                kTrue[i] = 0;
                kTrue[j] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++)
        if(kTrue[i]) sol = i;

    cout << sol;
    exit(0);

}

int main()
{
    cin >> n >> m >> k;
    if(n > 100 || m > 100) return 0;
    v.resize(n+1);
    for(int i = 1; i <= n; i++) v[i].resize(m);

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
            cin >> v[i][j];

    if(n <= 100 && m <= 100) bash();

    return 0;
}
