class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int sz=A.size();
    	vector<int> result(sz,1);
		if(A.empty())
            return result;
        //construct left down corner
       	vector<int> temp(sz);
        temp[0]=1;
        result[sz-1]=1;
        for(int i=1;i<sz;i++)
            temp[i]=A[i-1]*temp[i-1];
        for(int i=sz-2;i>=0;i--)
            result[i]=result[i+1]*A[i+1];
        for(int i=0;i<sz;i++)
            result[i]*=temp[i];
        return result;
    }
};
