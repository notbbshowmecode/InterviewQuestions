class Solution {
public:
    int jumpFloorII(int number) {
		return 1 << (number-1);  //n级台阶里，除了最后一级台阶必须要跳，其余台阶都存在跳与不跳两种情况，所以共有2^(n-1)种跳法
    }
};