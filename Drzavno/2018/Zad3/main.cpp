#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <pair<int, int>> prices;
vector <vector <pair<int, int>>> combo;

void traverse()
{
    sort(prices.begin(), prices.begin());

    for(int i = 1; i <= n; i++)
    {
        int index = prices[i].second, price = prices[i].first;

        for(int j = 0; j < combo[index].size(); j++)
        {
            int a = combo[index][j].first, b = combo[index][j].second;
            prices[i].first = min(price, prices[a].first+prices[b].first);
        }
    }
}

int main()
{
    cin >> n >> m;

    prices.resize(n+1);
    combo.resize(n+1);

    for(int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        prices[i] = {a,i};
    }
    for(int i = 1; i <= m; i++)
    {
        int a, x, y; cin >> a >> x >> y;
        combo[a].push_back({x,y});
    }

    for(int i = 1; i <= n; i++) traverse();

    for(int i = 1; i <= n; i++)
    {
        if(prices[i].second==1)
        {
            cout << prices[i].first;
            return 0;
        }
    }

    return 0;
}
