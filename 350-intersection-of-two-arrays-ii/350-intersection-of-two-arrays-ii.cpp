class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        map<int, int> num1;
        // map<int, int> num2;
        vector<int> num;
        
        // for(auto it : nums1){
        //     if(!num1.empty() && num1.find(it) != num1.end()){
        //         num1.at(it) += 1;
        //     }else{
        //         num1.insert({it, 1});
        //     }   
        // }
        // for(auto it : nums2){
        //     if(!num2.empty() && num2.find(it) != num2.end()){
        //         num2.at(it) += 1;
        //     }else{
        //         num2.insert({it, 1});
        //     }   
        // }
        // for(auto it = num1.begin(); it != num1.end(); it++){
        //     if(num2.find(it->first) != num2.end()){
        //         for(int i = 0; i < min(it->second, (num2.find(it->first))->second); i++){
        //             num.push_back(it->first);
        //         }
        //     }
        // }
        
        for(auto it : nums1){
            num1[it]++;
        }
        for(auto it : nums2){
            if(num1[it]-- > 0){
                num.push_back(it);
            }
        }
        return num;
    }
};