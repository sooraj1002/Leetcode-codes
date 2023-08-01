class Solution {
public:
    bool check(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int maxVowels(string s, int k) {
        int i=0,j=0;
        int n=s.size();
        int count=0;
        int ans=0;
        while(i<n){
            if(i<k && check(s[i])){
                count++;
            }
            else if(i>=k){
                if(check(s[j])){
                    count--;
                }
                if(check(s[i])){
                    count++;
                }
                j++;
            }
            ans=max(ans,count);
            i++;
        }
        return ans;
    }
};