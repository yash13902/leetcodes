class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        for( ;i < bits.size()-1; i += 1 + bits[i]){
            
        }
        if(i == (bits.size()-1)){
            return true;
        }
        return false;
    }
};