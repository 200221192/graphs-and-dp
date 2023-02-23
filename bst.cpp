//creating a binary search tree and binary tree insert the elements and traverse the tree by inorder , preorder , postorder method , left , right , top , bottom viw of tree
#include<iostream>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
typedef struct tree{
    struct tree *left ;
    struct tree *right ;
    int val ;
}btree;

btree* create( int num){
    btree *temp;
    temp = (btree*)malloc(sizeof(btree));
    if(temp == NULL){
        cout<<"memory not allocated\n";
    }
    else{
        temp->val = num;
        temp->left = NULL;
        temp->right = NULL;
    }
    return temp ;
}
void insert(btree *root , btree *temp){
    if(temp->val < root->val){
        if(root->left == NULL)
        root->left = temp;
        else
        insert(root->left , temp);
    }
    else{
        if(root->right == NULL)
         root->right = temp;
         else
          insert(root->right , temp);
    }
}

// level order traversal
void levelorder(btree *root){
    queue<btree*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        btree *temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<"  ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}
// inorder traversal
void inorder(btree *root){
    if(root == NULL)
    return ;

        inorder(root->left);
        cout<<root->val<<"\t";
        inorder(root->right);

}

//preorder traversal
void preorder(btree *root){
    if(root == NULL)
    return ;
        cout<<root->val;
        preorder(root->left);
        preorder(root->right);
        
}

//postorder traversal
void postorder(btree *root){
    if(root == NULL)
    return ;

        postorder(root->left);
        postorder(root->right);
         cout<<root->val;  
}

// right view 
void rightview(btree *root , int level ,vector<int> &ans){
    if(root == NULL)
    return ;

    if(level == ans.size())
    ans.push_back(root->val);
    rightview(root->right , level+1 , ans);
    rightview(root->left , level+1 , ans); 
}


// left view
void leftview(btree *root , int level ,vector<int> &ans){
    if(root == NULL)
    return ;

    if(level == ans.size())
    ans.push_back(root->val);
    leftview(root->left , level+1 , ans);
    leftview(root->right , level+1 , ans); 
}

// top view
vector<int> topview(btree *root){
    vector<int> ans ;
    if(root == NULL)
    return ans ;
    map<int ,int> mpp ; // line , node
    queue<pair<btree* , int>> q ; // node , line
    q.push({root , 0});
    while(!q.empty()){
        auto top = q.front() ;
        q.pop() ;
        int line = top.second ;
        btree* node = top.first ;
        if(mpp.find(line) == mpp.end())
        mpp[line] = node->val ;

        if(node->left != NULL){
            q.push({node->left , line-1});
        }
        if(node->right != NULL){
            q.push({node->right , line+1});
        }
    }
    for(auto it : mpp){
            ans.push_back(it.second);
        }
    return ans ;

}

// bottome view
vector<int> bottomview(btree *root){
    vector<int> ans ;
    if(root == NULL)
    return ans ;
    map<int ,int> mpp ; // line , node
    queue<pair<btree* , int>> q ; // node , line
    q.push({root , 0});
    while(!q.empty()){
        auto top = q.front() ;
        q.pop() ;
        int line = top.second ;
        btree* node = top.first ;
        //(mpp.find(line) == mpp.end())
        mpp[line] = node->val ;

        if(node->left != NULL){
            q.push({node->left , line-1});
        }
        if(node->right != NULL){
            q.push({node->right , line+1});
        }
    }
      for(auto it : mpp){
            ans.push_back(it.second);
        }
    return ans ;

}


// main function
int main(){
    btree *root = NULL , *temp = NULL ;
    int num , opt , ch ;
    cout<<"insert\n"<<"preorder\n"<<"inoreder\n"<<"postorder\n";
   do{
    cout<<"enter option\n";
    cin>>opt;
    if(opt == 1){
        cout<<"enter number\n";
        cin>>num;
        temp = create(num);
        if(root == NULL)
        root = temp;
        else
        insert(root , temp);
       // root = buildtree(root);
    }
    else if(opt == 2){
        cout<<"inorder traversel:\n";
        inorder(root);
    }
     else if(opt == 3){
        cout<<"preordee traversel:\n";
        preorder(root);
    }
     else if(opt == 4){
        cout<<"postorder traversel:\n";
        postorder(root);
    }
     else if(opt == 5){
        cout<<"level oreder traversel:\n";
        levelorder(root);
     }
    else if(opt == 6){
        vector<int>ans ;
        int level = 0 ;
        cout<<"right view of the tree:\n";
        rightview(root , level ,ans);
        for(int i = 0 ; i < ans.size() ; i++){
            cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    else if(opt == 7){
        vector<int>ans ;
        int level = 0 ;
        cout<<"left view of the tree:\n";
        leftview(root , level ,ans);
        for(int i = 0 ; i < ans.size() ; i++){
            cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    else if(opt == 8){
     vector<int>ans ;
        cout<<"top view of the tree:\n";
        ans = topview(root);
        for(int i = 0 ; i < ans.size() ; i++){
            cout<<ans[i]<<" ";
        }
    }
    else if(opt == 9){
     vector<int>ans ;
        cout<<"bottom view of the tree:\n";
        ans = bottomview(root);
        for(int i = 0 ; i < ans.size() ; i++){
            cout<<ans[i]<<" ";
        }
    }
    cout<<"enter your choice\n";
    cin>>ch;
   }while(ch==1);

}