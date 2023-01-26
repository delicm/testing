#include <bits/stdc++.h>

using namespace std;

int lcs(string a, string b, int i, int j)
{
    int sol = 0, c = 0;
    int x = a.length(), y = b.length();
    int z = min(x, y);
    while(a[(i+c)%x] == b[(j+c)%y] && c < z)
    {
        sol++; c++;
    }
    return sol;
}

pair<int,pair<int, int>> solve(string s, string t)
{
    int x = s.length(), y = t.length();
    pair<int,pair<int, int>> sol = make_pair(0, make_pair(0, 0));

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            int temp = lcs(s, t, i, j);
            if(temp > sol.first)
            {
                sol.first = temp;
                sol.second = {i, j};
            }
        }
    }
    return sol;             //far from done
}

int main()
{
    string s, t;
    cin >> s >> t;

    pair<int,pair<int, int>> sol = solve(s, t);

    /*reverse(t.begin(), t.end());

    pair<int,pair<int, int>> sol0 = solve(s, t);

    if(sol.first < sol0.first) swap(sol, sol0);*/

    cout << sol.first << endl << sol.second.first << " " << sol.second.second;

    return 0;
}
