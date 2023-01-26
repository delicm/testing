#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    pair <int, int> p[n];

    for(int i = 0; i < n; i++) cin >> p[i].first;
    for(int i = 0; i < n; i++) cin >> p[i].second;
    sort(p, p+n);

    vector <int> x;

    for(int i = 0; i < n; i++)
    {
        auto k = lower_bound(x.begin(), x.end(), p[i].second);
        if(k == x.end()) x.push_back(p[i].second);
        else *k = p[i].second;
    }

    cout << x.size();

    return 0;
}
