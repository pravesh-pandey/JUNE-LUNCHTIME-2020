#include<bits/stdc++.h>
using namespace std;
int main(){
   int test=0;
   int flag=1;
   int N=0, i=0, m=0;
   cin>> test;
   while( test--){
       
       cin>>N;
       vector<int> a(N, 0), temp ;
       
       for(i=0;i<N;i++)
            cin>>a[i];
        int count=0;
        sort(a.begin(), a.end());
       for(i=0;i<N;i++){
           count=1;
           while(a[i]==a[i+1] && i<N-1){
               i++;
               count++;
               temp.push_back(a[i]);
               m++;
           }
           if(count>2){
               flag=0;
               break;
           }
       }
   
       if(count>=2)
            flag=0;
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(i=0;i<N-1;i++) {
            if(a[i]!=a[i+1])
                cout<<a[i]<<" ";
        }
        cout<<a[N-1]<<" ";
       
        for(i=m-1;i>=0;i--)
            cout<<temp[i]<<" ";
           
        if(N>0)
            cout<<endl;
       
   }
   return 0;
}

