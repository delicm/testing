#include <bits/stdc++.h>

using namespace std;

int n;
int jump[2505][21];
int jumpp[2505][21];
vector <pair <int, int>> p;
vector <int> q;
vector <int> qq;

bool cmp(pair <int, int> a, pair <int, int> b)
{
    return a.second < b.second;
}

void compressSecond()
{
    sort(p.begin(), p.end(), cmp);
    for(int i = 0; i < n; i++) p[i].second = i+1;
}

void fillJump()
{
    for(int i = 0; i < n-1; i++)
    {
        int a = q[i], b = q[i+1];
        jump[i][0] = min(a, b);
    }

    for(int j = 1; j <= 20; j++)
    {
        for(int i = 0; i+(1<<(j-1))+1 < n; i++)
        {
            jump[i][j] = min(jump[i][j-1], jump[i+(1<<(j-1))+1][j-1]);
        }
    }
}

void fillJumpp()
{
    for(int i = 0; i < n-1; i++)
    {
        int a = qq[i], b = qq[i+1];
        jumpp[i][0] = min(a, b);
    }

    for(int j = 1; j <= 20; j++)
    {
        for(int i = 0; i+(1<<(j-1))+1 < n; i++)
        {
            jumpp[i][j] = min(jumpp[i][j-1], jumpp[i+(1<<(j-1))+1][j-1]);
        }
    }
}

int minQ(int x, int y)
{
    if(y < x) swap(x, y);
    int k = y-x+1;
    int t = (int) log2(k);
    int tt = 1<<t;

    if(x == y) return q[x];
    return min(jump[x][t-1], jump[y-tt+1][t-1]);
}

int maxQ(int x, int y)
{
    if(y < x) swap(x, y);
    int k = y-x+1;
    int t = (int) log2(k);
    int tt = 1<<t;

    if(x == y) return -qq[x];
    return -min(jumpp[x][t-1], jumpp[y-tt+1][t-1]);
}

int main()
{
    cin >> n;
    p.resize(n);
    q.resize(n);
    qq.resize(n);

    for(int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;

    compressSecond();
    sort(p.begin(), p.end());
    for(int i = 0; i < n; i++) q[i] = p[i].second;
    for(int i = 0; i < n; i++) qq[i] = -q[i];

    fillJump();
    fillJumpp();

    /*for(int j = 1; j <= 20; j++)
    {
        for(int i = 0; i+(1<<(j-1))+1 < n; i++)
        {
            cout << jump[i][j] << " ";//= min(jump[i][j-1], jump[i+(1<<(j-1))+1][j-1]);
        }
        cout << endl;
    }*/

    long long sol = n*(n+1);

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(maxQ(i, j)-minQ(i, j) == j-i) sol--;
        }
    }

    cout << sol+1;

    return 0;
}
