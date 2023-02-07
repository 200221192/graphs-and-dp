#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<set>
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

    void dijkstra(vector<int> &dist ,  int vertices , int source){
       for(int i = 0 ; i < vertices ; i++){
        dist[i] = INT_MAX ;
       }

       set<pair<int , int> > s ;

       dist[source] = 0 ;
       s.insert(make_pair(0 , source));
       while(!s.empty()){
        auto top = *(s.begin());

        int nodeDist = top.first;
        int topNode = top.second ;


        s.erase(s.begin());

        for(auto neighbour : adj[topNode]){
            if(nodeDist + neighbour.second < dist[neighbour.first]){
                auto record = s.find(make_pair(dist[neighbour.first] , neighbour.first));

                if(record != s.end()){
                    s.erase(record);
                }
               
               dist[neighbour.first] = nodeDist + neighbour.second ;

               s.insert(make_pair(dist[neighbour.first] , neighbour.first));

            }
          }
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

    int src ;
    cin>> src;
     
    vector<int> dist(n);
     g.dijkstra(dist , n , src );

     for(int i = 0 ; i < dist.size() ; i++){
        cout<<dist[i]<<" ";
     }

}
