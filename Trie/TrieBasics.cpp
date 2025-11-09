#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Creation of TrieNode class to declare and initilaize the Trie
class TrieNode
{
public:
    char data;
    bool isTerminal;
    TrieNode *children[26];

    TrieNode(char ch)
    {
        data = ch;
        isTerminal = false;
        for(int i = 0; i<26; i++)
        {
            children[i] = NULL;
        }
    }
};

// Creation of Trie class with functions
class Trie
{
public:
    TrieNode* root;            // pointer to an object of TrieNode class

    Trie()
    {   
        root = new TrieNode('\0');    // initialize the root node with zero as a char
    }


    //Function to insert
    void Insertion(TrieNode* root, string word)
    {
        // Base Case
        if(word.length() == 0)
        {
            root -> isTerminal = true;
            return;
        }

        // assuming words are all in lowercase
        int index = word[0] - 'a';
        TrieNode* child;

        // if the word exists in the trie, push it into the child node
        if(root -> children[index] != NULL)
            child = root -> children[index];

        // else create a new node and place inside children
        else{
            child = new TrieNode(word[0]);
            root -> children[index] = child;

        }
        // recursive call 
        Insertion(child, word.substr(1));

    }


    void insertWord(string word)
    {
        Insertion (root, word);
    }


    bool searchWord (TrieNode* root, string word)
    {
        if(word.length() == 0)
            return root -> isTerminal;

        int index = word[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL)
            child = root -> children[index];

        else
            return false;

        return searchWord( child, word.substr(1));
    }

    bool searching(string word)
    {
        return searchWord( root, word);
    }
    
};

int main()
{
    Trie *t = new Trie();
    t -> insertWord("ram");
    t -> insertWord("raju");
    t -> insertWord("raven");
    t -> insertWord("tree");

    cout << t -> searching("raju") << endl;     // returns 1;
    cout << t-> searching("make") << endl;      // returns 0;

    return 0;
}

