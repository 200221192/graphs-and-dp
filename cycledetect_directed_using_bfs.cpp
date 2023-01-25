#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>

// cycle detection in directed graph using bfs 
using namespace std ;


 // creating adjacency list 
 void addEdge(unordered_map<int , list<int>> &adj , int u , int v , bool direction){
   adj[u].push_back(v);
   if(direction == 0){
       adj[v].push_back(u);
   }
 }

int main(){
    unordered_map<int , list<int>>adj ;
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

    // find all indegree
    vector<int> indegree(n) ;
    for(auto i  : adj ){
        for(auto j : i.second){
            indegree[j]++ ;
        }
    }
    
    //push all node whose indegree is 0 
    queue<int> q;
    for(int i = 0 ; i < n ; i++){
        if(indegree[i] == 0)
          q.push(i);
    }

   // do bfs 
   int count = 0 ; 
   while(!q.empty()){
    int front = q.front();
    q.pop();

    // increment count 
    count++ ;

    // neighbour indegree update 
    for(auto neighbour : adj[front]){
        indegree[neighbour]-- ;
        if(indegree[neighbour] == 0 )
        q.push(neighbour);
    }
   }

  if(count == n)
   cout<<"cycle not present ";
  else 
  cout<<"cycle Detected" ;
}