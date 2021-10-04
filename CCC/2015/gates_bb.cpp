#include <bits/stdc++.h>

const int MAX = 1e5+10 ;

using namespace std ;

int N , P ;
int A[MAX] ;

bool test(int x)
{
	vector<int> v ;
	for(int i = 1 ; i <= x ; i++ ) v.push_back(A[i]) ;
	sort(v.begin() , v.end() ) ;
	
	for(int i = 0 ; i < x ; i++ )
		if( v[i] < i+1 ) return false ;
		
	return true ;	
}

int main()
{
	
	cin >> N >> P ;
	for(int i = 1 ; i <= P ; i++ ) cin >> A[i] ;
	
	int l = 1 , r = N , mid ;
	
	while(l < r )
	{
		mid = (l+r+1)>>1 ;
		
		if(test(mid)) l = mid ;
		else r = mid-1 ;
	}
	
	cout << l << endl ;
	
}
