#include <bits/stdc++.h>

using namespace std;

#define int long long int

int n;
int sol = 0;
int mod = 1000000007;

vector <int> h;
vector <int> w;
vector <int> X;
vector <int> Y;

pair <int, int> sorting;

int f(int A, int B)
{
    int a1 = (A*(A+1)/2)%mod;
    int a2 = ((B+1)*B/2)%mod;

    int sl = (a1*a2)%mod;

    return sl;
}

void fillX()
{

}

int32_t main()
{
    cin >> n;

    h.resize(n);
    w.resize(n);
    X.resize(n);
    Y.resize(n);
    sorting.resize(n);

    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> w[i];

    for(int i = 0; i < n; i++) sorting[i] = {h[i], i};
    sort(sorting.begin(), sorting.end());

    return 0;
}
