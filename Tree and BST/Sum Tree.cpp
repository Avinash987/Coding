class Solution
{ public:
    int solve(Node *node,bool &ans){
        if(node==NULL) return 0;
        if(node->left==NULL && node->right==NULL) return node->data;
        
        int ls=solve(node->left,ans);
        int rs=solve(node->right,ans);
        
        if(ls+rs!=node->data) ans=false;
        
        return node->data+ls+rs; 
        
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         bool ans=true;
         solve(root,ans);
         return ans;
        
    }
};
