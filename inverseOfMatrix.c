#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

float inputmat(float mat[N][N],int n);
float inversemat1(float mat[N][N],float birim[N][N],int n);
float printmat(float mat[N][N],int n);
float outbirim(float mat[N][N],int n);
float inversemat2(float mat[N][N],float birim[N][N],int n);
float inversemat3(float mat[N][N],float birim[N][N],int n);
int main () {  
 
	 
	int NumTerm, i ;
	float root,root1,root2;
	float f1,f2;
	float tolerance;
	float coef[N],expo[N];

	float h,k;
	float integral1, integral2, integral ;
	float myMat[N][N];
		float birim[N][N];
		int n;
		printf("enter the number of rows and columns: ");scanf("%d", &n);
		inputmat(myMat,n);
		outbirim(birim,n);
	
		inversemat1(myMat,birim,n);
		inversemat2(myMat,birim,n);
		inversemat3(myMat,birim,n);
	
		printf("\n\n\nInverse of Matrix is: \n");
		printmat(birim,n);
	return 0;
}



float inputmat(float mat[N][N],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("[%d][%d] :  ", i+1,j+1);scanf("%f", &mat[i][j]);
		}
	}
}
float printmat(float mat[N][N],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%.4f ", mat[i][j]);
		}
		printf("\n");
	}
}
float inversemat1(float mat[N][N],float birim[N][N],int n){
	int i,j,k;
	float factor;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			factor=-(mat[i][i]/mat[j][i]);
			for(k=0;k<n;k++){
				mat[j][k]=mat[j][k]*factor+mat[i][k];
				birim[j][k]=birim[j][k]*factor+birim[i][k];
			}
		}
	}
	
}
float outbirim(float mat[N][N],int n){
	int i,j;
	for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
    		if(i==j){
    			mat[i][j]=1;
    		} else{
    			mat[i][j]=0;
    		}
    	}
    	
    }
	
}
float inversemat2(float mat[N][N],float birim[N][N],int n){
	int i,j;
	float factor;
	
	for(i=0;i<n;i++){
		factor=mat[i][i];
		
		for(j=0;j<n;j++){
			mat[i][j]=mat[i][j]/factor;
			birim[i][j]=birim[i][j]/factor;
		}
	}
}
float inversemat3(float mat[N][N],float birim[N][N],int n){
	int i,j,k;
	float factor;
	for(i=n-1;i>0;i--){
		for(j=i-1;j>=0;j--){
			factor=-(mat[j][i]/mat[i][i]);
			for(k=0;k<n;k++){
				mat[j][k]=mat[j][k]+mat[i][k]*factor;
				birim[j][k]=birim[j][k]+birim[i][k]*factor;
			}
		}
	}
}
