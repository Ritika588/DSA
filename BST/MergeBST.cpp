#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;

    }
};


//Function to create a tree
Node* createTree()
{
    int val;
    cout <<"Enter the value: " <<endl;
    cin >> val ;

    if(val == -1)
        return NULL;
    
    Node* root = new Node(val);

    cout <<"Enter left child of " << val << endl;
    root -> left = createTree();

    cout <<"Enter right child of " << val << endl;
    root -> right = createTree();

    return root;
}


//Function to return the sorted arrangement of the tree
void inorder(Node* root, vector<int> &ans)
{
    if(root == NULL)
        return;
    
    inorder(root -> left, ans);
    ans.push_back(root -> data);
    inorder(root -> right, ans);

}

//Function to create a merged sorted array
    vector<int> mergetrees( vector<int> tree1, vector<int> tree2)
    {
        vector<int> result;
        int i =0, j =0;
        int m = tree1.size(), n = tree2.size();

        while( i<  m && j < n)
        {
            if(tree1[i] < tree2[j])
                result.push_back(tree1[i++]);
            else
                result.push_back(tree2[j++]);
        }

        while( i<m)
            result.push_back(tree1[i++]);
        while( j< n)
            result.push_back(tree2[j++]);

        return result;
    }


//Main function
int main()
{
    //input tree from the user

        cout <<"Build first tree" <<endl;
        Node* root1 = createTree();

        cout <<"Build second tree" <<endl;
        Node* root2 = createTree();

    //store their sorted vaues in array
    
        vector<int> tree1;
        vector<int> tree2;

        inorder(root1, tree1);
        inorder(root2, tree2);
    
    // return a merged sorted array
        
        vector<int> result = mergetrees(tree1, tree2);

    // build Binary Tree out of it
    return 0;
}


