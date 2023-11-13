#include<iostream>
using namespace std;


int presedence(char ltr){
    if(ltr=='x')
    return 10;
    if(ltr=='+'||ltr=='-')
    return 5;
    
    return 0;
}
// sumres is used to find the sum between two values
string sumres(string op1, string op2)
{
    int c= 0;
	string ans = "";
	if (op1.length()>op2.length())
	{
	string dstr=op1;
	op1=op2;
	op2=dstr;
	}
	int l2 = op2.size();
	int l1 = op1.size();
      
      
	int i=l1-1;
	while(i>=0)
	{
		
		int s = (op1[i]-'0') +(op2[i+l2 - l1]-'0');
		s=s+c;
		ans.push_back(s%10+'0');
		c = s/10;
		i--;
	}

	i=l2-l1;
	i--;
	while(i>=0)
	{
		int s = (op2[i]-'0');
		s=s+c;
		ans.push_back(s%10+'0');
		c = s/10;
		i--;
	}

	if (c>0)
	{
		ans.push_back(c+'0');
    }
   int ansl=ans.length();
    string res="";
    i=ansl-1;
    while(i>=0)
	{
     res=res+ans[i];
     i--;
    }

	return res;
}

// smaller is used to is op1 is small or not
int smaller(string op1, string op2)
{
	int l2 = op2.length();
	int l1 = op1.length();
    
     if (l2 < l1)
		return 0;
   else	if (l1<l2)
		return 1;
	
	else{
	
        int x=0;
	while(x < l1) {
		if (op1[x] < op2[x])
		{
			return 1;}
		else if (op1[x]>op2[x]){
		
			return 0;}
			x++;
		}
	
	return 0;}
}

// subres is used to find the sub between two number
string subres(string op1,string op2)
{
    int br=0;
      string ans= "";
	if(smaller(op1,op2)){
	string dstr=op1;
	op1=op2;
	op2=dstr;
		
		}
     
	int l2=op2.length();
	int l1=op1.length(); 
    int k=l2-1;
	while(k>=0)
	{
	
		
	int diff=((op1[k+l1-l2]-'0')-(op2[k]-'0'));
    diff=diff-br;
	if(diff>=0)
	{		
	br= 0;
	}
	else
	{
	    diff=diff+10;
		br= 1;
            
	}

     ans.push_back(diff+'0');
		k--;
	}
      int y=l1-l2-1;
      
      int i=y;
     
       while(i>=0) {
       	
		if(op1[i]=='0'){
		if(br!=0){
			ans.push_back('9');
			i--;
			continue;
		}}
		
		int diff=(op1[i]-'0');
		diff=diff-br;
		if (i>0||diff>0) 
		{
		
		ans.push_back(diff+'0');
		}
		     i--;
		    br=0;
		   
	}

	int ans1=ans.length();
	
    string res="";
    
    for(int i=ans1-1;i>=0;i--)
	{
        res=res+ans[i];      // it is used to reverse the string
    }
    
    string res2="";
    
    int t=0;
    
    for(int i=0;i<ans1;i++)
	{
    	if(res[i]!='0'){
    		t++;              // it is used to remove the leading 0000 for example 0003=3
		}
		if(t!=0)
		{
			res2=res2+res[i];
		}
    	
	}

	return res2;
}


// mulres is used to find the multiplication of two large number

string mulres(string op1,string op2){
    int l1=op1.size();
    int l2=op2.size();
    string ans="";
    if(op1=="0"||op2=="0"){
        ans="0";                      // if both any one of them is 0 so result is also zero
    }
    else
	{
        int multi[l1+l2];             //  create the 1D array to store the result
        for(int i=0;i<l1+l2;i++){
            multi[i]=0;              // initilize the array wirh all value zero
        }
        for(int m1=l1-1;m1>=0;--m1){
            for(int m2=l2-1;m2>=0;--m2){
                multi[m1+m2+1]=multi[m1+m2+1]+(op1[m1]-'0')*(op2[m2]-'0');
                multi[m1+m2]=multi[m1+m2]+multi[m1+m2+1]/10;
                multi[m1+m2+1]=multi[m1+m2+1]%10;



            }
        }
        int m1=0;
        while(m1<l1+l2&&multi[m1]==0)
		{
            m1=m1+1;
        }
        while(m1<l1+l2)
		{
            ans.push_back(multi[m1++]+'0');
        }

    }
    return ans;
}


// smallnum is use to find the mod of number 
//smallnum swap the num2 and num1 if num1<num2


void smallnum(string &num1,string &num2)
{
   int l1=num1.size();
   int l2=num2.size();
   if(l1<l2)
    {
     string small=num1;
     num1=num2;
     num2=small;
	 }
  else if(l2==l1)
  {
      for(int i=0;i<l1;i++)
	  {
         if(num1[i]<num2[i])
	      {
            string small=num1;
            num1=num2;
            num2=small;
             break;
	      }
         else if(num1[i]>num2[i])
	    {
          break;

         }


      } 

  }
}

//module is use to find num1%num2

string module(string num1,string num2)
{
   string a="2";
    string num3=num2;
    
    while(smaller(num3,num1))
	{
	num3=mulres(num2,a);
	a=sumres(a,"1");
	}
	if(num3==num1)
	{
	return "0";    // it retuen 0 when num1%num2
	}
	string num4=subres(num3,num2);
	string ans=subres(num1,num4);
	return ans;     // it return num1%num2
}

//gcdbet is used to find the gcd by using euclidean algorithm

string gcdbet(string num1,string num2)
{
   if(num2=="0")
  {
	return num1;
  }
  string mod1=module(num1,num2);     
  return gcdbet(num2,mod1);         // module is use to find the num1%num2 


}

//first is used to find the first operation for example 2+5x3-2

void first(){
    string inp;
    cout<<"Enter  valid input: ";
    cin>>inp;
    int ln=inp.size();
    int tokn=0;
    for(int i=0;i<ln-1;i++){
        if((inp[i]>='0'&&inp[i]<='9')||inp[i]=='+'||inp[i]=='-'||inp[i]=='x'){
         
        }
           else{
            
            tokn++;
            break;
        }
        
        if(inp[ln-1]=='+'||inp[ln-1]=='-'||inp[ln-1]=='x'||inp[0]=='+'||inp[0]=='-'||inp[0]=='x'){
            tokn++;
            break;
            }
            if((inp[i]=='+'||inp[i]=='-'||inp[i]=='x')&&(inp[i+1]=='+'||inp[i+1]=='-'||inp[i+1]=='x')){
              tokn++;
            break;
            }

        }
        if(tokn!=0){
            cout<<"!! Invalid Input !!"<<endl;
        }
        else{
            string opr[5000];
            char opt[5000];
           
            int top=-1;
            int topo=-1;
            string str1="";
            for(int i=0;i<ln;i++){
                if(inp[i]!='+'&&inp[i]!='-'&&inp[i]!='x'&&i!=ln-1)
				{
                    str1=str1+inp[i];
                
                  
                }
                else{
                      
                    if(i==ln-1)
					{
                        str1=str1+inp[i];
                    }
                     
                    top++;
                    //cout<<top<<"maxv";
                    opr[top]=str1;
                    //cout<<opr[top]<<endl;
                    if(topo==-1){
                        
                        topo++;
                        opt[topo]=inp[i];
                        //cout<<opt[topo]<<endl;
                    }
                    
                    else {
                         
                        while(1){
                        if(topo==-1||presedence(inp[i])>presedence(opt[topo])){
                            topo++;
                                opt[topo]=inp[i];
                                break;
                        }
                        else{
                            string a=opr[top];
                            
                            top--;
                            string b=opr[top];
                            
                            top--;
                            char c=opt[topo];
                            topo--;
                            string f;
                            if(c=='+'){
                                f=sumres(a,b);
                                 //cout<<f<<"f"<<endl;
                                //topo--;
                            }
                            else if(c=='-'){
                                f=subres(a,b);
                                //topo--;
                            }
                            else if(c=='x'){
                                f=mulres(a,b);
                                //topo--;
                            }
    
                            top++;
                            opr[top]=f;
                            if(i==ln-1&&top==0){
                                break;
                            }
    
                   }
           if(i==ln-1&&top==0)
                  	{
                                break;
                            }

                        }
                        
                    }
                
                   str1="";
                    }
                  }
                  int pal=opr[top].length();
                  if(pal==0){
                  	cout<<pal<<endl;
				  }
				  else{
				  
              cout<<opr[top]<<endl;}
              top--;

            }

}
    
// exp is used to find the base^n;

void exp()
{
string base;
cout<<"Enter two number :";
long long int  n;
cin>>base;
cin>>n;

string str=base;
if(n==0)
{
    cout<<1<<endl;
}
else if(n==1)
{
    cout<<base<<endl;
}
else
{
    string p=base;
for(int i=2;i<=n;i++){
      p=mulres(p,base);
      //cout<<p<<endl;
}
cout<<base<<"^("<<n<<") :  "<<p<<endl;
}
}

//gcdof is used to find the GCD between num1 and num2 
void gcdof(){
cout<<"Enter the two number"<<endl;
string num1,num2;
cin>>num1>>num2;
smallnum(num1,num2);
string ans= gcdbet(num1,num2);

cout<<"GCD of "<<num1<<" and "<<num2<<" is : "<<ans<<endl;

}

// factof is used to find the factorial of num
void factof()
{
    string num;
    cout<<"Enter number to find the Factorial:";
    cin>>num;
    if(num=="0"||num=="1"){
        cout<<1<<endl;       // when num=1,0  factorial is 1;
    }
    else{   
        
        
        string temp=subres(num,"1");
       
        while(1)          
		{
            num=mulres(num,temp);
            temp=subres(temp,"1");
          //  cout<<temp<<endl;
            if(temp=="1"||temp=="0"){
                break;
            }

        }
        cout<<"The Factorial is: "<<num<<endl;
    }

}
int main()
{
	while(1){
	
    
    cout<<"Enter 1 for Addition, Subtraction & Multiplication"<<endl;
    cout<<"Enter 2 for Exponentiation"<<endl;
    cout<<"Enter 3 for GCD"<<endl;
    cout<<"Enter 4 for Factorial"<<endl;
    cout<<"Enter the number from 1 to 4:";
    int t;
    cin>>t;
    if(t==1){
     first();
    }
   else if(t==2){
        exp();

    }
   else if(t==3){
        gcdof();
    }
    else if(t==4){
      factof();
    }
   else{
        cout<<"please enter valid number"<<endl;
        break;
    }
	}
    
    return 0;

} 
