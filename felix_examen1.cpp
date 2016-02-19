#include <iostream>

using std::cout;
using std::endl;
using std::cin;


void llenar(int **);
void imprimir(int **);
void mover_clonado(int**, int);
void mover_doble(int**, int);
int contar_espacios(int**);

int main(int argc, char* argv[]){
	int** matriz = new int*[7];
	for (int i = 0; i < 7; i++){
		matriz[i] = new int[7];
	}
	llenar(matriz);	
	imprimir(matriz);
	bool terminar=false;
	int turno =1;
	while(!terminar){
		if(turno==1){
			cout << "-----------TURNO DEL JUGADOR "<< turno << " ----------- "<<endl;
			int opcion;
			cout<< "1-Clonar"<<endl<<"2-mover dos espacios"<<endl<< "Eliga una de las opciones:";
			cin>>opcion;
			
			if(opcion ==1){
				mover_clonado(matriz,turno);
				imprimir(matriz);
			}else{
				if(opcion==2){
					mover_doble(matriz,turno);
					imprimir(matriz);				
				}else{
					cout<< "Opcion no valida! perdiste turno";
				}	
			}
			
			int espacios = contar_espacios(matriz);
			if(espacios <0){
				terminar=true;
			}
		turno =2;
		}
		if( turno==2){
			cout << "-----------TURNO DEL JUGADOR "<< turno << " ----------- "<<endl;
			int opcion;
                        cout<< "1-Clonar"<<endl<<"2-mover dos espacios"<<endl<< "Eliga una de las opciones:";
                        cin>>opcion;

                        if(opcion ==1){
                                mover_clonado(matriz,turno);
				imprimir(matriz);
                        }else{
				if(opcion==2){
                                	mover_doble(matriz,turno);
					imprimir(matriz);
                                }else{
                                        cout<< "Opcion no valida! perdiste turno";
                                }

                        }

                        int espacios = contar_espacios(matriz);
                        if(espacios <0){
                                terminar=true;
                        }

		turno=1;
		}
	}
	
	for (int i = 0; i < 7; i++){
		delete[] matriz[i];
	}

	delete[] matriz;

	return 0;
}

void mover_doble(int** matriz, int turno){
int x1,x2,y1,y2;
        if(turno==1){
                cout<< "Ingrese coordenada de la pieza que quiere clonar en X:";
                cin>>x1;
                cout<< "Ingrese coordenada de la píeza que quiere clonar en Y:";
                cin>>y1;
                cout<< "Ingrese coordenada adonde quiere clonar la pieza en X:";
                cin >> x2;
                cout<< "Ingrese coordenada adonde quiere clonar la pieza en Y:";
                cin >>y2;
		if((x2==x1-2 && y2== y1-2) || (x2== x1-2 && y2==y1) || (x2 == x1-2 && y2== y1 +2) ||
                        (x2==x1 && y2==y1-2) || (x2==x1 && y2==y1+2) ||
                        (x2== x1+2 && y2== y1-2)||(x2== x1+2 && y2==y1)||(x2==x1+2 && y2==y1+2) ){
                        if((x1>=0 && x1<7) && (x2>=0 && x2<7) && (y1>=0 && y1<7) && (y2>=0 && y2<7) ){
                                if(matriz[x1][y1]== 1){
                                        if(matriz[x2][y2]==0 ){
                                                matriz[x1][y1]=0;
                                                matriz[x2][y2]=1;
						
						
						if( (x2-1 >= 0 && x2-1 < 7) && (y2-1 >=0 && y2-1 < 7) ){
                                                        if(matriz[x2-1][y2-1]==2)
                                                        matriz[x2-1][y2-1]=1;
                                                }
                                                if( (x2-1 >= 0 && x2-1 < 7) && (y2 >=0 && y2 < 7) ){
                                                        if(matriz[x2-1][y2]==2)
                                                        matriz[x2-1][y2]=1;

                                                }
                                                if( (x2-1 >= 0 && x2-1< 7) && (y2+1 >=0 && y2+1 < 7) ){
                                                        if(matriz[x2-1][y2+1]==2)
                                                        matriz[x2-1][y2+1]=1;

                                                }
                                                if( (x2 >= 0 && x2< 7) && (y2-1 >=0 && y2-1 < 7) ){
                                                        if(matriz[x2][y2-1]==2)
                                                        matriz[x2][y2-1]=1;

                                                }
                                                if( (x2 >= 0 && x2< 7) && (y2+1 >=0 && y2+1 < 7) ){
                                                        if(matriz[x2][y2+1]==2)
                                                        matriz[x2][y2+1]=1;

                                                }
                                                if( (x2+1 >= 0 && x2+1< 7) && (y2-1 >=0 && y2-1 < 7) ){
                                                        if(matriz[x2+1][y2-1]==2)
                                                        matriz[x2+1][y2-1]=1;

                                                }
                                                if( (x2+1 >= 0 && x2+1< 7) && (y2 >=0 && y2 < 7) ){
                                                        if(matriz[x2+1][y2]==2)
                                                        matriz[x2+1][y2]=1;

                                                }
                                                if( (x2+1 >= 0 && x2+1< 7) && (y2+1 >=0 && y2+1 < 7) ){
                                                        if(matriz[x2+1][y2+1]==2)
                                                        matriz[x2+1][y2+1]=1;

                                                }
                                        }else{
                                                cout<< "En esa coordenada ya hay una pieza, Perdiste turno"<<endl;

                                        }
                                } 
                        }else{
                                cout<< "Coordenadas fuera de rango, Perdiste turno"<<endl;
                        } 
                }else{
                        cout<< "Movimiento no valido, Perdiste turno"<<endl;
                }

	}
	if(turno ==2){
		cout<< "Ingrese coordenada de la pieza que quiere clonar en X:";
                cin>>x1;
                cout<< "Ingrese coordenada de la píeza que quiere clonar en Y:";
                cin>>y1;
                cout<< "Ingrese coordenada adonde quiere clonar la pieza en X:";
                cin >> x2;
                cout<< "Ingrese coordenada adonde quiere clonar la pieza en Y:";
                cin >>y2;
		
		if((x2==x1-1 && y2== y1-1) || (x2== x1-1 && y2==y1) || (x2 == x1-1 && y2== y1 +1) ||
                        (x2==x1 && y2==y1-1) || (x2==x1 && y2==y1+1) ||
                        (x2== x1+1 && y2== y1-1)||(x2== x1+1 && y2==y1)||(x2==x1+1 && y2==y1+1) ){
			if((x1>=0 && x1<7) && (x2>=0 && x2<7) && (y1>=0 && y1<7) && (y2>=0 && y2<7) ){
				if(matriz[x1][y1]== 2){
					if(matriz[x2][y2]==0 ){
						matriz[x1][y1]=0;
						matriz[x2][y2]=2;
						
						if( (x2-1 >= 0 && x2-1 < 7) && (y2-1 >=0 && y2-1 < 7) ){
                                                        if(matriz[x2-1][y2-1]==1)
                                                        matriz[x2-1][y2-1]=2;
                                                }
                                                if( (x2-1 >= 0 && x2-1 < 7) && (y2 >=0 && y2 < 7) ){
                                                        if(matriz[x2-1][y2]==1)
                                                        matriz[x2-1][y2]=2;

                                                }
                                                if( (x2-1 >= 0 && x2-1< 7) && (y2+1 >=0 && y2+1 < 7) ){
                                                        if(matriz[x2-1][y2+1]==1)
                                                        matriz[x2-1][y2+1]=2;

                                                }
                                                if( (x2 >= 0 && x2< 7) && (y2-1 >=0 && y2-1 < 7) ){
                                                        if(matriz[x2][y2-1]==1)
                                                        matriz[x2][y2-1]=2;

                                                }
                                                if( (x2 >= 0 && x2< 7) && (y2+1 >=0 && y2+1 < 7) ){
                                                        if(matriz[x2][y2+1]==1)
                                                        matriz[x2][y2+1]=2;

                                                }
                                                if( (x2+1 >= 0 && x2+1< 7) && (y2-1 >=0 && y2-1 < 7) ){
                                                        if(matriz[x2+1][y2-1]==1)
                                                        matriz[x2+1][y2-1]=2;

                                                }
                                                if( (x2+1 >= 0 && x2+1< 7) && (y2 >=0 && y2 < 7) ){
                                                        if(matriz[x2+1][y2]==1)
                                                        matriz[x2+1][y2]=2;

                                                }
                                                if( (x2+1 >= 0 && x2+1< 7) && (y2+1 >=0 && y2+1 < 7) ){
                                                        if(matriz[x2+1][y2+1]==1)
                                                        matriz[x2+1][y2+1]=2;

                                                }

					}else{
						cout<< "En esa coordenada ya hay una pieza, Perdiste turno"<<endl;

					}
				}	
			}else{
				cout<< "Coordenadas fuera de rango, Perdiste turno"<<endl;
			}		
		}else{
                        cout<< "Movimiento no valido, Perdiste turno"<<endl;
                }


	} 
}
void mover_clonado(int** matriz, int turno){
	int x1,x2,y1,y2;
	if(turno==1){
		cout<< "Ingrese coordenada de la pieza que quiere clonar en X:";
		cin>>x1;
		cout<< "Ingrese coordenada de la píeza que quiere clonar en Y:";
		cin>>y1;
		cout<< "Ingrese coordenada adonde quiere clonar la pieza en X:";
		cin >> x2;
		cout<< "Ingrese coordenada adonde quiere clonar la pieza en Y:";
		cin >>y2;
		if((x2==x1-1 && y2== y1-1) || (x2== x1-1 && y2==y1) || (x2 == x1-1 && y2== y1 +1) || 
			(x2==x1 && y2==y1-1) || (x2==x1 && y2==y1+1) ||
			(x2== x1+1 && y2== y1-1)||(x2== x1+1 && y2==y1)||(x2==x1+1 && y2==y1+1) ){
			if((x1>=0 && x1<7) && (x2>=0 && x2<7) && (y1>=0 && y1<7) && (y2>=0 && y2<7) ){
				
				if(matriz[x1][y1]== 1){
					if(matriz[x2][y2]==0 ){
						matriz[x2][y2]=1;
						if( (x2-1 >= 0 && x2-1 < 7) && (y2-1 >=0 && y2-1 < 7) ){
							if(matriz[x2-1][y2-1]==2)
							matriz[x2-1][y2-1]=1;
						}
						if( (x2-1 >= 0 && x2-1 < 7) && (y2 >=0 && y2 < 7) ){
							if(matriz[x2-1][y2]==2)
                                                        matriz[x2-1][y2]=1;
							
                                                }
						if( (x2-1 >= 0 && x2-1< 7) && (y2+1 >=0 && y2+1 < 7) ){
							if(matriz[x2-1][y2+1]==2)
                                                        matriz[x2-1][y2+1]=1;
							
                                                }
						if( (x2 >= 0 && x2< 7) && (y2-1 >=0 && y2-1 < 7) ){
							if(matriz[x2][y2-1]==2)
                                                        matriz[x2][y2-1]=1;
							
                                                }
						if( (x2 >= 0 && x2< 7) && (y2+1 >=0 && y2+1 < 7) ){
							if(matriz[x2][y2+1]==2)
                                                        matriz[x2][y2+1]=1;
							
                                                }
						if( (x2+1 >= 0 && x2+1< 7) && (y2-1 >=0 && y2-1 < 7) ){
							if(matriz[x2+1][y2-1]==2)
                                                        matriz[x2+1][y2-1]=1;
							
                                                }
						if( (x2+1 >= 0 && x2+1< 7) && (y2 >=0 && y2 < 7) ){
							if(matriz[x2+1][y2]==2)
                                                        matriz[x2+1][y2]=1;
							
                                                }
						if( (x2+1 >= 0 && x2+1< 7) && (y2+1 >=0 && y2+1 < 7) ){
							if(matriz[x2+1][y2+1]==2)
                                                        matriz[x2+1][y2+1]=1;
							
                                                }
					}else{
						cout<< "En esa coordenada ya hay una pieza, Perdiste turno"<<endl;
					}
				}else{
					cout<< "En las coordenadas dadas no hay una pieza o no es una de tus piezas, Perdiste turno"<<endl;
				}
			}else{
				cout<< "Coordenadas fuera de rango, Perdiste turno"<<endl;
			}
		}else{
			cout<< "Movimiento no valido, Perdiste turno"<<endl;
		}

		
		
	}
	if(turno==2){
	          cout<< "Ingrese coordenada de la pieza que quiere clonar en X:";
                cin>>x1;
                cout<< "Ingrese coordenada de la píeza que quiere clonar en Y:";
                cin>>y1;
                cout<< "Ingrese coordenada adonde quiere clonar la pieza en X:";
                cin >> x2;
                cout<< "Ingrese coordenada adonde quiere clonar la pieza en Y:";
                cin >>y2;
                if((x2==x1-1 && y2== y1-1) || (x2== x1-1 && y2==y1) || (x2 == x1-1 && y2== y1 +1) ||
                        (x2==x1 && y2==y1-1) || (x2==x1 && y2==y1+1) ||
                        (x2== x1+1 && y2== y1-1)||(x2== x1+1 && y2==y1)||(x2==x1+1 && y2==y1+1) ){

                        if((x1>=0 && x1<7) && (x2>=0 && x2<7) && (y1>=0 && y1<7) && (y2>=0 && y2<7) ){
                                if(matriz[x1][y1]== 2){
                                        if(matriz[x2][y2]==0 ){
                                                matriz[x2][y2]=2;
						if( (x2-1 >= 0 && x2-1 < 7) && (y2-1 >=0 && y2-1 < 7) ){
                                                        if(matriz[x2-1][y2-1]==1)
                                                        matriz[x2-1][y2-1]=2;
                                                }
                                                if( (x2-1 >= 0 && x2-1 < 7) && (y2 >=0 && y2 < 7) ){
                                                        if(matriz[x2-1][y2]==1)
                                                        matriz[x2-1][y2]=2;

                                                }
                                                if( (x2-1 >= 0 && x2-1< 7) && (y2+1 >=0 && y2+1 < 7) ){
                                                        if(matriz[x2-1][y2+1]==1)
                                                        matriz[x2-1][y2+1]=2;

                                                }
                                                if( (x2 >= 0 && x2< 7) && (y2-1 >=0 && y2-1 < 7) ){
                                                        if(matriz[x2][y2-1]==1)
                                                        matriz[x2][y2-1]=2;

                                                }
                                                if( (x2 >= 0 && x2< 7) && (y2+1 >=0 && y2+1 < 7) ){
                                                        if(matriz[x2][y2+1]==1)
                                                        matriz[x2][y2+1]=2;

                                                }
                                                if( (x2+1 >= 0 && x2+1< 7) && (y2-1 >=0 && y2-1 < 7) ){
                                                        if(matriz[x2+1][y2-1]==1)
                                                        matriz[x2+1][y2-1]=2;

                                                }
                                                if( (x2+1 >= 0 && x2+1< 7) && (y2 >=0 && y2 < 7) ){
                                                        if(matriz[x2+1][y2]==1)
                                                        matriz[x2+1][y2]=2;

                                                }
                                                if( (x2+1 >= 0 && x2+1< 7) && (y2+1 >=0 && y2+1 < 7) ){
                                                        if(matriz[x2+1][y2+1]==1)
                                                        matriz[x2+1][y2+1]=2;

                                                }
                                        }else{
                                                cout<< "En esa coordenada ya hay una pieza, Perdiste turno"<<endl;
                                        }
                                }else{
                                        cout<< "En las coordenadas dadas no hay una pieza o no es una de tus piezas, Perdiste turno"<<endl;
                                }
                        }else{
                                cout<< "Coordenadas fuera de rango, Perdiste turno"<<endl;
                        }
                }else{
                        cout<< "Movimiento no valido, Perdiste turno"<<endl;
                }
	
	}

}
int contar_espacios(int** matriz){
	int espacios =0;
	for(int i = 0; i< 7; i++){
        	for(int j=0 ; j<7; j++){
			if(matriz[i][j]==0){
				espacios++;
			}		
		}
	}
	return espacios;
}
void imprimir(int** matriz){
	for(int i = 0; i< 7; i++){
                for(int j=0 ; j<7; j++){
                        if(matriz[i][j]== 0){
				cout<< " - ";
			}
			if(matriz[i][j]== 1){
				cout<< " + ";
			}
			if(matriz[i][j]==2){
				cout<< " # ";
			}
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
