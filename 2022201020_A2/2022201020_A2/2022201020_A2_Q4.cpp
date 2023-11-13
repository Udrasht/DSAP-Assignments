#include<iostream>
using namespace std;
template <typename R>
class sparsMatrix{
	
	int n;
	R trans_mat[100001][3];
	R spar[100001][3];
	int m;
	int u=0;
public:

	// It will create a sparse matrix from input matrix
	// It will take a input from user
	void input(){
            //index of sparse matrix
		
		cin>>n;
		
		cin>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				R c;
				cin>>c;
               if(c>0||c<0){
                spar[u][0]=i;
                spar[u][1]=j;
                spar[u][2]=c;
                u=u+1;
                       }
			}
		}
		//cout<<u<<"  hello "<<endl;

	}

	
// it will display thr matrix in sparse matrix form
	
	void dis_s_mat(){

		     
		for(int i=0;i<u;i++){
			cout<<(int)(spar[i][0])<<" "<<(int)(spar[i][1])<<" "<<spar[i][2]<<endl;
		}


	}
	void dis_s_mattrans(){
		int lo=0;
            for(int i=0;i<n;i++){
            	for(int j=0;j<m;j++){
            		if(lo<u&&(int)trans_mat[lo][0]==i&&(int)trans_mat[lo][1]==j){
            			cout<<trans_mat[lo][2]<<" ";
            			lo++;
            		}
            		else{
            			cout<<"0"<<" ";
            		}
            	}
            	cout<<endl;
            }
	/*for(int i=0;i<u;i++){
			cout<<(int)trans_mat[i][0]<<" "<<(int)trans_mat[i][1]<<" "<<trans_mat[i][2]<<endl;
		}*/

	}
	//It will perform the addition of sparse matrix
	void add_sparse(sparsMatrix &m2){
		if(n!=m2.n||m!=m2.m){
           cout<<"Addition is not possible n1!=n2 or m1!=m2"<<endl;
		}
		else{

        R ans[100001][3];
        int i=0,j=0;

        int l1=u;
        int ri=0;
        int l2=m2.u;
        while(i<l1&&j<l2){
            if(spar[i][0]==m2.spar[j][0]){
            	if(spar[i][1]==m2.spar[j][1]){
            		ans[ri][0]=spar[i][0];
            		ans[ri][1]=spar[i][1];
            		ans[ri][2]=spar[i][2]+m2.spar[j][2];
            		i++;
            		j++;
            		ri++;

            	}
            	else if (spar[i][1]<m2.spar[j][1]){
            		ans[ri][0]=spar[i][0];
            		ans[ri][1]=spar[i][1];
            		ans[ri][2]=spar[i][2];
            		i++;
            		ri++;

            	}
            	else{
            		ans[ri][0]=m2.spar[j][0];
            		ans[ri][1]=m2.spar[j][1];
            		ans[ri][2]=m2.spar[j][2];
            		j++;
            		ri++;



            	}

              }
              else if(spar[i][0]<m2.spar[j][0]){
              	    ans[ri][0]=spar[i][0];
            		ans[ri][1]=spar[i][1];
            		ans[ri][2]=spar[i][2];
            		i++;
            		ri++;

              }
              else{
              	   ans[ri][0]=m2.spar[j][0];
            		ans[ri][1]=m2.spar[j][1];
            		ans[ri][2]=m2.spar[j][2];
            		j++;
            		ri++;

              }


            }
            while(i<l1){
            	ans[ri][0]=spar[i][0];
            		ans[ri][1]=spar[i][1];
            		ans[ri][2]=spar[i][2];
            		i++;
            		ri++;

            }
            while(j<l2){
            	    ans[ri][0]=m2.spar[j][0];
            		ans[ri][1]=m2.spar[j][1];
            		ans[ri][2]=m2.spar[j][2];
            		j++;
            		ri++;

            }
        

        //cout<<"Matrix after addition: "<<endl;
                  int lo=0;
            for(int i=0;i<n;i++){
            	for(int j=0;j<m;j++){
            		if(lo<ri&&(int)ans[lo][0]==i&&(int)ans[lo][1]==j){
            			cout<<ans[lo][2]<<" ";
            			lo++;
            		}
            		else{
            			cout<<"0"<<" ";
            		}
            	}
            	cout<<endl;
            }
           
            /*for(int i=0;i<ri;i++){
			cout<<(int)ans[i][0]<<" "<<(int)ans[i][1]<<" "<<ans[i][2]<<endl;
		}*/
       }


	}
	//It will perform the transpose of matrix
	void trans(){
      int t=0;
          int max_count=0;
          for(int j=0;j<u;j++){
          	if((int)spar[j][1]>max_count){
          		max_count=(int)spar[j][1];
          	}
          }
          int supportarray[max_count+1]={0};
          int supportarray2[max_count+1]={0};
          for(int j=0;j<u;j++){
          
          	    supportarray[(int)spar[j][1]]++;;
          	
          }
          for(int j=1;j<max_count+1;j++){
          
          	    supportarray2[j]=supportarray2[j-1]+supportarray[j-1];
          	
          }

        for(int j=0;j<u;j++){
          	
          		  int it=(int)spar[j][1];
          		  int it1=supportarray2[it];
                   supportarray2[it]++;
                    trans_mat[it1][2]=spar[j][2];
					trans_mat[it1][1]=spar[j][0];
					trans_mat[it1][0]=spar[j][1];
					t=t+1;
          	      
          }
	


	}
	void mul_two(sparsMatrix &m2)
	{
		if(m!=m2.n){
			cout<<"Multiplication is not bossible m1!=n2"<<endl;
		}
		else{
			R mularr[100001][3];
			int mulsize=0;
			int a2=0;
			m2.trans();
			int n2=m2.u;
			int n1=u;
			int a1=0;
			
			for(int i=0;i<n1;){
				a1=spar[i][0];
				for(int j=0;j<n2;){
					R cur_sum=0;
					 int i2=j;
                   a2=m2.trans_mat[j][0];
                   int i1=i;
                  
                   for(;i1<n1&&i2<n2&&spar[i1][0]==a1&&m2.trans_mat[i2][0]==a2;){
                    if(spar[i1][1]==m2.trans_mat[i2][1]){
                    	cur_sum=cur_sum+spar[i1][2]*m2.trans_mat[i2][2];
                    	i1=i1+1;
                    	i2=i2+1;
                    }
                    else if(spar[i1][1]>m2.trans_mat[i2][1]){
                    	i2=i2+1;
                    }
                    else if(spar[i1][1]<m2.trans_mat[i2][1]){
                    	i1=i1+1;
                    }
                        }
                        if(cur_sum>0||cur_sum<0){
                        mularr[mulsize][0]=a1;
                        mularr[mulsize][1]=a2;
                        mularr[mulsize][2]=cur_sum;
                        mulsize=mulsize+1;
                    }
                    for(;j<n2&&m2.trans_mat[j][0]==a2;){
                    	j=j+1;
                    }

				}
				  for(;i<n1&&spar[i][0]==a1;){
                    	i=i+1;
                    }

			}
			//cout<<"After multiplication"<<endl;
			     int lo=0;
            for(int i=0;i<n;i++){
            	for(int j=0;j<m2.m;j++){
            		if(lo<mulsize&&(int)mularr[lo][0]==i&&(int)mularr[lo][1]==j){
            			cout<<mularr[lo][2]<<" ";
            			lo++;
            		}
            		else{
            			cout<<"0"<<" ";
            		}
            	}
            	cout<<endl;
            }
			/*for(int i=0;i<mulsize;i++){
			cout<<mularr[i][0]<<" "<<mularr[i][1]<<" "<<mularr[i][2]<<endl;
		}*/




		}
	}

};
template <typename U>
class sparslink{
	
   public:
   	class Node{
public:
	int row ;
	int col;
	U data;
	
	Node *right;
	Node(int ro, int co,U val){
		row=ro;
		col=co;
		data=val;
		right=NULL;

	}
};
int n;
int m;
   	Node* head;
   //	Node* trhead=NULL;
   	sparslink(){
   		head=NULL;
   	}
   	void insertNode(int r,int c,U v){
   		Node* item = new Node(r,c,v);
   		if(head==NULL){
             head=item;

   		}
   		else{
   			Node* temp=head;
   			while(temp->right!=NULL){
   				temp=temp->right;
   			}
   			temp->right=item;
   		}

   	}
   	void insertNodein(int r,int c,U v){
   		if(r<head->row&&c<head->col){
   			Node* item = new Node(r,c,v);
   			item->right=head;
   			head=item;
   		}
   		else{
   			Node* temp=head;
   			int u=0;
   			while(temp->right!=NULL){
   				if(r<=temp->right->row&&c<=temp->right->col){
   					u=1;
   					Node* item = new Node(r,c,v);
   					item->right=temp->right;
   					temp->right=item;
   					break;

   				}
   				temp=temp->right;
   			}
   			if(u==0){
   				Node* item = new Node(r,c,v);
   				temp->right=item;
   				item->right=NULL;
   			}
   		}
   	}
   	void disp_list(Node* t){

   		Node* temp=t;
   		/*while(temp){
   			cout<<temp->row<<" "<<temp->col<<" "<<temp->data<<endl;
   		     temp=temp->right;
   		}*/
        int lo=0;
            for(int i=0;i<n;i++){
            	for(int j=0;j<m;j++){
            		if(temp!=NULL&&(int)temp->row==i&&(int)temp->col==j){
            			cout<<temp->data<<" ";
            			temp=temp->right;
            		}
            		else{
            			cout<<"0"<<" ";
            		}
            	}
            	cout<<endl;
            }

   	}
   		void input_l(){
   		
		
		cin>>n;
	
		
		cin>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				U it;
				cin>>it;
				if(it>0||it<0){
				insertNode(i,j,it);
			}
			}
		}
      // disp_list(head);

	}
	void sumOfmatrixlink(sparslink &m2){

		if(n!=m2.n||m!=m2.m){
           cout<<"Addition is not possible n1!=n2 or m1!=m2"<<endl;
		}
		else{
		Node* temp1=head;
		Node* temp2=m2.head;
		Node* head2=NULL;
		Node* temp3;
		
		while(temp1&&temp2){
		
			if(temp1->row==temp2->row){
				if(temp1->col==temp2->col){
                   Node* item = new Node(temp1->row,temp1->col,temp1->data+temp2->data);
                   if(head2==NULL){
                   	head2=item;
                   	temp3=item;
                   }
                   else{
                       temp3->right=item;
                       temp3=temp3->right;
                   }
                   temp1=temp1->right;
                   temp2=temp2->right;	

 
				}
				else if(temp1->col<temp2->col){

                 Node* item = new Node(temp1->row,temp1->col,temp1->data);
                   if(head2==NULL){
                   	head2=item;
                   	temp3=item;
                   }
                   else{
                       temp3->right=item;
                       temp3=temp3->right;
                   }
                   temp1=temp1->right;
                 
                       }
				else{
					 Node* item = new Node(temp2->row,temp2->col,temp2->data);
                   if(head2==NULL){
                   	head2=item;
                   	temp3=item;
                   }
                   else{
                       temp3->right=item;
                       temp3=temp3->right;
                   }
                   temp2=temp2->right;

				}

			}
			else if(temp1->row<temp2->row){
				Node* item = new Node(temp1->row,temp1->col,temp1->data);
                   if(head2==NULL){
                   	head2=item;
                   	temp3=item;
                   }
                   else{
                       temp3->right=item;
                       temp3=temp3->right;
                   }
                   temp1=temp1->right;

			}
			else{
				Node* item = new Node(temp2->row,temp2->col,temp2->data);
                   if(head2==NULL){
                   	head2=item;
                   temp3=item;
                   }
                   else{
                       temp3->right=item;
                       temp3=temp3->right;
                   }
                   temp2=temp2->right;

			}
		}
         while(temp1){
	Node* item = new Node(temp1->row,temp1->col,temp1->data);
                   if(head2==NULL){
                   	head2=item;
                   	temp3=item;
                   }
                   else{
                       temp3->right=item;
                       temp3=temp3->right;
                   }
                   temp1=temp1->right;

          }
          while(temp2){
	Node* item = new Node(temp2->row,temp2->col,temp2->data);
                   if(head2==NULL){
                   	head2=item;
                   	temp3=item;
                   }
                   else{
                       temp3->right=item;
                       temp3=temp3->right;
                   }
                   temp2=temp2->right;

           }

          disp_list(head2);
	}
}


	void transLinklist(){

          Node* temp;
		temp=head;
		int max_count=0;
		while(temp){
			if(temp->col>max_count){
				max_count=temp->col;
			}
			temp=temp->right;
		}
		int supportarray[max_count+1]={0};
          int supportarray2[max_count+1]={0};
          temp=head;
          while(temp){
		supportarray[temp->col]++;
			temp=temp->right;
		}
		for(int j=1;j<max_count+1;j++){
          
          	    supportarray2[j]=supportarray2[j-1]+supportarray[j-1];
          	
          }

          temp=head;
           sparslink s5;
           int h1=0;
          while(temp){
            
       		s5.insertNode(-1,-1,0);
       	       h1++;
       	      temp=temp->right;

          }

          Node* Nodearr[max_count+1];

          Nodearr[0]=s5.head;
          Node* temp3=s5.head;

          for(int i=1;i<max_count+1;i++){
          	int d1=supportarray[i-1];
          	while(d1--){
              temp3=temp3->right;
          	}
          	Nodearr[i]=temp3;
          }

          temp=head;
          while(temp){
          	int c=temp->col;
          	Node* dd=Nodearr[c];
          	dd->row=temp->col;
          	dd->col=temp->row;
          	dd->data=temp->data;
          	Nodearr[c]=Nodearr[c]->right;
          	temp=temp->right;

          }

		disp_list(s5.head);

		
	}

	void multiLinklist(sparslink &m2){

if(m!=m2.n){
			cout<<"Multiplication is not bossible m1!=n2"<<endl;
		}
		else{
        Node* temp1;
        sparslink s3;
       //m2.transLinklist();
        Node* temp2;
        temp1=head;
        temp2=m2.head;
        while(temp1){
        	temp2=m2.head;
        	while(temp2->right){
        		if(temp1->col==temp2->row){
        			s3.insertNode(temp1->row,temp2->col,((temp1->data)*(temp2->data)));

        		}
        		temp2=temp2->right;

        	}
        	if(temp2->right==NULL){
        		if(temp1->col==temp2->row){
        			s3.insertNode(temp1->row,temp2->col,((temp1->data)*(temp2->data)));
        		}
        	}
        	temp1=temp1->right;
        }

       // cout<<"after multiplication"<<endl;

       temp1=s3.head;
       sparslink s4;

       while(temp1){
       	if(s4.head==NULL){
       		s4.insertNode(temp1->row,temp1->col,temp1->data);
       	}
       	else{ int u=0;
       		temp2=s4.head;
       		while(temp2){
       			if(temp1->row==temp2->row&&temp1->col==temp2->col){
       				temp2->data=temp2->data+temp1->data;
       				u=1;
       				break;
       			}
       			temp2=temp2->right;
       		}
       		if(u==0){
                 s4.insertNodein(temp1->row,temp1->col,temp1->data);
       		}

       	}
       		temp1=temp1->right;
       }
      Node* lov1=s4.head;
     int lo=0;
            for(int i=0;i<n;i++){
            	for(int j=0;j<m2.m;j++){
            		if(lov1!=NULL&&(int)lov1->row==i&&(int)lov1->col==j){
            			cout<<lov1->data<<" ";
            			lov1=lov1->right;
            		}
            		else{
            			cout<<"0"<<" ";
            		}
            	}
            	cout<<endl;
            }
}

	}

};
int main()
{
	int type;
	cin>>type;
	if(type==1){
		int opt;
		cin>>opt;
		if(opt==1){
	sparsMatrix<float> m1,m2;
	m1.input();
	//m1.dis_s_mat();
	m2.input();
	//m2.dis_s_mat();
	m1.add_sparse(m2);

		}
		else if(opt==2){
			sparsMatrix<float> m1;
			m1.input();
             m1.trans();
            m1.dis_s_mattrans();
		}
		else if(opt==3){
    sparsMatrix<float> m1,m2;
	m1.input();
	//m1.dis_s_mat();
	m2.input();
	//m2.dis_s_mat();
	m1.mul_two(m2);
		}
		else{
			cout<<"Invalid opertation"<<endl;
		}
	}
	/* spars matrix in linklist form */
else if(type==2){

	int opt;
		cin>>opt;
		if(opt==1){
	sparslink<float> m1,m2;
	 m1.input_l();
	 m2.input_l();
	m1.sumOfmatrixlink(m2);

		}
		else if(opt==2){
			sparslink<float> m1;
			 m1.input_l();
             m1.transLinklist();
           // m1.dis_s_mattrans();
		}
		else if(opt==3){
    sparslink<float> m1,m2;
	 m1.input_l();
	//m1.dis_s_mat();
	 m2.input_l();
	//m2.dis_s_mat();
	m1.multiLinklist(m2);;
		}
		else{
			cout<<"Invalid opertation"<<endl;
		}
}
	else{
		cout<<"Invalid operation"<<endl;
	}

	return 0;
}
