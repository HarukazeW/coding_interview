//一只青蛙想跳上n个台阶，它可以选择跳n-1个台阶再跳上，或是可以对于每个跳n-1台阶的方案中，它在最后一次跳时多跳一个台阶，便跳上n个台阶了
class Solution {
public:
    int jumpFloorII(int number) {
        return number<2?1:1<<(number-1);
    }
};
