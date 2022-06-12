oid remove_node(int i){
//     cout<<"HERE"<<i<<endl;
//     removed[i]=1;
//     vector<int>t=adj[i];
//     adj[i].clear();
//     for(auto x:t){
//         vector<int>::iterator it = find(adj[x].begin(),adj[x].end(),i);
//         adj[x].erase(it);
//         if(adj[x].size()<k){
//             remove_node(x);
//         }
//     }
// }