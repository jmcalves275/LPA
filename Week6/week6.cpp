#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector> 
using namespace std;
#define N 30
#define K 22
static int matrixIncidence[N][N]={{0}};
static int centroidsList[K];
int maximo=0;
int firstTime;

void findCluster(int points,int numCentroids){
	int i,j,distance,first=0,currentDistance=0,exists=1,currentMax=0;



	/*for(i=0;i<numCentroids;i++){
		printf("%d ",centroidsList[i]);
	}
	printf("\n");*/


	size_t myArraySize = sizeof(centroidsList) / sizeof(int);
	int *end = centroidsList + myArraySize;


	for(i=0;i<points;i++){
	
		int *result = std::find(centroidsList, end, i);

		if (result != end) {
				continue;
		}
	
		else{
			currentDistance=0;
			first=0;
			for(j=0;j<numCentroids;j++){
				
				if(i>centroidsList[j]){
					distance=matrixIncidence[centroidsList[j]][i];
				}
				else{
					distance=matrixIncidence[i][centroidsList[j]];
				}
				//printf("EM I=%d a ligacao para j=%d é %d\n",i,centroidsList[j],distance);

				if(first==0){
					currentDistance=distance;
					first=1;
				}
				else{
					if(distance<currentDistance)
						currentDistance=distance;
				}


				
			}
			
			if(currentDistance>currentMax){
				currentMax=currentDistance;
			}

			/*if(currentMax>maximo && firstTime!=0){
				break;
			}*/

			//printf("Distancia em i=%d é %d\n",i,currentDistance);

			}

		}
	/*printf("MAXIMO DA RODADA É %d\n",currentMax);*/

		if(firstTime==0){
			maximo=currentMax;
			firstTime=1;
		}
		else{
			if(currentMax<maximo)
				maximo=currentMax;
		}

/*
	printf("MAX FOUND %d\n",maximo);
	printf("\n");*/

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
		findCentroids(numCentroids,0,points,numCentroids-1);
		printf("%d\n",maximo);

		/*for(i=0;i<points-1;i++){
			for(j=i+1;j<points;j++){
				printf("%d ",matrixIncidence[i][j]);
			}
			printf("\n");
		}*/
		}
	}