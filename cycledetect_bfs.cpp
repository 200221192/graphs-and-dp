#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
// detect cycle in undirected graph using bfs

using namespace std ;
class graph{
public:
 
 // creating adjacency list 
 void addEdge(unordered_map<int , list<int>> &adj , int u , int v , bool direction){
   // direction = 0 -> undirected
   // direction = 1 -> directed 

   // create an edge from u to v
   adj[u].push_back(v);
   if(direction == 0){
       adj[v].push_back(u);
   }
 }

  bool iscyclic_bfs(unordered_map<int , list<int>> &adj  , unordered_map<int , bool> &visited , int node){
   unordered_map<int , int>parent ;
   parent[node] = -1 ;
   visited[node] = 1;

   queue<int>q;
   q.push(node);

   while(!q.empty()){
    int frontnode = q.front();
    q.pop();

    // traverse all the neighbour of frontnode
    for(auto neighbour : adj[frontnode]){
        if( visited[neighbour] == true && neighbour != parent[frontnode] ){
            return true ;
        }
        else if(!visited[neighbour])
        {
            q.push(neighbour);
            visited[neighbour] = 1 ; 
            parent[neighbour] = frontnode;
        }
    }
   }
    return false ;
}

};

int main(){

    unordered_map<int , list<int>>adj ;
    unordered_map<int , bool> visited ;
    int n ;
    cout<<"enter the number of nodes "<<endl;
    cin>>n;

    int m ;
    cout<<"enter the number of edges "<<endl;
    cin>>m ;

    graph g ;

    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin>>u >> v;

        // creating the undirected graph 

        g.addEdge( adj , u , v , 0);
    }

    //  printing the graph 
    for(auto i : adj){
        cout<<i.first<<"->";
        for(auto j : i.second){
            cout<< j <<",";
        }
        cout<<endl;
    }

  // traverse all the component of the graphs
  for(int i = 0 ; i <= n ; i++){
    if(!visited[i] ){
      bool ans = g.iscyclic_bfs(adj , visited , i);
      if(ans == 1)
       cout<<"Yes";
    }
  }
  

}