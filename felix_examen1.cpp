#include <iostream>

using std::cout;
using std::endl;
using std::cin;


void llenar(int **);
void imprimir(int **);
int main(int argc, char* argv[]){
	int** matriz = new int*[7];
	for (int i = 0; i < 7; i++){
		matriz[i] = new int[7];
	}
	llenar(matriz);	
	imprimir(matriz);





	return 0;
}
void imprimir(int** matriz){
	for(int i = 0; i< 7; i++){
                for(int j=0 ; j<7; j++){
                        cout << matriz[i][j];
                }
		cout<< endl;
        }


}
void llenar(int** matriz){
	for(int i = 0; i< 7; i++){
		for(int j=0 ; j<7; j++){
			matriz[i][j]= 0;
		}
	
	}
	
	matriz[0][3]=1;
	matriz[6][3]=1;
	matriz[3][0]=2;
	matriz[3][6]=2;

}
