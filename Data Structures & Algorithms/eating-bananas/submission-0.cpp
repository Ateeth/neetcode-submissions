class Solution {
public:
    int f(vector<int>& piles, int h, int speed){
        long long hours = 0;
        for(int i = 0 ; i < piles.size() ; ++i){
            hours += (piles[i] + speed - 1) / speed;
        }

        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // min speed 1, max speed max number of banana
        int n = piles.size();
        int s = 1;
        int e = INT_MIN;
        for(int pile: piles ){
            e = max(e, pile);
        }
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(f(piles, h, mid)){
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
