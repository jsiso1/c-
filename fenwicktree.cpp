class NumArray {
public:
    vector<int> original;
    vector<int> fenwick;

    NumArray(vector<int>&);
    
    void update(int, int);
    int sumRange(int, int);

private:
    void setup();
    int sum(int);
};

NumArray::NumArray(vector<int>& v) {
    original = v;

    int L = v.size();
    while ((L& (L-1)) > 0) {
        L += L& (-L);
    }

    fenwick.push_back(0);
    for (int i = 0; i<v.size(); i++) {
        fenwick.push_back(v[i]);
    }
    for (int i = v.size(); i<(L+1); i++){
        fenwick.push_back(0);
    }
    setup();
}

void NumArray::setup() { 
    for (int i = 1 ; (i + (i & (-i))) <fenwick.size(); i++) {
        int next_val = (i + (i & (-i)));
        fenwick[next_val] += fenwick[i]; 
    }
}

void NumArray::update(int idx, int val) {
    int diff = val - original[idx];
    if (diff == 0) return;
    original[idx] = val;
    
    
    idx ++;
    while (idx < fenwick.size()) {
        fenwick[idx] += diff;
        idx += idx& (-idx);
    }

    return;

}

int NumArray::sum(int range) {
    int sum = 0;
    while (range > 0) {
        sum += fenwick[range];
        range = range & (range - 1);
    }
    return sum;
}

int NumArray::sumRange(int L, int R) {
    return sum(R+1) - sum(L); 
}




/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
