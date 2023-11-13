#include<iostream>
using namespace std;
  template <typename T>
class avltree{
    class Node{
    public:

       T data;
       Node* left;
       Node* right;
       int hi;
       int oc;
       int gle;
       Node(T val){
       	left=NULL;
       	right=NULL;
       	data=val;
       	hi=1;
        oc=1;
        gle=0;
       }


    };
public:
    Node* root;
    
     int height(Node* temp){
        if(temp==NULL){
            return 0;
        }
        else{
            int h=temp->hi;
            return h;
        }
    }
    avltree(){
       root=NULL;
    }
      Node* lrotate(Node* te){
       Node* t1=te->right;
        te->right=t1->left;
        Node* u1=t1->left;
        t1->left=te;
        te->hi=max(height(te->left),height(te->right));
        te->hi=te->hi+1;
        t1->hi=max(height(t1->left),height(t1->right));
        t1->hi=t1->hi+1;
        
        int x=0;
        if(u1!=NULL){
            x=u1->gle+u1->oc;
        }
        int y1=te->gle-t1->gle-t1->oc;
        y1=y1+x;
        te->gle=y1;
        int y2=t1->gle-x;
        y2=y2+te->gle+te->oc;
        t1->gle=y2;

        return t1;

      }
      Node* rrotate(Node* te){
      Node* t1=te->left;
        te->left=t1->right;
        Node* u1=t1->right;
        t1->right=te;
        
        te->hi=max(height(te->left),height(te->right));
        te->hi=te->hi+1;
        t1->hi=max(height(t1->left),height(t1->right));
        t1->hi=t1->hi+1;
        int x=0;
        if(u1!=NULL){
            x=u1->gle+u1->oc;
        }
        int y1=te->gle-t1->gle-t1->oc;
        y1=y1+x;
        te->gle=y1;
        int y2=t1->gle-x;
        y2=y2+te->gle+te->oc;
        t1->gle=y2;
        

        return t1;
      }
    

    int bornot(Node* te){
        if(te!=NULL){
            int b;
            
            b=height(te->left)-height(te->right);
            return b;
        }
        else {
            return 0;
        }
    }

  Node* insuccessor(Node* temp){
    while(temp&&temp->left)
    {
        temp=temp->left;
    }
    return temp;
}


int search(Node* temp, T item){
    if(temp==NULL){
        return 0;
    }
    else if(temp->data==item){
        return temp->oc;
    }
    else if(temp->data<item){
        return search(temp->right,item);
    }
    else{
         return search(temp->left,item);
    }
    
}
int count_occ(Node* temp,T item){
    if(temp==NULL){
        return 0;
    }
    else if(temp->data==item){
        return temp->oc;
    }
    else if(temp->data<item){
        return count_occ(temp->right,item);
    }
    else{
        return count_occ(temp->left,item);
    }


}

int count_larger(Node* temp,T item){
      int count=0;
     // cout<<"hi"<<endl;
      while(temp!=NULL){
        int support=0;
        if(temp->right!=NULL){
            support=temp->right->gle+temp->right->oc;
        }
        if(temp->data<item){
            temp=temp->right;
        }
        else if(temp->data>item){
            count=count+support+temp->oc;
            temp=temp->left;
        }
        else{
            count=count+support;
            break;
        }
      }
      return count;

}
int range(Node* temp,T llimit,T rlimit){

        if(llimit>rlimit){
            return 0;
        }
        else{
            int a1=count_larger(temp,llimit-1);
            int a2=count_larger(temp,rlimit);
            return (a1-a2);
        }


}


T lowerboundlogic(Node* temp ,T input,T max){
    if(temp==NULL){
        return max;
    }

    if(temp->data<input){
        return lowerboundlogic(temp->right,input,max);
    }
    else{
        if(temp->data<=max){
            max=temp->data;
        }
       return lowerboundlogic(temp->left,input,max);
    }

}

T lowerbound(Node* temp ,T input){

       Node* temp2=temp;
       
        if(temp==NULL){
              T x=T();
             return x;
        }
        T max=temp->data;
       while(temp2!=NULL){
        max=temp2->data;
           temp2=temp2->right;
       }
       if(input>max){
         T x=T();
             return x;
       }
       else if(input<max){

        return lowerboundlogic(temp,input,max);
       }
       else{
        return max;
       }
}


T upperboundlogic(Node* temp ,T input,T max){
    if(temp==NULL){
        return max;
    }

    if(temp->data<=input){
        return upperboundlogic(temp->right,input,max);
    }
    else if(temp->data>input){
        if(temp->data<max){
            max=temp->data;
        }
       return upperboundlogic(temp->left,input,max);
    }
    else{
        return max;
    }

}


T upperbound(Node* temp ,T input){

       Node* temp2=temp;
       
        if(temp==NULL){
              T x=T();
             return x;
        }
        T max=temp->data;
       while(temp2!=NULL){
        max=temp2->data;
           temp2=temp2->right;
       }
       if(input>=max){
        T x=T();
             return x;
       }
       else{

        return upperboundlogic(temp,input,max);
       }

}


T lowerboundlogicc(Node* temp ,T input,T max){
    if(temp==NULL){
        return max;
    }

    if(temp->data<input){
        return lowerboundlogicc(temp->right,input,max);
    }
    else{
        if(temp->data<=max){
            max=temp->data;
        }
       return lowerboundlogicc(temp->left,input,max);
    }

}

T lowerboundc(Node* temp ,T input){

       Node* temp2=temp;
       
        if(temp==NULL){
              T x=T();
             return x;
        }
        T max=temp->data;
       while(temp2!=NULL){
        max=temp2->data;
           temp2=temp2->right;
       }
       if(input>max){
        return max;
       }
       else if(input<max){

        return lowerboundlogicc(temp,input,max);
       }
       else{
        return max;
       }
}



T closestboundlogic(Node* temp,T input,T min){

   if(temp==NULL){
        return min;
    }

    if(temp->data<input){
        if(temp->data>=min){
            min=temp->data;
        }
       return closestboundlogic(temp->right,input,min);
    }
    else{
        
      return closestboundlogic(temp->left,input,min);
    }


}
T closestbound(Node* temp ,T input){

       Node* temp2=temp;
       
        if(temp==NULL){
              T x=T();
             return x;
        }
        T min=input;
       while(temp2!=NULL){
        min=temp2->data;
           temp2=temp2->left;
       }
       if(input<min){
    
             return min;
       }
       else{

        return closestboundlogic(temp,input,min);
       }

}

T closest(Node* temp,T input){
     if(temp==NULL){
              T x=T();
             return x;
        }

        else{

            T ge=lowerboundc(temp,input);
            
            T le=closestbound(temp,input);

           if(input>ge||ge==input){
                return ge;
            }
            if(input<le||le==input){
                return le;
            }

            if(ge-input<input-le){
                return ge;
            }
            else{
                return le;
            }

        }


}






Node* newNode(T input){
    Node * temp=new Node(input);
    return temp;
}


    Node* insert(Node* temp,T input){

      if(temp==NULL){
        Node* t1;
        t1=newNode(input);
        return t1;
       }
      else if(input==temp->data){
        //temp->gle=temp->gle+1;
        temp->oc=temp->oc+1;
      }
      else if(input>temp->data){
          temp->right=insert(temp->right,input);
          temp->gle=temp->gle+1;

       }
       else if(input<temp->data){
        temp->left=insert(temp->left,input);
        temp->gle=temp->gle+1;
       }

       temp->hi=max(height(temp->left),height(temp->right));
       temp->hi=temp->hi+1;
       int bf;
       bf=bornot(temp);
       //L-L
       if(temp->left!=NULL&&input<temp->left->data&&bf>1){
        return rrotate(temp);
       }
       //R-R
       else  if(temp->right!=NULL&&input>temp->right->data&&bf<-1){
        return lrotate(temp);
       }

       //R-L
      else if(temp->right!=NULL&&input<temp->right->data&&bf<-1){
        temp->right=rrotate(temp->right);
        return lrotate(temp);

       }
       //L-R
        else if(temp->left!=NULL&&input>temp->left->data&&bf>1){
        temp->left=lrotate(temp->left);
        return rrotate(temp);

       }
       return temp;


    }

    Node* inpredecessor(Node* temp){
    while(temp&&temp->right)
    temp=temp->right;
    return temp;
     }

Node* beroreNodedelete(Node* temp,T input){
    int ocsub=search(temp,input);
    if(ocsub==0){
        return temp;
    }
    else{
        return Nodedelete(temp,input,ocsub);
    }
}

Node* Nodedelete(Node* temp,T item,int ocsub){
	if(temp!=NULL){
    if(temp->left==NULL && temp->right==NULL){
        if(item==temp->data){
            free(temp);
            return NULL;
            
        }
    }
    if(item>temp->data){
         temp->right=Nodedelete(temp->right,item,ocsub);
         temp->gle=temp->gle-ocsub;
      }
      else if(item<temp->data){
        temp->left=Nodedelete(temp->left,item,ocsub);
        temp->gle=temp->gle-ocsub;

      }
    
    else {
        if(temp->right!=NULL)
        {
            Node* q=NULL;
            q=insuccessor(temp->right);
            temp->data=q->data;
            temp->gle=temp->gle-q->oc;
            temp->oc=q->oc;
            temp->right=Nodedelete(temp->right, q->data,q->oc);
            
        }
        else
        {
            Node* q=NULL;
            q=inpredecessor(temp->left);
            temp->data=q->data;
            temp->gle=temp->gle-q->oc;
            temp->oc=q->oc;
            temp->left=Nodedelete(temp->left,q->data,q->oc);
        }
    }
     if(temp==NULL){
        return temp;
     }
     int t=max(height(temp->left),height(temp->right));
     t=t+1;
     temp->hi=t;
     int bf=bornot(temp);
     int b1=bornot(temp->left);
     if(b1<0&&bf>1){
        temp->left=lrotate(temp->left);
        return rrotate(temp);
     }
     int b2=bornot(temp->left);
       if(b2>=0&&bf>1){
        return rrotate(temp);
     }
     int b3=bornot(temp->right);
       if(b3>0&&bf<-1){
        temp->right=rrotate(temp->right);
        return lrotate(temp);
     }
     int b4=bornot(temp->right);
       if(b4<=0&&bf<-1){
        
        return lrotate(temp);
     }
    
      return temp;
    }
    else{
        return temp;
    }
}


void preorder(Node* temp){
    if(temp==NULL){
        return;
    }
    cout<<temp->data<<" ";
    preorder(temp->left);
    
    preorder(temp->right);
}
T kth(Node* temp,int k){

     T x=T();
    if(temp==NULL){
        return x;
    }
    else{

    if((k<1)||k>(temp->oc+temp->gle)){
        
        return x;
    }
    else{
    while(temp!=NULL){
        int pq=0;
        if(temp->right!=NULL){
            if(k>temp->right->oc+temp->right->gle+temp->oc){
                k=k-(temp->right->oc+temp->right->gle+temp->oc);
                temp=temp->left;
                
            }
            else if(k>temp->right->oc+temp->right->gle&&k<=temp->right->oc+temp->right->gle+temp->oc){
                x=temp->data;
                pq=1;
                break;


            }
            else{
                temp=temp->right;
            }
        }
        else{
            //cout<<"hi"<<k<<temp->oc;
            if(k>temp->oc){
                k=k-temp->oc;
                temp=temp->left;
              
                
            }
            else{

                x=temp->data;
                pq=1;
                break;
            }
        }
        if(pq==1){
            break;
        }
    }
    return x;}
}
}

void inorder(Node* temp){
    if(temp==NULL){
        
        return;
    }
    inorder(temp->left);
    cout<<"("<<temp->data<<","<<temp->oc<<","<<temp->gle<<") ";
    inorder(temp->right);
}

void searchoutput(int mlo){
    if(mlo==0){
            cout<<"False"<<endl;
         }
         else{
            cout<<"True"<<endl;
         }
}

};

int main(){
avltree<int> obj;
while(1){
    int n;
     cin>>n;
    int mlo;
switch(n){
	case 1:
	int n1;
	cin>>n1;
	obj.root=obj.insert(obj.root,n1);
	break;
	case 2:
	    int n2;
	    cin>>n2;
	    obj.root=obj.beroreNodedelete(obj.root,n2);
        break;
    case 3:
         int n3;
         cin>>n3;
          mlo=obj.search(obj.root,n3);
         obj.searchoutput(mlo);
         break;
    case 4:
          int n4;
         cin>>n4;
         cout<<obj.count_occ(obj.root,n4)<<endl;
         break;
    case 5:
          int n5;
         cin>>n5;
         cout<<obj.lowerbound(obj.root,n5)<<endl;
         break;
    case 6:
          int n6;
         cin>>n6;
         cout<<obj.upperbound(obj.root,n6)<<endl;
         break;
    case 7:
          int n7;
         cin>>n7;
         cout<<obj.closest(obj.root,n7)<<endl;
         break;
    case 8:
          int k;
          cin>>k;
         cout<<obj.kth(obj.root,k)<<endl;
         break;
    case 9: int ll,rl;

         cin>>ll;
         cin>>rl;
         cout<<obj.range(obj.root,ll,rl)<<endl;
         break;


    /*case 10:
         obj.preorder(obj.root);
         cout<<endl;
         obj.inorder(obj.root);
         cout<<endl;
         break;*/
    case 0:

        exit(1);

}
}


}