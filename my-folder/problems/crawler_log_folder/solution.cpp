class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(int i=0;i<logs.size();i++)
        {
            cout<<logs[i]<<endl;
            if(logs[i] != "../" && logs[i] != "./")
                count++;
            if(logs[i]=="../")
                count--;
            if(count<0)
                count=0;
        }
        return count;
    }
};