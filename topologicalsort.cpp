#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>

// topological sort using dfs 

using namespace std ;
 
 // creating adjacency list 
 void addEdge(unordered_map<int , list<int>> &adj , int u , int v , bool direction){
   adj[u].push_back(v);
   if(direction == 0){
       adj[v].push_back(u);
   }
 }

void toposort( int node ,unordered_map<int , bool> &visited ,stack<int> &s,  unordered_map<int , list<int>> &adj){
    visited[node] = true ;
    for(auto neighbour : adj[node]){
        if(!visited[neighbour])
        toposort(neighbour , visited , s , adj);
    }
    s.push(node);
}


int main(){

    unordered_map<int , list<int>>adj ;
    unordered_map<int , bool> visited ;
    int n ;
    cout<<"enter the number of nodes "<<endl;
    cin>>n;

    int m ;
    cout<<"enter the number of edges "<<endl;
    cin>>m ;

    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin>>u >> v;

        // creating the undirected graph 

        addEdge( adj , u , v , 1);
    }

    //  printing the graph 
    for(auto i : adj){
        cout<<i.first<<"->";
        for(auto j : i.second){
            cout<< j <<",";
        }
        cout<<endl;
    }

  stack<int> s;
  for(int i = 0 ; i < n ; i++){
    if(!visited[i]){
        toposort(i , visited , s , adj);
    }
  }

  vector<int> ans ;
  while(!s.empty()){
    ans.push_back(s.top());
    s.pop();
  }


  for(int i = 0 ; i < ans.size() ; i++){
    cout<<ans[i]<<" ";
  }


}