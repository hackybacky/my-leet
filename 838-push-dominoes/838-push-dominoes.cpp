class Solution {
public:
    string pushDominoes(string dominoes) {
        
        
        int n = dominoes.size();
        int r = -1;
        int l = -1;
        for(int i = 0 ; i < n ; i++){
            if(dominoes[i] == 'L'){
                if(r == -1){
                    for(int j = l + 1 ; j <= i ; j++)
                        dominoes[j] = 'L';
                }
                else{
                    int len = i - r + 1;
                    // cout << "hello" <<" " << len <<endl;
                    for(int j = r ; j < r + len/2 ; j++){
                        dominoes[j] = 'R';
                    }
                    for(int j = i ; j > i - len /2 ; j--){
                        dominoes[j] = 'L';
                    }
                    if(len % 2 == 1){
                        // cout << "helo" << endl;
                        int mid = (i + r)/2;
                        dominoes[mid] = '.';
                    }
                }
                l = i;
                r = -1;
            }
            else if(dominoes[i] == 'R'){
                if(r != -1){
                    for(int j =r ; j <= i ; j++)
                        dominoes[j] = 'R';
                }
                r = i;
            }
            // cout << dominoes << endl;
        }
        if(r != -1){
            cout << r  << endl;
            for(int j = r; j < n ;j++)
                dominoes[j] = 'R';
        }
        return dominoes;
    }
};