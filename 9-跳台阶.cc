class Solution {
public:
    int jumpFloor(int number) {
        vector<int> jump{1,1};
        for(int i=2;i<=number;i++){
            jump[i&1]=jump[0]+jump[1];
        }
        return jump[number&1];
    
    }
};
