/*
 * main.c
 *
 *  Created on: Feb 14, 2018
 *      Author: sheida
 */
#include<stdio.h>
#include<stdlib.h>

void ship_to_port(int, int, int, int *);
void ship_to_port_R(int *, int *,int, int *, int, int, int *, int,int*);
int check(int *, int, int, int);

int main() {

	int *length, N = 3, L = 10, m = 4;

	length = (int *) malloc(m * sizeof(int));
	if (length == NULL) {
		printf("Allocation Error!");
		return 1;
	}
	length[0]=5;length[1]=8;length[2]=4;length[3]=2;
	ship_to_port(N, L, m, length);

	return 0;
}
void ship_to_port(int N, int L, int m, int *length) {

	int *piers,*pierBest;
	int *mark;
	int *cnt=m+1;
	int i,sum=0;
	int p=1;
	mark = (int *) calloc(m, sizeof(int));
	if (mark == NULL) {
		printf("allocation Error!");
	}
	pierBest=(int *)calloc(m,sizeof(int));
	if (pierBest == NULL) {
			printf("ALlocation Error!");
			//exit(EXIT_FAILURE);
		}
	piers = (int *) calloc(m, sizeof(int));
	if (piers == NULL) {
		printf("ALlocation Error!");
		//exit(EXIT_FAILURE);
	}

	ship_to_port_R(piers,pierBest,N, mark, L, m, length, 0,&cnt);

	for (i = 0; i < m && p<=N; i++) {
					if ((sum += pierBest[i]) <= 10) {
						printf("pier %d for ships %d \n", p, pierBest[i]);
					} else {
						p++;
						i--;
						sum = 0;
					}

				}
				printf("\n");

	return;
}
void ship_to_port_R(int *piers, int *piersBest,int N, int *mark, int L, int m, int *length,int level,int *cnt) {

	int i;
	//int sum = 0, p = 1;
	int nbpiers;
	if (level == m) {
		nbpiers=check(piers,N,L,m);
		if(nbpiers< (*cnt)){
			*cnt=nbpiers;
			for(i=0;i<m ;i++){
				piersBest[i]=piers[i];
			}
		}

//		all sol
//		for (i = 0; i < m && p <= N; i++) {
//			if ((sum += piers[i]) <= 10) {
//				printf("%d ships %d \n", p, piers[i]);
//			} else {
//				p++;
//				i--;
//				sum = 0;
//			}
//
//		}
//		printf("\n");
		return;
	}

	for (i = 0; i < m; i++) {
		if (mark[i] == 0) {
			mark[i] = 1;
			piers[level] = length[i];

			ship_to_port_R(piers,piersBest,N, mark, L, m, length, level + 1,cnt);
			mark[i] = 0;
		}
	}



	return;

}
int check (int *piers,int N,int L,int m){

	int i,p=1;
	int sum=0;

			for (i = 0; i < m && p <= N; i++) {
				if ((sum += piers[i]) > L) {
					p++;
					sum=0;
					i--;
				}
			}
	return p;
}


