class Solution {
    priority_queue<int,vector<int>,less<int> > maxq;
    priority_queue<int,vector<int>,greater<int> > minq;
    bool even=true;
public:
    void Insert(int num)
    {
        if(even)
            if(maxq.empty() || num>maxq.top())
                minq.push(num);
            else {
                maxq.push(num);
                minq.push(maxq.top());
                maxq.pop();
            }
        else
            if(minq.empty() || num<minq.top())
                maxq.push(num);
            else {
                minq.push(num);
                maxq.push(minq.top());
                minq.pop();
            }
        even=!even;
    }

    double GetMedian()
    { 
        return even?((minq.top()+maxq.top())/2.0):minq.top();
    }

};
