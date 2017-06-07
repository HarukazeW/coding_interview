class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int target_index=numbers.size()/2;
        int beg=0;
        int end=numbers.size()-1;
        int index=partition(numbers,beg,end);
        while(index!=target_index){
            //notice here beg and end 's value should be changed
            if(index<target_index){
                beg=index+1;
                index=partition(numbers,beg,end);
            }
            else{
                end=index-1;
                index=partition(numbers,beg,end);
            }
        }
        int count=0;
        int result=numbers[index];
        for(auto num:numbers)
            if(result==num)
                count++;
        if(count>target_index)
            return result;
        return 0;
    }
    int partition(vector<int> &numbers,int beg,int end){
        if(beg>=end)
            return beg;
        int num=numbers[beg];
        int i=beg,j=end;
        while(i!=j){
            //<=,>=十分重要，不能忽略=
            //注意是j>i,不能写作>=
            while(j>i && numbers[j]>=num)
                j--;
            numbers[i]=numbers[j];
            while(j>i && numbers[i]<=num)
                i++;
            numbers[j]=numbers[i];
        }
        numbers[j]=num;
        return j;
    }
};
