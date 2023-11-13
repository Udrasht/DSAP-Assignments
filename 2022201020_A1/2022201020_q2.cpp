#include<iostream>
using namespace std;
template <typename U>
class pal{
    private:

          int f,r,s;
          U* array;
    public:
      pal(){
           array=new U[0];
           r=-1;
           f=-1;
           s=1;

      }
     
      void push_back(U item1){
      //  cout<<r<<"   "<<f<<"value of f and r"<<endl;
        int p=0;
        if(f==r&&r==-1){
            
                array[0]=item1;
                f++;
                r++;
                s=1;
        }
        else if((r+1)%s==f){
            int s2=2*s;
            U *arraytemp=new U[s2];
            if(r<f){
                int q=f;
                while(q<s){
                    arraytemp[p]=array[q];
                    q++;
                    p++;
                }
                q=0;
                while(q<=r){
                    arraytemp[p]=array[q];
                    q++;
                    p++;
                }
                arraytemp[p]=item1;
                r=p;
            }
            else{

                int q=f;
                while(q<=r){
                    arraytemp[p]=array[q];
                    p++;
                    q++;
                }
                arraytemp[q]=item1;
                r=r+1;
            }
            delete[] array;
            array=arraytemp;
            s=s+s;
            f=0;

            
        }
        else{
            r++;
            array[r]=item1;
        }
       // cout<<r<<"   "<<f<<"value of f and r"<<endl;

      }
      void pop_back(){
       
        if(f==r&&f==-1){
            cout<<"!! Empty !!"<<endl;

        }
        else if(f==r&&f!=-1){
            f=-1;
            r=-1;
            s=1;
        }
        else if(f>r&&r==0){
            r=s-1;
            s=s-1;
        }
        else if(f<=r){
        	r=r-1;
		}
        else{
            s=s-1;
            r=r-1;
        }

      }
     
      void push_front(U item1){
        int p=0;
        if(f==r&&f==-1){
            f++;
            r++;
            s++;
            array[0]=item1;
        }
        else if((r+1)%s==f){
            int size=2*s;
              U *arraytemp=new U[size];
              arraytemp[p]=item1;
              p++;
              if(f<=r){
                int q=f;
                while(q<=r){
                    arraytemp[p]=array[q];
                    q++;
                    p++;
                }
                 r++;
               
                 s=s+s;
                 f=0;
              }
              else  {
                int q=f;
                while(q<s){
                    arraytemp[p]=array[q];
                    q++;
                    p++;
                }
                q=0;
                while(q<=r){
                    arraytemp[p]=array[q];
                    p++;q++;
                }
                r=p;
                s=s+s;
                f=0;
              }
            delete[] array;
            array=arraytemp;
                  
        }
        else if(f==0){
            f=s-1;
            array[f]=item1;
        }

        else {
            f=f-1;
            array[f]=item1;
        }

 }
      void pop_front(){
        // cout<<r<<"   "<<f<<"value of f and r"<<endl;
        if(f==r&&f==-1){
            cout<<"!! Empty !!"<<endl;

        }
        else if(f==r&&f!=-1){
        	cout<<"!! Empty !!"<<endl;
            f=-1;
            r=-1;
            s=s-1;
        }
        else if(f==s-1){
            f=0;
            s=s-1;
        }
        else{
            f=f+1;
            
        }
      

      }

      U front(){
        if(f==-1&&f==r){
           static U x;
            return x;
        }
        else{
            return array[f];
        }
      }
      
      
      U  back(){
        if(f==-1&&f==r){
            static U x;
            return x;
        }
        else{
            return array[r];
        }
      }
      bool empty(){
        if(f==-1&&f==r){
            return true;
        }
        else{
            return false;
        }
      }
      void clear(){
        delete []array;
        array=new U[s];
        
        f=-1;
        r=-1;
        s=1;
      }
      
       pal(int l,U item1){
        array=new U[l];
        int m1=0;
        f=0;r=l-1;
        while(m1<l){
            array[m1]=item1;
            m1++;

        }
           s=l;

      }
      
      
      
      U operator [](int item1){
        int pos;
        int i=0;
            if(f>r){
                pos=s-f+r+1;
                 i=(f+item1)%s;
            
            }
            else{
               
           pos=r-f+1;
           i=f+item1;
            }
            if(item1>=pos){
                cout<<" No value at :"<<item1<<endl;
          static U x;
            return x;
            }
            else{
                
                return array[i];
            }

      }
      

      void resize(int s1,U item1){
        int p=0;
         U *arraytemp=new U[s1];
         if(r<f){
            int acl=s-f+1+r+1;
            if(s1<acl){
                p=0;
                int t=f;
                f=0;
                while(p<s1){
                   arraytemp[p]=array[t];
                   p++;
                   t++;
                }
                s=s1;
                r=t-1;
               
                
            }
             if(s1>acl){
                int q=f;
                p=0;
                while(q<s){
                    arraytemp[p]=array[q];
                    p++;
                    q++;

                }
                q=0;
                while(q<=r){
                    arraytemp[p]=array[q];
                    p++;
                    q++;

                }
                
                while(p<s1){
                     arraytemp[p]=item1;
                     p++;
                }
                s=s1;
                r=p-1;
              

            }
            if(s1!=acl){
               f=0;
              delete[] array;
            array=arraytemp;
            }

         }
         else{
            int acl=r-f+1;
            if(s1<acl){
                int q=f,p=0;
                while(p<s1){
                    arraytemp[p]=array[q];
                    q++;
                    p++;
                }
                r=q-1;
                s=s1;
                }
              else  if(s1>acl){
                    p=0;
                    int q=f;
                    while(q<=r){
                        arraytemp[p]=array[q];
                        q++;
                        p++;
                    }
                    
                    while(p<s1){
                        arraytemp[p]=item1;
                        p++;
                    }
                    r=p-1;
                    s=s1;
                }
                if(s1!=acl){
                    f=0;
                    delete[] array;
                     array=arraytemp;
                     }
                    
                
            
            }

         }



      
      int size(){
      	//cout<<f<<r<<s<<endl;
        if(f==-1&&f==r){
            return 0;
        }
        if(f<=r){
            int diff=r-f+1;
            return diff;
        }
        else{
            int diff=r+1+s-f;
            return diff;
        }
      }
    

};

int main()
{
	    cout<<"Enter 1 for push_back()"<<endl;
		cout<<"Enter 2 for pop_back()"<<endl;
		cout<<"Enter 3 for push_front()"<<endl;
		cout<<"Enter 4 for pop_front()"<<endl;
		cout<<"Enter 5 for front()"<<endl;
		cout<<"Enter 6 for back()"<<endl;
		cout<<"Enter 7 for D[n]"<<endl;
		cout<<"Enter 8 for size()"<<endl;
		cout<<"Enter 9 for clear()"<<endl;
		cout<<"Enter 10 for resize()"<<endl;
		cout<<"Enter 0 for terminate the program"<<endl;
		
     pal<int> p;
     
    // pal<int> p(10,5);
	while(1){
		cout<<"Enter value according to the operation"<<endl;
		int n;
		int g;
		cin>>n;
			switch(n)
			{
			case 1: 
			       p.push_back(30);
			       break;
			case 2: 
			       p.pop_back();
			       break;
			case 3: 
			       p.push_front(80);
			       break;
			case 4: 
			       p.pop_front();
			       break;
			case 5: 
			       cout<<p.front()<<endl;
			       break;
			case 6: 
			        cout<<p.back()<<endl;
			       break;
	    	case 7: 
	    	       int num;
	    	       cin>>num;
			       cout<<p[num]<<endl;
		   case 8: 
			      cout<<p.size()<<endl;
			       break;
			case 9: 
			       p.clear();
			       break;			
			case 10: 
			        p.resize(20,89);
			        break;
			case 0:
				cout<<"Terminate"<<endl;
				g=1;
				break;
		}
		if(g==1){
			break;
		}
	}
	


}
