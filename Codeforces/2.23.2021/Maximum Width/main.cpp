#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    char s[n];
    char t[m];

    vector <int> x[26];
    int last[m];

    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        x[s[i]-97].push_back(i);
    }
    for(int i = 0; i < m; i++) cin >> t[i];

    int nextElement = INT_MAX;
    for(int i = m-1; i >= 0; i--)
    {
        auto temp = lower_bound(x[t[i]-97].begin(), x[t[i]-97].end(), nextElement);
        temp--;
        last[i] = *temp;
        nextElement = *temp;
    }

    /*for(int i = 0; i < 5; i++)
    {
        for(auto v : x[i])
            cout << v << " ";
        cout << endl;
    }*/

    //for(int i = 0; i < m; i++) cout << last[i] << " ";

    int sol = 0, NCpos = 0;
    char nextChar = t[0];
    for(int i = 0; i < n; i++)
    {
        if(s[i] == nextChar)
        {
            NCpos++;
            if(NCpos == m) break;
            nextChar = t[NCpos];
            sol = max(sol, last[NCpos]-i);
        }
    }

    cout << sol;

    return 0;
}
