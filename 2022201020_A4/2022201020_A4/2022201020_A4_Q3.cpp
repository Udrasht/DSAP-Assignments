#include<iostream>
using namespace std;


struct pal{
	 int x;
	int y;
};
template <typename T>
class udrasht_maxheap
{
   public:
    pal arr[20002];
    int size=0;
    int i=0;
     bool empty(){
        if(size==0){
            return true;
        }
        else{
            return false;
        }
    }

 void hepify(int p){
          int t=p;
        while(t>1&&arr[t].x<arr[t/2].x){
            pal temp=arr[t];
            arr[t]=arr[t/2];
            arr[t/2]=temp;
            t=t/2; //update index to new position
        }
    }

    void push(pal a){
          size=size+1;
           i=i+1;
           arr[i]=a;
           hepify(i);
    }
    
    
    void pop(){
        int j=1;
        arr[1]=arr[i];
        size=size-1;
        i=i-1;
        int lc,rc;
        while(j<i){
            rc= 2*j+1;
            lc= 2*j;
             int y1=j;
            if(lc<=i&&arr[lc].x<arr[y1].x){
               //  pal temp=arr[j];
           // arr[j]=arr[lc];
           // arr[lc]=temp;
                y1= lc;
            }
            if(rc<=i&&arr[rc].x<arr[y1].x ){
                // pal temp=arr[j];
           // arr[j]=arr[rc];
           // arr[rc]=temp;
                y1=rc;
            }
            if(j!=y1)
            {
             pal temp=arr[j];
            arr[j]=arr[y1];
           arr[y1]=temp;
                j=y1;
            }
            else break;

        }
    }

    pal top(){
       if(empty()){
            exit(1);
        }
        else{
            return arr[1];
       }
    }

};







class node{
public:
	int city;
	int distance;
	node *next=NULL;
	node(int x,int y){
		city=x;
		distance=y;
		next=NULL;
	}
};

int main(){
	int node1;
	int edge;
	int k;
	cin>>node1;
	cin>>edge;
	cin>>k;
	node *adj_list[node1+1];
	for(int i=0;i<node1+1;i++){
		adj_list[i]=NULL;
	}
	for(int i=1;i<=edge;i++){
		int sd,nd,eg;
		cin>>sd;
		cin>>nd;
		cin>>eg;
		
		node * temp1=new node(nd,eg);
		if(adj_list[sd]==NULL){
			adj_list[sd]=temp1;
			//cout<<"if"<<endl;
		}
		else{
			//cout<<"else"<<endl;
			temp1->next=adj_list[sd];
			adj_list[sd]=temp1;
		}
		node *temp2=new node(sd,eg);
		if(adj_list[nd]==NULL){
			adj_list[nd]=temp2;
			//cout<<"if"<<endl;
		}
		else{
			//cout<<"else"<<endl;
			temp2->next=adj_list[nd];
			adj_list[nd]=temp2;
		}


	}
	for(int i=0;i<k;i++){

      int police;
      cin>>police;

		node * temp1=new node(police,0);
		if(adj_list[0]==NULL){
			adj_list[0]=temp1;
			//cout<<"if"<<endl;
		}
		else{
			//cout<<"else"<<endl;
			temp1->next=adj_list[0];
			adj_list[0]=temp1;
		}
		node *temp2=new node(0,0);
		if(adj_list[police]==NULL){
			adj_list[police]=temp2;
			//cout<<"if"<<endl;
		}
		else{
			//cout<<"else"<<endl;
			temp2->next=adj_list[police];
			adj_list[police]=temp2;
		}

	}
	// for(int i=0;i<node1+1;i++){
	// 	node *t=adj_list[i];
	// 	cout<<"i->"<<i<<endl;
	// 	while(t!=NULL){
	// 		cout<<t->city<<"->"<<t->distance<<"->";
	// 		t=t->next;
	// 	}
	// 	cout<<endl;
	// }
       int dist[node1+1];
        udrasht_maxheap<pal> pq;


        for (int i=1;i<node1+1;i++){

            dist[i]=1000000000;

        }
      int S=0;
        dist[S]=0;
        pal u1;
        u1.x=0;
        u1.y=S;

        pq.push(u1);

        

        while (pq.empty()==false){

            pal u2=pq.top();
           int dis=u2.x;
            int node3=u2.y;

            pq.pop();

            
             node *temp3=adj_list[node3];
            while(temp3!=NULL){

                int edgeweight=temp3->distance;

                int adjnode=temp3->city;

                

                if (dis+edgeweight<dist[adjnode]){

                    dist[adjnode]=dis+edgeweight;
                    pal u3;
                    u3.x=dist[adjnode];
                    u3.y=adjnode;

                    pq.push(u3);

                }
                  temp3=temp3->next;
            }

        }

        for(int i=1;i<node1+1;i++){
        	if(dist[i]==1000000000){
        		dist[i]=-1;
        	}
        	cout<<dist[i]<<" ";
        }

     cout<<endl;
	

}