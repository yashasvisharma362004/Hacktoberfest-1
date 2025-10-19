#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std;
char firstNonRepeating(string s){
    vector<int> freq(256,0);
    for(char c:s) freq[c]++;
    for(char c:s) if(freq[c]==1) return c;
    return '#';
}
int main(){cout<<firstNonRepeating("swiss");}