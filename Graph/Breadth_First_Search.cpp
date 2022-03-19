#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int size;
    list<int> *adj;
    public:
    // Constructor.
    Graph(int s){
        this->size = s;
        adj = new list<int> [s];
    }
    void addEdge(int a, int b){
        adj[a].push_back(b);
    }
    void BFS(int elem){
        bool *visited = new bool[size]; // boolen array same size as graph.

        // initilize all element to false.
        for (int i = 0; i < size; i++)
        {
            visited[i] = false;
        }
        queue<int> q;
        
        
        visited[elem] = true;
        q.push(elem);

        list<int> ::iterator i;

        while (!q.empty())
        {   
            // pop element from queue and print it.
            elem = q.front();
            cout<< elem <<" ";
            q.pop();
            // visit all element from 'elem'(poped element) and push unvisited element to queue.
            for ( i = adj[elem].begin(); i != adj[elem].end(); i++)
            {
                if(!visited[*i]){
                    visited[*i] = true;
                    q.push(*i);
                }
            }
            

        }        
    }
};

int main(){
    Graph g(4);
     g.addEdge(0,1);
     g.addEdge(0,2);
     g.addEdge(1,2);
     g.addEdge(2,0);
     g.addEdge(2,3);
     g.addEdge(3,3);
     g.addEdge(3,0);
     g.BFS(3);


    return 0;
}