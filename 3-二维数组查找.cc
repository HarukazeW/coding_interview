class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        //注意区分行列
        int row=0,rowsz=array.size()-1;
        int col=array[0].size()-1;
        while(row<=rowsz && col>=0){
            if(array[row][col]<target){
                row++;
            }
            else if(array[row][col]==target)
                return true;
            else
                col--;
        }
        return false;
    }
};
