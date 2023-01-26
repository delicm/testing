#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, r;
    cin >> s >> r;

    int a[26];
    int b[26];

    for(int i = 0; i < 26; i++)
    {
        a[i] = 0; b[i] = 0;
    }

    for(int j = 1; j < s.length(); j++)
    {
        a[s[j]-97]++;
    }
    for(int j = 0; j < r.length()-1; j++)
    {
        b[r[j]-97]++;
    }

    int S = 0;

    for(int i= 0; i < 26; i++)
    {
        S+= a[i] * b[i];
    }
    cout << s.length()*r.length()-S;

    return 0;
}
