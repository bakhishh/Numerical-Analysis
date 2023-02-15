#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
long factorial(int n) ;
int main () {  
 
	 
	int NumTerm ;
	float root,root1,root2;
	float f1,f2;
	float tolerance;
	float coef[N],expo[N];


	float integral1, integral2, integral ;
 

	int maxyeri[N]={0};
	float result[N];
	float prev_result[N];
	float a[N][N];
	float a_prev[N][N];
	double value[N][N],x0,h,n,difference,x,res=0,interpol;
	int i,k,j,flag=1;
	printf("enter the starting value of x: ");scanf("%lf",&x0);
	printf("enter h: ");scanf("%lf",&h);
	printf("enter n: ");scanf("%lf",&n);
	printf("enter x: ");scanf("%lf",&x);
	
	interpol=(x-x0)/h;
	
	for(i=0;i<n;i++){
		 value[i][0]= x0+i*h;
	}
	for(i=0;i<n;i++){
		printf("\nf(%lf)= ",x0+i*h);scanf("%lf",&value[i][1]);
	}
	k=n;
	j=2;
	do{
		for(i=0;i<k-1;i++){
			value[i][j] = value[i+1][j-1]-value[i][j-1];
		}
		k--;
		j++;
	}while((value[0][j-1]-value[1][j-1])!= 0);
	
	for(i=1;i<j-1;i++){
		res =res+ (factorial(interpol)/(factorial(interpol-i)*factorial(i)))*value[0][i+1];
	}
	res =res+ value[0][1];
	printf("\nf(%lf)= %lf",x,res);
	return 0;
}

long factorial(int n)  
{  
  if (n == 0)  
    return 1;  
  else  
    return(n * factorial(n-1));  
}


