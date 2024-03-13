#include<iostream>
#include<climits>
using namespace std;

int findMiVertex(int* distance, bool* visited,int n){
    int minVertex = -1;
    for(int i=0;i<n;i+=1){
        if(!visited[i] && distance[i]<distance[minVertex]){
            minVertex=i;
        }
    }return minVertex;
}
void dijkstra2(int** edges, int n){
    int* distance = new int[n];
    bool* visited = new bool[n];
    for(int i = 0; i < n; i+=1){
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    distance[0]=0;

    for(int i = 0; i<n-1;i+=1){
        int minVertex=findMiVertex(distance,visited,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j] !=0 && !visited[j]){
                int dist = distance[minVertex]+edges[minVertex][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }
    for(int i=0; i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete [] visited;
    delete [] distance;
}
int main(){
int n,e;
cin>>n>>e;
int** edges= new int*[n];
for(int i = 0; i<n;i++){
    edges[i]=new int[n];
    for(int j=0;j<0;j++){
        edges[i][j]=0;
    }
}

return 0;
}

