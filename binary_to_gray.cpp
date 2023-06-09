class Solution {
public:
    //Conversion from binary to gray code
    //Shared below
    vector<int> grayCode(int n) {
        vector<int> result (1<<n);
        iota(result.begin(), result.end(), 0);

        
        for (auto& val: result){
            int prev = 0;
            for (int i =n-1; i>=0; i--){
                int temp = (val>>i)&1;
                val = val^(prev<<i);
                prev= temp;
            }
        }

        return result;
    }
};