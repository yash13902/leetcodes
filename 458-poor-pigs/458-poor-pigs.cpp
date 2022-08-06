class Solution {
public:
    int poorPigs(int b, int md, int mt) {
        return ceil(log(b)/log(mt/md + 1));
    }
};