class Solution {
public:
    bool checkString(string s) {
        int l=s.size();
        int flag=0;
        for(int i=0;i<l-1;i++)
        {
            if(s[i]=='b')
            {
                for(int j=i+1;j<l;j++)
                {
                    cout<<"for loop"<<endl;
                    if(s[j]=='a')
                    {
                        cout<<"yes"<<endl;
                        flag=1;
                        break;
                    }
                }
                if (flag==1)
                    break;
            }
        }
        if(flag==1)
            return false;
        else 
            return true;
    }
};