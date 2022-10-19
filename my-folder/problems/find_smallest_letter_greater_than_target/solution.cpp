class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=0;
        int flag=0;
        for(;i<letters.size();i++)
        {
            if(letters[i]>target)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            return letters[i];
        return letters[0];
    }
};