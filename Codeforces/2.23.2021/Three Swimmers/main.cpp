#include <iostream>

using namespace std;

#define int long long int

int32_t main()
{
    int t; cin >> t;

    while(t--)
    {
        int p, a, b, c;
        int sol = LLONG_MAX;
        cin >> p >> a >> b >> c;

        sol = min(sol, (a-(p%a))%a);
        sol = min(sol, (b-(p%b))%b);
        sol = min(sol, (c-(p%c))%c);

        cout << sol << endl;
    }

    return 0;
}
