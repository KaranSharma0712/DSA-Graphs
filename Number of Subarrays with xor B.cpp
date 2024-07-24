int solve(int* A, int n, int B) {
    map<int,int> mapp;
    int xorr =0;
    int count = 0;
    mapp[xorr]++;
    for(int i=0;i<n;i++){
        xorr = xorr ^ A[i] ;
        int x = xorr ^ B;
        count += mapp[x];
        mapp[x]++;
    }
    return count;
}
