#include <stdio.h>
#include <stdlib.h>
/*
void read(int** arr, int n)
{
    for(int i=1; i<=n; i++)
    {
        printf("Enter %d row: ",i);
        for(int j=1; j<=n; j++)
            scanf("%d",&arr[i][j]);
    }
}

void show(int** arr, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%d\t",arr[i][j]);
        printf("\n");
    }
} */

int main(void)
{
	int n, i, j, a, b, u, v;
	printf("Enter total no. of verteces: ");
	scanf("%d",&n);

	int adj_matrix[10][10];
	//int *adj_matrix;
	//adj_matrix = (int*) malloc( n * n * sizeof(int) );

	/* read(adj_matrix, n);
	show(adj_matrix, n); */
	for(i=0; i<n; i++)
    {
        printf("Enter %d row: ",i);
        for(j=0; j<n; j++)
            scanf("%d",&adj_matrix[i][j]);
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d\t",adj_matrix[i][j]);
        printf("\n");
    }

    int *visited;
    visited = (int*) malloc(n * sizeof(int));

    for(i=0; i<n; i++)
        visited[i] = 0;

    int source;
    printf("Enter Source: ");
    scanf("%d",&source);

    visited[source] = 1;

    int ne=1, min, min_cost=0;

    while(ne<n)
    {
        for(i=0,min=999; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if( adj_matrix[i][j] < min )
                {
                    if( visited[i]!=0 )
                    {
                        min = adj_matrix[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if(visited[u]==0 || visited[v]==0)
        {
            printf("\nedge: %d-%d, Cost -> %d",a,b,min);
            ne++;
            min_cost += min;
            visited[b] = 1;
        }
        adj_matrix[a][b] = adj_matrix[b][a] = 999;
    }
    printf("\nMinimum Cost: %d",min_cost);
	return 0;
}

