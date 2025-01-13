#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj(n);
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);

        for(auto flight:flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        q.push({0,{src,0}});
        dist[src] =0;

        //dijksra
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            int stops = frontNode.first;
            int node = frontNode.second.first;
            int cost = frontNode.second.second;

            if(stops>k){
                continue;
            }
            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int w = iter.second;

                if(cost+w < dist[adjNode] && stops<=k){
                    dist[adjNode] = cost+w;
                    q.push({stops+1,{adjNode,cost+w}});
                }
            }
        }

        if(dist[dst]==1e9){
            return -1;
        }
        else{
            return dist[dst];
        }
    }
};