class Solution {
public:
    bool isPalindrome(int x) {
        int flag=0;
        int temp=x,rev=0;
        if(x<0 || (x !=0 && x%10 ==0))
        {   
            return false;
        }
            
        while(x>rev)
        {
            rev=rev*10+x%10;
            x=x/10;
        } 
        
        return rev==x||x==rev/10;
        
    }
};