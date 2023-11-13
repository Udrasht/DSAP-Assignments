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
    void kssai(vector<int> &prefix,vector<int> &SA,string str,int kc){
    	int nen=SA.size();
    	//cout<<"hello"<<endl;
    	vector<int> support(nen);
    	int i=0;
    	//support[SA[i]]=-1;
    	//i=i+1;
    	char cht1[nen+1];
         strcpy(cht1, str.c_str());
     
    	while(i<nen){
    		int j=SA[i];
    		int k=i-1;
    		support[j]=i;
          i=i+1;
    	}
     
    	int match=0;
    	for(int l=0;l<nen;l++){
                  match=max(0,match-1);
    			  int utility=support[l]+kc-1;
                  if(utility>nen-1){
                  	match=0;
     
                  	continue;
                  }
                  else{
    				  int utility2=support[l]+kc-1;
                  	int x=SA[utility2];
                  	while((l+match<nen)&&(x+match<nen)&&(cht1[l+match]==cht1[x+match])){
                  		match=match+1;
                  	}
                  	prefix[support[l]]=match;
     
                  }
    	}
    }
    void logic(string str,int kc){
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
    	for(int j=1;j<n;j=j*2){
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
    	vector<int> prefix(n);
    	kssai(prefix,SA,str,kc);
    	//vector<int> resprefix(n);
    	prefix[0]=0;
    	for(int i=n-1;i>0;i--){
    		prefix[i]=prefix[i-1];
    	}
           //  int l23=0;
           //  int max=0;
            // int to=1;
            // int k34=2;
    	/*for(int i=0;i<n;i++){
    		cout<<SA[i]<<" ";
    		cout<<cht+SA[i]<<" "<<prefix[i]<<endl;*/
              // if(prefix[i-1]==prefix[i]or){
              // 	to=to+1;
              // 	l23=prefix[i-1];
              // }
              // else{
              // 	if(to>=k34&&max<l23){
              // 		max=l23;
              // 		l23=0;
              // 		to=1;
              // 	}
              // }
    	
    	int ansmax=0;
    	//int anscount=1;
       //int	maxans=0;
       //int kc=3;
    	for(int i=0;i<n;i++){
    		
          if(prefix[i]>ansmax){
    		  ansmax=prefix[i];
    	  }
    	}
    	cout<<ansmax<<endl;
    	
     
    }
    int main() {
    	string str;
    	cin>>str;
    	int kc;
    	cin>>kc;
    	int leto=str.size();
    	
    	str=str+"$";
    	if(kc!=1)
    	logic(str,kc);
    	else{
    		cout<<leto<<endl;
    	}
    }