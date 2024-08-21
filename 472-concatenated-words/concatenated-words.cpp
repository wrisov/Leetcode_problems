class Solution {
public:
    struct trie{
        trie* child[26];
        string s="";
    };
    vector<string>ans;
    trie* root;
    void insert(string key,trie* root){
        for(int i=0;i<key.size();i++){
            if(root->child[key[i]-'a']==NULL){
                root->child[key[i]-'a']=new trie();
            }
            root=root->child[key[i]-'a'];
        }
        root->s=key;
    }
    void search1(trie* curr,trie* newnode){
         if(curr->s!="" && newnode->s!=""){
            ans.push_back(curr->s);
            curr->s="";
         }
         if(newnode->s!=""){
            search1(curr,root);
         }
         for(int i=0;i<26;i++){
            if(curr->child[i]!=NULL && newnode->child[i]!=NULL){
                search1(curr->child[i],newnode->child[i]);
            }
         }
    }
    void search(trie* curr){
         if(curr->s!=""){
             search1(curr,root);
         }
         for(int i=0;i<26;i++){
            if(curr->child[i]!=NULL){
                search(curr->child[i]);
            }
         }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root=new trie();
        for(string x:words){
            insert(x,root);
        }
        trie* curr=root;
        search(curr);
        return ans;
    }
};