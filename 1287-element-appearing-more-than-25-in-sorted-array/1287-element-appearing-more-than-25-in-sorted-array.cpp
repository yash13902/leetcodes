class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        vector<int>::iterator p = arr.begin();
        vector<int>::iterator it = arr.begin()+1;
        int l = arr.size();
        int sum = 1;
        if(arr.size() == 1 || arr.size() == 2){
            return *p;
        }
        while(it < arr.end()){
            while(it != arr.end() && *p == *it ){
                sum++;
                it++;
            }
            if((double)sum/l > 0.25){
                return *p;
            }
            p = it;
            it++;
            sum = 1;
        }
        return -1;
    }
};