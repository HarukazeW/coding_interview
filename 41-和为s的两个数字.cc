/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
*/
class Solution {
public:
    //乘积最小，即两数的差最大
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
       	int i=0;
        int j=array.size()-1;
        //只用一个while循环即可，每次加以判断
        while(i<j){
            if(array[i]+array[j]>sum)
                j--;
            else if(array[i]+array[j]<sum)
                i++;
            else {
                //应当在循环内完成，这样可以避免内存泄漏
                result.push_back(array[i]);
        		result.push_back(array[j]);
                break;
            }
        }
        return result;
    }
};
