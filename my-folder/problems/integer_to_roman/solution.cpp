class Solution {
public:
    string intToRoman(int num) {
        vector<string> ones = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string> tens = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> hundred = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> thousand ={"","M","MM","MMM"};
        

        return thousand[num/1000]+hundred[(num%1000)/100]+tens[(num%100)/10]+ones[num%10];
    }
};