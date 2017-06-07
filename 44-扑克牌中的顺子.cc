class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
      	std::sort(numbers.begin(),numbers.end());
        const int num=5;
        if(numbers.size()!=num || numbers[0]<0)
            return false;
        int i=0;
        for(;i<num && numbers[i]==0;i++)
            ;
        int j=i; 
        int last_num=numbers[j]; //first value which not 0
        for(int index=j+1;i>=0 && index<num;index++){
           	int diff=numbers[index]-last_num;
            last_num=numbers[index];
            if(diff==0)
                return false;
            if(diff==1)
                continue;
           i-=diff-1;
        }
        //以count作为区分标准而不可以index作为区分
        return i<0?false:true;
    }
};
