class Trie {
public:
    struct Node {
        Node* children[26];
        bool end;
        Node() {
            for(int i=0; i<26; i++)
                children[i]=NULL;
            end=false;
        }
    };
    Node* head;
    Trie() {
        head=new Node();        
    }
    
    void insert(string word) {
        Node *temp=head;
        for(char c: word) {
            if(temp->children[c-'a']==NULL) {
                Node *nn=new Node();
                temp->children[c-'a']=nn;
            }
            temp=temp->children[c-'a'];
        }
        temp->end=true;
    }
    
    bool search(string word) {
        Node *temp=head;
        for(int i=0; i<word.size(); i++) {
            if(temp->children[word[i]-'a']==NULL)
                return false;
            temp=temp->children[word[i]-'a'];
        }
        return temp->end;
    }
    
    bool startsWith(string word) {
        Node *temp=head;
        for(int i=0; i<word.size(); i++) {
            if(temp->children[word[i]-'a']==NULL)
                return false;
            temp=temp->children[word[i]-'a'];
        }
        return true;
    }
};
