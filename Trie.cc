/*
Implementation of Trie:

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and 
retrieve keys in a dataset of strings. There are various applications of this data structure, such as 
autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/
struct Node{
    Node*link[26];
    bool flag=false;

    bool contains(char x){
        return link[x-'a']!=NULL;
    }
};

class Trie {
public:
    Node*root;
    Trie() {
        root=new Node();
    }
    /*
    inserting of string in a Trie
    */
    void insert(string word) {
        Node*node=root;
        int size=word.size();
        for(int i=0;i<size;i++){
              if(!node->contains(word[i])){
                  node->link[word[i]-'a']=new Node();
              }
              node=node->link[word[i]-'a'];
        }
        node->flag=true;
    }
    /*
    searching for a word in a Trie.
    */
    bool search(string word) {
        Node*node=root;
        int size=word.size();
        for(int i=0;i<size;i++){
              if(!node->contains(word[i])){
                  return false;
              }
              node=node->link[word[i]-'a'];
        }
        return node->flag;
    }
    /*
    Searching for a prefix in a Trie.
    */
    bool startsWith(string prefix) {
         Node*node=root;
        int size=prefix.size();
        for(int i=0;i<size;i++){
              if(!node->contains(prefix[i])){
                  return false;
              }
              node=node->link[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */