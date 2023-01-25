#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
// dfs graph traversal

using namespace std ;
class graph{
public:
 void addEdge(unordered_map<int , list<int>> &adj , int u , int v , bool direction){
   // direction = 0 -> undirected
   // direction = 1 -> directed 

   // create an edge from u to v
   adj[u].push_back(v);
   if(direction == 0){
       adj[v].push_back(u);
   }
 }

 void dfs(unordered_map<int , list<int>> &adj ,unordered_map<int , bool> &visited , vector<int> &component , int node ){
   component.push_back(node);
   visited[node] = true;

   // all connected node k liye recursive call
   for(auto i : adj[node]){
    if(!visited[i]){
        dfs(adj , visited , component ,i);
    }
   } 
 }
};

int main(){

    unordered_map<int , list<int>>adj ;
    unordered_map<int , bool> visited ;
    vector<vector<int>>ans ;
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
  for(int i = 0 ; i < n ; i++){
    if(!visited[i]){
       vector<int> component ;
       g.dfs(adj , visited , component , i );
       ans.push_back(component);
    }
  }

  // printing the dfs traversal
  for(int i = 0 ; i < ans.size() ; i++){
    for(int j = 0 ; j < ans[i].size() ; j++){
        cout<<ans[i][j]<<" ";
    }
  }
}