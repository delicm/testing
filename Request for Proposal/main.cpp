#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int n, p, main = -1, temp_main = 0, counter=0;
    string name, temp_name, waste;
    double price = 1000000000.0, temp_price;

    while(scanf("%d %d", &n, &p), (n!=0 || p!=0))
    {
        counter++;
        for(int i =0; i<n; i++)
        {
            scanf("%s", &waste);
        }
        for(int i =0; i<p; i++)
        {
            cin >> temp_name;
            scanf("%lf %d", &temp_price, &temp_main);
            for(int j =0; j< temp_main; j++){
                scanf("%s", &waste);
            }
            if(temp_main > main){
                main = temp_main;
                name=temp_name;
                price = temp_price;
            }else if(temp_main == main && price >temp_price)
            {
                main = temp_main;
                name=temp_name;
                price = temp_price;
            }
        }
        cout << "RRP #" << counter << endl << name << endl;
    }

    return 0;
}
