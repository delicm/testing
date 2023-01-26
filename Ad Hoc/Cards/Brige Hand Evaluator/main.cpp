#include <iostream>

using namespace std;

char card[2][13];
int S = 0, D = 0, H=0, C=0;
bool s, d, h, c;
int point = 0;
//int point = 0;

void hand()
{
    S=0;
    H=0;
    C=0;
    D=0;

    for(int i = 0; i < 13; i++)
    {
        //cout << S << " " << D << " " << H << " " << C << endl;
        scanf("%s", card[i]);
        if(card[i][1] == 'S')
        {
            S++;
        }else if(card[i][1] == 'D')
        {
            D++;
        } else if(card[i][1] == 'H')
        {
            H++;
        }else
        {
            C++;
        }
    }
    /*for(int i = 0; i < 13; i++)
    {
        cout << card[i][0] << card[i][1] << " ";
    }*/


    return;
}

void calc1()
{
    point = 0;
    for(int i = 0 ; i < 13; i++){
        if(card[i][0] == 'K')
        {
            point += 3;
            if(card[i][1] == 'S')
            {
            if(S==1) point--;
            else s=1;
            }else if(card[i][1] == 'D')
            {
            if(D==1) point--;
            else d=1;
            }else if(card[i][1] == 'H')
            {
                if(H==1) point--;
                else h=1;
            }else
            {
                if(C==1) point--;
                else{c=1;}
            }
        }
        else if(card[i][0] == 'Q')
        {
            point += 2;
            if(card[i][1] == 'S')
            {
            if(S<=2) point--;
            else s=1;
            }else if(card[i][1] == 'D')
            {
            if(D<=2) point--;
            else d=1;
            }else if(card[i][1] == 'H')
            {
                if(H<=2) point--;
                else h=1;
            }else
            {
                if(C<=2) point--;
                else c=1;
            }
        }
        else if(card[i][0] == 'J')
        {
            point +=1;
            if(card[i][1] == 'S')
            {
            if(S<=3) point--;
            }else if(card[i][1] == 'D')
            {
            if(D<=3) point--;
            }else if(card[i][1] == 'H')
            {
                if(H<=3) point--;
            }else
            {
                if(C<=3) point--;
            }
        }
        else if(card[i][0] == 'A')
        {
            point += 4;
            if(card[i][1] == 'S')
            {
            s=1;
            }else if(card[i][1] == 'D')
            {
            d=1;
            }else if(card[i][1] == 'H')
            {
                h=1;
            }else
            {
                c=1;
            }
        }

    }

}

void calc2()
{
   if(S<=2) point++;
   if(D<=2) point++;
   if(H<=2) point++;
   if(C<=2) point++;
}

int main()
{
    s=0; d=0; h=0; c=0;
    while(true)
    {
        hand();
       /* calc1();
        if(point > 15 && s==1 && d==1 && h==1 && c==1)
        {
            cout << "BID NO-TRUMP" <<endl;
            continue;
        }
        calc2();
        if(point > 13)
        {
            if(S>=D)
            {
                if(S>=C)
                {
                    if(S>=H)
                    {
                        cout << "BID S" << endl;
                    }
                    else
                    {
                        cout << "BID H" << endl;
                    }
                }
                else
                {
                    if(C>=H)
                    {
                        cout << "BID C" << endl;
                    }
                    else
                    {
                        cout << "BID H" << endl;
                    }
                }
            }
            else
            {
                if(D>=H)
                {
                    if(D>=C)
                    {
                        cout << "BID D" << endl;
                    }
                    else
                    {
                        cout << "BID C" << endl;
                    }
                }
                else
                {
                    if(H>=C)
                    {
                        cout << "BID H" << endl;
                    }
                    else
                    {
                        cout << "BID C" << endl;
                    }
                }
            }
        }

        else
        {
            cout << "PASS" << endl;
        }*/

    }
    return 0;
}
