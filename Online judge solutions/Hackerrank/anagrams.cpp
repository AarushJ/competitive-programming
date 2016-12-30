#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >>t ;
    string s;
    
    for(int i=0 ; i<t ; i++){
        cin >> s;
        int count1[26]={0},count2[26]={0};
        int len=s.length();
        if(len%2==0){
            for(int i=0 ; i<len/2 ; i++){
                count1[s[i]-'a']++;
                count2[s[len-1-i]-'a']++;
            }
            int count=0;
            for(int i=0 ; i<26 ; i++){
                if(count1[i]!=count2[i]){
                    count+=abs(count1[i]-count2[i]);
                }
            }
            cout << count/2 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    
    return 0;
}

