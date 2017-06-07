class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum<=0)
            return vector<vector<int> >();
        int beg=1,end=2;
        int num=beg+end;
        vector<vector<int>> result;
//出现beg==end
/*
1.num==sum,也即本是两个相邻的数相加等于sum,此时以后的数必然均大于sum
  循环可以终止
2.上一循环是num>sum,也即a1+a2>sum,此后不会再有a3+a4==sum，因为a4>a1,a3>=a2,故循环可以终止
*/
        while(beg<end){
           if(num==sum){
               vector<int> temp;
               temp.reserve(end-beg+1);
               for(int i=beg;i<=end;i++)
                   temp.push_back(i);
               result.push_back(std::move(temp));
               num-=beg;
               beg++;
           }
           else if(num<sum){
               end++;
			   num+=end;
           }
           else {
               num-=beg;
               beg++;
           }
        }
        return result;
    }
};
