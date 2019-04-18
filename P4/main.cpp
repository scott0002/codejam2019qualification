#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int cnt=1; cnt<=t; cnt++)
    {
        int n,b,f;
        cin>>n>>b>>f;
        string q[5];
        int block[5][1024];
        memset(block,0,sizeof(block));
        bool state;
        for(int p=4;p>=0; p--)
        {
            state=true;
            for(int i=0; i<n; i++)
            {
                if(i!=0&&i%(1<<p)==0) state=!state;
                cout<<(int)state;
            }
            cout<<endl;
            cin>>q[p];
        }
/////////////////////////////////////////
        int counts=0,bc=0;
        for(int i=0; i<(n-b); i++)
        {
            if(i!=0 && q[4][i-1]!=q[4][i])
            {
                bc++;
                block[4][bc-1]=16-counts;
                counts=0;
            }
            counts++;
        }
        bc++;
        block[4][bc-1]=(n%16==0?16:n%16)-counts;
/*
        for(int i=0; i<bc; i++)
        {
            printf("block[4][%d]: %d\n",i,block[4][bc-1]);
        }*/
        for(int p=4;p>0;p--)
        {
            bc=0;
            int simu=0,c1=0,c0=0;
            for(int i=0; i<n;i++)
            {
                if(i==simu+(1<<p)-block[p][bc])
                {
                            block[p-1][bc*2]=(1<<(p-1))-c1;
                            block[p-1][bc*2+1]=(1<<(p-1))-c0;
                            simu+=(1<<p)-block[p][bc];
                            bc++;
                            c1=0;
                            c0=0;
                        while((1<<p)-block[p][bc]==0)
                        {
                                block[p-1][bc*2]=(1<<(p-1));
                                block[p-1][bc*2+1]=(1<<(p-1));
                                bc++;
                                c1=0;
                                c0=0;
                        }

                }

                if(i<n-b)
                if(q[p-1][i]=='1')
                    c1++;
                else
                    c0++;
            }
                block[p-1][bc*2]=(n%(1<<p)==0?1<<(p-1):(n%(1<<p)>=(1<<(p-1))?1<<(p-1):n%(1<<(p-1))))-c1;
                block[p-1][bc*2+1]=(n%(1<<p)==0?1<<(p-1):(n%(1<<p)>=(1<<(p-1))?n%(1<<(p-1)):0))-c0;
                bc++;

/*
            for(int i=0; i<bc*2+2; i++)
            {
                printf("block[%d][%d]: %d\n",p-1,i,block[p-1][i]);
            }*/

        }
//////////////////////////////////////////////
        int c=0;
        for(int i=0; i<n; i++)
        {
            if(!c&&block[0][i])
            {
                cout<<i;
                c++;
            }
            else if(c&&block[0][i])
            {
                cout<<" "<<i;
            }
        }
        int judge;
        cin>>judge;


    }
    return 0;
}
