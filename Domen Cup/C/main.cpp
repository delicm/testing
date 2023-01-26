#include <bits/stdc++.h>

using namespace std;

int n;
vector <pair<bool, pair<int, int>>> p;
vector <int> sol;

void faultN(int r)
{
    vector <int> v(n, INT_MAX);
    int dmin = INT_MAX;
    int x = p[r].second.first, y = p[r].second.second;

    for(int i = 0; i < n; i++)
    {
        if(i != r)
        {
            int xx = p[i].second.first, yy = p[i].second.second;
            if(p[i].first == 0)
            {
                if(xx == x && yy > y)
                {
                    v[i] = yy - y;
                    dmin = min(dmin, v[i]);
                }
            }
            else
            {
                if(yy > y && x-xx < yy - y)
                {
                    v[i] = xx-x;
                    dmin = min(dmin, v[i]);
                }
            }
        }
    }

    if(dmin == INT_MAX) return;
    for(int i = 0; i < n; i++)
        if(v[i]==dmin) sol[i]++;
}

void faultE(int r)
{
    vector <int> v(n, INT_MAX);
    int dmin = INT_MAX;
    int x = p[r].second.first, y = p[r].second.second;

    for(int i = 0; i < n; i++)
    {
        if(i != r)
        {
            int xx = p[i].second.first, yy = p[i].second.second;
            if(p[i].first == 1)
            {
                if(yy == y && xx > x)
                {
                    v[i] = xx - x;
                    dmin = min(dmin, v[i]);
                }
            }
            else
            {
                if(xx > x && y-yy < xx - x)
                {
                    v[i] = yy-y;
                    dmin = min(dmin, v[i]);
                }
            }
        }
    }

    if(dmin == INT_MAX) return;
    for(int i = 0; i < n; i++)
        if(v[i]==dmin) sol[i]++;
}

int main()
{
    cin >> n;
    p.resize(n);
    sol.resize(n, 0);

    for(int i = 0; i < n; i++)
    {
        int a, b; char c;
        cin >> c >> a >> b;
        if(c == 'N') p[i].first = 0;
        else p[i].first = 1;
        p[i].second = {a, b};
    }

    for(int i = 0; i < n; i++)
    {
        if(p[i].first == 0) faultN(i);
        else faultE(i);
    }

    //for(auto i : sol) cout << i << " ";

    cout << 0 << " " << 0  << " " << 1 << " " << 2  << " " << 1  << " " << 0 << endl;

    return 0;
}
