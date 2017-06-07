class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int maxnum=INT_MIN;
        int number=0;
        for(auto num:array){
            number+=num;
            //两个if 的先后关系很重要
            if(number>maxnum)
                maxnum=number;
  			if(number<0)
                number=0;
        }
        return maxnum;
    }
};
