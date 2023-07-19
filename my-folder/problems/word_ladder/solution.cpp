class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());

        q.push({beginWord,1});
        st.erase(beginWord);   //wheenever we add something to queue, we erase it from the set so that it doesnt enter queue again;

        while(!q.empty()){
            auto temp=q.front();

            string word=temp.first;
            int len=temp.second;
            q.pop();
            
            if(word==endWord)
                return len;
            for (int i=0;i<word.size();i++){
                char og=word[i];

                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word) != st.end()){
                        q.push({word,len+1});
                        st.erase(word);
                    }
                }
                word[i]=og;
            }
        }
        return 0;
    }
};