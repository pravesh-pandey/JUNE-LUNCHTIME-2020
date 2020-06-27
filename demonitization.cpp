#include <bits/stdc++.h>
using namespace std;

int main() 
{
       int t;
       cin>>t;
       while(t--)
       {
              int s=0,n=0,sum=0,count=0;
              cin>>s>>n;
              
              
              while(s>0&&n>0)
              {
                    count+=s/n;
                    s=s%n;
                    if(n>s)
                    {
                           if(s%2==0)
                           n=s;
                           else
                           {
                                  n=s-1;
                           }
                    }
                     
                     
              }
              if(s>=0)
              count+=s;
              cout<<count<<endl;
              
              
       }
	
	
	return 0;
}
