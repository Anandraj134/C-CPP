#include<stdio.h>
#include<string.h>
#include"password.h"

int spec(int a)
{
    switch(a)
    {
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
        case '^':
        case '&':
        case '*':
        case '(':
        case ')':
        case '-':
        case '_':
        case '=':
        case '+':
        case '{':
        case '}':
        case '[':
        case ']':
        case ';':
        case ':':
        case '<':
        case '>':
        case ',':
        case '.':
        case '?':
        case '/':
        case '|':return 1;
        default :return 0;
    }    
}
int main()
{
    int len = 0;//Check for length
    int num = 0;
    int alpha = 0;
    int special = 0;
    char a[50];
    char str[50];

    printf("Please enter password between 8 to 16 character include Capital, small, Special character, numbers.\n");
    printf("Enter your password :- ");
    scanf("%s",str);
    len = strlen(str);
    if(len < 8 || len > 16)
    {
        if(len <= 8)
        {
            //printf("Password length is short.\n");
            psort();
            return 1;
        }
        if(len >= 16)
        {
            //printf("Password length is long.\n");
            plong();
            return 1;
        }
    }

    for(int i=0;i<len;i++)
    {
        char temp = str[i];
        a[i] = temp;
    }

    for(int i=0;i<len;i++)
    {
        if(a[i] >= '0' && a[i] <= '9')
        {
            num++;
            if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
            {
                alpha++;
                if(spec(a[i]))
                {
                    special++;
                }
            }
            else
            {
                if(spec(a[i]))
                {
                    special++;
                    if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
                    {
                        alpha++;
                    }
                }
            }
            
        }
        else if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
        {
            alpha++;
            if(a[i] >= '0' && a[i] <= '9')
            {
                num++;
                if(spec(a[i]))
                {
                    special++;
                }
            }
            else
            {
                if(spec(a[i]))
                {
                    special++;
                    if(a[i] >= '0' && a[i] <= '9')
                    {
                        num++;
                    }
                }
            }
        }
        else if(spec(a[i]))
        {
            special++;
            if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
            {
                alpha++;
                if(a[i] >= '0' && a[i] <= '9')
                {
                    num++;
                }
            }
            else
            {
                if(a[i] >= '0' && a[i] <= '9')
                {
                    num++;
                    if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
                    {
                        alpha++;
                    }                    
                }
            }
        }
    }
    printf("Alpha:- %d\nNumbers:- %d\nSpecial Character:- %d\n", alpha, num, special);
    if(alpha >= 1)
    {
        if(num >= 1)
        {
            if(special >= 1)
            {
                // printf("Entered password provides Strong security.\n");
                strong();
                return 0;
            }
            else
            {
                //printf("Entered password provides Medium security.\n");
                Medium();
                return 0;
            }
        }
        else
        {
            if(special >= 1)
            {
                //printf("Entered password provides Medium security.\n");
                Medium();
                return 0;
            }
            else
            {
            //printf("Enter password provides Week security.\n");
            Week();
            return 0;
            }
        }
    }
    if(num >= 1)
    {
        if(alpha >= 1)
        {
            if(special >= 1)
            {
                //printf("Entered password provides Strong security.\n");
                strong();
                return 0;
            }
            else
            {
                //printf("Entered password provides Medium security.\n");
                Medium();
                return 0;
            }
        }
        else
        {
            if(special >= 1)
            {
                //printf("Entered password provides Medium security.\n");
                Medium();
                return 0;                
            }
            else
            {
                //printf("Enter password provides Week security.\n");
                Week();
                return 0;
            }
        }
    }
    if(special >= 1)
    {
        if(num >= 1)
        {
            if(alpha >= 1)
            {
                //printf("Entered password provides Strong security.\n");
                strong();
                return 0;
            }
            else
            {
                //printf("Entered password provides Medium security.\n");
                Medium();
                return 0;
            }
        }
        else
        {
            if(alpha >= 1)
            {
                //printf("Entered password provides Medium security.\n");
                Medium();
                return 0;
            }
            else
            {
                //printf("Enter password provides Week security.\n");
                Week();
                return 0;
            }
        }
    }
}