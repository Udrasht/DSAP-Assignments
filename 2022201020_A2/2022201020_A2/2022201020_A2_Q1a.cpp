#include<iostream>
#include<map>
using namespace std;

 class node{
	   	public:
	   	node* left;
	   	
	   	int key;
	   	node* right;
	   	int value;
	   	node(int k,int v){
	   		this->value = v;   
	   	    this->key = k;
            
		   }
	   };
class my_lru{
	public:
	   
	   map<int,node*> map_occ;
	  
	   	node* head;
	   int 	cach_size;
	   node* tail;
	my_lru(int n){
	head=new node(0,0);
	 tail=new node(0,0);
		head->left=NULL;
		head->right=tail;
		tail->left=head;
		tail->right=NULL;
		cach_size=n;
				
		}
		
		
		
		void add_node(node* new_node){
			node* temp=head->right;
			head->right=new_node;
			new_node->right=temp;
			new_node->right->left=new_node;
			new_node->left=head;
				}
		void delete_node(node* del_node)
			{
					del_node->right->left=del_node->left;
					del_node->left->right=del_node->right;
			
				//	cout<<"hi";
					
			}
    int get(int key_val){
    	if(map_occ.find(key_val)!=map_occ.end()){
    	//	cout<<"kkkkk"<<endl;
    		node* temp;
    		temp=map_occ[key_val];
    		int value_at_key=temp->value;
    		map_occ.erase(key_val);
    		delete_node(temp);
    		add_node(temp);
    		map_occ[key_val]=head->right;
    		return value_at_key;
		}
		else{
			return -1;
		}
	}
	void set(int key_val,int new_value){
			if(map_occ.find(key_val)!=map_occ.end()){
				node* temp;
				temp=map_occ[key_val];
				map_occ.erase(key_val);
				delete_node(temp);
				 node* temp1=new node(-1,-1);
			     	temp1->key=key_val;
					temp1->value=new_value;
				add_node(temp1);
				map_occ[key_val]=head->right;
				
			}
			else{
				if(map_occ.size()>=cach_size){
					 map_occ.erase(tail->left->key);
					delete_node(tail->left);
					
					 node* temp=new node(-1,-1);
					 temp->key=key_val;
					 temp->value=new_value;
					 
					
					add_node(temp);
					map_occ[key_val]=head->right;
				
					
				}
				else{
					 node* temp=new node(-1,-1);
					temp->key=key_val;
					temp->value=new_value;
						add_node(temp);
						map_occ[key_val]=temp;
				}
			}
	}
/*	void shoe(){
		node* temp=head;
		while(temp!=NULL){
			cout<<temp->key<<"->"<<temp->value<<endl;
			temp=temp->right;
		}
	}*/				
				
};




int main(){
	int max_cap;
	
	cin>>max_cap;
	int no_queries;
	cin>>no_queries;
	my_lru* lru=new my_lru(max_cap);
	for(int i=0;i<no_queries;i++){
		int opt;
	//	cout<<" Enter 1 for get() 2 for set() :";
		cin>>opt;
		if(opt==1){
			int k;
			cin>>k;
			int val_at_k;
			
		  val_at_k=lru->get(k);
		  cout<<val_at_k<<endl;
			
		}
		else if(opt==2){
			int k;
			cin>>k;
			int va;
			cin>>va;
			lru->set(k,va);
			
		}
		else{
			cout<<"Invalid Enyry"<<endl;
		}
	}
}
