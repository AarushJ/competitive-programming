#include <bits/stdc++.h>

using namespace std;
bool cmp(pair <int,pair<int,int> > p1,pair <int,pair<int,int> > p2){
	if (p1.first>p2.first) return true;
	else if (p1.first==p2.first){
		if (p1.second.first<p2.second.first) return true;
		else return false;
	}
	else return false;
}

int main(){
	int n,c;
	cin>>n>>c;
	vector <int> vec(n);
	map <int,pair<int,int> > mp;
	vector <pair<int,pair<int,int> > > q;
	for (int i=0;i<n;i++){
		cin>>vec[i];
		if (mp.find(vec[i])!=mp.end()) mp[vec[i]].first++;
		else mp.insert(make_pair(vec[i],make_pair(1,0)));
	}
	vector <int> v(n);
	for (int i=0;i<n;i++){
		if (mp[vec[i]].second==0){
			q.push_back(make_pair(mp[vec[i]].first,make_pair(++v[mp[vec[i]].first],vec[i])));
			mp[vec[i]].second=1;
		}
	}
	sort(q.begin(),q.end(),cmp);
	for (int i=0;i<q.size();i++){
		for (int j=0;j<q[i].first;j++){
			cout<<q[i].second.second<<" ";
		}
	}
	cout<<endl;
}