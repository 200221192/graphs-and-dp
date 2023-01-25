#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<queue>
// shortest path

using namespace std ;

 void addEdge(unordered_map<int , list<int>> &adj , int u , int v , bool direction){
   // create an edge from u to v
   adj[u].push_back(v);
   if(direction == 0){
       adj[v].push_back(u);
   }
 }

  void shortest_path(int src , int dst , unordered_map<int , list<int>> &adj , vector<int>&ans){
    unordered_map<int , bool>visited;
    unordered_map<int , int> parent ;

   queue<int>q;
   q.push(src);
   parent[src] = -1 ;
   visited[src] = 1;

   while(!q.empty()){
    int frontnode = q.front();
    q.pop();

    // traverse all the neighbour of frontnode
    for(auto i : adj[frontnode]){
        if(!visited[i]){
            visited[i] = 1;
            parent[i] = frontnode ;
            q.push(i);
        }
    }
  }

   // prepare shortest path
  int currentnode = dst ;
  ans.push_back(dst);

  while(currentnode != src){
    currentnode = parent[currentnode];
    ans.push_back(currentnode);
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
         addEdge( adj , u , v , 0);
    }

    //  printing the graph 
    for(auto i : adj){
        cout<<i.first<<"->";
        for(auto j : i.second){
            cout<< j <<",";
        }
        cout<<endl;
    }

    cout<<"enter the source node: " ;
    int src ;
    cin>>src ;

    cout<<endl; 
    cout<<"entr the destination node : " ;
    int dst ;
    cin>>dst ;

    vector<int>ans ;

    shortest_path(src , dst , adj ,ans);

    reverse(ans.begin() , ans.end());

    for(int i = 0 ; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}