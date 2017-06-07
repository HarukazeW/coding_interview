class Solution {
public:
    vector<string> Permutation(string str) {
        //char 可能会有重复
        vector<string> result;
        //notice empty str
        if(str.empty())
            return result;
        recur_permutation(result,str,0,str.size());
        sort(result.begin(),result.end());
        return result;
    }
    void recur_permutation(vector<string> &result,string &str,size_t cur_index,size_t size){
        if(cur_index==size){
            result.push_back(str);
            return;
        }
        for(int i=cur_index;i<size;i++){
            if(i!=cur_index && str[i]==str[cur_index])
                continue;
            char c=str[cur_index];
            str[cur_index]=str[i];
            str[i]=c;
            recur_permutation(result,str,cur_index+1,size);
            str[i]=str[cur_index];
            str[cur_index]=c;
        }
    }
};
