#include <bits/stdc++.h>

using namespace std;

int n;
int jump[2505][21];
vector <pair <int, int>> p;
vector <int> q;

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

int minQ(int x, int y)
{
    if(y < x) swap(x, y);
    int k = y-x+1;
    int t = (int) log2(k);
    int tt = 1<<t;

    return min(jump[x][t-1], jump[y-tt+1][t-1]);
}

int main()
{
    cin >> n;
    p.resize(n);
    q.resize(n);

    for(int i = 0; i < n; i++) cin >> q[i];

    fillJump();

    /*for(int i = 0; i < n; i++) cout << jump[i][0] << " ";
    cout << endl;
    for(int j = 1; j <= 20; j++)
    {
        for(int i = 0; i+(1<<(j-1))+1 < n; i++)
        {
            cout << jump[i][j] << " ";//= min(jump[i][j-1], jump[i+(1<<(j-1))+1][j-1]);
        }
        cout << endl;
    }*/

    while(true)
    {
        int a, b;
        cin >> a >> b;
        cout << minQ(a, b) << " ";
    }


    return 0;
}
