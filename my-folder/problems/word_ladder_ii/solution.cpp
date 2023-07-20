class Solution {
public:
    string b;
    void dfs(string word,vector<string> &seq,vector<vector<string>> &ans,unordered_map<string,int> &mp){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mp[word];
        int size=word.size();
        for(int i=0;i<size;i++){
            char c=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mp.find(word) != mp.end() && mp[word]+1 ==steps){
                    seq.push_back(word);
                    dfs(word,seq,ans,mp);
                    seq.pop_back();
                }
            }

            word[i]=c;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        unordered_map<string,int> mp;
        b=beginWord;

        q.push(beginWord);
        mp[beginWord]=1;
        int size=beginWord.size();
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front();
            int steps=mp[word];
            q.pop();

            if(word==endWord)
                break;
            for(int i=0;i<size;i++){
                char c=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        q.push(word);
                        mp[word]=steps+1;
                        st.erase(word);
                    }
                }

                word[i]=c;
            }
        }
        vector<vector<string>> ans;
        if(mp.find(endWord) != mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq,ans,mp);
        }


        return ans;
    }
};