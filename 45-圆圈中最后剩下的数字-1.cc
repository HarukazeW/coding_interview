class Solution {
public://用list来模拟遍历与删除

    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1)
            return -1;
        //consider input error
        list<int> serial_num;
        for(int i=0;i<n;i++)
            serial_num.push_back(i);
        auto current=serial_num.begin();
        int sz=n;
        while(sz>1){ //should be the size of linked list
            int seq=(m-1)%sz;
            for(int i=0;i<seq;i++) {  //截至到第m个数
                current++;
                if(current==serial_num.end())
                    current=serial_num.begin();
            }
            auto next=++current; 
            if(next==serial_num.end())
                next=serial_num.begin();
           --current;
           serial_num.erase(current);
           sz--;
           current=next;
        }
        return *current;
    }
};
