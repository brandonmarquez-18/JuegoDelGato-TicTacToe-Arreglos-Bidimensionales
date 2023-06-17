#include<iostream>
#include<locale.h>//CARACTERES ESPECIALES
#include<stdlib.h>//LIBRERÍA PARA PODDER USAR: system("cls");
#include<string>//Permite manejar mrtodos referidos al string
#include<cstdlib>//Permite hacer conversion de cadena a entero (atoi)

using namespace std;

//ARREGLO MATRICIAL DE 3X3 PARA EL TABLERO
string tablero[3][3] = {{"_","_","_"}, //FILA #1
						{"_","_","_"}, //FILA #2
						{"_","_","_"}  //FILA #3
						};
int x, y;
//LA INSTRUCCIÓN "void" SE UTLIZAN PARA FUNCIONES QUE NO VAN A REGRESAR O RETORNAR UNA VALOR
//FUNCIÓN PARA MOSTRAR EL TABLERO:
void mostrar_tablero(){//EL NOMBRE DE DE LA FUNCION ES: "mostrar_tablero"
	for(int i = 0; i <= 2; i++){//SE HACE CICLO "for" PARA PARA QUE "i" PASE POR CADA UNA DE LAS FILAS DEL ARREGLO MATRICIAL "tablero"
		cout<<endl;//SALTO DE LÍNEA
		for(int j = 0; j <= 2; j++){//SE HACE CICLO "for" PARA PARA QUE "j" PASE POR CADA UNA DE LAS COMLUMNAS DEL ARREGLO MATRIACIAL "tablero"
			cout<<tablero[i][j]<<"";//SE IMPRIME EL ARREGLO MATRICIAL "tablero" INVOCANDO A LOS 2 CICLOS "for" ANTERIORES TOMANDO CADA UNA-
									//DE LAS DIMENCIONES QUE TOMÓ "i" y "j" A BASE DE LOS 2 CICLOS "for" ANTERIORES
		}
	}
}

void LimpiarTablero(){
	tablero[0][0] = "_";
	tablero[0][1] = "_";
	tablero[0][2] = "_";
	tablero[1][0] = "_";
	tablero[1][1] = "_";
	tablero[1][2] = "_";
	tablero[2][0] = "_";
	tablero[2][1] = "_";
	tablero[2][2] = "_";
}

int validar(string menaje){
	bool bandera = true;
	string valor1;
	int valor2;
	while(bandera){
		cin>>valor1;
		//valor1 va ha ser igual a valor2 y despues se convierte de cadena a entero es decir a 0
		valor2 = atoi(valor1.c_str());
		bandera = false;
		if(valor2 != 0){
			
			bandera = false;
		}
		else{
			cout<<"Solo se admiten números: ";
			bandera = true;
		}
	}
	return valor2;
}




void turno_de_x(){ 
	int PedirDimenciones = 1;
	while(PedirDimenciones == 1){
		cout<<"\nTURNO DE 'X'"<<endl;
		cout<<""<<endl;
		cout<<"Indica el Número de fila para 'X': ";
		x = validar("");
		x-=1;
		cout<<"Indica el Número de columna para 'X': ";
		y = validar("");
		y-=1;
		if((x >= 3) || (y >= 3)){
			cout<<"\nNO PUEDE DAR VALORES MAYORES A 3!!, ELIGA ENTRE 1-3...";
			PedirDimenciones = 1;
		}
		else{
			if(tablero[x][y] == "_"){
				tablero[x][y] = "X";
				PedirDimenciones = 2;
			}
			else{
				cout<<"Casilla ocupada, Eliga otra por favor...";
				PedirDimenciones = 1;
			}
		}
	}
}
void turno_de_O(){
	int PedirDimenciones = 1;
	while(PedirDimenciones == 1){
		cout<<"\nTURNO DE 'O'"<<endl;
		cout<<""<<endl;
		cout<<"Indica el Número de fila para 'O': ";
		x = validar("");
		x-=1;
		cout<<"Indica el Número de columna para 'O': ";
		y = validar("");
		y-=1;
		if((x >= 3) || (y >= 3)){
			cout<<"\nNO PUEDE DAR VALORES MAYORES A 3!!, ELIGA ENTRE 1-3...";
			PedirDimenciones = 1;
		}
		else{
			if(tablero[x][y] == "_"){
				tablero[x][y] = "O";
				PedirDimenciones = 2;
			}
			else{
				cout<<"Casilla ocupada, Eliga otra por favor...";
				PedirDimenciones = 1;
			}
		}
	}
}





int main(){
	setlocale(LC_CTYPE, "Spanish");	
	int RepetirJuego = 1;
	while(RepetirJuego == 1){
		system("cls");
		mostrar_tablero();
		cout<<""<<endl;
		turno_de_x();
		if((tablero[0][0] == "X" && tablero[0][1] == "X" && tablero[0][2] == "X") || //FILA #1
		   (tablero[1][0] == "X" && tablero[1][1] == "X" && tablero[1][2] == "X") || //FILA #2
		   (tablero[2][0] == "X" && tablero[2][1] == "X" && tablero[2][2] == "X") || //FILA #3
		   (tablero[0][0] == "X" && tablero[1][0] == "X" && tablero[2][0] == "X") || //COLUMNA #1
		   (tablero[0][1] == "X" && tablero[1][1] == "X" && tablero[2][1] == "X") || //COLUMNA #2
		   (tablero[0][2] == "X" && tablero[1][2] == "X" && tablero[2][2] == "X") || //COLUMNA #3
		   (tablero[0][0] == "X" && tablero[1][1] == "X" && tablero[2][2] == "X") || //DIAGONAL INVERSA
		   (tablero[0][2] == "X" && tablero[1][1] == "X" && tablero[2][0] == "X") 	 //DIAGONAL INCLINADA
		   ){
		   	cout<<"\nEL GANADOR ES 'X'!!....";
		   	mostrar_tablero();
		   	RepetirJuego = 2;
		   	cout<<"\n¿Quieres jugar de nuevo?, Si=1, No=2: "; cin>>RepetirJuego;
		   	LimpiarTablero();
		   }
		   else{
		   	if((tablero[0][0] != "_" && tablero[0][1] != "_" && tablero[0][2] != "_") && //FILA #1
			   (tablero[1][0] != "_" && tablero[1][1] != "_" && tablero[1][2] != "_") && //FILA #2
			   (tablero[2][0] != "_" && tablero[2][1] != "_" && tablero[2][2] != "_") && //FILA #3
			   (tablero[0][0] != "_" && tablero[1][0] != "_" && tablero[2][0] != "_") && //COLUMNA #1
			   (tablero[0][1] != "_" && tablero[1][1] != "_" && tablero[2][1] != "_") && //COLUMNA #2
			   (tablero[0][2] != "_" && tablero[1][2] != "_" && tablero[2][2] != "_") && //COLUMNA #3
			   (tablero[0][0] != "_" && tablero[1][1] != "_" && tablero[2][2] != "_") && //DIAGONAL INVERSA
			   (tablero[0][2] != "_" && tablero[1][1] != "_" && tablero[2][0] != "_") 	 //DIAGONAL INCLINADA
			   ){
			   	cout<<"\nNO HAY NINGÚN GANADOR!! :("<<endl;
			   	mostrar_tablero();
			   	RepetirJuego = 2;
		   		cout<<"\n¿Quieres jugar de nuevo?, Si=1, No=2: "; cin>>RepetirJuego;
		   		LimpiarTablero();
			   }
			   else{
			   	system("cls");
				mostrar_tablero();
				cout<<""<<endl;
				turno_de_O();
				if((tablero[0][0] == "O" && tablero[0][1] == "O" && tablero[0][2] == "O") || //FILA #1
				   (tablero[1][0] == "O" && tablero[1][1] == "O" && tablero[1][2] == "O") || //FILA #2
				   (tablero[2][0] == "O" && tablero[2][1] == "O" && tablero[2][2] == "O") || //FILA #3
				   (tablero[0][0] == "O" && tablero[1][0] == "O" && tablero[2][0] == "O") || //COLUMNA #1
				   (tablero[0][1] == "O" && tablero[1][1] == "O" && tablero[2][1] == "O") || //COLUMNA #2
				   (tablero[0][2] == "O" && tablero[1][2] == "O" && tablero[2][2] == "O") || //COLUMNA #3
				   (tablero[0][0] == "O" && tablero[1][1] == "O" && tablero[2][2] == "O") || //DIAGONAL INVERSA
				   (tablero[0][2] == "O" && tablero[1][1] == "O" && tablero[2][0] == "O") 	 //DIAGONAL INCLINADA
				   ){
				   	cout<<"\nEL GANADOR ES 'O'!!....";
				   	mostrar_tablero();
				   	RepetirJuego = 2;
				   	cout<<"\n¿Quieres jugar de nuevo?, Si=1, No=2: "; cin>>RepetirJuego;
				   	LimpiarTablero();
			   	   }
			   }
		   }
	}	
	return 0;
}







