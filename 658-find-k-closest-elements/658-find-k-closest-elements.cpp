class Solution {
public:
    // struct myComp{
    // bool operator()(int x1, int x2){
    //         return abs(x1) == abs(x2)? x1 > x2: abs(x1)>abs(x2);
    //     }
    // };
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
    }
};