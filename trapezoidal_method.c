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
	float h;
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
	
	integral=ResultFunc(root1,NumTerm,coef,expo)+ResultFunc(root2,NumTerm,coef,expo);
	for(i=1;i<n;i++){
		integral=integral+2*ResultFunc(root1+i*h,NumTerm,coef,expo);
	}
	
	
	printf("\n\n %f", (h/2)*integral);
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
