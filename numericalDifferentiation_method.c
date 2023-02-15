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
	float back,forward,central;
		printf("enter the number of the terms: ");scanf("%d", &NumTerm);
		for(i=0;i<NumTerm;i++){
			printf("enter the coefficient of  %d.term: ",i+1);scanf("%f",&coef[i]);
			printf("enter the exponent of  %d.term: ",i+1);scanf("%f",&expo[i]);
		}
		printf("enter the value of x: ");scanf("%f", &root);
		printf("enter the value of h: ");scanf("%f", &tolerance);
		f1=ResultFunc(root+tolerance,NumTerm,coef,expo);
		f2=ResultFunc(root,NumTerm,coef,expo);
		printf("\nForward Differencing: %f", (f1-f2)/tolerance);
		f1=ResultFunc(root,NumTerm,coef,expo);
		f2=ResultFunc(root-tolerance,NumTerm,coef,expo);
		printf("\nBackward Differencing: %f", (f1-f2)/tolerance);
		f1=ResultFunc(root+tolerance,NumTerm,coef,expo);
		f2=ResultFunc(root-tolerance,NumTerm,coef,expo);
		printf("\nCentral Differencing: %f", (f1-f2)/(2*tolerance));
	
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
