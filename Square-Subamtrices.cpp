#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef LOCAL 
#include "/media/brayand/BrayanD/debugger.h"
#else
template<typename... Args>
void db(Args... args){}
#endif

const int MAXN = 1e6 + 10;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	int N, X;
    	cin >> N >> X;

    	int A[N+1];

    	for(int i = 0 ; i <= N ; i++)
    	{
    		A[i] = 0;
    	}

    	for(int i = 1 ; i <= N ; i++)
    	{
    		cin >> A[i];
    		A[i] += A[i-1];
    	}

    	vector<int> div;

    	for(int i = 1 ; i*i <= X ; i++)
    	{
    		if(X%i==0)
    		{
    			div.push_back(i);
    			div.push_back(X/i);
    		}
    	}

    	sort(div.begin(),div.end());
    	div.resize(unique(div.begin(),div.end()) - div.begin());

    	int res = 0;

        int mp[MAXN];

        for(int i = 0 ; i < MAXN ; i++)mp[i] = 0;

    	for(auto ddd : div)
    	{
    		if(ddd > N)continue;
    		for(int i = ddd ; i <= N ; i++)
    		{
                if(A[i]-A[i-ddd] < MAXN)mp[A[i]-A[i-ddd]]++;
    		}
    		for(int i = ddd ; i <= N ; i++)
    		{
                if(X/ddd-(A[i]-A[i-ddd]) >= 0)res += mp[X/ddd-(A[i]-A[i-ddd])];
    		}
            for(int i = ddd ; i <= N ; i++)
            {
                if(A[i]-A[i-ddd] < MAXN)mp[A[i]-A[i-ddd]]--;
            }
    	}

    	cout << res << '\n';
    }

    return 1;
}