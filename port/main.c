/*
 * main.c
 *
 *  Created on: Feb 14, 2018
 *      Author: sheida
 */
#include<stdio.h>
#include<stdlib.h>
#define N 3
#define L 10
#define m 4

void ship_to_port(int,int,int,int *);
int ship_to_port_R(int **,int,int,int,int *,int,int);
int check(int**,int,int,int *);

int main(){

	int *length;

	length=(int *)malloc(m*sizeof(int));
	if(length==NULL){
		printf("Allocation Error!");
		return 1;
	}
	ship_to_port(N,L,m,length);


return 0;
}
void ship_to_port(int N,int L,int m,int *length){

	int **piers,i;
	piers=(int **)malloc(L*sizeof(int*));
	if(piers== NULL){
		printf("ALlocation Error!");
		//exit(EXIT_FAILURE);
	}
	for(i=0;i<N;i++){
		piers[i]=(int *)malloc(N*sizeof(int));
		if(piers[i]==NULL){
			printf("Allocation Error.");
		}
	}
	if(ship_to_port_R(piers,N,L,m,length,0,0)){
		printf("possible placement for those ships is on piers");
	}
	else{
		printf("!!Solution not found!!");
	}
return ;
}
int ship_to_port_R(int **piers,int N,int L,int m,int *length,int level,int start){

	int i;
	if(level==N*L){
		//check to find minimum N
		if(check(piers[N][L],m,length,start)){
			printf("%d , %d",N,length[m]);
		}
		printf("\n");
return 1;
	}
	for(i=start;i<L;i++){
		length[level]=i;


		ship_to_port_R(piers,N,L,m,length,level+1,start+l[length]);

	}

}
int check(int **piers,int m,int *length,int pos){
	//to find minimum numbers of piers
	//if there was no free space in a pier in size of m ,go to the next one
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<N;j++){
			if(length[i]>piers[pos]){
				//go to he next pier!
			}
		}
	}


}

