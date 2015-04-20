#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h>     // std::string
#include <iostream>     // std::cout
#include <sstream>
#include <cstring>
#define N 50
using namespace std;

int total=0;
map<string,int> mymap;
int checkAdjacent (int array[],int n,int index);
int recursive(int array[],int n);



int checkAdjacent (int array[],int n,int index) {
	total=0;
	int i,j,aux=0,check=-1,founded=-1;
	int inicialState=-1,numChanges=0,finalState=-1;

	for(i=index;i<n-1;i++){
		check=-1;

		if(array[i]==-1 && i==n-1 && check==1){
			founded=1;
			continue;
		}
		else if(array[i]==-1)
			continue;

		for(j=i+1;j<n;j++){
			if(array[j]==-1 && j==n-1 && check==1){
				founded=1;
				continue;
			}
			else if(array[j]==-1)
				continue;
			else{
				if(array[j]==array[i] && j==n-1){ //ultimo caso da array
					numChanges++;
					founded=1;
					break;
				}
				else if(array[j]==array[i]){ //numero em j igual a numero em i -> incrementa numero de de bolas sequencias
					numChanges++;
					check=1;
				}
				else if(check==1){ //encontrou sequencia e mete founded=1
					founded=1;
					break;
				}
				else if(j==n-1 && check==1){
					founded=1;
					break;
				}
				else{

					break;
				}
			}
		}

		if(founded==1){ // se encontrou sequencia sai do ciclo

			inicialState=i;
			break;
		}
	}

//arrebenta bolas
	if(inicialState!=-1){ //caso nao encontre sequencia o inicial state é -1.

		for(i=inicialState;i<=n;i++){
			if(aux==numChanges+1){ //Se aux==numBolas encontradas então ultimo estado=i

				finalState=i;
				break;
			}
			else if(array[i]==-1)//Se encontra bola a -1 então continua
				continue;
			else{ //arrebenta bola e incrementa aux
				array[i]=-1;
				aux++;
			}
		}
		total=(numChanges+1)*(numChanges+2); 

		return finalState;


	}
	else{
		return -1;
	}




}
string arrayToString(int array[], int size) {
	ostringstream str("");
	for (int i = 0; i < size; i++)
		str << array[i];
	return str.str();
}

int recursive(int array[],int n){
	string str;

	map<string,int>::const_iterator findValue;


	int arrayAux[n],index=0,totalAux,current=0,maxNode=0;

	int i;
	for ( i = index; i < n; i++)
	{

		memcpy(arrayAux,array,sizeof(int)*(n)); //copia array para dentro de arrayaux para nao afectar proxima iteracao
		str=arrayToString(arrayAux,n);
		findValue= mymap.find (str);//ve se o valor actual ja foi calculado
		if ( findValue != mymap.end() )
			return findValue->second; //se foi calculado retorna-o

		index=checkAdjacent(arrayAux,n,index); //index=ultimo estado verificado
		totalAux=total;

		if(index==-1) //Se não foi encontrada sequencia
			break;
		else{
			current=recursive(arrayAux,n);

			current=current+totalAux;//current = maximo que foi encontrado + total das contas feitas

			
			if(current>maxNode) //se o que foi encontrado é superior ao que tinhamos encontrado ate agora entao...
				maxNode=current;
		}




	}



	mymap.insert (make_pair<string,int>(str,maxNode));//insere o maximo encontrado nesta iteração




	return maxNode; //retorna maximo encontrado
}
int main(){
	int array[N];
	int numCases,i,num,j,n;

	scanf("%d",&numCases);

	for(i=0;i<numCases;i++){
		scanf("%d",&n);

		for(j=0;j<n;j++){

			scanf("%d",&num);
			array[j]=num;         
		}


		int x=recursive(array,n);



		printf("%d\n",x);
		




	}


	return 0;
}