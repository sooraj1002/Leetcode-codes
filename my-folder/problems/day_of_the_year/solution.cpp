class Solution {
public:
    int dayOfYear(string date) {
        int y,m,d;
        vector<int> v={31,28,31,30,31,30,31,31,30,31,30,31};
        int flag=0;
        
        y=((int)date[0]-48)*1000+((int)date[1]-48)*100+((int)date[2]-48)*10+((int)date[3]-48);
        m=((int)date[5]-48)*10+((int)date[6]-48);
        d=((int)date[8]-48)*10+((int)date[9]-48);
            
        int ans=d;
        if(y%400==0)
            flag=1;
        else if (y%4==0 && y%100 != 0)
            flag=1;
        if(flag==1)
            v[1]=29;
        for(int i=0;i<m-1;i++)
            ans=ans+v[i];
        return ans;
    }
};