#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
float ResultFunc(float rootf,int length,float coef1[N], float expo1[N]);
float DerivativeFunc(float rootf,int length,float coef1[N], float expo1[N]);
int main () {  
 
	//NEWTON RAPHSHON METHOD 
	int NumTerm, i ;
	float root,root1,root2;
	float f1,f2;
	float tolerance;
	float coef[N],expo[N];
	printf("enter the number of the terms: ");scanf("%d", &NumTerm);
	for(i=0;i<NumTerm;i++){
		printf("enter the coefficient of the %d.term: ",i+1);scanf("%f",&coef[i]);
		printf("enter the exponent of the %d.term: ",i+1);scanf("%f",&expo[i]);
	}
	printf("enter the guess: ");scanf("%f", &root1);
	
	printf("enter the tolerance: ");scanf("%f", &tolerance);
	f1=ResultFunc(root1,NumTerm,coef,expo);
	f2=DerivativeFunc(root1,NumTerm,coef,expo);
	root=root1-(f1/f2);
	int NumIteration=0;
	while(pow((root-root1),2)>pow(tolerance,2)){
		printf("\n %d.iteration    %f         %f",NumIteration+1,root, ResultFunc(root,NumTerm,coef,expo));
		root1=root;
		f1=ResultFunc(root1,NumTerm,coef,expo);
		f2=DerivativeFunc(root1,NumTerm,coef,expo);
		root=root1-(f1/f2);
		NumIteration++;
	}
	
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
