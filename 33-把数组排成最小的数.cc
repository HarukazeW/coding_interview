//注意compare_combi must be static function
class Solution {
public:
    static bool compare_combi(const string &first,const string &last){
        string s1=first+last;
        string s2=last+first;
        if(s1<s2)
            return true;
        return false;
    }
    string PrintMinNumber(vector<int> numbers) {
        vector<string> nums_str;
        string result;
        for(auto num:numbers){
           nums_str.push_back(to_string(num));
        }
        //compare_combi即可，不可写成compare_combi()
        std::sort(nums_str.begin(),nums_str.end(),compare_combi);
        for(auto s:nums_str){
            result+=s;
        }
        return result;
    }

};	
