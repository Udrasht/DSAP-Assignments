#include<iostream>
#include<map>
using namespace std;
class Node{
	   	public:
	   	Node* left;
	   	
	   	int frq;
	   	Node* right;
	   	int key;
	   	int value;
	   	Node(int k,int v){
	   	
	   	   this->key = k;
	   	
            this->value = v;  
			frq=1; 
		   }
	   };
class my_lfu{
	public:

class List {
	
        Node* head;
        int cur_cap;
        Node* tail;
        
    public:

        List(){
        	cur_cap = 0;
            head = new Node(0, 0);
            
            tail = new Node(0, 0);
            tail->left = head;
            head->right = tail;
            
            
        }
        
        
        
       
         bool empty(){
            return (cur_cap<=0);
        }
        void remove_node(Node* node) {
            
            if(cur_cap!=0){
			
            cur_cap=cur_cap-1;
            Node* temp=node;
            node->left->right = node->right;
            node->right->left = temp->left;
        }
         
        }
        
        void add_front(Node* node) {
            cur_cap=cur_cap+1;
           
          head->right->left=node;
          node->right=head->right;
          head->right=node;
          node->left=head;
        
        }
         Node* remove_start()
		 {

            
            cur_cap=cur_cap-1;
            Node* temp = head->right;
            head->right->right->left=head;
            head->right=head->right->right;
            //cout<<"f";
            return temp;
            
        }
        
        void add_back(Node* node) {
           cur_cap=cur_cap+1;
           //cout<<"him";
           tail->left->right=node;
           node->left=tail->left;
           tail->left=node;
           node->right=tail;
           
        }
    };

    map<int, Node*> map_occ;
    
    int min_freq;
    int max_cap;
    map<int, List> freq;
    int cur_cap;
    
    my_lfu(int cap){
    	cur_cap=0;
    	max_cap=cap;
	}
	 int get(int key)
	 {        
       
        if(max_cap!=0){
		
        if (map_occ.find(key)!= map_occ.end())
		 {
        Node* node;
		node=map_occ[key];
        int v=node->value;
        int f=node->frq;
        List* list1=&freq[f];
        (*list1).remove_node(node);
        if((*list1).empty()){
        	freq.erase(f);
        	if(f==min_freq){
        		min_freq=min_freq+1;
			}
		}
		node->frq=node->frq+1;
		int h=f+1;
		List* list2=&freq[h];
		(*list2).add_back(node);
        return v;
         }
	    else
		{
            return -1;
        }
	}
	else
        {
            return -1;
		}
	}
	void set(int k,int val){
		if(max_cap==0){
			return;
		}
		if(map_occ.find(k)!=map_occ.end()){
			//cout<<"b";
			Node * node;
			node=map_occ[k];
			node->value=val;
			 int f=node->frq;
        List* list1=&freq[f];
        (*list1).remove_node(node);
        if((*list1).empty()){
        	freq.erase(f);
        	if(f==min_freq){
        		min_freq=min_freq+1;
			}
		}
		node->frq=node->frq+1;
		int h=f+1;
		List* list2=&freq[h];
		(*list2).add_back(node);
			return;
		}
		
		if(max_cap<=cur_cap){
		
			
			int f=min_freq;
			cur_cap=cur_cap-1;
			List *list1=&freq[f];	
			//cout<<"c";
			Node* node=(*list1).remove_start();
		
			int temp=node->key;
				
			map_occ.erase(temp);
		
			if((*list1).empty()){
					
				freq.erase(f);
				
			}
			
		}
		Node* demo=new Node(k,val);
		map_occ[k]=demo;
		freq[1].add_back(demo);
		min_freq=1;
		cur_cap=cur_cap+1;
	}

};

int main(){
	int max_cap;
	
	cin>>max_cap;
	int no_queries;
	cin>>no_queries;
	my_lfu* lfu=new my_lfu(max_cap);
	for(int i=0;i<no_queries;i++){
		int opt;
	//	cout<<" Enter 1 for get() 2 for set() :";
		cin>>opt;
		if(opt==1){
			int k;
			cin>>k;
			int val_at_k;
			
		  val_at_k=lfu->get(k);
		  cout<<val_at_k<<endl;
			
		}
		else if(opt==2){
			int k;
			cin>>k;
			int va;
			cin>>va;
			lfu->set(k,va);
			
		}
		else{
			cout<<"Invalid Enyry"<<endl;
		}
	}
}
