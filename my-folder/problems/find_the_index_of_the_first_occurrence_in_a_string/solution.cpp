class Solution {
public:
    int strStr(string haystack, string needle) {
        int k=0;
        for(int i=0;i +needle.size()-1<haystack.size();i++){
            if(haystack.substr(i,needle.size())==needle){
                return i;
            }
        } 
        return -1;
    }
};