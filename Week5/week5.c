#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;
void calc(int *matrix,int *matrixAux,int size,int sizeAux,int timeProcess,int batch){
	int z,i,j,sum;
	z=sizeAux-1;
	j=0;
	for(i=size-1;i>=0;i--){
		if(j==0){
			matrixAux[z]=matrix[i];
			z--;
		}
		j++;
		if(j==batch){
			j=0;
		}


	}

	sum=0;
	for(i=0;i<sizeAux;i++){
		if(sum<matrixAux[i]){
			sum=matrixAux[i];
		}
		if(i==sizeAux-1){
			sum+=timeProcess;	
		}
		else
			sum+=(timeProcess*2);	

	}
	printf("%d\n",sum);
}
int main(){

	int i,*matrix,size,batch,timeProcess,*matrixAux,sizeAux;
	float aux;
	while(scanf("%d %d %d",&batch,&size,&timeProcess)!=EOF){
		aux=(float)size/batch;
		sizeAux=ceil(aux);

		matrix=(int*)malloc(size*sizeof(int));

		matrixAux=(int*)malloc(sizeAux*sizeof(int));

		for(i=0;i<size;i++){
			scanf("%d",&matrix[i]);
		}
		sort(matrix,matrix+size);

		calc(matrix,matrixAux,size,sizeAux,timeProcess,batch);


		free(matrix);

	}

	

	


	return 0;
}