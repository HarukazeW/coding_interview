class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty())
            return 0;
        vector<int> copy;
        for(auto i:data){
            copy.push_back(i);
        }
        return (recur_find(data,copy,0,data.size()-1)%1000000007);
    }
    
    long long  recur_find(vector<int> &data,vector<int> &copy,int index,int maxindex){
        if(index==maxindex){
            copy[index]=data[index];
            return 0;
        }
        long long count=0;
        int middle=index+(maxindex-index)/2;
        count+=recur_find(copy,data,index,middle);
        count+=recur_find(copy,data,middle+1,maxindex);
        //此时data中存储的才是left和right分别有序的数据
		
        int lend=middle,rend=maxindex;
        int copy_index=maxindex;
        while(lend>=index && rend>middle){
            while(rend>middle && data[lend]<=data[rend]){
		//将data误写作copy,排查好久，以后一定要小心再小心
                copy[copy_index--]=data[rend--];
            }
            copy[copy_index--]=data[lend--];
            count+=rend-middle;
        }
       	while(lend>=index){
            copy[copy_index--]=data[lend--];
        }
        while(rend>middle){
            copy[copy_index--]=data[rend--];
        }
        return count;
    }
    
};
