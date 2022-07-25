#include<bits/stdc++.h>
using namespace std;

void D2B(int n)
{
    int a, b, c=0;
    vector<int> temp(0);
    while(n != 0)  
    {
        c++;
        a = n%2;
        n/=2;
        temp.push_back(a);
    }
    cout << "Binary :- ";
    for(int i = c-1; i>=0;i--)
    {
        cout << temp[i];
    }
}

void B2D(int n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    cout << "Decimal number is :- "<< decimalNumber;
}

void D2O(int n)
{
    int a, b, c=0;
    vector<int> temp(0);
    while(n != 0)  
    {
        c++;
        a = n%8;
        n/=8;
        temp.push_back(a);
    }
    cout << "Octal :- ";
    for(int i = c-1; i>=0;i--)
    {
        cout << temp[i];
    }
}

void O2D(int n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(8,i);
        ++i;
    }
    cout << "Decimal number is :- "<< decimalNumber;
}

int main()
{
    int n, ch;
    cout << "==========================" << endl;
    cout << "1. Decimal to Binary" << endl << "2. Binary to Decimal" << endl;
    cout << "3. Decimal to Octal" << endl << "4. Octal to Decimal" << endl;
    cout << "<------------------------>" << endl;
    cout << "Enter your choice :- ";
    cin >> ch;
    cout << "==========================" << endl;
    switch (ch)
    {
    case 1:
        cout << "Enter decimal int number :- ";
        cin >> n;
        D2B(n);
        break;
    case 2:
        cout << "Enter Binary number :- ";
        cin >> n;
        B2D(n);
        break;
    case 3:
        cout << "Enter decimal int number :- ";
        cin >> n;
        D2O(n);
        break;
    case 4:
        cout << "Enter Octal number :- ";
        cin >> n;
        O2D(n);
        break;    
    default:
        cout << "Choose valid option" << endl;
        break;
    }
}