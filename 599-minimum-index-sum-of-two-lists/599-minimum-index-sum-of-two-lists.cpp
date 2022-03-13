class Solution {
public:
    // typedef pair<string, int> MyPairType;
    // struct CompareSecond
    // {
    //     bool operator()(const MyPairType& left, const MyPairType& right) const
    //     {
    //         return left.second < right.second;
    //     }
    // };
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> common;
        vector<string> vec;
        int min = INT_MAX;
        // for(int i = 0; i < list1.size(); i++){
        //     for(int j = 0; j < list2.size(); j++){
        //         if(list1[i] == list2[j]){
        //             common[list1[i]] = i+j;
        //         }
        //     }
        // }
        // pair<string, int> min = *min_element(common.begin(), common.end(), CompareSecond());
        // int i = min.second;
        // for(auto it : common){
        //     if(it.second == i){
        //         vec.push_back(it.first);
        //     }
        // }
        // return vec;
        int i;
        for(i = 0; i < list1.size(); i++) common[list1[i]] = i;
        for(i = 0; i < list2.size(); i++){
            if(common.count(list2[i]) != 0){
                if(common[list2[i]] + i < min){
                    vec.clear();
                    vec.push_back(list2[i]);
                    min = common[list2[i]] + i;
                } else if(common[list2[i]] + i == min){
                    vec.push_back(list2[i]);
                }
            }
        }
        return vec;
    }
};