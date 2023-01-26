#include <iostream>

using namespace std;

int main()
{
    int L;
    char temp[2];
    char current[2];
    current[0] = '+';
    current[1] = 'x';

    while(scanf("%d", &L)!= 0)
    {
        for(int i = 0; i < L; i++)
        {
            scanf("%s", temp);
            if(temp[1] =='z')
            {
                if(temp[0]=='+')
                {
                    if(current[0]=='+')
                    {
                        if(current[1] == 'x')
                        {
                            current[0]='+';
                            current[1]='z';
                        }
                        else if(current[1] == 'y')
                        {
                            current[0]= '+';
                            current[1]= 'z';
                        }
                        else
                        {
                            current[0]='-';
                            current[1]='x''
                        }
                    }
                    else
                    {
                        if(current[1] == 'x')
                        {
                            current[0]='-';
                            current[1]='z';
                        }
                        else if(current[1] == 'y')
                        {
                            current[0]= '-';
                            current[1]= 'y';
                        }
                        else
                        {

                        }
                    }
                }
                else
                {

                }
            }
            else if(temp[1] == 'y')
            {
                if(temp[0]=='+')
                {

                }
                else
                {

                }
            }
        }
    }
    return 0;
}
