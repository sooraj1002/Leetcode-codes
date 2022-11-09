class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        int l=n.size();
        int a;
        if(n[0]==n[l-1])
            return 1;
        int count;
        int k=1;
        for(int i=0;i<n.size()-1;i++)
        {
            if(n[i] != n[i+1])
            {
                count++;
                n[k]=n[i+1];
                k++;
            }
        }
        return count;
    }
};