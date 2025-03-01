#include <iostream>
#include <unordered_map>
#include <string>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isFullWord;

    TrieNode() {
        children = {};
        isFullWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(std::string word) {
        TrieNode* curr = root;
        for(char& c : word) {
            if(curr->children.find(c) == curr->children.end()) {
                TrieNode* newNode = new TrieNode();
                curr->children.insert({c, newNode});
            }
            curr = curr->children[c];
        }

        curr->isFullWord = true;
    }

    bool search(std::string word) {
        TrieNode* curr = root;

        for(char& c : word) {
            if(curr->children.find(c) == curr->children.end())
                return false;

            curr = curr->children[c];
        }

        return curr->isFullWord;
    }

    bool starts_with(std::string prefix) {
        TrieNode* curr = root;

        for(char& c : prefix) {
            if(curr->children.find(c) == curr->children.end())
                return false;

            curr = curr->children[c];
        }

        return true;
    }
};

int main()
{
    Trie* trie = new Trie();

    trie->insert("hello");
    trie->insert("hell");
    if(trie->search("hell"))
        std::cout<<"Word exists in the dictionary"<<std::endl;
    else
        std::cout<<"Word does not exist inside the dictionary"<<std::endl;
}