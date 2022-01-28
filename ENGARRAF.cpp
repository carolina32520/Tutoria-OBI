#include <bits/stdc++.h>

const int MAXN = 110 ;
const int inf = 1e9+10 ;

using namespace std ;

int N , M , S , T ;
int dist[MAXN] ;
vector<pair<int,int> > adj[MAXN] ;

void dijkstra()
{
    for(int i = 1 ; i <= N ; i++ ) dist[i] = inf ;
    dist[S] = 0 ;

    //pega sempre o menor: priority_queue< tipo , vector<tipo>, greater<tipo> > pq
    //pega sempre o maior: priority_queue<tipo> pq 
    
    priority_queue< pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > fila ;
    fila.push( make_pair(dist[S] , S) ) ;

    while( !fila.empty() )
    {
        int x = fila.top().second ;
        int d = fila.top().first ;
        fila.pop() ;

        if(d > dist[x]) continue ;

        for(int i= 0; i < (int)( adj[x].size() ) ; i++ )
        {
            int viz = adj[x][i].first ;
            int w = adj[x][i].second ;

            if( dist[viz] >= dist[x]+w )
            {
                dist[viz]=dist[x]+w ;
                fila.push(make_pair(dist[viz],viz)) ;
            }
        }

    }

}

int main()
{
    while( cin >> N >> M )
    {
        if(N == 0 && M == 0 ) break ;

        for(int i = 1 ; i <= N ; i++ ) adj[i].clear() ;

        for(int i = 0 , a , b , c ; i < M ; i++ )
        {
            cin >> a >> b >> c ;
            adj[a].push_back(make_pair(b,c)) ;
        }

        cin >> S >> T ;

        dijkstra() ;

        if( dist[T] == inf ) dist[T] = -1 ;
        cout << dist[T] << endl ;
    }
}
