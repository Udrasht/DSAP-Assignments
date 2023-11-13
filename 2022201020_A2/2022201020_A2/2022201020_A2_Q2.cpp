#include<iostream>
using namespace std;
    struct pal{
        long long int x;
        int y;
    };
template <typename T>
class udrasht_maxheap
{
   public:
    pal arr[4005];
    int size=0;
    int i=0;
     bool empty(){
        if(size==0){
            return 1;
        }
        else{
            return 0;
        }
    }

 void hepify(int p){
          int t=p;
        while(t!=1&&arr[t].x>arr[t/2].x){
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
            if(arr[lc].x>arr[y1].x&&lc<=i){
               //  pal temp=arr[j];
           // arr[j]=arr[lc];
           // arr[lc]=temp;
                y1= lc;
            }
            if(rc<=i&&arr[rc].x>arr[y1].x ){
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
      /*  if(empty()){
            exit(1);
        }
        else{*/
            return arr[1];
       // }
    }

};
    
    
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  {
    int lc=2*i+1;
    int rc=2*i+2;
    int lar=i;
    if(lc<n&&arr[lar]<arr[lc]){
        lar=lc;
    }
     if(rc<n&&arr[lar]<arr[rc]){
        lar=rc;
    }
    if(i!=lar){
        swap(arr[lar],arr[i]);
        heapify(arr,n,lar);
    }
      // Your Code Here
    }


    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=(n/2)-1;i>=0;i--){
            heapify(arr,n,i);
        }
    // Your Code Here
    }

    
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        n=n-1;
        while(n>=1){
            swap(arr[0],arr[n]);
            
            heapify(arr,n,0);
            n=n-1;
        }}


int main(){
	int n;
	cin>>n;
	int k;
	cin>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
         long long int max_sum=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                max_sum=max_sum+arr[i];
            }
            else{
                arr[i]=arr[i]*(-1);
            }
        }
         long long int k_sum_arr[k];
        int k_n=0;
        k_sum_arr[k_n]=max_sum;
        udrasht_maxheap<pal> max_seq;
        heapSort(arr,n);
        pal qa;
        qa.x=max_sum-arr[0];
        qa.y=0;
        max_seq.push(qa);
       // int k_n=k_sum_arr.size();
        k_n=k_n+1;
        
       long long sum;
        int i;
        while(k_n<k){
            
           pal ele=max_seq.top();
            max_seq.pop();
            sum=ele.x;
         // cout<<"sum  "<<sum<<endl;
              k_sum_arr[k_n]=sum;
             k_n=k_n+1;
            i=ele.y;
             int j=i+1;
            int l=n;
            if(j<l){
                sum=sum-arr[i+1];
                pal qb;
                qb.x=sum;
                qb.y=i+1;
                max_seq.push(qb);
                sum=sum+arr[i];
                qb.x=sum;
                qb.y=i+1;
                max_seq.push(qb);
                
            }
           // k_n=k_sum_arr.size();
            
         }
        
            
      for(int m=0;m<k;m++){
          cout<<k_sum_arr[m]<<" ";
      }
      cout<<endl;
}
