/*
 * we use two pointers technique to calcute the distance between every two intervals in O(n^2)
 * because of strict memory limit we cant store in n*n matrix , instead we use prefix sum to answer the queries
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , l , q;
vi ord ;
int a[10009] , que [109] , ans[10009][109]; 
int id(int x ) {
	return lb(ord.begin(),ord.end(),x) - ord.begin() ;
}
int main () {
	scanf("%d%d",&n,&l);
	for ( int i = 0 ; i < n ; i ++ ) scanf("%d",&a[i]) ;
	scanf("%d",&q);
	for ( int i = 0 ; i < q ; i ++ ) {
		scanf("%d",&que[i]);
		ord.pb ( que[i] ) ;
	}
	sort(ord.begin(),ord.end());
	for ( int i = 1 ; i <= n ; i ++ ) {
		int st1=0 , en1=l-1;
		int st2=i , en2=st2+l-1;
		if ( en2 >= n ) break ;
		int crnt = 0 ;
		for ( int j = st1 ; j <= en1 ; j ++ ) {
			crnt += ( a[j] != a[j+i] ) ;
		}
		ans[st1][id(crnt)]++;
		ans[st2][id(crnt)]++;
		while ( en2+1 < n ) {
			crnt -= ( a[st1] != a[st2] ) ;
			st1 ++ , st2 ++ ;
			en1 ++ , en2 ++ ;
			crnt += ( a[en1] != a[en2] ) ;
			ans[st1][id(crnt)]++;
			ans[st2][id(crnt)]++;
		}
	}
	for ( int i = 0 ; i < n ; i ++ ) {
		for ( int j = 1 ; j < q ; j ++ ) {
			ans[i][j] += ans[i][j-1] ;
		}
	}
	for ( int i = 0 ; i < q ; i ++ ) {
		int k = que[i] ;
		for ( int j = 0 ; j < n-l+1 ; j ++ ) {
			cout << ans [j][id(k)] << " " ;
		}
		cout << endl ; 
	}
}
