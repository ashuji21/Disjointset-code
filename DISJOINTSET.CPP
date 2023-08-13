#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
      vector<int> rank, parent, size;
      DisjointSet(int n){
         rank.resize(n+1,0);
         parent.resize(n+1);
         for(int i=0; i<=n; i++){
            parent[i]=i;
         }
      }
      int findUpar(int node){
         if(node==parent[node]){
            return node;
         }
         return parent[node]=findUpar(parent[node]);
      }
      void UnionByRank(int u, int v){
         int ulp_u=findUpar(u);
         int ulp_v=findUpar(v);
         if(ulp_v==ulp_u) return;
         if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
         }
         else if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
         }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
         }
      }
      void UnionBySize(int u, int v){
         int ulp_u=findUpar(u);
         int ulp_v=findUpar(v);
         if(ulp_u==ulp_v) return;
         if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
         }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
         }
      }
};
int main(){
   DisjointSet ds(7);
   ds.UnionByRank(1,2);
   ds.UnionByRank(2,3);
   ds.UnionByRank(4,5);
   ds.UnionByRank(6,7);
   ds.UnionByRank(5,6);
   if(ds.findUpar(3)==ds.findUpar(7)){
      cout<<"SAME"<<endl;
   }else{
      cout<<"NOT SAME"<<endl;
   }
   ds.UnionByRank(3,7);
   if(ds.findUpar(3)==ds.findUpar(7)){
      cout<<"SAME"<<endl;
   }else{
      cout<<"NOT SAME"<<endl;
   }
}