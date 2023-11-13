#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int *constructST(int arr[],int n)
{
  int* st=new int[2*n];
  for(int i=0;i<n;i++){
      st[n+i]=arr[i];
  }
  for(int i=n-1;i>0;i--){
      st[i]=min(st[i<<1],st[i<<1|1]);
  }
  return st;
}



int RMQ(int st[] , int n, int a, int b)
{
    int ans=100000000;
    a+=n;b+=n;
    while(a<b){
        if(a%2){
            ans=min(ans,st[a++]);
        }
        if((b+1)%2){
            ans=min(ans,st[b--]);
        }
        a>>=1;b>>=1;
    }
    if(a==b){
        ans=min(ans,st[a]);
    }
    return ans;
}
void sortlogic(int j,vector<int> &RA,vector<int> &SA,int n){
    //int n=RA.size();
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
void kssai(int prefix[],vector<int> &SA,string str,int nen,int leto){
    //int nen=SA.size();
    //cout<<"hello"<<endl;
    vector<int> support(nen);
    int i=0;
    //support[SA[i]]=-1;
    //i=i+1;
   // char cht1[nen+1];
    // strcpy(cht1, str.c_str());

    while(i<nen){
        int j=SA[i];
       // int k=i-1;
        support[j]=i;
      i++;
    }

    int match=0;
    int utility,utility2;
    for(int l=0;l<nen;l++){
              match=max(0,match-1);
              utility=support[l];
              if(utility==nen-1){
                  match=0;

                  continue;
              }
              else{
                  utility2=support[l]+1;
                  int x=SA[utility2];
                  while((l+match<nen)&&(x+match<nen)&&(str[l+match]==str[x+match])){
                      match=match+1;
                  }
                  prefix[support[l]]=match;

              }
    }
    int *st = constructST(prefix, nen);
    int maxlcs=0,strstart=0,ug,ug3;
    int xtq=0,qtr=0;
    for(int i=0;i<nen-1;i++){
        //cout<<SA[i]<<" "<<cht+SA[i]<<" "<<prefix[i]<<endl;
        if(prefix[i]>maxlcs){
            if((SA[i]>leto&&SA[i+1]<leto)){
                ug=nen-(SA[i]+prefix[i]);
                    if(ug<nen&&SA[i+1]==ug){
                maxlcs=prefix[i];
                strstart=SA[i+1];}
                else{
                    
                   xtq=support[ug];
                   if(i<xtq){

                  qtr=RMQ(st,nen,i,xtq);}
                  else{
                      qtr=RMQ(st,nen,xtq,i);
                  }
                  if(qtr>=prefix[i]){
                     maxlcs=prefix[i];
                    strstart=SA[i+1];
                  }
                }

            }
            else if((SA[i]<leto&&SA[i+1]>leto)){
                ug3=nen-(SA[i+1]+prefix[i]);
                if(ug3<nen&&SA[i]==ug3){
                maxlcs=prefix[i];
                strstart=SA[i];}
                else{
                   
                   xtq=support[ug3];
                   if(i<xtq){

                  qtr=RMQ(st,nen,i,xtq);}
                  else{
                      qtr=RMQ(st,nen,xtq,i);
                  }
                  if(qtr>=prefix[i]){
                     maxlcs=prefix[i];
                    strstart=SA[i];
                  }

                }
              }
            }
        }
        cout<<str.substr(strstart,maxlcs)<<endl;
}
void logic(string str,int leto){
    int n=str.size();
    vector<int> RA(n),SA(n);
     char cht[n+1];
     strcpy(cht, str.c_str());
    for(int i=0;i<n;i++){
        int tq1=str[i];
        //cout<<tq1;
        RA[i]=tq1;
        SA[i]=i;
    

    }
    int temp2=0;
     int c2=0,c1=0;
    vector<int> TAR(n);
    for(int j=1;j<n;j <<= 1){
        //cout<<j<<endl;
        sortlogic(j,RA,SA,n);
        sortlogic(0,RA,SA,n);
        //int temp2=0;
        TAR[SA[0]]=temp2=0;
        for(int i=1;i<n;i++){
            //TAR[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+j] == RA[SA[i-1]+j]) ? temp2 : ++temp2;
            c1=0,c2=0;
            if(RA[SA[i]]==RA[SA[i-1]]){
                c1=1;}
           
            if(RA[SA[i]+j]==RA[SA[i-1]+j]){
                c2=1;}
            
            if(c1&c2){
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
    int *prefix;
    prefix=new int[n];
    kssai(prefix,SA,str,n,leto);
    //vector<int> resprefix(n);
    // prefix[0]=0;
    // for(int i=n-1;i>0;i--){
    //     prefix[i]=prefix[i-1];
    // }
    
   



        

         

}
int main() {
    string str;
    cin>>str;
    int leto;
    leto=str.size();
    str=str+"$";
    string str1="";
    for(int i=leto-1;i>=0;i--){
        str1=str1+str[i];
    }
    str=str+str1;
    //cout<<str<<endl;
    
    logic(str,leto);
    
        
    
}