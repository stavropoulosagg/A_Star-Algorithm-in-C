#include <stdio.h>
#include <stdlib.h>

int **map;
int r1[2] ; // coords of the rob1 x,y 
int r2[2] ; // coords of the rob2 x,y 
int counter;// count of nodes that are opened
int limits[2];//the number of rows and columns
int meety,meetx;//the meeting point

struct graph_node {
    struct graph_node *parent;    
    int x;
    int y; 
    int h;
    int g;
    int cost;
    struct graph_node *next;
};
typedef struct graph_node node;

void readmap() {
    FILE *arxeio;
    int x,y,r1x,r1y,r2x,r2y,i,j,temp;
    char tempRead;
    
    arxeio=fopen("roll.txt","r");
    if (arxeio==NULL) 
        perror ("Error opening file");
        
    fscanf(arxeio , "%d %d\n" , &y , &x);
    map=malloc(x * sizeof( int* ));
    for (i=0; i < x ; i++) 
        map[i]=malloc(y * sizeof( int ) );
        
    limits[0]=x;
    limits[1]=y;
    
    fscanf(arxeio , "%d %d\n" , &r1y , &r1x);
    fscanf(arxeio , "%d %d\n" , &r2y , &r2x);
    
    r1[0]=--r1x;
    r1[1]=--r1y;
    r2[0]=--r2x;
    r2[1]=--r2y;
    
    fscanf(arxeio , "%d %d\n" , &meety , &meetx);
    meetx--;
    meety--;
    
    for (i=0; i < x ;i++){
        for (j=0 ; j < y ; j++) {
            fscanf(arxeio,"%c" , &tempRead );
            if (tempRead == 'x' )
                map[i][j] = 1 ;
            else map[i][j] = 0 ;
            printf("%d",map[i][j]);
        }
    printf("\n");    
    fscanf(arxeio ,"\n");
    }
}

int notExists(node **open,node **closed,node **min,int newX, int newY,int newCost) {
    node *temp;
    temp = *open ;
    while (temp!= NULL) {
        if ( (temp->x == newX) && (temp->y == newY) ) {
            if (newCost <= temp->g) {
                temp->parent = *min ;
                temp->g = newCost ;
                temp->cost = (temp->g) + (temp->h) ;
                return 0;
            }
        return 0 ;
        }
        temp = temp->next ;
    }
    temp = *closed ;
    while (temp != NULL ) {
        if ((temp->x == newX) && (temp->y == newY))
            return 0 ;
        temp = temp->next ;
    }
    return 1 ;
}

int main (int argc, char **argv) {
    node * rob1,*rob2;
    readmap();
    printf("starting position of rob1 (%d %d) and of rob2 (%d %d)\n", r1[0], r1[1], r2[0], r2[1]) ;
    printf("meeting point is %d %d\n",meetx,meety);
    return 0;    
}
