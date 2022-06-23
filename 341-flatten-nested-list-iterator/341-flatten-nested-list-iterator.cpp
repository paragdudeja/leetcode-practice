/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> flatList;
    int i;
public:
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        vector<int> result;
        for(auto element: nestedList) {
            if(element.isInteger())
                result.push_back(element.getInteger());
            else {
                vector<int> temp = flatten(element.getList());
                for(auto x: temp)
                    result.push_back(x);
            }
        }
        return result;
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatList = flatten(nestedList);
        i = 0;
    }
    
    int next() {
        return flatList[i++];
    }
    
    bool hasNext() {
        return i < flatList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */