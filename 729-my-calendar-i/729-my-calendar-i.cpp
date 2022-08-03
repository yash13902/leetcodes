// class MyCalendar {
// public:
//     vector<vector<int>> ans;
//     MyCalendar() {
//         ans = {};
//     }
    
//     bool book(int start, int end) {
//         for(int i=0;i<ans.size();i++){
//             if(max(start, ans[i][0]) < min(end, ans[i][1])) return false;
//         }
//         ans.push_back({start,end});
//         return true;
        
        
        
//     }
// };

// /**
//  * Your MyCalendar object will be instantiated and called as such:
//  * MyCalendar* obj = new MyCalendar();
//  * bool param_1 = obj->book(start,end);
//  */

class MyCalendar {
    set<pair<int, int>> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound({s, e}); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
        if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
        books.insert({ s, e });
        return true;
    }
};