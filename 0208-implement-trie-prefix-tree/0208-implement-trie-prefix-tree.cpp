struct Node{
    Node *links[26];
    bool flag = false;

    //check if reference trie is present or not
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    //creating reference trie
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }

    //to get to node for traversal
    Node *get(char ch){
        return links[ch-'a'];
    }

    //setting flag to true at the end of the word
    void setEnd(){
        flag = true;
    }

    //checking if the word is completed or not
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        //creating new object
        root= new Node();
    }
    
    void insert(string word) {
        //initializing dummy node pointing to root initially to root
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            //moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i]))return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node *node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i]))return false;
            node = node->get(word[i]);
        }
        return true;
    }
};
