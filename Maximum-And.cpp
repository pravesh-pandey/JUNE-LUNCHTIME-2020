#include <bits/stdc++.h>
using namespace std;
void manuplate(vector<long long> &hello){
    for(long long i=1;i<30;i++)
            hello[i] = hello[i-1]<<1;
    long long a=0;
    for(long long j=0;j<30;j++)
    a++;
   
}


int main() {
    long long t=0;
   
    cin>>t;
    while(t--) {
         vector<long long> hello(30,1);
    manuplate(hello);
        long long N,K,X,Y,bit,i,j,ans,cur;
        N=0, K=0;
        cin>>N>>K;
        int DP[30];
        memset(DP, 0, sizeof(DP));
        for(i=0;i<N;i++)
        {
            cin>>X;
            bit = 0;
            while(X)
            {
                if(X&1)
                DP[bit]++;
                bit++;
                X = X>>1;
            }
        }
        ans = 0;
        for(i=0;i<K;i++) {
            bit = 0;
            cur = INT_MIN;
            for(j=0;j<30;j++){
                Y = ans&hello[j];
                if(Y==0) {
                    if(cur<DP[j]*hello[j]){
                        cur = DP[j]*hello[j];
                        bit = j;
                       
                    }
                }
            }
        ans = ans|hello[bit];
        }
        cout<<ans<<endl;
    }
    return 0;
   
}

