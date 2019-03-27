#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define N 5
int max_value,row=0,col=0;
void min_distance();
double min_dist,distance_matrix[N][N];

void min_distance() {
	int  i, j;
	min_dist = max_value;
	for (i = 0;i < N;i++) {
		for (j = 0;j < N;j++) {
			if (distance_matrix[i][j] < min_dist && distance_matrix[i][j]>0) {
				min_dist = distance_matrix[i][j];
				row = i;
				col = j;
			}
		}
	}
}

void calculate_distance(double x[N][2]) {
	int i,j;
	max_value = 0;
	for (i = 0;i < N;i++) {
		for (j = 0;j < N;j++) {
			distance_matrix[i][j] = sqrt(pow(x[i][0]-x[j][0],2)
										+pow(x[i][1] - x[j][1], 2));
			if (max_value < distance_matrix[i][j])max_value = distance_matrix[i][j];
		}
	}
	max_value++; //max_value is a number bigger than all the distances
}
			
int main(int argc, char **argv)
{
	double X[N][2] = { {1,1},{1,1.1},{3,3},{3.5,4},{8,9}};
	int cluster[N],new_cluster_index=N,i,j,current_n_clusters=N;
	printf("Hierarchical clustering\n---------------------------------------\n");
	calculate_distance(X);
	for (i = 0;i < N;i++) {
		cluster[i] = i;
	}
	printf("%d clusters:\n---------------------------------------\n", current_n_clusters);
	for (i = 0;i < N;i++) {
		printf("object %d is in cluster %d\n", i, cluster[i]);
	}
	printf("---------------------------------------\n");
	min_dist = max_value;
	while (current_n_clusters>1)
	{
		min_distance();
		for (i = 0;i < N;i++) {
			if (cluster[i] == cluster[row] && i != row)cluster[i] = new_cluster_index;
			if (cluster[i] == cluster[col] && i != col)cluster[i] = new_cluster_index; 
		}
		cluster[row] = new_cluster_index;
		cluster[col] = new_cluster_index;
		current_n_clusters--;
		for (i = 0;i < N;i++)
			for (j = 0;j< N;j++)
				if (cluster[i] == cluster[j]) {
					distance_matrix[i][j] = 0;
					distance_matrix[j][i] = 0;
				}
		new_cluster_index++;
		printf("%d clusters:\n---------------------------------------\n",current_n_clusters);
		for (i = 0;i < N;i++) {
			printf("object %d is in cluster %d\n",i, cluster[i]);
		}
		printf("---------------------------------------\n");
	}
	getchar();
	return 0;
}
