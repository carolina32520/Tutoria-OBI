#include <bits/stdc++.h>

using namespace std ;

int N , P ;
set<int> s ;

void giveAns(int x)
{
	cout << x << endl ;
	exit(0) ;
}

int main()
{
	
	cin >> N >> P ;
	
	for(int i = 1 ; i <= N ; i++ ) s.insert(i) ;
	
	for(int i = 1 , x ; i <= P ; i++ )
	{
		cin >> x ;
		
		auto it = s.upper_bound(x) ;
		
		if(it == s.begin() ) giveAns(i-1) ;
		
		it-- ;
		
		s.erase(it) ;		
	}
	
	giveAns(P) ;
	
}
