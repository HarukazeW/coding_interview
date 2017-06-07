//依次判断当前数组是否可划分为一半比末尾数字小，一半比末尾数字大，再依次递归，直到只有0个或1个数字
//注意题中默认认为空vector为false
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
		return recur_verify(sequence,0,sequence.size()-1);
    }
    bool recur_verify(vector<int> &sequence,int beg,int end){
        if(beg>=end)
            return true;
        int lend,rbeg;
        int i=0;
        int root_val=sequence[end];
        for(;i<end && sequence[i]<root_val;i++)
            ;
        lend=i-1;
        rbeg=i++;
       	while(i<end){
            if(sequence[i]<root_val)
                return false;
            i++;
        }
        return recur_verify(sequence,beg,lend) && \
            recur_verify(sequence,rbeg,end-1);
    }
};
