class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
       	if(data.empty())
            return 0;
        //以-1标志没找到
        int beg=find_beg(data,k);
        if(beg==-1)
            return 0;
        int end=find_end(data,k);
        return end-beg+1;
    }
    int find_beg(vector<int> &data,int k){
        int beg=0;
        int end=data.size()-1;
        while(beg<=end){
            int middle=beg+(end-beg)/2;
            if(data[middle]==k && ((middle==0) || (data[middle-1]!=k)))
                return middle;
            else if(data[middle]<k) 
                beg=middle+1;
            else
                end=middle-1;
        }
        return -1;//not find
    }
    int find_end(vector<int> &data,int k){
        int beg=0;
        int end=data.size()-1;
        while(beg<=end){
            int middle=beg+(end-beg)/2;
            if(data[middle]==k && ((middle==data.size()-1) || data[middle+1]!=k))
                return middle;
            else if(data[middle]>k)
               end=middle-1;
            else  //careful when data[middle]==k but data[middle+1]!=k
               beg=middle+1;
        }
        return -1;
    }
};
