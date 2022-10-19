class Solution {
public:
    int add(int num){
        int sum=0;
        while(num !=0)
        {
            sum=sum+num%10;
            num=num/10;
        }
        return sum;
    }
    int addDigits(int num) {
        int sum= num;
        while(sum>9)
        {
            sum=add(sum);
        }
        return sum;
    }
};