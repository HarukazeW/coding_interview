class Solution {
public:
    void reOrderArray(vector<int> &array) {
   		vector<int> even_num;
    	int seq_index=0;
     	int odd_index=0;
       	int sz=array.size();
        while(odd_index<sz){
            //++就要记得检查范围
            while(odd_index<sz && !(array[odd_index]&1)){
                even_num.push_back(array[odd_index]);
                odd_index++;
            }
            if(odd_index<sz)
           		array[seq_index++]=array[odd_index++];
        }
        for(auto num:even_num)
          //  if(seq_index<sz)
            	array[seq_index++]=num;
    }   
};
