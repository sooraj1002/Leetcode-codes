class Solution {
public:
    void forward(string &s){
        int l=s.size();
        char temp;
        temp=s[0];
        for(int i=0;i<l-1;i++)
        {
            s[i]=s[i+1];
        }
        s.pop_back();
        s=s+temp;
    }
        
    bool rotateString(string s, string goal) {
        int flag=0;
        if(goal.size() != s.size())
            return false;
        for(int i=0;i<goal.size();i++)
        {
            cout<<s<<endl;
            if(s==goal)
            {
                flag=1;
                break;
            }
            forward(s);
        }
        return flag==1;
    }
};