#include<bits/stdc++.h>
using namespace std;

void traversePath(int** edges, int v, int start, int dest, bool* isPath, stack<int> path){      //BFS traversal
    
    queue<int> pending;
    bool* visited = new bool[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
    }

    pending.push(start);
    visited[start] = true;

    while(!pending.empty()){
        int currVertex = pending.front();
        pending.pop();
        path.push(currVertex);
        if(currVertex == dest){
            *isPath = true;
            break;
        }

        for(int i=0; i<v; i++){
            if(i == currVertex){
                continue;
            }
            if(edges[currVertex][i] == 1 && !visited[i]){
                visited[i] = true;
                pending.push(i);
            }
        }
    }
    delete [] visited;
}

int main(){
    int v,e;
    cin >> v >> e;
    int** edges = new int*[v];
    for(int i=0; i<v; i++){
        edges[i] = new int[v];
        for(int j=0; j<v; j++){
            edges[i][j] = 0;
        }
    }

    while(e--){
        int v1,v2;
        cin >> v1 >> v2;
        edges[v1][v2] = 1;
        edges[v2][v1] = 1;
    }

    bool* visited = new bool[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
    }

    int start, destn;
    cin >> start >> destn;
    
    if(edges[start][destn] == 1){
        cout << destn << " " << start << endl;
    }
    else{
        bool isPath = false;
        stack<int> path;
        traversePath(edges, v, start, destn, &isPath, path);

        if(isPath){
            while(!path.empty()){
                cout << path.top() << " ";
                path.pop();
            }
        }
    }
    
    for(int i=0; i<v; i++){
        delete [] edges[i];
    }delete [] edges;
    delete [] visited;
    return 0;
}





