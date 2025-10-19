#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rearrange(long long arr[], int n){
    int maxIdx = n-1, minIdx = 0;
    long long maxElem = arr[n-1]+1;
    for(int i=0;i<n;i++){
        if(i%2==0) arr[i]+=(arr[maxIdx--]%maxElem)*maxElem;
        else arr[i]+=(arr[minIdx++]%maxElem)*maxElem;
    }
    for(int i=0;i<n;i++) arr[i]/=maxElem;
}