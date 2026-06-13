class Solution {
public:
    int f(vector<int>& piles, int h, int speed){
        long long hours = 0;
        for(int pile : piles){
            hours += (pile + speed - 1) / speed;
        }    
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // min speed 1, max speed max number of banana
        int s = 1;
        int e = piles[0];

        for(int pile : piles){
            e = max(e , pile);
        }

        int ans = 0;
        while(s <= e){
            int m = s + (e - s) / 2;

            if(f(piles, h, m)){
                ans = m ; 
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ans;
    }
};
