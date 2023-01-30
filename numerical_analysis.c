#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 10
long factorial(int n);
float ResultFunc(float rootf,int length,float coef1[N], float expo1[N]);
float DerivativeFunc(float rootf,int length,float coef1[N], float expo1[N]);
float inputmat(float mat[N][N],int n);
float printmat(float mat[N][N],int n);
float inversemat1(float mat[N][N],float birim[N][N],int n);
float outbirim(float mat[N][N],int n);
float inversemat2(float mat[N][N],float birim[N][N],int n);
float inversemat3(float mat[N][N],float birim[N][N],int n);

int main(){
	int method;
	printf("1.Bisection yontemi\n2.Regula-Falsi yontemi\n3.Newton-Raphson yontemi\n4.NxN'lik matrisin tersi\n5.Gauss Eleminasyon yontemi\n6.Gauss Seidal yontemi\n7.Sayisal Turev\n8.Simpson yontemi\n9.Trapez yontemi\n10.Degisken donosomsuz Gregory Newton Enterpolasyonu");
	printf("\n\nPlease select the method: ");scanf("%d", &method);
	int NumTerm;
	float integral,integral1,integral2;
	int n;
	float h,k;
	int i;
	float root,root1,root2;
	float f1,f2;
	float tolerance;
	float coef[N],expo[N];
																															/*BISECTION START*/
	if(method==1){
		printf("enter the number of the terms: ");scanf("%d", &NumTerm);
	for(i=0;i<NumTerm;i++){
		printf("enter the coefficient of the %d.term: ",i+1);scanf("%f",&coef[i]);
		printf("enter the exponent of the %d.term: ",i+1);scanf("%f",&expo[i]);
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
	while(pow((root1-root2),2)>pow(tolerance,2)){
		root=(root1+root2)/2;
		printf("\n %d.iteration    %f         %f",NumIteration+1,root, ResultFunc(root,NumTerm,coef,expo));
		if(ResultFunc(root,NumTerm,coef,expo)==0){
			printf("\n  The root of the given equation is %f", root);
			root1=root2;
		}
		else{
			if(ResultFunc(root,NumTerm,coef,expo)*ResultFunc(root1,NumTerm,coef,expo)<0){
			root2=root;
		}
		else{
			root1=root;
		}
		NumIteration++;
		}
		
	}
	}
																															/*REGULA FALSI START*/
	else if(method==2){
		printf("enter the number of the terms: ");scanf("%d", &NumTerm);
	for(i=0;i<NumTerm;i++){
		printf("enter the coefficient of the %d.term: ",i+1);scanf("%f",&coef[i]);
		printf("enter the exponent of the %d.term: ",i+1);scanf("%f",&expo[i]);
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
	}
																															/*NEWTON-RAPHSON START*/
	else if(method==3){
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
	}
																															/*SAYISAL TUREV START*/
	else if(method==7){
		float geri,ileri,merkez;
		printf("enter the number of the terms: ");scanf("%d", &NumTerm);
		for(i=0;i<NumTerm;i++){
			printf("enter the coefficient of the %d.term: ",i+1);scanf("%f",&coef[i]);
			printf("enter the exponent of the %d.term: ",i+1);scanf("%f",&expo[i]);
		}
		printf("enter the value of x: ");scanf("%f", &root);
		printf("enter the value of h: ");scanf("%f", &tolerance);
		f1=ResultFunc(root+tolerance,NumTerm,coef,expo);
		f2=ResultFunc(root,NumTerm,coef,expo);
		printf("\nileri fark: %f", (f1-f2)/tolerance);
		f1=ResultFunc(root,NumTerm,coef,expo);
		f2=ResultFunc(root-tolerance,NumTerm,coef,expo);
		printf("\ngeri fark: %f", (f1-f2)/tolerance);
		f1=ResultFunc(root+tolerance,NumTerm,coef,expo);
		f2=ResultFunc(root-tolerance,NumTerm,coef,expo);
		printf("\nmerkezi fark: %f", (f1-f2)/(2*tolerance));
	
	}
																														/*TRAPEZ START*/
	else if(method==9){
	
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
	}
																															/*SIMPSON START*/
	else if(method==8){
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
	}
																									/*NxN MATRIS TERSI START*/
	else if(method==4){
		float myMat[N][N];
		float birim[N][N];
		int n;
		printf("enter the number of rows and columns: ");scanf("%d", &n);
		inputmat(myMat,n);
		outbirim(birim,n);
		printmat(myMat,n);
		inversemat1(myMat,birim,n);
		inversemat2(myMat,birim,n);
		inversemat3(myMat,birim,n);
	
		printf("\n\n\n");
		printmat(birim,n);
	}
																												/*GAUSS ELIMINATION START*/
	else if(method==5){
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
	}
																									/*SEIDEL START*/
	else if(method==6){
		int i,j,k;
		int n;
	int maxyeri[N]={0};
	float result[N];
	float prev_result[N];
	float a[N][N];
	float a_prev[N][N];
	printf("enter the number of unknowns: ");
	scanf("%d", &n);
																				/*Matris alma*/
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
	}
																							/*INterpolation started*/
	else if(method==10){
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
	}

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
float inputmat(float mat[N][N],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("[%d][%d].eleaman: ", i+1,j+1);scanf("%f", &mat[i][j]);
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
long factorial(int n)  
{  
  if (n == 0)  
    return 1;  
  else  
    return(n * factorial(n-1));  
}


