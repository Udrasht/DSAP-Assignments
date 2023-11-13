#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
class Paltrie{
	
	class Trie{
   public:
	char data;
	
	bool endornot;
	Trie* node[26];
	int count;
	
    Trie(char c){
	count=0;
	data=c;
	endornot=false;
	int i=0;
	while(i<26){
		node[i]=NULL;
		i=i+1;
	}
	

}

};
public:
	int ans;
Trie* root;

Paltrie(){

	root=new Trie('#');
	ans=0;

	
}
void insert(Trie* temp, string str){
	int n=str.length();
	if(n==0){
		//cout<<str[0]<<endl;
		temp->endornot=true;
		return;
	}
   // cout<<str<<endl;
	Trie* childnode;


	int i;
	if(str[0]>='A'&&str[0]<='Z'){
		i=str[0]-'A';
	}
	else{
		i=str[0]-'a';
	}
	if(temp->node[i]!=NULL){
		childnode=temp->node[i];
	}
	else{
		temp->count=temp->count+1;
		char crt=str[0];
		childnode=new Trie(crt);
		temp->node[i]=childnode;

	}
	insert(childnode,str.substr(1));
}
void strinsert(string str){
	insert(root,str);
}

int spellcheck(Trie* temp,string querystring){
	int n=querystring.size();
	int i=0;
	int p=0;
	while(temp){
		if(querystring[i]>='A'&&querystring[i]<='Z'){
			if(temp->node[querystring[i]-'A']!=NULL){
			
			if(temp->node[querystring[i]-'A']->endornot==true&&i+1==n){
				p=1;
				break;
			}
			temp=temp->node[querystring[i]-'A'];
			i=i+1;
			if(p==1){
				break;
			}
		}
		else{
			break;
		}
		}
		else{if(temp->node[querystring[i]-'a']!=NULL){
			
			if(temp->node[querystring[i]-'a']->endornot==true&&i+1==n){
				p=1;
				break;
			}
			temp=temp->node[querystring[i]-'a'];
			i=i+1;
			if(p==1){
				break;
			}
		}
		else{
			break;
		}

	}}
if(p==1){
	return 1;
}
else{
	return 0;
}
}
void segessetion(Trie* temp,vector<string> &outputarray,string str){
	if(temp==NULL){
		outputarray.push_back(str);
		return;
	}
	str=str+temp->data;

  if(temp->endornot==true){
  
  	outputarray.push_back(str);
  
  }
    

   
  for(int k=0;k<26;k++){
  	if(temp->node[k]!=NULL){
  		segessetion(temp->node[k],outputarray,str);

  	}
  }

}
void autocompleat(Trie* temp,string querystring,vector<string> &outputarray){
	int i=0;
    int ct=0;
    string str="";
    
while(i<querystring.size()&&temp!=NULL){

     int j;
	if(querystring[i]>='A'&&querystring[i]<='Z'){
		j=querystring[i]-'A';
	}
	else{
		j=querystring[i]-'a';
	}
	if(temp->node[j]!=NULL){
		if(i!=querystring.size()-1){
            str=str+querystring[i];}
        temp=temp->node[j];
            
            ct++;
	}

	else{
		break;
	}
	i++;

}

if(ct==querystring.size()){
	int j;
	if(querystring[i]>='A'&&querystring[i]<='Z'){
		j=querystring[i]-'A';
	}
	else{
		j=querystring[i]-'a';
	}
	
	segessetion(temp,outputarray,str);
}


	
}

void autosuggest(Trie* temp,int *v,string uncorrectstring,string suggested,vector<string> &suggestedarr){
	
	int n=uncorrectstring.size();
	int *v2;
    v2=new int[n+1];
     v2[0]=v[0]+1;
     int mini=n+1;
      //cout<<v2[0];
    for(int i=1;i<n+1;i++){
    	char tc=temp->data;
    	if(temp->data>='A'&&temp->data<='Z'){
    		tc=temp->data+32;
    	}
    	char td=uncorrectstring[i-1];
    	if(td>='A'&&td<='Z'){
    		td=td+32;
    	}
    	if(td==tc){
    		v2[i]=v[i-1];
    	}
    	else{
    		v2[i]=min(v2[i-1],min(v[i-1],v[i]))+1;
    	}
    	if(v2[i]<mini){
    		mini=v2[i];
    	}
    	//cout<<v2[i]<<" ";

    }
    //cout<<endl;
    suggested=suggested+temp->data;
    if(temp->endornot==true&&v2[n]<=3){
         suggestedarr.push_back(suggested);
         return;
    }
    else if(temp->endornot==true){
    	return ;
    }
    else if(mini>3){
    	//cout<<suggested<<endl;
    	return ;

    }
    else{
    	for(int i=0;i<26;i++){
	if(temp->node[i]!=NULL){
		
autosuggest(temp->node[i],v2,uncorrectstring,suggested,suggestedarr);
}
}

    }


}

void autocorrect(Trie* temp,string uncorrectstring,int r){

int n=uncorrectstring.size();
int *v;
v=new int[n+1];
for(int i=0;i<n+1;i++){
	v[i]=i;
   //cout<<v[i]<<" ";
}
//cout<<endl;
vector<string> suggestedarr;

if(temp!=NULL){

for(int i=0;i<26;i++){
	if(temp->node[i]!=NULL){
		
		string suggested="";
		//cout<<temp->node[i]->data<<endl;
autosuggest(temp->node[i],v,uncorrectstring,suggested,suggestedarr);}
}}
int sasize=suggestedarr.size();
cout<<sasize<<endl;
for(int i=0;i<sasize;i++){
	cout<<suggestedarr[i]<<endl;
}
delete[] v;
}

};





int main(){
	int r;
cin>>r;
int c;
cin>>c;
string arr[r];
Paltrie s1;
for(int i=0;i<r;i++){
	cin>>arr[i];
	s1.strinsert(arr[i]);
}

for(int i=0;i<c;i++){
	int query;
	cin>>query;
	string querystring;
	cin>>querystring;
	if(query==1){
		int ans=s1.spellcheck(s1.root,querystring);
		cout<<ans<<endl;
	}
	else if(query==2){
		vector<string> outputarray;

		s1.autocompleat(s1.root,querystring,outputarray);
		if(outputarray.size()==0){
			cout<<0<<endl;
		}
		else{
			cout<<outputarray.size()<<endl;
			for(int k=0;k<outputarray.size();k++){
				cout<<outputarray[k]<<endl;
			}
		}
	}
	else if(query==3){
		//string uncorrectstring;
		//cin>>uncorrectstring;
		
		s1.autocorrect(s1.root,querystring,r);
	}
}

}