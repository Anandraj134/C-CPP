#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    // cin >> n;
    int k = 3;
    // cin >> k;
    vector<int> a{1,7,2,4}, b;
    // for(int i=0;i<n;i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     a.push_back(temp);
    // }
    bool flag = false;
    for(int i=0;i<n-1;i++)
    {
        flag = false;
        for(int j=0;j<n;j++)
        {
            if(i == j)
            {
                continue;
            }
            if((a[i] + a[j]) % k == 0)
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            b.push_back(a[i]);
        }
    }
    for(int i=0;i<b.size();i++)
    {
        cout << b[i] << ' ';
    }
}