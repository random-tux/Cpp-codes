#include<bits/stdc++.h>
using namespace std;

bool isConnected(int** edges, int v, int startVertex){
    
    queue<int> pending;
    bool* visited = new bool[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
    }

    pending.push(startVertex);
    visited[startVertex] = true;

    while(!pending.empty()){
        int currVertex = pending.front();
        pending.pop();
        cout << currVertex << " ";

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
    for(int i=0; i<v; i++){
        if(!visited[i]){
            return false;
        }
    }
    delete [] visited;
    return true;
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

    cout << isConnected(edges, v, 0) << endl;

    for(int i=0; i<v; i++){
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}





