#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
    public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    void addEdge(int a, int b){
        adj[a].push_back(b);
    }
    void DFS(int e){
        visited[e] = true;
        cout<< e <<" ";

        list<int> ::iterator i;

        for ( i = adj[e].begin(); i != adj[e].end(); i++)
        {
            if(!visited[*i]){
                visited[*i] = true;
                DFS(*i);
            }
        }
        
    }
};

int main(){

    Graph g;
     g.addEdge(0,1);
     g.addEdge(0,2);
     g.addEdge(1,2);
     g.addEdge(2,0);
     g.addEdge(2,3);
     g.addEdge(3,3);
     g.addEdge(3,0);

     g.DFS(2);


    return 0;
}