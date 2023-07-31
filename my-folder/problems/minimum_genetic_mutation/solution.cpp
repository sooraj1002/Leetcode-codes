class Solution {
public:
    int minMutation(string begin, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        vector<char> vec={'A','C','G','T'};
        queue<pair<string,int>> q;
        q.push({begin,0});
        st.erase(begin);

        while(!q.empty()){
            auto t=q.front();
            q.pop();
            string word=t.first;
            int dist=t.second;

            if(word==end)
                return dist;

            for(int i=0;i<word.size();i++){
                char c=word[i];
                for(int j=0;j<4;j++){
                    word[i]=vec[j];
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,dist+1});
                    }
                }
                word[i]=c;
            }
        }
        return -1;
    }
};