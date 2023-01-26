#include <bits/stdc++.h>

using namespace std;

int n, k, m;
int M = 0;

vector <int> c;
vector <vector <int>> g;
vector <vector <int>> f;



int main()
{
    cin >> n >> m >> k;
    c.resize(n+1);
    g.resize(n+1);
    f.resize(n+1);
    for(int i = 1; i <= n; i++) f[i].resize((1<<k));

    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    long long ans  = 0;



    cout << ans;

    return 0;
}
