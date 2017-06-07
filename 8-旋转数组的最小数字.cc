//数组可划分为big-small两大部分，两部分中数组均非递减排序，
//当中间数大于small最大数时，其必定属于big组，故继续比较middle+1---end
//当中间数小于small最大数时，其可能是small最小数或是small中的数，故下一步比较beg---mid
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int sz=rotateArray.size();
        if(sz==0)
            return 0;
        int result=recur_find(rotateArray,0,sz-1);
        return result;
    }
    int recur_find(vector<int> &arr,int beg,int end){
        while(beg<end){
            int mid=beg+(end-beg)/2;
            if(arr[mid]>arr[end]){
                beg=mid+1;
            }
            else{
                end=mid;
            }
        }
        return arr[beg];
    }
};

