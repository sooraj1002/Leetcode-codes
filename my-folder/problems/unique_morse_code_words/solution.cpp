class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> l={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> v;
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            string s1;
            for(int j=0;j<s.size();j++)
            {
                int temp=(int)s[j]-97;
                string s2=l[temp];
                s1=s1+s2;
            }
            v.push_back(s1);
            s1="";
        }
        
        sort(v.begin(),v.end());
        
        for(string i:v)
            cout<<i<<endl;
        int distinct=1,len=v.size();
        if(len>1)
        {
            for(int i=0;i<len-1;i++)
            {
                if(v[i] != v[i+1])
                    distinct++;
            }
        }
        else
            return 1;
        
        // if(len>2 && v[len-2] != v[len-1])
        //     distinct++;
        return distinct;
    }
};