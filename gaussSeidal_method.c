#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10


int main () {  
 
	 
	int NumTerm ;
	float root,root1,root2;
	float f1,f2;
	float tolerance;
	float coef[N],expo[N];


	float integral1, integral2, integral ;
 

	int i,j,k;
		int n;
	int maxyeri[N]={0};
	float result[N];
	float prev_result[N];
	float a[N][N];
	float a_prev[N][N];
	printf("enter the number of unknowns: ");
	scanf("%d", &n);
																				/*get the matrix*/
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			if(j==n){
		  			printf("enter the result of %d.equation: ",i+1);scanf("%f", &result[i]);
		  			prev_result[i]=result[i];
		  		}
			   else{
			   		printf("enter the coefficent of the %d.term  of %d.equation: ",j+1,i+1);
			   		scanf("%f", &a[i][j]);
			   		a_prev[i][j]=a[i][j];
			   }
		}
	}
	
	float xvalue[N];
	for(i=0;i<n;i++){
		printf("enter starting value of %d.unknown: ",i+1);scanf("%f", &xvalue[i]);
	}
	int iteration;
	printf("enter the number of iteration: ");scanf("%d", &iteration);
													/*rearranging matrix*/
													for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%f ", a[i][j]);
			
		}
		
		printf("\n");
	}
	int max,maxyeri1,temp;
	for(i=0;i<n;i++){
		max=a_prev[i][0];
		maxyeri1=0;
		for(j=1;j<n;j++){
			if(abs(max)<abs(a_prev[i][j])){
				max=a_prev[i][j];
				maxyeri1=j;
			}
		}
		maxyeri[i]=maxyeri1;
		}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j]=a_prev[maxyeri[i]][j];
			
		}
		result[i]=prev_result[maxyeri[i]];
	}
	
	printf("\n\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%f ", a[i][j]);
			
		}
		
		printf("\n");
	}	
																									/*EQUATION STATRTED*/
																									
	
	int h;
	while(h<iteration){
		for(i=0;i<n;i++){
		xvalue[i]=result[i]/a[i][i];
		
		for(j=0;j<n;j++){
			if(i!=j){
				xvalue[i]=xvalue[i]-(a[i][j]*xvalue[j])/a[i][i];
			}
			
		}
	}
	
	printf("\n\n");
	printf("%d.iteration  ", h+1);
	for(j=0;j<n;j++){
			printf(" %f ", xvalue[j]);
		}
	h++;
	}
	return 0;
}


