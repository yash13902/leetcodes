class MyCalendar {
public:
    vector<vector<int>> ans;
    MyCalendar() {
        ans = {};
    }
    
    bool book(int start, int end) {
        for(int i=0;i<ans.size();i++){
            if(max(start, ans[i][0]) < min(end, ans[i][1])) return false;
        }
        ans.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */