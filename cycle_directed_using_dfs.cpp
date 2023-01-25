#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
// detect cycle in undirected graph using bfs

using namespace std ;

 // creating adjacency list 
 void addEdge(unordered_map<int , list<int>> &adj , int u , int v , int direction){
    adj[u].push_back(v);
    if(direction == 0){
       adj[v].push_back(u);
   }
 }

 bool checkcycleDfs(int node , unordered_map<int , bool> &visited , unordered_map<int , bool> &dfsvisited ,unordered_map<int , list<int>> &adj ){
    visited[node] = true ;
    dfsvisited[node] = true ;

    for(auto  neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = checkcycleDfs(neighbour , visited , dfsvisited , adj );
            if(cycleDetected)
             return true ;
        }
        else if(dfsvisited[neighbour]){
               return true ;
         }
    }
    dfsvisited[node] = false ;
    return false ;
 }


int main(){
    unordered_map<int , list<int>> adj;
    int n ;
    cout<<"enter the number of nodes "<<endl;
    cin>>n;

    int m ;
    cout<<"enter the number of edges "<<endl;
    cin>>m ;

    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin>>u >>v;
        // creating the undirected graph 

        addEdge(adj , u , v , 1);
    }

    //  printing the graph 
     for(auto i : adj){
        cout<<i.first<<"->";
        for(auto j : i.second){
            cout<< j <<",";
        }
        cout<<endl;
    }

   unordered_map<int , bool> visited ;
   unordered_map<int , bool> dfsvisited ;
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            bool cyclefound = checkcycleDfs(i , visited , dfsvisited , adj);
            if(cyclefound)
            cout<<"Yes";
        }
    }
}