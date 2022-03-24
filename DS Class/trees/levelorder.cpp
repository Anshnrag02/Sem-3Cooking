/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<pair<int,int>>v;
    queue<pair<Node*,int>>q;
public:
    
    void solver(Node* root, int lvl=0){
        
        if(root==NULL)
            return;
        
        q.push({root,lvl});
        
        while(!q.empty()){
            pair<Node * , int>p = q.front();
            Node* node = p.first;
            int level = p.second;
            v.push_back({node->val,level});
            q.pop();
            for(int i = 0 ; i<node->children.size(); ++i){
                if(node->children[i]!=NULL){
                    q.push({node->children[i],level+1});
                }
            }
        }           
    }
    
    bool compare(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    
    
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL){
            return {};
        }
        solver(root);
        vector<vector<int>>ans;
        vector<int>temp;
        temp.push_back(v[0].first);
        for(int i = 1 ; i<v.size(); ++i ){
            if(v[i-1].second == v[i].second){
                temp.push_back(v[i].first);
            }
            else{
                if(!temp.empty())
                    ans.push_back(temp);
                temp.clear();
                temp.push_back(v[i].first);
            }
        }
        if(!temp.empty()){
            ans.push_back(temp);
        }
        
        return ans;
    }
};