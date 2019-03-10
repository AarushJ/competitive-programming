include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<string, ll> &a, pair<string, ll> &b){
	return a.first.length() < b.first.length();
}

int main(){
	ll n;
	
	cin >> n;
	vector<pair<string, ll> > corpus(2*n - 2);
	for(ll i = 0 ; i < 2*n - 2 ; i++){
		cin >> corpus[i].first;
		corpus[i].second = i;
	}	

	sort(corpus.begin(), corpus.end(), cmp);

	ll actual_index_from_sorted_index[2*n - 2];

	for(ll i = 0 ; i < 2*n - 2 ; i++)	actual_index_from_sorted_index[i] = corpus[i].second;

	vector<char> ans1(2*n - 2), ans2(2*n - 2);

	// length 1 -> 0, 1
	// length 2 -> 2, 3
	// length x -> 2*(x-1), 2*(x-1) + 1 => 2*x - 2, 2*x - 1
	
	string suffix1 = corpus[2*n - 3].first;
	set<ll> suffix_indices1;

	/*
		Find if possible suffixes competent with this suffix exist
		Make string using one letter prefix and string
		Make all the remaining strings prefixes of length 2 or more. see if the prefixes are valid
	*/

	suffix_indices1.insert(2*n - 3);
	
	bool flag = true;
	
	ll len = n-2;
	for(ll i = 2*n - 5 ; i > 0 ; i -= 2, len--){
		// comparison loop
		if( corpus[i].first == corpus[i-1].first ){
			string temp = corpus[i].first;
			if( suffix1.compare(n-len-1, len, temp) == 0 ){
	//			cout << "corpus[" << i << "]: " << corpus[i].first << "  matches\n";
				suffix_indices1.insert(i);
			}else{
				flag = false;
				break;
			}
		}else{
			string temp1 = corpus[i].first;
			string temp2 = corpus[i-1].first;
			if( suffix1.compare(n-len-1, len, temp1) == 0){
				suffix_indices1.insert(i);
			}else if( suffix1.compare(n-len-1, len, temp2) == 0){
				suffix_indices1.insert(i-1);
			}else{
				flag = false;
				break;
			}
		}
	}

	if( flag ){
		string first = (suffix_indices1.count(0) == 1)? (corpus[1].first):(corpus[0].first);
		string str = first + suffix1;
		ll len = 2;
		
		for(ll i = 2 ; i < 2*n - 2 && i+1 < 2*n - 2; i+=2, len++){
			string curr_prefix = (suffix_indices1.count(i) == 1)? (corpus[i+1].first):(corpus[i].first);
			if( str.compare(0, len, curr_prefix) != 0 ){
				flag = false;
				break;
			}
		}	

		if( flag ){
			for(ll i = 0 ; i < 2*n - 2 ; i++){
				if( suffix_indices1.count(i) ){
					ans1[actual_index_from_sorted_index[i]] = 'S';
				}else{
					ans1[actual_index_from_sorted_index[i]] = 'P';
				}
			}
			for(ll i = 0 ; i < 2*n - 2; i++)	cout << ans1[i];
			cout << "\n";
			return 0;
		}	

	}

	string suffix2 = corpus[2*n - 4].first;
	set<ll> suffix_indices2;
	suffix_indices2.insert(2*n - 4);
	len = n - 2;
	
	for(ll i = 2*n - 5 ; i > 0 ; i-=2, len--){
		if( suffix2.compare(n-len-1, len, corpus[i].first) == 0){
			suffix_indices2.insert(i);
		}else{
			suffix_indices2.insert(i-1);
		}
	}

	for(ll i = 0 ; i < 2*n - 2; i++){
		if( suffix_indices2.count(i) == 1 ){
			ans2[actual_index_from_sorted_index[i]] = 'S';
		}else{
			ans2[actual_index_from_sorted_index[i]] = 'P';
		}
	}


	//cout << "reached here5\n";
	for(ll i = 0 ; i < 2*n - 2; i++)	cout << ans2[i];
	cout << "\n";

}