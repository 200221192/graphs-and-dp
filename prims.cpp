#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<set>
#include<limits.h>
using namespace std ;

// dijkstra algorithm to find shortest distance from source node to destination node

class Graph{
    public:
    unordered_map<int , list<pair<int , int> > > adj ;

    void addedge(int u , int v , int weight){
        pair<int , int> p = make_pair(v , weight);
        adj[u].push_back(p);
        pair<int , int> q = make_pair(u , weight);
        adj[v].push_back(q);
    }
     
    void print(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"["<<j.first<<","<<j.second<<"]" ;
            } cout<<endl;
        }
    }

   void  prims( vector<pair<pair<int, int>, int>> &v ,  int n){
    vector<int> key(n+1);
    vector<bool>mst(n+1) ;
    vector<int>parent(n+1) ;

    for(int i = 0 ; i <= n ; i++){
        key[i] = INT_MAX ;
        mst[i] = false ;
        parent[i] = -1 ;
    }
   
   key[1] = 0 ;
   parent[1] = -1 ;

   for(int i = n ; i < n ; i++){
       int mini = INT_MAX ;
       int u ;
       for(int v = 1 ; v <= n ; v++){
        if(mst[v] == false && key[v] < mini){
            u = v ;
            mini = key[v] ;
        }
       }

       mst[u] = true ;

       for(auto it : adj[u]){
        int v = it.first;
        int w = it.second ;
        if(mst[v] == false && w < key[v]){
            parent[v] = u ;
            key[v] = w ;
        }
       }
   }

   for(int i = 2 ; i <= n  ; i++){
    v.push_back({{parent[i] , i} , key[i]});
   }
   }
};

int main(){
    Graph g ;
    g.addedge(0 , 1 , 7);
    g.addedge(0 , 2, 1);
    g.addedge(0 , 3, 2);
    g.addedge(1 , 2, 3);
    g.addedge(1 , 3 , 5);
     g.addedge(1 , 4 , 1);
    g.addedge(3 , 4 , 7 );
    
    g.print();
    int n = 5 ;

   vector<pair<pair<int, int>, int>> v ;
   g.prims(v , n ) ;


}
