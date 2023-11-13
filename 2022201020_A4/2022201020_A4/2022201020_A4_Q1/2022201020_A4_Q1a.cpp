#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void sortlogic(int j,vector<int> &RA,vector<int> &SA){
	int n=RA.size();
	int max1=max(n,256);
	int sum1=0;
	vector<int> CA(max1,0);
	//memset(CA,0,sizeof(CA));
	vector<int> TA(n);
	//cout<<n<<endl;
	for(int i=0;i<n;i++){
		if(i+j<n){
			CA[RA[i+j]]=CA[RA[i+j]]+1;
			
		}
		else{
			CA[0]=CA[0]+1;
			
		}
		
	}
	for(int i=0;i<max1;i++){
		int temp=CA[i];
		CA[i]=sum1;
		
		sum1=sum1+temp;

	}
	for(int i=0;i<n;i++){
       if(SA[i]+j<n){
       	CA[RA[SA[i]+j]]=CA[RA[SA[i]+j]]+1;
       	int x1=CA[RA[SA[i]+j]]-1;
       	TA[x1]=SA[i];
       }
       else{
       	CA[0]=CA[0]+1;
       	int x2=CA[0]-1;
       	TA[x2]=SA[i];
       }
	}
	for(int i=0;i<n;i++){
		SA[i]=TA[i];
		//cout<<SA[i]<<" ";
		
	}
	//cout<<endl;
}
void logic(string str,int slen){
	int n=str.size();
	vector<int> RA(n);
	vector<int> SA(n);
     char cht[n+1];
     strcpy(cht, str.c_str());
	for(int i=0;i<n;i++){
		int tq1=cht[i];
		//cout<<tq1;
		RA[i]=tq1;
		SA[i]=i;
	

	}
	int temp2=0;
	vector<int> TAR(n);
	for(int j=1;j<n;j <<= 1){
		//cout<<j<<endl;
		sortlogic(j,RA,SA);
		sortlogic(0,RA,SA);
		//int temp2=0;
		TAR[SA[0]]=temp2=0;
		for(int i=1;i<n;i++){
			//TAR[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+j] == RA[SA[i-1]+j]) ? temp2 : ++temp2;
			int c1=0;
			if(RA[SA[i]]==RA[SA[i-1]]){
				c1=1;}
			int c2=0;
			if(RA[SA[i]+j]==RA[SA[i-1]+j]){
				c2=1;}
			int c3=c1*c2;
			if(c3==1){
				TAR[SA[i]]=temp2;
			}
			else{
				TAR[SA[i]]=++temp2;
			}

		}
		for(int i=0;i<n;i++){
			RA[i]=TAR[i];
			//cout<<RA[i]<<"  k ";
		}
		//cout<<endl;
		if(RA[SA[n-1]]==n-1){
			break;
		}


	}
	int res1=0;
	for(int i=0;i<n;i++){
		//cout<<cht+SA[i]<<SA[i]<<endl;
		if(SA[i]<slen){
			res1=SA[i];
		//cout<<cht+SA[i]<<endl;
		break;
		}
		

	}
	string str2=str.substr(res1,slen);
	cout<<str2<<endl;

}
int main(){
	string str;
	cin>>str;
	//cout<<str.size()<<endl;
	int slen=str.size();
	str=str+str;
	str=str+"$";
	logic(str,slen);

}
