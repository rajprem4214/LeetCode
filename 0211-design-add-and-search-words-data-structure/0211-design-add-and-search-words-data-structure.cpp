class Node{
    public:
    Node* link[26];
    bool flag;
    
    bool hasLink(char chr){
        return link[chr-'a'] != NULL;
    }
    
    void putLink(char chr,Node* node){
        link[chr-'a'] = node;
    }
    
};
class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        Node* temp = new Node();
        root = temp;
    }
    
    void addWord(string word) {
        Node* temp = root;
        
        for(auto chr : word){
            if(temp->hasLink(chr) == false){
                temp->putLink(chr,new Node());
            }
            
            temp = temp->link[chr-'a'];
        }
        
        temp->flag = true;
    }
    
    bool getans(int ind,string word,Node* node){
        
        
        if(node == NULL) return false;
        
        if(ind == word.size()) return node->flag;
        
        if(word[ind] == '.'){
            
            for(int i = 0;i < 26;i++){
                if(node->link[i] != NULL && getans(ind+1,word,node->link[i])) return true;
            }
            
        }else{
            //Note : Below line reduces the run time of code
            if(node->link[word[ind] - 'a'] == NULL) return false;
            
            return getans(ind+1,word,node->link[word[ind] - 'a']);
        }
        return false;
    }
    
    bool search(string word) {
        
        Node* temp = root;
        return getans(0,word,temp);
        
    }
};
