#include<iostream>
#include<algorithm>
using namespace std;

//This is because the number values are 10^12.
typedef long long dataType;
dataType X[2000005], Y[2000005];
//Parameters
dataType S = 25;
dataType SET[] = {30, 25, 20, 15, 10, 5};
int N = sizeof(SET)/sizeof(SET[0]);

void halfSet(dataType A[], dataType X[], int n, int c){
    for(int i = 0; i < (1<<n); i++){
        dataType s = 0;
        for(int j = 0; j < n; j++){
            if(i & (1<<j))
                s += A[j+c];
        }
        X[i] = s;
    }
}

dataType solve(){
    //Divide SET in A & B.
    halfSet(SET, X, N/2, 0);
    halfSet(SET, Y, N-N/2, N/2);

    int sizeX = 1 << (N/2);
    int sizeY = 1 << (N-N/2);
    
    sort(Y, Y+sizeY);
    
    dataType maxSum = 0;

    for(int i = 0; i < sizeX; i++){
        if(X[i] <= S){
            int p = lower_bound(Y, Y+sizeY, S-X[i]) - Y;

            if(p == sizeY || Y[p] != (S-X[i]))
                p--;
            
            if((Y[p] + X[i]) > maxSum)
                maxSum = Y[p] + X[i];
        }
    }
    return maxSum;
}

int main(){
    dataType result = solve();
    cout << "Largest Sum is <= " << S << " is: " << result << endl;
    return 0;
}
