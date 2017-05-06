#include<bits/stdc++.h>
#define MAX_N 10
using namespace std;
int matAdy[10][10];
int cofactors[10][10];
int N,D;
struct Punto{
	int x,y;
}puntos[12];
double dist(int x1, int y1, int x2, int y2){
	double x = (x2-x1) * (x2-x1);
	double y = (y2-y1) * (y2-y1);
	return sqrt((double)x+y);
}
void clearMatrix(){
	memset(matAdy,0,sizeof(matAdy));
}

// Function to get cofactor of mat[p][q] in temp[][]. n is current
// dimension of mat[][]
void getCofactor(int mat[MAX_N][MAX_N], int temp[MAX_N][MAX_N], int p, int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
 
/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
int determinantOfMatrix(int mat[MAX_N][MAX_N], int n)
{
    int D = 0; // Initialize result
 
    //  Base case : if matrix contains single element
    if (n == 1)
        return mat[0][0];
 
    int temp[MAX_N][MAX_N]; // To store cofactors
 
    int sign = 1;  // To store sign multiplier
 
     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
        getCofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinantOfMatrix(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}
int main(){
	int x,y;
	while(cin>>N>>D && N){
		clearMatrix();
		int edgeIndex = 0;
		for(int i=0;i<N;i++){
			cin>>x>>y;
			puntos[i].x = x;
			puntos[i].y = y;
			for(int j=0;j<i;j++){
				double d = dist(puntos[i].x,puntos[i].y,puntos[j].x,puntos[j].y);
				if(d<=D){
					//printf("Creando n arista %d %d, %.2f %d\n",i,j,d,D);
					matAdy[i][j]=1;
					matAdy[i][i]++;
					matAdy[j][i]=1;
					matAdy[j][j]++;
				}
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i==j) continue;
				if(matAdy[i][j]) matAdy[i][j] = -1;
			}
		}
		getCofactor(matAdy,cofactors,0,0,N);
		int res = determinantOfMatrix(cofactors,N-1);
		//LLI res = backtrack(0,0,vi());
		cout<<res<<'\n';
	}
	return 0;
}
