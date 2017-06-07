class Solution {
public:
    //repeat num 要考虑,会有2×3=6，3×2=6这样的情况发生
    int GetUglyNumber_Solution(int index) {
    	if(index<=0)
            return 0;
        vector<int> cur_ugly(index);
        cur_ugly[0]=1;
        int index_multi2=0;
        int index_multi3=0;
        int index_multi5=0;
        
        int i=1;
        while(i<index){
            /*别人这样的代码更好，又精简，又直观

	   res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if (res[i] == res[t2] * 2)t2++;
            if (res[i] == res[t3] * 3)t3++;
            if (res[i] == res[t5] * 5)t5++;
*/
            int num2=cur_ugly[index_multi2]*2;
            int num3=cur_ugly[index_multi3]*3;
            int num5=cur_ugly[index_multi5]*5;
            /*不能这样检验，因为很可能会有++index_multi2数组下标越界的情况发生
            if(num2==num3 || num2==num5){
                num2=cur_ugly[++index_multi2];
            }
            if(num3==num5){
                num3=cur_ugly[++index_multi3];
            }*/
            if(num2<=num3 && num2<=num5){
                if(cur_ugly[i-1]!=num2)  //据此筛选掉重复值
                	cur_ugly[i++]=num2;
                index_multi2++;
            }
            else if(num3<=num2 && num3<=num5){
                if(cur_ugly[i-1]!=num3)
                	cur_ugly[i++]=num3;
                index_multi3++;
            }
            else {
                if(cur_ugly[i-1]!=num5)
                	cur_ugly[i++]=num5;
                index_multi5++;
            }
        }
        return cur_ugly[--i];
    }
};
