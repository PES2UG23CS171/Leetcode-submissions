class WordDictionary {
private:
    struct Node {
        Node* next[26];
        bool end;
        Node() {
            for(int i=0; i<26; i++)
                next[i]=NULL;
            end=false;
        }
    };
    Node *head;
public:
    WordDictionary() {
        head=new Node();
    }
    
    void addWord(string word) {
        Node* temp=head;
        for(char c: word) {
            if(temp->next[c-'a']==NULL) {
                Node* nn= new Node();
                temp->next[c-'a']=nn;
            }
            temp=temp->next[c-'a'];
        }
        temp->end=true;
    }
    bool back(Node* th, string& word, int s) {
        Node* temp=th;
        bool cond=false;
        for(int i=s; i<word.size(); i++) {
            char c=word[i];
            if(c=='.') {
                for(int j=0; j<26 && !cond; j++) {
                    if(temp->next[j])
                        cond=cond | back(temp->next[j], word, i+1);
                }
                return cond;
            }
            if(temp->next[c-'a']==NULL)
                return false;
            temp=temp->next[c-'a'];
        }
        return temp->end;
    }
    bool search(string word) {
        return back(head, word, 0);
    }
};
