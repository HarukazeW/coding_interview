class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result;
        if(matrix.empty() || matrix[0].empty())
            return result;
        recur_print(matrix,result,0,matrix.size()-1,0,matrix[0].size()-1);
        return result;
    }
    //notice 只有一行一列的情况
    //而且应该是matrix[][],不要忘
    void recur_print(vector<vector<int>> &matrix,vector<int> &result,int rowb,int rowe,int colb,int cole){
        if(rowb>rowe || colb>cole)
            return;
        if(rowb==rowe){
            for(int i=colb;i<=cole;i++)
                result.push_back(matrix[rowb][i]);
            return;
        }
        if(colb==cole){
            for(int i=rowb;i<=rowe;i++)
                result.push_back(matrix[i][colb]);
            return; 
        }
        for(int i=colb;i<=cole;i++)
            result.push_back(matrix[rowb][i]);
        for(int i=rowb+1;i<=rowe;i++)
            result.push_back(matrix[i][cole]);
        for(int i=cole-1;i>=colb;i--)
            result.push_back(matrix[rowe][i]);
        for(int i=rowe-1;i>=rowb+1;i--)
            result.push_back(matrix[i][colb]);
        recur_print(matrix,result,rowb+1,rowe-1,colb+1,cole-1);
    }
};
