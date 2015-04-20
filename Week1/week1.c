#include <stdio.h>
#define N 300000
#define M 5000

int numberTopics,numberPrecedences,maxTopics,precedent,sucessor,numberDays,count,numberMaxTopics,processed;
static int matrixIncidence[M][M]={{0}};
static int matrix[M]; 
void print();
void initialize();
void checkIncidence(int value);
void deleteNode(int value);
int main(){


	scanf("%d %d %d",&numberTopics,&numberPrecedences,&maxTopics);

	initialize(); 
	int i;


		for(i=0;i<numberPrecedences;i++){ 
			scanf("%d %d",&precedent,&sucessor);
			matrixIncidence[precedent][sucessor]=1;
		
			matrix[sucessor]+=1;

		}
		
		

		while(processed!=numberTopics){

			for(i=0;i<numberTopics;i++){ 
				if(matrix[i]==-2)
					matrix[i]=0; 
			}
			for(i=0;i<numberTopics;i++){
			

				if(matrix[i]==0){
					
					matrix[i]=-1; //eliminar nó
					processed++;
					
					deleteNode(i); //decrementar filhos
					
					count++;
				}
				
			}
			if(count>numberMaxTopics){
				numberMaxTopics=count;
				
			}
			if(count>maxTopics){
				numberDays++;
			}

			count=0;
			
		
		}

		
	printf("%d %d\n", numberMaxTopics,numberDays);
	return 0;
}

void deleteNode(int value){
	int i;
	for(i=0;i<numberTopics;i++){
		if(matrixIncidence[value][i]==1){
			matrixIncidence[value][i]=0;
			matrix[i]--;
			if(matrix[i]==0)
				matrix[i]=-2;
		}
	}

}


void initialize(){
	int i;
	for(i=0;i<numberTopics;i++){
		matrix[i]=0;
	}
	numberDays=0;
	numberMaxTopics=0;
	processed=0;
}


