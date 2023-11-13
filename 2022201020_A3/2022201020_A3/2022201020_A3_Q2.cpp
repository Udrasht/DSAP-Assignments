#include <iostream>
#include <fstream>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<chrono>
using namespace std;
using namespace std::chrono;

struct pal{
	 long long int x;
	long long int y;
};

template <typename T>
class udrasht_maxheap
{
   public:
    pal arr[4005];
    long long int size=0;
    long long int i=0;
     bool empty(){
        if(size==0){
            return 1;
        }
        else{
            return 0;
        }
    }

 void hepify(long long int p){
          long long int t=p;
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
        long long int j=1;
        arr[1]=arr[i];
        size=size-1;
        i=i-1;
        long long int lc,rc;
        while(j<i){
            rc= 2*j+1;
            lc= 2*j;
            long long int y1=j;
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
string convertString(long long int val) {
    stringstream stream;
    stream<<val;
    return stream.str();
}
void combineallsortedfile(long long int ccount){
	ifstream* sarr=new ifstream[ccount];
	udrasht_maxheap<pal> heap;
	string ofn="output.txt";
	ofstream outputFile(ofn.c_str());
	for(long long int i=0;i<ccount;i++){
		long long int u=i+1;
		string sifn=convertString(u)+".txt";
		long long int a;
		sarr[i].open(sifn.c_str());
		sarr[i]>>a;
		pal val;
		val.x=a;
		val.y=i;
		heap.push(val);
	}
	while(!heap.empty()){
		pal val=heap.top();
		heap.pop();
		outputFile<<val.x<<'\n';
		long long int a;
		flush(outputFile);
		if(sarr[val.y]>>a){
			pal val1;
		   val1.x=a;
		   val1.y=val.y;
		heap.push(val1);
		
		}
		


	}
	long long int k=0;
	while(k<ccount){
		sarr[k].close();
		k++;
	}
	delete[] sarr;
	

}
int main(){
   auto s=high_resolution_clock::now();
	long long int sizeofchunk=100000;
	 ifstream inputFile("input.txt");
	 long long int index=0;
	 bool randomdata=true;
	long long int inputvalue=0;
	 long long int ccount=1;
	long long int ans=0;
	 long long int *arr=new long long int[sizeofchunk];
	 while(inputFile>>inputvalue){
	 	randomdata=true;
        arr[index]=inputvalue;
        index=index+1;
        ans++;
        if(index==sizeofchunk)
         {
         	sort(arr,arr+index);
         	string filename=convertString(ccount)+".txt";
         	ofstream outputFile(filename.c_str());
         	long long int j=0;
         	while(j<index){
         		outputFile<<arr[j]<<'\n';
         		j++;
         	}
         	outputFile.close();
         	
         	ccount=ccount+1;
         	index=0;
         	randomdata=false;

         }
	 }
	 if(randomdata==false){
	 	ccount--;
	 	delete[] arr;
	 }
	 else{
              sort(arr,arr+index);
         	string filename=convertString(ccount)+".txt";
         	ofstream outputFile(filename.c_str());
         	long long int j=0;
         	while(j<index){
         		outputFile<<arr[j]<<'\n';
         		j++;
         	}
         	outputFile.close();
         	delete[] arr;
	 }

       inputFile.close();

       combineallsortedfile(ccount);
     auto e=high_resolution_clock::now();
     auto time=duration_cast<microseconds>(e-s);
     
    cout<<sizeofchunk<<endl;
    cout<<ccount<<endl;
    double tt=time.count()/1000000;
    cout<<fixed<<setprecision(2)<<tt<<endl;

}
