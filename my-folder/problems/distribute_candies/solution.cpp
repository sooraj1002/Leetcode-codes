class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int l=candyType.size();
        int count=0;
        sort(candyType.begin(),candyType.end());
        for(int i=0;i<l-1;i++)
        {
            if(candyType[i] != candyType[i+1] )
                count++;
        }
        count++;
        if(count>l/2)
            count=l/2;
        return count;
    }
};