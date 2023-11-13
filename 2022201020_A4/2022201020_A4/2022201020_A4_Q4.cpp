#include<iostream>
using namespace std;
int largestparti=0;
int noofpartied=0;
int parentfind(int n1,int *parent){
	if(parent[n1]==n1){
		return n1;
	}
	return parent[n1]=parentfind(parent[n1],parent);
}

void uni(int n1,int n2,int *parent,int *rank,int *size){
	int un1=parentfind(n1,parent);
	int un2=parentfind(n2,parent);
	if(un1==un2){
		return;
	}
	if(rank[un1]<rank[un2]){
		parent[un1]=un2;
		size[un2]=size[un1]+size[un2];
		if(size[un2]>largestparti){
			largestparti=size[un2];
		}
		noofpartied--;
	}
	else if(rank[un1]>rank[un2]){
		parent[un2]=un1;
		size[un1]=size[un1]+size[un2];
		if(size[un1]>largestparti){
			largestparti=size[un1];
		}
		noofpartied--;
	}
	else{
		parent[un2]=un1;
		rank[un1]=rank[un1]+1;
		size[un1]=size[un1]+size[un2];
		if(size[un1]>largestparti){
			largestparti=size[un1];
		}
		noofpartied--;
	}

}
int main(){
	int no_parties;
	int no_aliance;
	cin>>no_parties;
	cin>>no_aliance;
	int *parent;
	largestparti=1;
	noofpartied=no_parties;
	parent = new int [no_parties+1];

	int *rank;
	int *size;
	rank= new int [no_parties+1];
	size= new int [no_parties+1];
	for(int i=0;i<=no_parties;i++){
		parent[i]=i;
		rank[i]=0;
		size[i]=1;
	}
	while(no_aliance--){
		int n1;
		int n2;
		cin>>n1;
		cin>>n2;
		uni(n1,n2,parent,rank,size);
		cout<<noofpartied<<" "<<largestparti<<endl;

	}


}