#include<iostream>
using namespace std;

class Paltrie{
	
	class Trie{
   public:
	char data;
	
	bool endornot;
	int alrd=0;
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
	int i=str[0]-'a';
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


void search(int r,int c, char **givenmat,int i,int j,Trie* temp,string outputword[],string res){

        
         if(i<0||j<0||i>=r||j>=c||givenmat[i][j]=='@'||temp==NULL||temp->node[givenmat[i][j]-'a']==NULL)
         {
         	return;
         }
         
          res=res+givenmat[i][j];
          if(temp->node[givenmat[i][j]-'a']->endornot==true&&temp->node[givenmat[i][j]-'a']->alrd==0){
          	outputword[ans]=res;
              temp->node[givenmat[i][j]-'a']->alrd=1;
          	
          	ans=ans+1;
          }
    
        char t=givenmat[i][j];
       
       
         temp=temp->node[givenmat[i][j]-'a'];
         givenmat[i][j]='@';
      

       
        search(r,c,givenmat,i+1,j,temp,outputword,res);
        search(r,c,givenmat,i,j+1,temp,outputword,res);
        search(r,c,givenmat,i-1,j,temp,outputword,res);
        search(r,c,givenmat,i,j-1,temp,outputword,res);
        
        
        givenmat[i][j]=t;
    
    
    }





};

int pal_strcmp(string a,string b)
{
    int i=0;
    while(a[i]&&b[i]){
       if (a[i]==b[i]||(a[i]^32)==b[i])
       {
        }
        else
        {
        break;
        }
    	i=i+1;
    }
   
    if (a[i]==b[i])
    {
        return 0;
       }
    
    if ((a[i]|32)<(b[i]|32))
    {
        return -2;
      }

    return 2;
}

 void heapify(string arr[], int n, int i)  {
    int lc=2*i+1;
    int rc=2*i+2;
    int lar=i;
    if(lc<n&&pal_strcmp(arr[lar],arr[lc])==-2){
        lar=lc;
    }
     if(rc<n&&pal_strcmp(arr[lar],arr[rc])==-2){
        lar=rc;
    }
    if(i!=lar){
        swap(arr[lar],arr[i]);
        heapify(arr,n,lar);
    }
   
    }


   
    void buildHeap(string arr[], int n)  
    { 
        for(int i=(n/2)-1;i>=0;i--){
            heapify(arr,n,i);
        }

    }

    
    void heapSort(string arr[], int n)
    {
        buildHeap(arr,n);
        n=n-1;
        while(n>=1){
            swap(arr[0],arr[n]);
            
            heapify(arr,n,0);
            n=n-1;
        }}


 
int main(){
int r;
cin>>r;
int c;
cin>>c;
char **givenmat;
 givenmat =new char *[r];
for(int i=0;i<r;i++){
	givenmat[i] =new char [c];
	for(int j=0;j<c;j++){
		cin>>givenmat[i][j];
	}
}
int x;
cin>>x;
Paltrie s1;
string givenword[x];
for(int i=0;i<x;i++){
	cin>>givenword[i];
	s1.strinsert(givenword[i]);
}

  string outputword[x];
       
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
            	int k=givenmat[i][j]-'a';

                if(s1.root->node[k]!=NULL){
                	//cout<<givenmat[i][j]<<" kdjdf"<<endl;
                	string s="";
                s1.search(r,c,givenmat,i,j,s1.root,outputword,s);
                    
                }
            }
        }
          
            string temp;
        
            heapSort(outputword,s1.ans);

        cout<<s1.ans<<endl;
        for(int i=0;i<s1.ans;i++){
        	cout<<outputword[i]<<endl;
        }
        



}