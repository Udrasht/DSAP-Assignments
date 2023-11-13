#include<iostream>
#include<vector>
using namespace std;
template<typename T, typename U>
   class node {
    public:
    T key;
    node *next;
    U value;
    

    node(T key1, U value1) {
        key = key1;
        value = value1;
    }
    

};

template<typename T, typename U>
class unorder_map{
public:
int elements;
int places;
float f;
node<T, U> **maparr;
int hashfunction(int ke){
   int res=ke%places;
   return res;
}
int hashfunction(float ke){
     float ke1=ke*100;
   int res=(int)(ke1)%places;
   return res;
}
int hashfunction(char ke){

   int res=(int)(ke)%places;
   return res;
}
int hashfunction(double ke){
    double ke2=100*ke;
   int res=(int)(ke2)%places;
   return res;
}
int hashfunction(string ke){
   int p=1;
   int pri=26;
   int res;
   int l=ke.size();
   for(int i=0;i<l;i++){
       res=res+ke[i]*p;
       res=res%places;
       p=p*pri;
       p=p%places;
   }
   
    return res;
}
unorder_map(){
   elements=0;
   places=10010;
  
   maparr=new node<T,U> *[places];
   for(int i=0;i<places;i++){
      maparr[i]=NULL;
   }
}

void insert(T ke,U val){
   int x;
   x=hashfunction(ke);
   node<T, U> *t9=maparr[x];
   while(t9!=NULL){
      if(t9->key==ke){
         t9->value=val;
         return;
      }
      t9=t9->next;
   }
   
   auto *temp=new node<T, U> (ke,val);
   temp->next=maparr[x];
   elements=elements+1;
   maparr[x]=temp;
   
}
bool find(T ke){
   int x;
   x=hashfunction(ke);
   node<T, U> *t2=maparr[x];
   while(t2!=NULL){
      if(t2->key==ke){
         return true;
      }
      t2=t2->next;
   }

return false;

}
void erase(T ke){
   int x;
   x=hashfunction(ke);
    node<T, U> *t4=NULL;
   node<T, U> *t5=maparr[x];
   while(t5!=NULL){
      if(t5->key==ke){
         break;
      }
      t4=t5;
      t5=t5->next;
   }
   if(t5==NULL){
      return;
   }
   else if(t4==NULL){
      maparr[x]=t5->next;
   }
   else{
      t4->next=t5->next;
   }

elements=elements-1;
return;
}
U operator [](T ke){
   int x;
   x=hashfunction(ke);
   //cout<<x<<endl;
  node<T, U>*t6=maparr[x];
   while(t6!=NULL){
      if(t6->key==ke){
         return t6->value;
      }
      t6=t6->next;
   }
U x1=U();
return x1;
}
void print() {
        ///Iterate over buckets array
        for (int i = 0; i < places; i++) {
            ///Print the LL for each buckets
            node<T, U> *temp7 = maparr[i];
            cout << "Bucket " << i << "->";
            while (temp7 != nullptr) {
                cout << temp7->key << ",";
                temp7 = temp7->next;
            }
            cout << endl;
        }
    }

int sizeofmap(){
   return elements;
}




};
int main(){
   int num;
   cin>>num;
   int kum;
   cin>>kum;
   int A[num];
   for(int i=0;i<num;i++){
      cin>>A[i];
   }
   vector<int> ans;
   unorder_map<int,int> ud;
   for(int i=0;i<kum;i++){
            if(ud.find(A[i])==1){
                int udr= ud[A[i]];
                udr=udr+A[i];
                ud.insert(A[i],udr);
            }
            else{
                ud.insert(A[i],A[i]);
            }
            
        }
        int j=0;
        for(int i=kum;i<num;i++){
            ans.push_back(ud.sizeofmap());
            if(ud.find(A[j])==1){
                int gp=ud[A[j]];
                if(ud[A[j]]!=A[j]){
                    ud.insert(A[j],gp-A[j]);
                }
                else{
                    ud.erase(A[j]);
                }
            }
            if(ud.find(A[i])==1){
                int udr= ud[A[i]];
                udr=udr+A[i];
                ud.insert(A[i],udr);
            }
            else{
                ud.insert(A[i],A[i]);
            }
            j++;
            
            
            
        }
        //code here.
        ans.push_back(ud.sizeofmap());
        int num1=ans.size();
        for(int i=0;i<num1;i++){
         cout<<ans[i]<<" ";
        }
}