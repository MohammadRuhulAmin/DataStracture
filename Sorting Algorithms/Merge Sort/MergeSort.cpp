#include<bits/stdc++.h>
using namespace std;
void conqure(vector<int>&vec,int s,int mid,int e){
	vector<int>marged(e-s+1);
	int idx1 = s;
	int idx2 = mid+1;
	int mIndex = 0;
	while(idx1<=mid && idx2<=e){
		if(vec[idx1]<=vec[idx2])marged[mIndex++] = vec[idx1++];
		else marged[mIndex++] = vec[idx2++];
	}
	while(idx1<=mid)marged[mIndex++] = vec[idx1++];
	while(idx2<=e)marged[mIndex++] = vec[idx2++];
	for(int i = 0;i!=mIndex;i++){
		vec[s+i] = marged[i];
	}
	
}

void divide(vector<int>&vec,int s,int e){
	if(s >= e)return;
	else{
		int mid = s+(e-s)/2;
		divide(vec,s,mid);
		divide(vec,mid+1,e);
		conqure(vec,s,mid,e);
	}
}

int main(){
	vector<int>vec = {1,5,3,2,4,2};
	for(const auto&ite:vec){
		cout << ite <<" ";
	}
	cout << endl;
	int length = vec.size();
	divide(vec,0,length-1);
	cout << endl;
	for(const auto&ite:vec){
		cout << ite <<" ";
	}
	
	
	return 0;
}