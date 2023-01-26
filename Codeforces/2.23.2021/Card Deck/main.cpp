#include <iostream>
#include <set>

using namespace std;

void printStuff(int a, int b, int c[])
{
    for(int i = a; i <= b; i++)
        cout << c[i] << " ";
}

int main()
{
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        int c[n];
        for(int i = 0; i < n; i++) cin >> c[i];

        set <int> s;
        for(int i = 1; i <= n; i++) s.insert(-i);
        int k = n-1, target = n;

        while(k >= 0)
        {
            int targetPos = 0;
            for(int i = k; i >= 0; i--)
            {
                s.erase(-1*c[i]);
                if(c[i] == target)
                {
                    targetPos = i;
                    break;
                }
            }
            printStuff(targetPos, k, c);
            k = targetPos-1;
            target = -*s.upper_bound(-n);
        }
        cout << "\n";
    }

    return 0;
}
