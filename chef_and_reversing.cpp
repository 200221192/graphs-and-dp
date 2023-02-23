#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int bfs01(vector<pair<int, int>>  g[] , int n ){
    vector<int>level(n+1 , INT_MAX) ;
    level[1] = 0 ;
    queue<int> q;
    q.push(1) ;
    while(!q.empty()){
        int top = q.front() ;
        q.pop() ;
        for(auto neighbour : g[top]){
            int neigh_v = neighbour.first ;
            int weight = neighbour.second ;
            if(level[top] + weight < level[neigh_v]){
                level[neigh_v]  = level[top] + weight ;
                q.push(neigh_v);
            }
        }
    }
    return level[n] == INT_MAX ? -1 : level[n];
    
}
int main() {
	// your code goes here
	int n , m ;
	cin>>n>>m ;
	vector<pair<int , int>>g[n+1] ;
	for(int i = 0 ; i < m ; i++){
	    int u , v ;
	    cin>>u>>v ;
	    g[u].push_back({v,0});
	    g[v].push_back({u,1});
	}
	cout<<bfs01(g,n);
	return 0;
}
