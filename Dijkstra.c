#include<stdio.h>
//#include<conio.h>
#define INFINITY 9999
#define MAX 10

void greedy(int G[MAX][MAX],int n,int startnode);

int matrix1(){
  int G[MAX][MAX];
  G = [0, 30, -15, 0, 20],[-30, 0, -10, 50, 0],[15, 10, 0, 5, -10],[0, 50, -5, 0, -30],[-20, 0, 10, 30, 0];

  return (G);
}


int main(){
    int G[MAX][MAX],i,j,n,u,op=0;

    do {
      printf("Chose the metrix:\n 1 - adjacency matrix (1)\n 2 - adjacency matrix(2)\n");
      scanf("%d", &op);
      switch (op) {
        case 1:
          printf("\nEnter the starting node:");
          scanf("%d",&u);
          greedy(matrix1, 5, u);
        case 2:
          printf("\nEnter the starting node:");
          scanf("%d",&u);
          greedy(matrix2, 7, u);
        case 0:
          printf("i'm out\n");
        default:
          printf("Not a valid option, try again\n");
      }
    } while(op != 0);

    greedy(G,n,u);

    return 0;
}

void greedy(int G[MAX][MAX],int n,int startnode)
{

    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;

    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;

        //nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }

            //check if a better path exists through nextnode
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }

    //print the path and distance of each node
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistance of node%d=%d",i,distance[i]);
            printf("\nPath=%d",i);

            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
    }
}
