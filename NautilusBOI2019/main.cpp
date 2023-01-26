#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int r, c, M;
char m[1005];

bitset <505> x[505][1005];
bitset <505> s[505];

void printStuff(int k)
{
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cout << x[i][k][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void traverse(int k)
{
    if(k == M+1) return;

    if(m[k] == '?')
        for(int i = 1; i <= r; i++) x[i][k] = (x[i][k-1] << 1 | x[i][k-1] >> 1 | x[i+1][k-1] | x[i-1][k-1])&s[i];
    else if(m[k] == 'W')
        for(int i = 1; i <= r; i++) x[i][k] = (x[i][k-1] >> 1)&s[i];
    else if(m[k] == 'E')
        for(int i = 1; i <= r; i++) x[i][k] = (x[i][k-1] << 1)&s[i];
    else if(m[k] == 'N')
        for(int i = 1; i <= r; i++) x[i][k] = (x[i+1][k-1])&s[i];
    else if(m[k] == 'S')
        for(int i = 1; i <= r; i++) x[i][k] = (x[i-1][k-1])&s[i];

    //printStuff(k);
    traverse(k+1);
}

int cnt()
{
    int ans = 0;
    for(int i = 1; i <= r; i++)
        ans += x[i][M].count();
    return ans;
}

int main()
{
    cin >> r >> c >> M;

    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            char cc; cin >> cc;
            if(cc == '.') s[i][j] = 1;
        }
    }

    for(int i = 1; i <= M; i++) cin >> m[i];

    for(int i = 1; i <= r; i++) x[i][0] = s[i];
    traverse(1);

    cout << cnt();

    return 0;
}
