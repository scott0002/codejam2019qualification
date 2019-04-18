#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int cnt=1; cnt<=t; cnt++)
    {
        int n;
        cin>>n;
        string p;
        cin>>p;
        for(int i=0; i<p.size(); i++)
        {
            if(p[i]=='S')
            {
                p[i]='E';
            }
            else
            {
                p[i]='S';
            }
        }
        printf("Case #%d: ",cnt);
        cout<<p<<endl;
    }
    return 0;
}
