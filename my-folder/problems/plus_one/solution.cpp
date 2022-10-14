class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int carry=0;
        vector<int> ans;
        if(*d.rbegin()+1>9)
        {
            *d.rbegin()=0;
            carry=1;
        }
        else
            *d.rbegin()=*d.rbegin()+1;
        
        for (auto it = d.rbegin()+1; it != d.rend(); it++)
        {
            if(*it+carry>9)
            {
                cout<<"yes"<<endl;
                *it=0;
                carry=1;
            }
            else
            {
                *it=*it+carry;
                carry=0;
            }
        }
        for(int i:d)
            cout<<i<<" ";
        
        if(d[0]==0)
        {
            ans.push_back(1);
            ans.push_back(0);
        }
        else
        {           
            ans.push_back(d[0]);
        }
        
        for (int i=1;i<d.size();i++)
            ans.push_back(d[i]);
        
        return ans;
    }
};