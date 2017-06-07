//此题要掌握multiset的性质和用法，并且知道multiset的构造和具体内部结构
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        multiset<int,greater<int>> leastnum;
        if(k<1 || input.size()<k)
            return vector<int>();
        for(auto num:input){
            if(leastnum.size()<k)
                leastnum.insert(num);
            else {
                auto max_num=leastnum.begin();
                if(num<*max_num){
                    leastnum.erase(max_num);
                    leastnum.insert(num);
                }
            }
        }
        return vector<int>(leastnum.begin(),leastnum.end());
    }
};
