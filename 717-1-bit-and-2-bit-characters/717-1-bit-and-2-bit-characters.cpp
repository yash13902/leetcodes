class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while(i < bits.size()-1){
            if(bits.at(i) == 1){
                i = i+2;
            } else if(bits.at(i) == 0){
                i++;
            }
        }
        if(i == (bits.size()-1)){
            return true;
        }
        return false;
    }
};