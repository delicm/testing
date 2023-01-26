#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

vector <vector <int>> g;
vector <int> depth;
vector <int> minn;
vector <int> maxx;

void bfs()
{
    queue <pair<int, int>> q;
    q.push({1, 0});

    for(int i = 0; i <= n; i++) depth[i] = INT_MAX;

    while(!q.empty())
    {
        int s = q.front().first, d = q.front().second;
        q.pop();

        if(depth[s] < d) continue;
        depth[s] = d;

        for(auto v : g[s]) q.push({v, d+1});
    }
}

int main()
{
    cin >> n;
    g.resize(n+1);
    depth.resize(n+1);
    minn.resize(n+1);
    maxx.resize(n+1);

    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs();

    return 0;
}
