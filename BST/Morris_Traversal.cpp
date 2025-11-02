#include <iostream>
#include<vector>
using namespace std;

class Node
{
public: 
    int data;
    Node* left;
    Node* right;
    
    Node(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
    
};

// to create node using data
Node* createBST(Node* root, int data)
{
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    
    if(data < root -> data)
        root -> left = createBST(root -> left, data);
    
    else
        root -> right = createBST(root -> right, data);
        
    return root;
}

// to take the data
void inputdata(Node* &root)
{
    int data;
    cin>> data;
    
    while(data != -1)
    {
        root = createBST(root, data);
        cin>>data;
    }
    
}

vector<int> morrisTraversal(Node* root, vector<int>& ans)
{
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr -> left != NULL)
        {
            Node* prev = curr -> left;
            
            while(prev -> right != NULL && prev -> right != curr)
            {
                prev = prev -> right;
            }
            
            if(prev -> right == NULL){
                prev -> right = curr;
                curr = curr -> left;
            }
            else{
                prev -> right = NULL;
                ans.push_back(curr  -> data);
                curr = curr -> right;
            }
           
        }
        
        else
        {
            ans.push_back(curr -> data);
            curr = curr -> right;
        }
    }
    
        
    return ans;
}

int main()
{
    Node* root = NULL;
    cout<<"Enter the root data: "<<endl;
    
    inputdata(root);
    
    vector<int>ans;
    morrisTraversal(root, ans);
    
    for(int x : ans)
        cout<< x << " ";
    
    cout<< endl;
    
    return 0;
    
}