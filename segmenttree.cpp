#include <iostream>

using namespace std;

class NumArray {
public:

    vector<int> segment_tree;
    int N;

    NumArray(vector<int>& nums);
    void update(int index, int val);
    int sumRange(int left, int right);
};

NumArray::NumArray(vector<int>& original) {
    N = original.size();
    segment_tree.reserve(N*2);

    for (int i =N; i<2*N; i++) {
        segment_tree[i] = original[i-N];
    }
    for (int i = N-1; i>0; i--) {
        segment_tree[i] = segment_tree[2*i] + segment_tree[2*i + 1];
    }


}

void NumArray::update(int idx, int val) {
    idx += N;
    int diff = val - segment_tree[idx];
    if (diff == 0) return;

    while (idx > 0 ){
        segment_tree[idx] += diff;
        idx /= 2;
    }

}

int NumArray::sumRange(int L, int R) {
    L += N; R += N;
    int s = 0;
    while (L<=R) {
        if ((L&1)==1) {
            s += segment_tree[L++];
        }
        if ((R&1)==0) {
            s += segment_tree[R--];
        }
        L /= 2; R /= 2;
    }

    return s;
}



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */:
:
