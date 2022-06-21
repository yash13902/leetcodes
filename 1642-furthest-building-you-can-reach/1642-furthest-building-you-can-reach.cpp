class Solution {
public:
    int furthestBuilding(vector<int>& H, int B, int L) {
        int h = H.size()-1;
        priority_queue<int> pq;
        for(int i=0;i<h;i++){
            int d = H[i+1] - H[i];
            if(d > 0){
                if(L){
                    pq.push(-d);
                    L--;
                } else if(!pq.empty() && d > -pq.top()){
                    pq.push(-d);
                    B += pq.top();
                    pq.pop();
                } else{
                    B -= d;
                }
                if(B < 0) return i;
            }
        }
        return h;
    }
};