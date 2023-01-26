#include <iostream>

using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    if(b == 1)
    {
        if(k == 0)
        {
            cout << "Yes" << endl;
            cout << 1;
            for(int i = 0; i < a; i++) cout << 0;
            cout << endl;
            cout << 1;
            for(int i = 0; i < a; i++) cout << 0;
            cout << endl;
            return 0;
        }
        else
        {
            cout << "No";
            return 0;
        }
    }

    if(a == 0)
    {
        if(k == 0)
        {
            cout << "Yes" << endl;
            for(int i = 0; i < b; i++) cout << 1;
            cout << endl;
            for(int i = 0; i < b; i++) cout << 1;
            return 0;
        }
        else
        {
            cout << "No";
            return 0;
        }
    }

    if(k >= a+b-1)
    {
        cout << "No";
        return 0;
    }

    cout << "Yes" << endl;

    if(k <= a)
    {
        for(int i = 0; i < b; i++) cout << 1;
        for(int i = 0; i < a; i++) cout << 0;
        cout << endl;
        for(int i = 0; i < b-1; i++) cout << 1;
        for(int i = 0; i < k; i++) cout << 0;
        cout << 1;
        for(int i = 0; i < a-k; i++) cout << 0;
    }
    else
    {
        for(int i = 0; i < b; i++) cout << 1;
        for(int i = 0; i < a; i++) cout << 0;
        cout << endl;
        int l = a+b-1-k;
        for(int i = 0; i < l; i++) cout << 1;
        cout << 0;
        for(int i = 0; i < b-l-1; i++) cout << 1;
        for(int i = 0; i < a-1; i++) cout << 0;
        cout << 1;
    }

    return 0;
}
