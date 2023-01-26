#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector <vector<pair<int, int>>> g;
vector <int> best;

void dijsktra()
{
    priority_queue <pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty())
    {
        int vertex = q.top().first, cost = q.top().second;
        q.pop();

        for(auto v : g[vertex])
        {
            int next = v.first, p = v.second;
            if(p+cost<best[next])
            {
                best[next] = p+cost;
                q.push({next, p+cost});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    g.resize(n+1);
    best.resize(n+1);

    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        best[i] = INT_MAX;
        g[0].push_back({i, x});
    }
    for(int i = 1; i <= m; i++)
    {
        int a, x, y; cin >> a >> x >> y;
        g[x].push_back({a, g[0][y-1].second});
        g[y].push_back({a, g[0][x-1].second});
    }

    dijsktra();

    cout << best[1];

    return 0;
}
