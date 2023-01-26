#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector <vector<pair<int, int>>> g;
vector <pair<int, float>> f;
vector <bool> vis;
stack <int> last;

float x =2e10;
bool swtch = 0;

void termination()
{
    cout << "NO";
    exit(0);
}

void setX()
{
    swtch = 1;
    while(!last.empty())
    {
        int s = last.top();
        last.pop();
        f[s] = {0, f[s].first * x + f[s].second};
    }
}

void unsetValue()
{
    vector <int> v;
    vector <int> index;
    while(!last.empty())
    {
        int s = last.top();
        last.pop();
        index.push_back(s);
        if(f[s].first == 1) v.push_back(-f[s].second);
        if(f[s].first == -1) v.push_back(f[s].second);
    }
    sort(v.begin(), v.end());
    x = v[v.size()/2];
    for(auto u : index) f[u] = {0, f[u].first * x + f[u].second};
}

void dfs(int v, int parent, int color)
{
    //cout << v << " ";
    pair <int, float> p;
    if(color == 1) p = {-f[parent].first, 1-f[parent].second};
    if(color == 2) p = {-f[parent].first, 2-f[parent].second};

    if(vis[v])
    {
        if(f[v] == p) return;
        if(f[v].first == p.first && f[v].second != p.second) termination();
        x = (f[v].second - p.second)/(p.first-f[v].first);
        setX();
        return;
    }

    vis[v] = 1;
    f[v] = p;
    last.push(v);

    for(auto u : g[v]) dfs(u.first, v, u.second);
    return;
}

int main()
{
    int n, m; cin >> n >> m;
    g.resize(n+1);
    f.resize(n+1);
    vis.resize(n+1, 0);

    for(int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            swtch = 0;
            g[0].push_back({i, 1});
            f[0] = {-1, 1};
            dfs(i, 0, 1);
            if(!swtch) unsetValue();
        }
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++)
        cout << f[i].second << " ";


    return 0;
}
