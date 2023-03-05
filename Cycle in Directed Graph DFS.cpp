#include<list>
#include<unordered_map>
bool iscycle(int node,  unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,unordered_map<int, list<int>> &adj){
visited[node]=true;
dfsvisited[node]=true;
for(auto neighbour:adj[node]){
  if(!visited[neighbour]){
    bool cycle=iscycle(neighbour,visited,dfsvisited,adj);
    if(cycle)return true;
  }
  else if (dfsvisited[neighbour])return true;
}
dfsvisited[node]=false;
return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int, list<int>> adj;
  for(int i=0;i<n;i++){
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
  }
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;
  for(int i=1;i<=n;i++){
    if(!visited[i]){
      bool cycle=iscycle(i,visited,dfsvisited,adj);
      if(cycle)return true;
    }
  }
  return false;
}