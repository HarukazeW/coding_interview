//奇数间，偶数间相对位置变化
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int i=0,j=array.size()-1;
        while(i<j){
            while(i<j &&array[i]&1)
                i++;
            while(i<j && !(array[j]&1))
                j--;
            if(i<j){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
                i++,j--;
            }
        }
    }
};
