#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;
 
int max_num(int a, int b){
    if(a>=b) return a;
    else return b;
}

enum{
    LEFT = -1,
    UP = 1,
    CROSS = 0
};

void LCS_LENGTH(string A, string B){

    int **arr = new int*[A.length()+1]();
    int **s_arr = new int*[A.length()+1]();

    for(int i=0;i<=A.length();i++){
        arr[i] = new int[B.length()+1]();
        s_arr[i] = new int[B.length()+1]();
    }

    int result = 0;
    
	for(int i=1;i<=A.length();i++){
        for(int j=1;j<=B.length();j++){
            if(A[i-1]==B[j-1]){
                arr[i][j] = arr[i-1][j-1]+1;
                s_arr[i][j] = CROSS;
            }
            else{
                arr[i][j] = max_num(arr[i-1][j], arr[i][j-1]);
                if(arr[i][j]==arr[i-1][j]) s_arr[i][j] = LEFT;
                else s_arr[i][j] = UP;
            }
        }
    }
    int k = A.length();
    int l = B.length();
    string answer="";
    while(arr[k][l]!=0){
        switch(s_arr[k][l]){
        case UP:
            {
                l--;
                break;
            }
        case CROSS:
            {
                answer = A[k-1]+answer;
                k--; l--;
                break;
            }
        case LEFT:
            {
                k--;
                break;
            }
        }
    }
	/*
	for(int i=0;i<=A.length();i++){
        for(int j=0;j<=B.length();j++){
            cout<<arr[i][j]<<" ";
        } 
        cout<<endl;
    }
	*/
    printf("%d\n", arr[A.length()][B.length()]) ;
    cout<<answer<<endl ;

}

int main(){
     
    string A, B ;
	char temp[30] ;
	ifstream ifile ;

	ifile.open("C:\\Users\\Administrator\\Desktop\\sample\\sample_lcs2.txt");
	ifile.getline(temp, sizeof(temp)) ;
	ifile.getline(temp, sizeof(temp)) ;
	A = temp ;
	ifile.getline(temp, sizeof(temp)) ;
	ifile.getline(temp, sizeof(temp)) ;
	B = temp ;
	ifile.close(); // ÆÄÀÏ ´Ý±â
	
	cout << A << endl;
	cout << B << endl;

	LCS_LENGTH(A,B) ;

	system("pause") ;
}