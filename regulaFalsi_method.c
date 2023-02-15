#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
float ResultFunc(float rootf,int length,float coef1[N], float expo1[N]);
int main () {  
 
	//REGULA-FALSI METHOD
	int NumTerm, i ;
	float root,root1,root2;
	float f1,f2;
	float tolerance;
	float coef[N],expo[N];
	printf("enter the number of the terms: ");scanf("%d", &NumTerm);
	for(i=0;i<NumTerm;i++){
		printf("enter the coefficient of  %d.term: ",i+1);scanf("%f",&coef[i]);
		printf("enter the exponent of  %d.term: ",i+1);scanf("%f",&expo[i]);
	}
	printf("enter the first guess: ");scanf("%f", &root1);
	printf("enter the second guess: ");scanf("%f", &root2);
	f1=ResultFunc(root1,NumTerm,coef,expo);
	f2=ResultFunc(root2,NumTerm,coef,expo);
	while(f1*f2>0){
		printf("There is no root of the function in the given interval! Enter new guesses!");
		printf("\nenter the first guess: ");scanf("%f", &root1);
		printf("enter the second guess: ");scanf("%f", &root2);
		f1=ResultFunc(root1,NumTerm,coef,expo);
		f2=ResultFunc(root2,NumTerm,coef,expo);
	}
	printf("enter the tolerance: ");scanf("%f", &tolerance);
	int NumIteration=0;
	while((root2-root1)/pow(2,NumIteration+1)>tolerance){
		root=((root1*ResultFunc(root2,NumTerm,coef,expo)-root2*ResultFunc(root1,NumTerm,coef,expo))/(ResultFunc(root2,NumTerm,coef,expo)-ResultFunc(root1,NumTerm,coef,expo)));
		printf("\n %d.iteration    %f         %f",NumIteration+1,root, ResultFunc(root,NumTerm,coef,expo));
		if(ResultFunc(root,NumTerm,coef,expo)*ResultFunc(root1,NumTerm,coef,expo)<0){
			root2=root;
		}
		else{
			root1=root;
		}
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
