#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> p;
vector <int> prefix;
vector <int> pos[1001];

int main()
{
    cin >> n;
    p.resize(n);
    prefix.resize(n);

    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) pos[p[i]].push_back(i);
    prefix[0] = p[0];
    for(int i = 1; i < n; i++) prefix[i] = prefix[i-1]+p[i];

    int sol = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int av = prefix[j]-prefix[i]+p[i];
            if(av%(j-i+1) != 0) continue;
            av /= j-i+1;
            for(auto T : pos[av])
            {
                if(T >= i && T <= j)
                {
                    sol++;
                    break;
                }
            }
        }
    }

    cout << sol;

    return 0;
}
