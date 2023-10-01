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

int main(){}
ll siz[N];
ll parent[N];
void make(ll v){
	parent[v]=v;
	siz[v]=1;
}

ll find(ll v){
	if(parent[v]==v) return parent[v];
	return parent[v]=find(parent[v]);
}

void Union(ll a,ll b){
	a=find(a);
	b=find(b);
	if(a==b)return;
	if(siz[a]<siz[b])swap(a,b);

	parent[b]=a;
	siz[a]+=siz[b];
}