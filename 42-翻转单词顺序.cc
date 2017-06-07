class Solution {
public:
    string ReverseSentence(string str) {
        string result(str.size(),'0');
        int index=0;
        int end=str.size()-1;
        int beg=end;
        while(beg>=0){
			if(str[beg]==' '){
                int i=beg+1;
                for(;i<=end;i++)
                    result[index++]=str[i];
                result[index++]=str[beg];
                beg--;
                end=beg; //notice
            }
            else if(beg==0){
                for(int i=beg;i<=end;i++)
                    result[index++]=str[i];
                beg--;	//勿忘
            }
            else
                beg--;
        }
        return result;
    }
};
