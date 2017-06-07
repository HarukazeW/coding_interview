class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;
        deque<int> max;
        //notice size==0
        if(size==0 || num.size()<size)
            return result;
        //notice,it's also while loop
        int sz=num.size();
        for(int index=0;index<sz;index++) {
            //it's max,max!!!
            while(!max.empty() && num[index]>=num[max.back()])
                max.pop_back();
            if(!max.empty() && index-max.front()>=size)
                max.pop_front();
           	max.push_back(index);
            if(index>=size-1)
                result.push_back(num[max.front()]);
        }
        return result;
    }
};
