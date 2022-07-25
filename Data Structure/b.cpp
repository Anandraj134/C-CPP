#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> s1,s2;

    string s;
    string r;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        int a = s.length();
        int z = 0;

        for(int j=a-1;j >=0;j--)
        {
            s[j] = r[z];
            z++;
        }
        for(int j=1;j < a;j++)
        {
            int b = abs(s[j] - s[j-1]);
            s1.push_back(b);
            int c = abs(r[j] - r[j-1]);
            s2.push_back(c);
        }
        if(s1 == s2)
        {
            cout << "Funny";
        }
        else
        {
            cout << "Not Funny";
        }
    }
}