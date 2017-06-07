
class Solution {
public:
    int StrToInt(string str) {
        int result=0;
        int sign=1;
        int i=0;
        int sz=str.size();
        while(i<sz && (str[i]==' ' || str[i]=='\t'))
            i++;
        if(i<sz && str[i]=='+')
            i++;
        else if(i<sz && str[i]=='-'){
            sign=-1;
            i++;
        }
        while(i<sz && isdigit(str[i])){
            result=result*10+(str[i]-'0');
            i++;
        }
	//因题目说若字符串不是一个不合法数字，则返回0
        if(i<sz)
            return 0;
        return result*sign;
    }
};
