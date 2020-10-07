#include <bits/stdc++.h>
#include <functional>
#include<stdio.h>
using namespace std;
#define ll       	int
#define dd      	long double
#define pb          push_back
#define pf          push_front
#define pi         pair<ll,ll>
#define vi          vector<ll>
#define vpi        vector<pi>
#define mi          map<ll,ll>
#define vvi         vector<vector<ll>>
#define mpi         map<pi,ll>
#define pipi        pair<ll,pair<ll,ll> >
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define x         first
#define y         second
#define sz(x)       (ll)x.size()
#define u        	'\n'
#define PI          3.141592653589
#define bs(v,n)     binary_search(all((v)),(n))
#define lb(v,n)     lower_bound(all((v)),(n))
#define ub(v,n)     upper_bound(all((v)),(n))
#define fo(i,l,u)   for(i=l;i<u;i++)
#define rfo(i,l,u)  for(i=l;i>=u;i--)
#define rf(s)       for(auto &c : s)
#define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++) //use Iterator
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define M           1000000007
#define ef          else if
#define yes       cout<<"YES"<<endl;
#define no        cout<<"NO"<<endl;
#define C         continue;
#define wa(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#define debug(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i<<" "; cout<<endl
#define debugp(vec) cout<<(#vec)<<": "; for (auto& i: vec) cout<<i.x<<","<<i.y<<" | "; cout<<endl
const ll N = 1e5+5;
#include <ext/pb_ds/tree_policy.hpp>      // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>     //common file
using namespace __gnu_pbds;
typedef tree<pi,null_type,less<pi>,rb_tree_tag,tree_order_statistics_node_update> pbds;
#define fbo find_by_order
#define ook order_of_key

//const ll inf=1e17+7;
/*
template<class T>
T big(T a, T b) { return a>b ? a : b; }*/
ll gcd(ll a, ll b) {  if (a == 0)  return b; return gcd(b % a, a); } 
/*
ll lcm(ll a, ll b) { return (a*b)/gcd(a,b); } 
bool M(double a,double b) {return a/b - floor(a/b);}
ll occurs(vi v,ll n)  {  auto it=lb(v,n);auto it1=ub(v,n);ll x=it1-it;return x;}
ll logb(ll base, ll x) {return (log(x) / log(base));}*/
ll power(ll x, ll y) 
{ 
    ll res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}/*
ll factors(ll ans){
    ll count=0;
    for (ll i=1; i<=sqrt(ans); i++) { 
        if (ans%i == 0) 
        {if (ans/i == i) count++;
            else count+=2;} 
    }
    return count;     
}
bool isSubSequence(string str1, string str2, ll m, ll n)  // str1<str2
{ 
  
    if (m == 0) return true; 
    if (n == 0) return false; 
  
  	if (str1[m-1] == str2[n-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
  
    return isSubSequence(str1, str2, m, n-1); 
} 
bool search(int x[], int n, int k) {
    int p = 0;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= k) p += a;
    }
    return x[p] == k;
}
*/
struct node
{
	ll ar[3];
};
node st[400005];
ll lz[400005];
void shift(ll si)
{
	ll a = st[si].ar[2];
	st[si].ar[2] = st[si].ar[1];
	st[si].ar[1] = st[si].ar[0];
	st[si].ar[0] = a;
}
ll query(ll si,ll ss,ll se,ll qs,ll qe)
{
	if(lz[si]!=0)
	{
		ll temp=lz[si];
		lz[si]=0;
		if(ss!=se)
		{
			lz[2*si]+=temp;
			lz[2*si+1]+=temp;
		}
		temp%=3;
		ll i;
		fo(i,0,temp)
		{
			shift(si);
		}
	}
	if(qs>se || qe<ss)
	return 0;
	if(ss>=qs && se<=qe)
	return st[si].ar[0];
	ll mid=(ss+se)/2;
	ll l=query(2*si,ss,mid,qs,qe);
	ll r=query(2*si+1,mid+1,se,qs,qe);
	return l+r;
}
void build(ll si,ll ss,ll se)
{
	if(ss==se)
	{
		st[si].ar[0] = 1;
		st[si].ar[1] = 0;
		st[si].ar[2] = 0;
		return;
	}
	ll mid=(ss+se)/2;
	build(2*si,ss,mid);
	build(2*si+1,mid+1,se);
	st[si].ar[0]=st[2*si].ar[0]+st[2*si+1].ar[0];
	st[si].ar[1]=st[2*si].ar[1]+st[2*si+1].ar[1];
	st[si].ar[2]=st[2*si].ar[2]+st[2*si+1].ar[2];
}
void update(ll si,ll ss,ll se,ll qs,ll qe)
{
	if(lz[si]!=0)
	{
		ll temp=lz[si];
		lz[si]=0;
		if(ss!=se)
		{
			lz[2*si]+=temp;
			lz[2*si+1]+=temp;
		}
		temp%=3;
		ll i;
		fo(i,0,temp)
		{
			shift(si);
		}
	}
	if(qs>se || qe<ss)
	return;
	if(ss>=qs && se<=qe)
	{
		shift(si);
		if(ss!=se)
		{
			lz[2*si]++;
			lz[2*si+1]++;
		}
		return;
	}
	ll mid=(ss+se)/2;
	update(2*si,ss,mid,qs,qe);
	update(2*si+1,mid+1,se,qs,qe);
	st[si].ar[0] = st[2*si].ar[0] + st[2*si+1].ar[0];
	st[si].ar[1] = st[2*si].ar[1] + st[2*si+1].ar[1];
	st[si].ar[2] = st[2*si].ar[2] + st[2*si+1].ar[2];
}
signed main()
{
	tezz
	ll t=1;
	//cin>>t;
	while(t--)
	{
		ll n,q,i;
		cin>>n>>q;
		build(1,1,n);
		fo(i,0,q)
		{
			ll a,b,c;
			cin>>a>>b>>c;
			if(a==0)
			{
				update(1,1,n,b+1,c+1);
			}
			else
			{
				ll ans=query(1,1,n,b+1,c+1);
				cout<<ans<<u;
			}
		}
	}
	return 0;
}
