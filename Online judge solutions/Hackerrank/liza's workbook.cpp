#include <iostream>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int problemsInChapter[n];
    for(int i=0 ; i<n ; i++){
        cin >> problemsInChapter[i];
    }
    int startPage=1;
    int special=0;
    for(int i=0 ; i<n ; i++){
        int probNum=1;
		int endPage=((problemsInChapter[i]%k)?startPage+(problemsInChapter[i]/k):startPage+((problemsInChapter[i]/k)-1));
        
		for(int pageNum=startPage ; pageNum<=endPage && probNum<=problemsInChapter[i] ; probNum++){
        	if(probNum==pageNum){
        		special++;
			}
			if(probNum%k==0){
				pageNum++;
			}
		}
		startPage=endPage+1;	
    }
    cout << special;
    return 0;
}
