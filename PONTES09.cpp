#include <bits/stdc++.h>

const int MAXN = 1010 ;
const int inf = 1e9+10 ;

using namespace std ;

int N , M ;
int dist[MAXN] ;
vector< pair<int,int> > adj[MAXN] ;
set<pair<int,int> > s ;

void dijkstra()
{

    for(int i = 1 ; i <= N+1 ; i++ ) dist[i] = inf ;
    for(int i = 0 ; i <= N+1 ; i++ ) s.insert(make_pair(dist[i] , i )) ;

    while(!s.empty())
    {
        int x = s.begin()->second ; //tambem pode ser (*s.begin()).second
        s.erase( s.begin() ) ;

        for(int i = 0 ; i < (int)(adj[x].size()) ; i++ )
        {
            int viz = adj[x][i].first ;
            int w = adj[x][i].second ;

            if( dist[viz] <= dist[x]+w ) continue ;

            s.erase(make_pair(dist[viz], viz)) ;
            dist[viz] = dist[x]+w ;
            s.insert(make_pair(dist[viz],viz)) ;

        }

    }

}

int main()
{
    cin >> N >> M ;
    for(int i = 1 ; i <= M ;i ++ )
    {
        int a , b , c ;
        cin >> a >> b >> c ;
        adj[a].push_back(make_pair(b,c)) ;
        adj[b].push_back(make_pair(a,c)) ;
    }

    dijkstra() ;

    cout << dist[N+1] << endl ;
}
