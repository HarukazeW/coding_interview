class Solution {
public:
    //1<=num<=times,超过一半次数的数字出现次数
//对出现次数为k的数，要使其num!=该数，至少需要k次repeat--,才能使得其对应repeat=0,从而换其他数，也即至少需要k个与它不同的数
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if(numbers.empty())
            return 0;
        int repeat=1;
        int num=numbers[0];
        int sz=numbers.size();
        for(int i=1;i<sz;i++){
            if(numbers[i]==num)
                repeat++;
            else if(repeat>0)
                repeat--;
            else {
                num=numbers[i];
                repeat=1;
        	}
        }
        int count=0;
		for(auto n:numbers){
            if(n==num)
                count++;
        }
        if(count>sz/2)
            return num;
        return 0;
    }
};
