#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
float ResultFunc(float rootf,int length,float coef1[N], float expo1[N]);
float DerivativeFunc(float rootf,int length,float coef1[N], float expo1[N]);
int main () {  
 
	 
	int NumTerm, i ;
	float root,root1,root2;
	float f1,f2;
	float tolerance;
	float coef[N],expo[N];
	int n;
	float h,k;
	float integral1, integral2, integral ;
	printf("enter the number of the terms: ");scanf("%d", &NumTerm);
	for(i=0;i<NumTerm;i++){
		printf("enter the coefficient of the %d.term: ",i+1);scanf("%f",&coef[i]);
		printf("enter the exponent of the %d.term: ",i+1);scanf("%f",&expo[i]);
	}
	printf("enter the value of n: ");scanf("%d", &n);
	printf("enter X0: ");scanf("%f", &root1);
	printf("enter Xn: ");scanf("%f", &root2);
	h=(root2-root1)/n; 
	for(i=0;i<n;i++){
		integral1=integral1+h*((ResultFunc(root1+i*h,NumTerm,coef,expo)+ResultFunc(root1+i*h+h,NumTerm,coef,expo)+4*ResultFunc((root1+i*h+root1+i*h+h)/2,NumTerm,coef,expo))/6);
		
		
	}
	printf("\n\n Simpson 1/3:  %f", integral1);
	integral2=ResultFunc(root1,NumTerm,coef,expo)+ResultFunc(root2,NumTerm,coef,expo);
	for(i=1;i<=n-1;i++){
		k=root1+i*h;
		if(i%3==0){
			integral2=integral2+2*ResultFunc(k,NumTerm,coef,expo);
		}
		else{
			integral2=integral2+3*ResultFunc(k,NumTerm,coef,expo);
		}
	}
	integral2=integral2*h*3/8;
	printf("\n\n Simpson 3/8: %f", integral2);
	return 0;
}

float ResultFunc(float rootf,int length,float coef1[N], float expo1[N]){
	int j;
	float res=0;
	for(j=0;j<length;j++){
		res=res+coef1[j]*pow(rootf,expo1[j]);
	}
	return res;
}

float DerivativeFunc(float rootf,int length,float coef1[N], float expo1[N]){
	int j;
	float res=0;
	float coefder[N];
	float expoder[N];
	for(j=0;j<length;j++){
		coefder[j]=coef1[j]*expo1[j];
		expoder[j]=abs(expo1[j]-1);
	}
	for(j=0;j<length;j++){
		res=res+coefder[j]*pow(rootf,expoder[j]);
	}
	return res;
}
