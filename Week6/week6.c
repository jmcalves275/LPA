#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 30
#define K 22
static int matrixIncidence[N][N]={{0}};
static int centroidsList[K];
int maximo=0;
int firstTime;


void findCluster(int points,int numCentroids){
	int i,j,distance,first=0,currentDistance=0,currentMax=0;

	for(i=0;i<points;i++){
		int exists=0;
		for(j=0;j<numCentroids;j++){ 
			if(centroidsList[j]==i){ /*check if point is a centroid*/
				exists=1;
				break;
			}
		}
		if(exists==1){
			continue;
		}
		else{
			currentDistance=0;
			first=0;
			for(j=0;j<numCentroids;j++){/*find best distance for a point in centroid's list*/
				
				if(i>centroidsList[j]){
					distance=matrixIncidence[centroidsList[j]][i];
				}
				else{
					distance=matrixIncidence[i][centroidsList[j]];
				}
				

				if(first==0){
					currentDistance=distance;
					first=1;
				}
				else{
					if(distance<currentDistance) /*check if is the best distance*/
						currentDistance=distance;
				}


				
			}
			if(currentDistance>=maximo && firstTime!=0){ 
				return;
			}
			if(currentDistance>currentMax){
				currentMax=currentDistance;
			}

			
			
		

		}
		
	}


	if(firstTime==0){
		maximo=currentMax;
		firstTime=1;
	}
	else{
		if(currentMax<maximo)
			maximo=currentMax;
	}
	

	

}

void findCentroids(int len,int startPosition,int points,int numCentroids){
	int i;

	if (numCentroids == 0){
	
		findCluster(points,len);
		
		return;
	}  

	for ( i = startPosition; i < points; i++){
		centroidsList[len - numCentroids] = i;
		
		findCentroids(len,i+1,points,numCentroids-1);

	}
}


int main(){

	int points,point1,point2,distance,numCentroids,i;
	while(scanf("%d %d",&points,&numCentroids)!=EOF){
		for(i=0;i<points*(points-1)/2;i++){
			scanf("%d %d %d",&point1,&point2,&distance);
			matrixIncidence[point1-1][point2-1]=distance;
		}

		
		firstTime=0;
		maximo=0;
		findCentroids(numCentroids,0,points,numCentroids);
		printf("%d\n",maximo);

		
	}
	return 0;
}