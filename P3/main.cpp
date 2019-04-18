#include <bits/stdc++.h>

using namespace std;
bool prime[10001];
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int t;
    cin>>t;
    memset(prime,1,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2; i<=10000;i++)
    {
        for(int j=2; ;j++)
        {
            if(i*j>10000) break;
            prime[i*j]=false;
        }
    }
    for(int cnt=1; cnt<=t; cnt++)
    {
        int n,L;
        string ans="";
        cin>>n>>L;
        int arr[L];
        memset(arr,0,sizeof(arr));
        int num[L+1];
        memset(num,0,sizeof(num));
        set<int,less<int>> s;
        map<int,char> m;
        for(int i=0; i<L; i++)
        {
            cin>>arr[i];
        }
        int g,i,index;
        for(i=0; i<L-1; i++)
        {
            if(arr[i]!=arr[i+1])
            {
                g=gcd(arr[i],arr[i+1]);
                num[i]=arr[i]/g;
                num[i+1]=g;
                num[i+2]=arr[i+1]/g;
                s.insert(num[i]);
                s.insert(num[i+1]);
                s.insert(num[i+2]);
                break;
            }
        }
        index=i;
        while(i>0)
        {
            num[i-1]=arr[i-1]/num[i];
            s.insert(num[i-1]);
            i--;
        }
        i=index;
        while(i<L)
        {
            num[i+1]=arr[i]/num[i];
            s.insert(num[i+1]);
            i++;
        }
        int c=0;
        for(auto x:s)
        {
            m[x]=('A'+c);
            c++;
        }
        for(int i=0 ;i<=L; i++)
        {
            ans.push_back(m[num[i]]);
        }
        printf("Case #%d: ",cnt);
        cout<<ans<<endl;
    }
    return 0;
}
