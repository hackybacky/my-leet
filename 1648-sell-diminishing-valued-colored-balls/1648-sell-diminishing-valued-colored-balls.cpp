class Solution {
public:
	long check(vector<int>& inventory, int target) {// count how many orders with buying balls with value at least target
		long sum = 0;
		for(auto& x:inventory) {
			if(x >= target) {
				sum += x - target + 1;
			}
		}
		return sum;
	}
	int maxProfit(vector<int>& inventory, int orders) {
		long low = 1;
		long hi = INT_MAX;
		int kMod = 1e9 + 7;
		while(low < hi) {
			long mid = low + (hi - low+1) /2;
			long res = check(inventory, mid);
			if(res < orders) {
				hi = mid - 1;
			} else {
				low = mid;
			}
		}
		long ans = 0;
		low = low + 1; // buy all balls with this value and above
		for(auto& x:inventory) {
			if(x >= low ) {
				ans += (low + x)*(x-low + 1)/2;
				ans = ans%kMod;
				orders -= x-low+1;
			}
		}
		low = low - 1;
		for(int i=0;i<orders;i++) {
			ans += low;
			ans = ans%kMod;

		}
		return ans;


	}
};