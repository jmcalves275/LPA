#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 30
#define K 22
static int matrixIncidence[N][N]={{0}};
static int centroidsList[K];
int maximo=0,global=0;
int firstTime;


void findCluster(int points,int numCentroids){
	int i,j,distance,first=0,currentDistance=0,currentMax=0;
	/*for(i=0;i<numCentroids;i++){
		printf("%d ",centroidsList[i]);
	}
	printf("\n");*/
	for(i=0;i<points;i++){
		int exists=0;
		for(j=0;j<numCentroids;j++){

			if(centroidsList[j]==i){
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
			for(j=0;j<numCentroids;j++){ /*for to find best distance for a point to centroid*/

			if(i>centroidsList[j]){
				distance=matrixIncidence[centroidsList[j]][i];
			}
			else{
				distance=matrixIncidence[i][centroidsList[j]];
			}
				/*printf("EM I=%d a ligacao para j=%d Ã© %d\n",i,centroidsList[j],distance);*/

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

		if(currentMax>=maximo && firstTime!=0){
			return;
		}

			/*printf("Distancia em i=%d Ã© %d\n",i,currentDistance);*/

	}

}
/*printf("MAXIMO DA RODADA Ã© %d\n",currentMax);*/

if(firstTime==0){
	maximo=currentMax;
	firstTime=1;
}
else{
	if(currentMax<maximo)
		maximo=currentMax;
}

	/*printf("MAX FOUND %d\n",maximo);
	printf("\n");*/



}

int bound(int points,int numPoints,int numCentroids){
	int i,j,distance,first=0,currentDistance=-1,currentMax=-1,pointMax;
	
	/*printf("pois \n");*/
	for(i=0;i<points;i++){
		
		int exists=0;
		for(j=0;j<numCentroids;j++){
			
			if(centroidsList[j]==i){
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
			for(j=0;j<numCentroids;j++){ /*for to find best distance for a point to centroid*/

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
				if(distance<currentDistance)
					currentDistance=distance;
			}

		}

		if(currentDistance>currentMax){
			pointMax=i;
			currentMax=currentDistance;
		}

		/*printf("currentDistance %d \n",currentDistance);*/
	}

}
int check;
/*printf("Current Max %d and pointMax %d\n",currentMax,pointMax);
printf("\n");*/
if(currentMax != -1){
	first=0;
	check=0;
	for(i=points+1;i<numPoints;i++){
		/*printf("depois faz ligacao entre %d e %d\n",i,pointMax);*/
		check=1;
		if(i>pointMax){
			distance=matrixIncidence[pointMax][i];
		}
		else{
			distance=matrixIncidence[i][pointMax];
		}
		if(distance<currentMax){
			return 1;
		}
		/*printf("Sendo distancia %d\n",distance);*/

	}
	/*printf("Sendo distancia melhor atÃ© agora de %d\n",currentDistance);*/
	if(check==1)
		return -1;
	else
		return 0;
}
else{
	return 0;
}


}
void printCentroid(int points){
	int i;
		for(i=0;i<points;i++){
		printf("%d ",centroidsList[i]);
	}
	printf("\n");
}
void findCentroids(int len,int startPosition,int points,int numCentroids){
	int i;

	if (numCentroids == 0){
			global++;
		
		findCluster(points,len);

		return;
	}  

	for ( i = startPosition; i < points; i++){

		centroidsList[len - numCentroids] = i;
	
		printCentroid(len - numCentroids+1);
		if(numCentroids-1!=0){
			int keepTesting=bound(centroidsList[len-1],points,len);
			if(keepTesting==1 || keepTesting==0)
				findCentroids(len,i+1,points,numCentroids-1);
			else if(keepTesting==-1){
				printf("return\n");
				return;

			}
		}
		else
			findCentroids(len,i+1,points,numCentroids-1);

		
	}
	return;
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
		printf("%d %d\n",maximo,global);

		/*for(i=0;i<points-1;i++){
			for(j=i+1;j<points;j++){
				printf("%d ",matrixIncidence[i][j]);
			}
			printf("\n");
		}*/
		}
		return 0;
	}