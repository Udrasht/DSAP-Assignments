#include <iostream>
#include <fstream>
#include<math.h>

using namespace std;

void engcal(int ***rgb,int **en,int H,int W){

         
   for(int i=0;i<H;i++){
   
        for(int j=0;j<W;j++){
            if(i==0&&j==0){
                int x=pow((rgb[i][j+1][0]-rgb[i][W-1][0]),2)+pow((rgb[i][j+1][1]-rgb[i][W-1][1]),2)+pow((rgb[i][j+1][2]-rgb[i][W-1][2]),2);
            int y=pow((rgb[i+1][j][0]-rgb[H-1][j][0]),2)+pow((rgb[i+1][j][1]-rgb[H-1][j][1]),2)+pow((rgb[i+1][j][2]-rgb[H-1][j][2]),2);
            en[i][j]=sqrt(x+y);
            }
            
            else if(i==0&&j!=0&&j!=W-1){
                int x=pow((rgb[i][j+1][0]-rgb[i][j-1][0]),2)+pow((rgb[i][j+1][1]-rgb[i][j-1][1]),2)+pow((rgb[i][j+1][2]-rgb[i][j-1][2]),2);
                int y=pow((rgb[i+1][j][0]-rgb[H-1][j][0]),2)+pow((rgb[i+1][j][1]-rgb[H-1][j][1]),2)+pow((rgb[i+1][j][2]-rgb[H-1][j][2]),2);
            en[i][j]=sqrt(x+y);
            }
            else if(j==0&&i!=0&&i!=H-1){
              int x=pow((rgb[i][j+1][0]-rgb[i][W-1][0]),2)+pow((rgb[i][j+1][1]-rgb[i][W-1][1]),2)+pow((rgb[i][j+1][2]-rgb[i][W-1][2]),2);
               int y=pow((rgb[i+1][j][0]-rgb[i-1][j][0]),2)+pow((rgb[i+1][j][1]-rgb[i-1][j][1]),2)+pow((rgb[i+1][j][2]-rgb[i-1][j][2]),2);
            en[i][j]=sqrt(x+y);
            }
            else if(i==H-1&&j==W-1){
                int x=pow((rgb[i][0][0]-rgb[i][j-1][0]),2)+pow((rgb[i][0][1]-rgb[i][j-1][1]),2)+pow((rgb[i][0][2]-rgb[i][j-1][2]),2);
                int y=pow((rgb[0][j][0]-rgb[i-1][j][0]),2)+pow((rgb[0][j][1]-rgb[i-1][j][1]),2)+pow((rgb[0][j][2]-rgb[i-1][j][2]),2);
                en[i][j]=sqrt(x+y);
            }
             else if(i==H-1&&j!=W-1&&j!=0){
                int x=pow((rgb[i][j+1][0]-rgb[i][j-1][0]),2)+pow((rgb[i][j+1][1]-rgb[i][j-1][1]),2)+pow((rgb[i][j+1][2]-rgb[i][j-1][2]),2);
                 int y=pow((rgb[0][j][0]-rgb[i-1][j][0]),2)+pow((rgb[0][j][1]-rgb[i-1][j][1]),2)+pow((rgb[0][j][2]-rgb[i-1][j][2]),2);
            en[i][j]=sqrt(x+y);
            }
            else if(i!=H-1&&j==W-1&&i!=0){
           int x=pow((rgb[i][0][0]-rgb[i][j-1][0]),2)+pow((rgb[i][0][1]-rgb[i][j-1][1]),2)+pow((rgb[i][0][2]-rgb[i][j-1][2]),2);
            int y=pow((rgb[i+1][j][0]-rgb[i-1][j][0]),2)+pow((rgb[i+1][j][1]-rgb[i-1][j][1]),2)+pow((rgb[i+1][j][2]-rgb[i-1][j][2]),2);
            en[i][j]=sqrt(x+y);
            }
             else if(i==H-1&&j==0){
               int x=pow((rgb[i][j+1][0]-rgb[i][W-1][0]),2)+pow((rgb[i][j+1][1]-rgb[i][W-1][1]),2)+pow((rgb[i][j+1][2]-rgb[i][W-1][2]),2);
            int y=pow((rgb[0][j][0]-rgb[i-1][j][0]),2)+pow((rgb[0][j][1]-rgb[i-1][j][1]),2)+pow((rgb[0][j][2]-rgb[i-1][j][2]),2);
            en[i][j]=sqrt(x+y);


             }
               else if(i==0&&j==W-1){
               
                 int x=pow((rgb[i][0][0]-rgb[i][j-1][0]),2)+pow((rgb[i][0][1]-rgb[i][j-1][1]),2)+pow((rgb[i][0][2]-rgb[i][j-1][2]),2);
            int y=pow((rgb[i+1][j][0]-rgb[H-1][j][0]),2)+pow((rgb[i+1][j][1]-rgb[H-1][j][1]),2)+pow((rgb[i+1][j][2]-rgb[H-1][j][2]),2);
            en[i][j]=sqrt(x+y);

             }
             
            else if(i!=0&&j!=0&&i!=H-1&&j!=W-1){
            int x=pow((rgb[i][j+1][0]-rgb[i][j-1][0]),2)+pow((rgb[i][j+1][1]-rgb[i][j-1][1]),2)+pow((rgb[i][j+1][2]-rgb[i][j-1][2]),2);
            int y=pow((rgb[i+1][j][0]-rgb[i-1][j][0]),2)+pow((rgb[i+1][j][1]-rgb[i-1][j][1]),2)+pow((rgb[i+1][j][2]-rgb[i-1][j][2]),2);
            en[i][j]=sqrt(x+y);}
            
        
        }
       
    }



}

void versem(int ***rgb, int H, int W){

 int **en;
 en =new int *[H];
 for(int i=0;i<H;i++){
    en[i] = new int[W];
 }
  engcal(rgb,en,H,W);
   
  
    for(int i=1;i<H;i++){
     
        for(int j=0;j<W;j++){
          if(j==0){
            en[i][j]=en[i][j]+min(en[i-1][j],en[i-1][j+1]);
          }
          else if(j==W-1){
            en[i][j]=en[i][j]+min(en[i-1][j],en[i-1][j-1]);
          }
          else {en[i][j]=en[i][j]+min(en[i-1][j+1],min(en[i-1][j],en[i-1][j-1]));
        }
        
    }
    

 
         
    }


    
    
    int a=en[H-1][0];   
    int minindex=0;
    for(int i=1;i<W;i++){
               if(en[H-1][i]<a){
                 a=en[H-1][i];
                 minindex=i;
               }
    }
  

    for(int i=H-1;i>=0;i--){
        for(int j=minindex;j<W-1;j++){
            rgb[i][j]=rgb[i][j+1];
        }
        if(i>0){
        if(minindex==0){
            int minsem=en[i-1][minindex];
            minindex=minindex;
            if(minsem>en[i-1][minindex+1]){
                 minsem=en[i-1][minindex+1];
                minindex=minindex+1;
            }

        }

       else if(minindex==W-1){
            int minsem=en[i-1][minindex];
            minindex=minindex;
            if(minsem>en[i-1][minindex-1]){
                 minsem=en[i-1][minindex-1];
                minindex=minindex-1;
        }
        }
        else{
              int minsem=en[i-1][minindex];
               minindex=minindex;
               if(minsem>en[i-1][minindex-1]){
                minsem=en[i-1][minindex-1];
                minindex=minindex-1;
        }
        if(minsem>en[i-1][minindex+1]){
                minsem=en[i-1][minindex+1];
                minindex=minindex+1;
        }

        }
    }

    }
    
    delete[] en;
    W=W-1;
   

}

// horsem find the the horizontal seam and reduce the width
void horsem(int ***rgb, int H, int W){

int **en;
 en =new int *[H];
 for(int i=0;i<H;i++){
    en[i] = new int[W];
 }
  engcal(rgb,en,H,W);


     for(int j=1;j<W;j++){
        for(int i=0;i<H;i++){
           if(i==0){
            en[i][j]=en[i][j]+min(en[i][j-1],en[i+1][j-1]);
          }
          else if(i==H-1){
            en[i][j]=en[i][j]+min(en[i][j-1],en[i-1][j-1]);
          }
          else {en[i][j]=en[i][j]+min(en[i][j-1],min(en[i+1][j-1],en[i-1][j-1]));
        }
        }
     }
    

     int a=en[0][W-1];   
     int minindex=0;
    for(int i=1;i<H;i++){
               if(en[i][W-1]<a){
                 a=en[i][W-1];
                 minindex=i;
               }
    }

    for(int i=W-1;i>=0;i--){
        for(int j=minindex;j<H-1;j++){
            rgb[j][i]=rgb[j+1][i];
        }
        if(i>0){
        if(minindex==0){
            int minsem=en[minindex][i-1];
            minindex=minindex;
            if(minsem>en[minindex+1][i-1]){
                 minsem=en[minindex+1][i-1];
                minindex=minindex+1;
            }

        }

       else if(minindex==H-1){
            int minsem=en[minindex][i-1];
            minindex=minindex;
            if(minsem>en[minindex-1][i-1]){
                 minsem=en[minindex-1][i-1];
                minindex=minindex-1;
        }
        }
        else{
              int minsem=en[minindex][i-1];
               minindex=minindex;
               if(minsem>en[minindex-1][i-1]){
                minsem=en[minindex-1][i-1];
                minindex=minindex-1;
        }
        if(minsem>en[minindex+1][i-1]){
                minsem=en[minindex+1][i-1];
                minindex=minindex+1;
        }

        }
    }

    }

    delete[] en;
    H=H-1;


}


void solve(int ***rgb, int H, int W, int C, int H_, int W_, int C_) {
    // We've provided you the driver.py and main.cpp for your convinience
    // Please go through them and understand the file handling and input/output format
    // Feel free to experiment on your own

    // can access the array using rgb[i][j][k] like a regular 3D array

    // Write your code here
    int dum=W-W_;
    
  for(int k=0;k<dum;k++){
    versem(rgb,H,W);
    W=W-1;
     }
    ;
    int dum1=H-H_;
     for(int k=0;k<dum1;k++){

        horsem(rgb,H,W);
        H=H-1;
     }

    
}

int main() {
    string ip_dir = "./data/input/";
    string ip_file = "rgb_in.txt";
    ifstream fin(ip_dir + ip_file);

    int H, W, C;
    fin >> H >> W >> C;

    int ***rgb;
    rgb = new int **[H];
    for(int i = 0; i < H; ++i) {
        rgb[i] = new int *[W];
        for(int j = 0; j < W; ++j) {
            rgb[i][j] = new int[C];
            for(int k = 0; k < C; ++k)
                fin >> rgb[i][j][k];
        }
    }
    fin.close();

    int H_, W_, C_;
    cout << "Enter new value for H (must be less than " << H << "): ";
    cin >> H_;
    cout << "Enter new value for W (must be less than " << W << "): ";
    cin >> W_;
    cout << '\n';
    C_ = C;

    solve(rgb, H, W, C, H_, W_, C_);

    string op_dir = "./data/output/";
    string op_file = "rgb_out.txt";
    ofstream fout(op_dir + op_file);
    
    fout << H_ << " " << W_ << " " << C_ << endl;
    for(int i = 0; i < H_; ++i) {
        for(int j = 0; j < W_; ++j) {
            for(int k = 0; k < C_; ++k) {
                fout << rgb[i][j][k] << " ";
            }
        }
        fout << '\n';
    }
    fout.close();

    return 0;
}