#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxSum=0;


void calcula(int *matrix,int numLines,int numCols){
	int i,j,z,sum;
	
	int *matrixAux=(int*)calloc(numCols,sizeof(int));
	for(z=0;z<numLines;z++){

		memset(matrixAux,0,numCols*sizeof(int));

		for(i=z;i<numLines;i++){
			sum=0;

			for(j=0;j<numCols;j++){

				matrixAux[j]+=matrix[i*numCols+j];
				sum+=matrixAux[j];

				if(sum<0)
					sum=0;
				
				if(sum>maxSum)
					maxSum=sum;

			}
			


		}

	}
	free(matrixAux);
	printf("%d\n",maxSum);
	maxSum=0;
}
int main(){
	int i,j,numLines,numCols;
	while(scanf("%d %d",&numLines,&numCols)!=EOF){
		int *matrix=(int*)calloc(numCols*numLines,sizeof(int));

		if(numLines<numCols){
			for(i=0;i<numLines*numCols;i++){
				scanf("%d",&matrix[i]);
			}
			calcula(matrix,numLines,numCols);
		}
		else //transposta
		{
			for(i=0;i<numLines;i++){
				for(j=0;j<numCols;j++){
					scanf("%d",&matrix[j*numLines+i]);
				}
			}
			calcula(matrix,numCols,numLines);//num colunas troca com num linhas
		}
		free(matrix);
		
	}

	return 0;
}