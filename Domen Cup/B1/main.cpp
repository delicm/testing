#include <bits/stdc++.h>

using namespace std;

int n;
vector <pair <int, int>> p;
vector <int> q;

int main()
{
    cin >> n;
    p.resize(n);
    q.resize(n);

    for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p, p+n);



    return 0;
}
