/*
author: Apoorv Singh
*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <long long> vll;
typedef pair <long long, long long> pll;
#define pb push_back   
#define all(c) c.begin(), c.end()
#define For(i, a, b) for (long long i = a; i < b; ++i)
#define Forr(i, a, b) for (long long i = a; i > b; --i)
#define um unordered_map
#define F first
#define S second
#define ll long long 
#define endl "\n"
#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout << name << " : " << arg1 << endl;  
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

template <class X>
void printarr(X arr[], int n) 
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}
 
template <class T, class cmp = less<T>> using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
 
ll modulo = 1e9 + 7;

ll fpow(ll a, ll n) 
{
	ll ans = 1;
	while (n) 
	{
		if (n&1) ans = (ans*a)%modulo;
		a = (a*a)%modulo; n = n >> 1;
	}
	return ans;
}

void solve() 
{
	ll n,d;
	ll m;
	cin >> n >> d >> m;
	vector <ll> great, lesser;
	For(i,0,n)
	{
		ll a; cin >> a;
		if (a > m) great.pb(a);
		else lesser.pb(a);
	}				
	sort(all(great), greater <ll>());
	sort(all(lesser), greater <ll>());
	int x = great.size(), y = lesser.size();
	ll pref1[x+1]; pref1[0] = 0;
	ll pref2[y+1]; pref2[0] = 0;
	For(i,0,x)
	{
		pref1[i+1] = pref1[i] + great[i];
	} 
	For(i,0,y)
	{
		if (i == 0) pref2[i] = 0;
		pref2[i+1] = pref2[i] + lesser[i];
	} 
	ll ans = 0;
	For(i,0,x+1)
	{
		ll done = max(0ll, (i-1ll)*d);
		done += i;
		if (done > n) break;
		ll curr = pref1[i];
		curr += pref2[min(y,n-done)];
		ans = max(ans, curr);
	}
	cout << ans << endl;
}

int main() 
{
	fast_io();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int t = 1;
	// cin >> t;
	while (t--) solve();
	return 0;
}
