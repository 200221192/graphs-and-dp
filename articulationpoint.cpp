#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std ;

// articulation point in a grpah 
void addedge(unordered_map<int,list<int>> &adj , int u , int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(unordered_map<int,list<int>> &adj , unordered_map<int , bool > &vis , vector<int> &disc , vector<int> &low , int parent , int node , int timer , vector<int>&res){
    vis[node] = 1 ;
    disc[node] = low[node] = timer++ ;
    int child = 0 ;

    for(auto nbr : adj[node]){
        // if the node is parent
        if(nbr == parent)
        continue ;

        // univisited node
        if(!vis[nbr]){
            dfs(adj , vis , disc , low , node , nbr , timer , res);
            low[node] = min(low[node] , low[nbr]);

            // check whether the node is articulation point or not
            if(low[nbr] >= disc[node] && parent != -1){
                res[node] =  1 ;   
            }
            child++ ;
        }
        else{
         // the node is visited but not the parent 
          // back edge
          low[node] = min(low[node] , disc[nbr]);
        }
    }
    if(parent == -1 && child > 1){
        res[node] = 1;
    }

}


int main()
{
    cout<<"enter the no of nodes and edeges:"<<endl;
    int n , m ;
    cin>>n>>m;
    unordered_map<int , list<int>>adj;
    for(int i = 0 ; i < m ; i++){
         int u , v ;
         cin>>u>>v;
         addedge(adj , u , v);
    }

    // printing the adjacency list
    for(auto i : adj){
        cout<<i.first<<"->";
        for(auto j : i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    // finding bridges in graph
    vector<int>low(n);
    vector<int>disc(n);
    int parent=-1 ;
    unordered_map<int,bool>vis ;

    for(int i = 0 ; i < n ; i++){
        disc[i] = -1;
        low[i] = -1  ;
    }
    int timer = 0 ;

    vector<int>ans(n,0) ;
    for(int i = 0 ; i < n ; i++){
        if(!vis[i] ){
            dfs(adj , vis , disc , low , parent , i , timer ,ans);
        }
    }

    cout<<"the articulation points in the graphs are as follows:"<<endl;
    for(int i = 0 ; i < n ; i++){
       if(ans[i] != 0){
        cout<<i<<" ";
       }
    }cout<<endl;
}
