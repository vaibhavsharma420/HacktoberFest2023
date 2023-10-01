#include <bits/stdc++.h>
typedef long long ll;
#define nl "\n"
#define mod 1000000007
#define ye cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define inp(n) cin>>n
#define FC ios_base::sync_with_stdio(false);cin.tie(NULL);
#define forl(i,n) for(ll i=0;i<n;i++)
#define _inp(arr,n) for(ll i=0;i<n;i++)cin>>arr[i]
#define _print(arr,n) for(ll i=0;i<n;i++)cout<<arr[i]<<" "
#define all(a) a.begin(),a.end()
#define pb push_back 
#define setall(arr,n,p) for(ll i=0;i<n;i++)arr[i]=p;
using namespace std;
const ll N=1e5+10;

void SieveOfEratosthenes(ll n){
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for (ll p=2;p*p<=n;p++) {
		if (prime[p]==true) {
			for (ll i=p*p;i<=n;i+=p)
				prime[i]=false;
		}
	}
	for (ll p=2;p<=n;p++){
		if(prime[p])cout<<p<<" ";
	}
}

int main(){}