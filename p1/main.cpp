#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int cnt=1; cnt<=t; cnt++)
    {
        string n;
        cin>>n;
        string a="",b="";
        for(int i=0; i<n.size(); i++)
        {
            int bit=(int)(n[i]-'0');
            for(int j=0;j<=8;j++)
            {
                if(!(i==0&&j==0)&&j!=4 &&bit-j>=0&&bit-j<=9&&bit-j!=4)
                {
                    a.push_back('0'+j);
                    b.push_back('0'+bit-j);
                    break;
                }
            }
        }

        printf("Case #%d:",cnt);
        cout<<" "<<a<<" "<<b<<endl;
    }
    return 0;
}
