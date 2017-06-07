class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int sz=input.size();
        vector<int> s1;
        //开始没有想到k==0的情况，调试许久找不出错误
        if(k==0 || k>sz)
            return vector<int>();
        int beg=0,end=sz-1;
        int index=partition(input,beg,end);
        while(index!=k-1){
            if(index<k-1){
               	//notice should change beg and end
                beg=index+1;
                //notice it should align to index!!!
                index=partition(input,beg,end);
            }
            else{
                end=index-1;
                index=partition(input,beg,end);
            }
        }
       // vector<int> result;
       vector<int> result(input.begin(),input.begin()+k);
       return result;
    }
    int partition(vector<int> &nums,int beg,int end){
       	if(beg>=end)
            return beg;
        int temp=nums[beg];
        int i=beg,j=end;
        while(i!=j){
            //should be >=
            while(j>i && nums[j]>=temp)
                j--;
            nums[i]=nums[j];
            while(j>i && nums[i]<=temp)
                i++;
            nums[j]=nums[i];
        }
        nums[i]=temp;
        return j;
    }
};
