#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int x[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> x[i][j];
        }
    }

    return 0;
}
