class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int result=0;//要初始化，慎重之
        for(auto num:data)
            result^=num;
        if(result==0){
            num1=NULL;
            num2=NULL;
            return;//error,no two number occur only once
        }
        int bit=1;
        while(!(bit&result))
            bit<<=1;
        *num1=0;
        *num2=0;
       	for(auto num:data){
            if((num&bit)==0)
                *num1^=num;
            else
                *num2^=num;
        }
    }
};
