#include <vector>
#include <iostream>
using namespace std;


int main(){
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    int sum1=0,sum2=0,sum3=0;
    for(int i=0; i<n1 ; i++ ){
       cin >> h1[i];
        sum1+=h1[i];
    }
    vector<int> h2(n2);
    for(int i=0 ; i<n2 ; i++ ){
       cin >> h2[i];
       sum2+=h2[i];
	}
    vector<int> h3(n3);
    for(int i=0 ; i<n3 ; i++ ){
       cin >> h3[i];
       sum3+=h3[i];
    }
    
    int flag=0;
    
	while(sum1!=sum2 || sum2!=sum3){
        if(sum1==0 || sum2==0 || sum3==0){
            cout << 0 ; 
            flag++;
			break;
        }else{
            if(sum1>=sum2){
                if(sum1>=sum3){
                    sum1-=h1.front();
                    h1.erase(h1.begin());
                }
                else{
                    sum3-=h3.front();
                    h3.erase(h3.begin());
                }
            }else{
                if(sum2>=sum3){
                    sum2-=h2.front();
                    h2.erase(h2.begin());
                }else{
                    sum3-=h3.front();
                    h3.erase(h3.begin());
                }
            }
        }        
    }
    if(!flag){
    	cout << sum1<< endl; 
	}
    return 0;
}

