#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
float ResultFunc(float rootf,int length,float coef1[N], float expo1[N]);
float DerivativeFunc(float rootf,int length,float coef1[N], float expo1[N]);
float inputmat(float mat[N][N],int n);
float inversemat1(float mat[N][N],float birim[N][N],int n);
float printmat(float mat[N][N],int n);
float outbirim(float mat[N][N],int n);
float inversemat2(float mat[N][N],float birim[N][N],int n);
float inversemat3(float mat[N][N],float birim[N][N],int n);
int main () {  
 
	 
	int NumTerm ;
	float root,root1,root2;
	float f1,f2;
	float tolerance;
	float coef[N],expo[N];

	float h;
	float integral1, integral2, integral ;
	int i,j,k,n; 
	float a[N][N], res[N], ratio;
	printf("enter the number of unknowns: ");
	scanf("%d", &n);
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
		  	if(j==n+1){
		  			printf("enter the result of %d.equation: ",i);scanf("%f", &a[i][j]);
		  		}
			   else{
			   		printf("enter the coefficent of the %d.term  of %d.equation: ",j,i);
			   		scanf("%f", &a[i][j]);
			   }
		  }
	 }
	 for(i=1;i<=n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   printf("Mathematical Error!");
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = a[j][i]/a[i][i];
			   
			   for(k=1;k<=n+1;k++)
			   {
			  		a[j][k] = a[j][k]-ratio*a[i][k];
			   }
		  }
	 }
	 res[n] = a[n][n+1]/a[n][n];
	
	 for(i=n-1;i>=1;i--)
	 {
		  res[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		res[i] = res[i] - a[i][j]*res[j];
		  }
		  res[i] = res[i]/a[i][i];
	 }
	 for(i=1;i<=n;i++)
	 {
	  	printf("%0.3f\n",res[i]);
	 }
	return 0;
}


