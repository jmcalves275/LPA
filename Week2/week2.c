#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define D1 0
#define D2 1
#define L1 2
#define L2 3
#define R1 4
#define R2 5
#define U1 6
#define U2 7
#define N 5
char *string[]={"D1","D2","L1","L2","R1","R2","U1","U2"};
int matrixRight [24]={4,5,6,7,8,9,10,11,12,13,14,15,0,1,2,3,17,18,19,16,21,22,23,20};
int matrixLeft [24]={12,13,14,15,0,1,2,3,4,5,6,7,8,9,10,11,19,16,17,18,23,20,21,22};
int matrixUp [24]={20,23,22,21,5,6,7,4,18,19,16,17,15,12,13,14,0,1,2,3,10,9,8,11};
int matrixDown [24]= {16,17,18,19,7,4,5,6,22,21,20,23,13,14,15,12,10,11,8,9,0,3,2,1};
static int matrix[N];
static int matrixFinal[N];
int bestCase=N;
int length;


int findSequence(int inicial,int n, int x, int y, int w, int z, int op){
	int i,check=0;
	if(n==inicial || n>bestCase){
		return 0;
	}
	
	if(op==0){
		x=matrixDown[x];
		w=matrixDown[w];
		matrix[n]=0;

	}
	else if(op==1){
		y=matrixDown[y];
		z=matrixDown[z];
		matrix[n]=1;
	}
	else if(op==2){
		x=matrixLeft[x];
		y=matrixLeft[y];
		matrix[n]=2;

	}
	else if(op==3){
		w=matrixLeft[w];
		z=matrixLeft[z];	
		matrix[n]=3;
	}
	else if(op==4){
		x=matrixRight[x];
		y=matrixRight[y];
		matrix[n]=4;
		
	}
	else if(op==5){
		w=matrixRight[w];
		z=matrixRight[z];
		matrix[n]=5;
	}
	else if(op==6){
		x=matrixUp[x];
		w=matrixUp[w];
		matrix[n]=6;
	}
	else if(op==7){
		y=matrixUp[y];
		z=matrixUp[z];
		matrix[n]=7;
	}

	if(x==0 && y==0 && w==0 && z==0){
		
		
		
		if(n<bestCase){

			bestCase=n;
			for(i=0;i<=bestCase;i++){
				matrixFinal[i]=matrix[i];
			}
			
			return 0;
		}
		else if(n==bestCase){
			for(i=0;i<=bestCase;i++){
				if(matrix[i]<matrixFinal[i]){
					matrixFinal[i]=matrix[i];
					check=1;

				}
				else if(matrix[i]>matrixFinal[i] && check==1){
					matrixFinal[i]=matrix[i];
				}
				else if(matrix[i]>matrixFinal[i] && check==0){
					break;
				}
			}
			check=0;
			
			return 0;
	}
}
	findSequence(inicial,n+1,x,y,w,z,0);
	findSequence(inicial,n+1,x,y,w,z,1);
	findSequence(inicial,n+1,x,y,w,z,2);
	findSequence(inicial,n+1,x,y,w,z,3);
	findSequence(inicial,n+1,x,y,w,z,4);
	findSequence(inicial,n+1,x,y,w,z,5);
	findSequence(inicial,n+1,x,y,w,z,6);
	findSequence(inicial,n+1,x,y,w,z,7);

/*
	right1(inicial,n,x,y,w,z,string);
	right2(inicial,n,x,y,w,z,string);
	up1(inicial,n,x,y,w,z,string);
	up2(inicial,n,x,y,w,z,string);
	left1(inicial,n,x,y,w,z,string);
	left2(inicial,n,x,y,w,z,string);
	down1(inicial,n,x,y,w,z,string);
	down2(inicial,n,x,y,w,z,string);*/

	return 0;

}
void initialize(int inicial){
	int i;
	for(i=0;i<inicial;i++){
		matrix[i]=10;
		matrixFinal[i]=10;
	}
	bestCase=inicial;
	
	
}
int main(){
	int inicial, x,y,w,z;

	
	scanf("%d",&inicial);
	scanf("%d %d",&x,&y);
	scanf("%d %d",&w,&z);
	
	initialize(inicial);

	x-=1;
	y-=1;
	w-=1;
	z-=1;

	
	findSequence(inicial,-1,x,y,w,z,-1);
	int i;

	for(i=0;i<=bestCase;i++){
		if(matrixFinal[i]<=7 && matrixFinal[i]>=0 )
			printf("%s ",string[matrixFinal[i]]);
	}
	printf("\n");


	
	return 0;
}

