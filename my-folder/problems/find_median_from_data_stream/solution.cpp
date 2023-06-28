class MedianFinder {
public:

    priority_queue<int> lower;  //stores first half of array
    priority_queue<int,vector<int>,greater<>> upper;   //stores second half of array
    MedianFinder() {

    }

    void addNum(int num) {
        if(lower.empty() || lower.top()>num )
            lower.push(num);
        else
            upper.push(num);

        if(lower.size()>upper.size()+1){
            upper.push(lower.top());
            lower.pop();
        }
        else if(upper.size()>lower.size()+1){
            lower.push(upper.top());
            upper.pop();
        }
        // cout<<"lets go die"<<endl;
    }
    
    double findMedian() {
        // cout<<"wtf"<<endl;
        // while(!lower.empty()){
        //     cout<<lower.top()<<" ";
        //     lower.pop();
        // }cout<<endl;
        // while(!upper.empty()){
        //     cout<<upper.top()<<" ";
        //     upper.pop();
        // }cout<<endl;
        if(lower.size()==upper.size())
            return double(lower.top()+upper.top())/2;
        else{
            if(lower.size()>upper.size())
                return lower.top();
            else
                return upper.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */