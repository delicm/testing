#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> s;

void init()
{
    s.resize(n);
    map <string, int> names;
    map <int, string> l;

    for(int i = 0; i < n; i++)
    {
        string S, T; cin >> S >> T;
        names[S] = i;
        l[i] = T;
    }

    for(int i = 0; i < n; i++) s[i] = names[l[i]];
}

int bash()
{
    int m = n+1;
    for(int t = 1; t < (1<<n); t++)
    {
        vector <bool> vis;
        vis.resize(n, 0);
        bool good = 1;
        for(int i = 0; i < n; i++)
        {
            if(!(t&(1<<i)))
            {
                if(vis[s[i]])
                {
                    good = 0; break;
                }
                vis[s[i]] = 1;
                if(!(t&(1<<s[i])) && i != s[s[i]])
                {
                    good = 0; break;
                }
                if(s[i] == i)
                {
                    good = 0; break;
                }
            }
        }
        if(good)
        {
            int sz = 0;
            for(int i = 0; i < n; i++)
                if(t&(1<<i)) sz++;
            m = min(m, sz);
        }
    }
    return m;
}

bool case2()
{
    vector <bool> v;
    v.resize(n, 0);
    for(int i = 0; i < n; i++)
    {
        if(v[s[i]]) return 0;
        v[s[i]] = 1;
    }
    return 1;
}

int cntOdds()
{
    vector <bool> vis;
    vis.resize(n, 0);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            int j = s[i];
            int sol = 1;
            while(j != i)
            {
                vis[j] = 1;
                j = s[j];
                sol++;
            }
            if(sol%2==1) cnt += sol/2+1;
            else if(sol != 2) cnt += sol/2;
        }
    }
    return cnt;
}

int main()
{
    cin >> n;
    init();


    if(n % 2 == 1)
    {
        cout << -1;
        return 0;
    }

    int sol = 0;

    if(case2())
    {
        sol = cntOdds();
        cout << sol;
        return 0;
    }

    if(n <= 20)
    {
        sol = bash();
        cout << sol;
        return 0;
    }



    return 0;
}
