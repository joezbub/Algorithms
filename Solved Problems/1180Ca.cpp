#include <bits/stdc++.h>

using namespace std;

int arr[222222];

int main() {
    int N;
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
        if(arr[i]==0) {
            arr[i] = -1;
        }
        else if(arr[i] > 0){
            arr[i] = 0 - (arr[i]) - 1;
        }
    }
    if(N%2 == 1) {
        int maxm = -0x7fffffff;
        int index = 1;
        for(int i=1;i<=N;i++) {
            if(arr[i] > maxm && arr[i] < -1) {
                maxm = arr[i];
                index = i;
            }
        }
        arr[index] = -arr[index] - 1;
    }
    for(int i=1;i<=N;i++) {
        cout << arr[i] << endl;
    }
}