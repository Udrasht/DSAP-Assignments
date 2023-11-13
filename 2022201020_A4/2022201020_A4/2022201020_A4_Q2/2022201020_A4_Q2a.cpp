#include<iostream>
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
// void print() {
       
//         for (int i = 0; i < places; i++) {
//             ///Print the LL for each buckets
//             node<T, U> *temp7 = maparr[i];
//             cout << "Bucket " << i << "->";
//             while (temp7 != nullptr) {
//                 cout << temp7->key << ",";
//                 temp7 = temp7->next;
//             }
//             cout << endl;
//         }
//     }

int sizeofmap(){
   return elements;
}




};
int main(){
   // unorder_map<string,int> ud;
  //  ud.insert("sad",11);
  //  ud.insert("22",12);
  //  ud.insert("152",45896);
  //  ud.insert("52",5269);
  // // ud.print();
  //  bool pq=ud.find("52");
  //  cout<<pq<<endl;
  //  cout<<ud["52"]<<endl;
  //     cout<<ud.sizeofmap()<<endl;
  //  ud.insert("52",2356);
  //     cout<<ud.sizeofmap()<<endl;
  //  ud.insert("90",14);
  //  ud.insert("100",15);
  //  ud.insert("15",21);
   
   
  //  ud.insert("35",22);
  //  ud.insert("252",4896);
   
  //  ud.insert("62",569);

  //  ud.insert("70",56);
  //  ud.insert("80",147);
  //  ud.insert("300",1532);
  //  ud.erase("52");
  //  bool pq1=ud.find("52");
  //  cout<<pq1<<endl;
  //  cout<<ud["52"]<<endl;
  //  cout<<ud.sizeofmap()<<endl;
   //ud.print();
   unorder_map<int,int> udpal;
   cout<<"Enter 1 for Insert"<<endl;
   cout<<"Enter 2 for erase"<<endl;
   cout<<"Enter 3 for find"<<endl;
   cout<<"Enter 4 for map[key]"<<endl;
   cout<<"Enter 5 for exit"<<endl;
   
   while(1)
   {
      int option;
   cin>>option;
      if(option==1){
         cout<<"insert"<<endl;
         int enkey;
         cin>>enkey;
         int enval;
         cin>>enval;
         udpal.insert(enkey,enval);

      }
      else if(option==2){
         int enkey;
         cout<<"erase"<<endl;
         cin>>enkey;
         udpal.erase(enkey);

      }
      else if(option==3){
         cout<<"find"<<endl;
         int enkey;
         cin>>enkey;
         int dil=udpal.find(enkey);
         if(dil==1){
            cout<<"True"<<endl;
         }
         else{
            cout<<"False"<<endl;
         }
      }
      else if(option==4){
         cout<<"map[key]"<<endl;
         int enkey;
         cin>>enkey;
         cout<<udpal[enkey]<<endl;
         
      }
      else if(option==5){
         break;
      }
      else{
         cout<<"Enter valid key!"<<endl;
      }
   }
   
cout<<udpal.sizeofmap()<<endl;
   
   


}