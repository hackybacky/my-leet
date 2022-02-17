class Solution {
public:
    int flipLights(int n, int presses) {
        n=min(n,3);
        return min(1<<n ,1+presses*n);
    }
};