#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<queue>
// bfs graph traversal

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

 //bfs traversal
  void bfs(unordered_map<int , list<int>> &adj  , unordered_map<int , bool> &visited , vector<int>&ans , int node){
   queue<int>q;
   q.push(node);
   visited[node] = 1;
   while(!q.empty()){
    int frontnode = q.front();
    q.pop();

    //store frontnode into ans ;
    ans.push_back(frontnode);

    // traverse all the neighbour of frontnode
    for(auto i : adj[frontnode]){
        if(!visited[i]){
            q.push(i);
            visited[i] = 1;
        }
    }
  }
}
};

int main(){

    unordered_map<int , list<int>>adj ;
    unordered_map<int , bool> visited ;
    vector<int>ans ;
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
      g.bfs(adj , visited , ans , i );
    }
  }

  // printing the bfs traversal
  for(int i = 0 ; i < n ; i++){
    cout<<ans[i]<<" ";
  }
}