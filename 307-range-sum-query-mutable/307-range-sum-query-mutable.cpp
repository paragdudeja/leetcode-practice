class SegmentTree {
private:
    vector<int> tree;
public:
    void buildTree(vector<int> &nums) {
        int n = nums.size();
        tree.resize(4*n);
        constructST(0, n-1, 0, nums);
    }
    
    int constructST(int ss, int se, int si, vector<int> &nums) {
        if(ss == se) return tree[si] = nums[ss];
        int mid = (ss + se) / 2;
        return tree[si] = constructST(ss, mid, 2 * si + 1, nums)
            + constructST(mid + 1, se, 2 * si + 2, nums);
    }
    
    int getSum(int qs, int qe, int ss, int se, int si) {
        if(se < qs || ss > qe) return 0;
        if(qs <= ss && qe >= se) return tree[si];
        
        int mid = (ss + se) / 2;
        return getSum(qs, qe, ss, mid, 2 * si + 1) + getSum(qs, qe, mid + 1, se, 2 * si + 2); 
    }
    
    void update(int ss, int se, int i, int si, int diff) {
        if(i < ss || i > se) return;
        
        tree[si] += diff;
        if(se != ss) {
            int mid = (ss + se) / 2;
            update(ss, mid, i, 2 * si + 1, diff);
            update(mid + 1, se, i, 2 * si + 2, diff);
        }
    }
    
    /*
    void display() {
        for(int i: tree)
            cout << i << ' ';
        cout << endl;
    }
    */
};

class NumArray {
private:
    SegmentTree st;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.buildTree(nums);
        // st.display();
    }
    
    void update(int index, int val) {
        int old_val = st.getSum(index, index, 0, n - 1, 0);
        // cout << old_val << ": ";
        int diff = val - old_val;
        // cout << diff << endl;
        st.update(0, n-1, index, 0, diff);
    }
    
    int sumRange(int left, int right) {
        return st.getSum(left, right, 0, n - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */