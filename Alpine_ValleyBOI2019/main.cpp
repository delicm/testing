#include <bits/stdc++.h>

using namespace std;

int n, s, q, e;
int globalCnt = 0;
bool swtch = 1;

vector <vector <pair<int, int>>> g;
vector <pair<int, int>> edge;
vector <bool> shop;

vector <int> level;
vector <pair<int, int>> levelOrd;
vector <bool> vis;

void dfs(int v)
{
    if(vis[v]) return;
    vis[v] = 1;
    levelOrd[v].first = globalCnt;
    globalCnt++;
    for(auto u : g[v]) dfs(u.first);
    levelOrd[v].second = globalCnt;
    globalCnt++;
    return;
}

void bfs(int e)
{
    queue <pair<int, int>> q;
    q.push({e, 0});

    while(!q.empty())
    {
        int s = q.front().first, d = q.front().second;
        q.pop();

        if(level[s] < d) continue;
        level[s] = d;
        for(auto v : g[s])
        {
            q.push({v.first, d+1});
        }
    }
}

bool escape(int I, int R)
{
    int up = edge[R].first, down = edge[R].second;
    if(levelOrd[up].first > levelOrd[down].first) down = up;

    if(down == I) return 0;
    if(levelOrd[down].first < levelOrd[I].first && levelOrd[down].second > levelOrd[I].second) return 0;
    return 1;
}

int leftShop(int R)
{
    int i = R;
    int sol = 0;
    while(!shop[i] && i > 0)
    {
        int ind = 0;
        if(g[i][0].first != i-1) ind++;
        sol += g[i][ind].second;
        i--;
    }
    if(shop[0] == 0 && i == 0) return INT_MAX;
    else return sol;
}

int rightShop(int R)
{
    int i = R;
    int sol = 0;
    while(!shop[i] && i < n-1)
    {
        int ind = 0;
        if(g[i][0].first != i+1) ind++;
        sol += g[i][ind].second;
        i++;
    }
    if(shop[n-1] == 0 && i == n-1) return INT_MAX;
    else return sol;
}

int main()
{
    cin >> n >> s >> q >> e;
    int I, R;

    g.resize(n+1);
    shop.resize(n+1, 0);
    levelOrd.resize(n+1);
    level.resize(n+1);
    vis.resize(n+1, 0);
    edge.push_back({0, 0});

    for(int i = 0; i < n-1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
        edge.push_back({a, b});
        if(abs(a-b) != 1) swtch = 0;
    }

    for(int i = 0; i < s; i++)
    {
        int x; cin >> x;
        shop[x] = 1;
    }

    dfs(e);

    if(s == n)
    {
        while(q--)
        {
            cin >> I >> R;
            if(escape(R, I)) cout << "escaped" << endl;
            else cout << 0 << endl;
        }

        return 0;
    }

    if(swtch)
    {
        while(q--)
        {
            cin >> I >> R;
            if(escape(R, I))
            {
                cout << "escaped" << endl;
                continue;
            }
            int d = INT_MAX;
            d = min(d, leftShop(R));//left off here
        }

        return 0;
    }

    return 0;
}
