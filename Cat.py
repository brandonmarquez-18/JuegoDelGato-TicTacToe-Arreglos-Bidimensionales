import os #SIRVE PARA USAR EL "os.system("cls")" QUE ES PARA LIMPIAR PANTRALLA
#ARREGLO MATRICIAL DE 3X3 PARA EL TABLERO
tablero = [["_","_","_"],#FILA #1
           ["_","_","_"],#FILA #2
           ["_","_","_"]]#FILA #3

x = 0
y = 0

def mostrar_tablero():#//EL NOMBRE DE DE LA FUNCION ES: "mostrar_tablero"
    for i in range(0,3):#//SE HACE CICLO "for" PARA PARA QUE "i" PASE POR CADA UNA DE LAS FILAS DEL ARREGLO MATRICIAL "tablero"
        print("")#SALTO DE LINEA
        for j in range(0,3):#SE HACE CICLO "for" PARA PARA QUE "j" PASE POR CADA UNA DE LAS COMLUMNAS DEL ARREGLO MATRIACIAL "tablero"
            print(tablero[i][j], end = " ")#SE IMPRIME EL ARREGLO MATRICIAL "tablero" INVOCANDO A LOS 2 CICLOS "for" ANTERIORES TOMANDO CADA UNA-
                                           #DE LAS DIMENCIONES QUE TOMÓ "i" y "j" A BASE DE LOS 2 CICLOS "for" ANTERIORES

def LimpiarTablero():
    tablero[0][0] = "_"
    tablero[0][1] = "_"
    tablero[0][2] = "_"
    tablero[1][0] = "_"
    tablero[1][1] = "_"
    tablero[1][2] = "_"
    tablero[2][0] = "_"
    tablero[2][1] = "_"
    tablero[2][2] = "_"


def validar(mensaje):#definimos(def) la función para validar el "mensaje"(parametro) de entrada para elegir opcion del menú principal
    bandera = True #Variable de control para tomar una desición o tambien es como un parámetro la iniciamos en "True"
    while bandera: #Mientras la bandera sea "True" hacer:
        try:#Intenta hacer:
            valor = int(input(mensaje)) #Se lee el "mensaje" de entrada que sea de tipo entero
            bandera = False #Si el dato ingresado es entero la variable de control se rompe y no se vuelve a repetir que nos pida otra opción
        except:#Si no se ingreso un entero se muestra el siguiente mensaje con "print("")"
            print ("\nSolamente se admiten números enteros")
    return valor #Con "return" retornamos o regresamos a la asignación de valor, es decir para que se le vuelva a dar lectura a la opción deseada del menú principal


def turno_de_x():
    PedirDimenciones = 1
    while PedirDimenciones == 1:
        print("\nTURNO DE 'X'\n")
        print("")
        x = validar("Indica el Número de fila para 'X': ")
        x -= 1
        y = validar("Indica el Número de columna para 'X': ")
        y -= 1
        if x >= 3 or y >= 3:
            print("\nNO PUEDE DAR VALORES MAYORES A 3!!, ELIGA ENTRE 1-3...")
            PedirDimenciones = 1
        else:
            if tablero[x][y] == "_":
                tablero[x][y] = "X"
                PedirDimenciones = 2
            else:
                print("Casilla ocupada, Eliga otra por favor...")
                PedirDimenciones = 1


def turno_de_o():
    PedirDimenciones = 1
    while PedirDimenciones == 1:
        print("\nTURNO DE 'O'\n")
        print("")
        x = validar("Indica el Número de fila para 'O': ")
        x -= 1
        y = validar("Indica el Número de columna para 'O': ")
        y -= 1
        if x >= 3 or y >= 3:
            print("\nNO PUEDE DAR VALORES MAYORES A 3!!, ELIGA ENTRE 1-3...")
            PedirDimenciones = 1
        else:
            if tablero[x][y] == "_":
                tablero[x][y] = "O"
                PedirDimenciones = 2
            else:
                print("Casilla ocupada, Eliga otra por favor...")
                PedirDimenciones = 1



RepetirJuego = 1
while RepetirJuego == 1:
    os.system("cls")
    mostrar_tablero()
    print("")
    turno_de_x()
    if tablero[0][0] == "X" and tablero[0][1] == "X" and tablero[0][2] == "X" or tablero[1][0] == "X" and tablero[1][1] == "X" and tablero[1][2] == "X" or tablero[2][0] == "X" and tablero[2][1] == "X" and tablero[2][2] == "X" or tablero[0][0] == "X" and tablero[1][0] == "X" and tablero[2][0] == "X" or tablero[0][1] == "X" and tablero[1][1] == "X" and tablero[2][1] == "X" or tablero[0][2] == "X" and tablero[1][2] == "X" and tablero[2][2] == "X" or tablero[0][0] == "X" and tablero[1][1] == "X" and tablero[2][2] == "X" or tablero[0][2] == "X" and tablero[1][1] == "X" and tablero[2][0] == "X":
        print("\nEL GANADOR ES 'X'!!....")
        mostrar_tablero()
        RepetirJuego = 2
        RepetirJuego = int(input("\n¿Quieres jugar de nuevo?, Si=1, No=2: "))
        LimpiarTablero()
    else:
        if tablero[0][0] != "_" and tablero[0][1] != "_" and tablero[0][2] != "_" and tablero[1][0] != "_" and tablero[1][1] != "_" and tablero[1][2] != "_" and tablero[2][0] != "_" and tablero[2][1] != "_" and tablero[2][2] != "_" and tablero[0][0] != "_" and tablero[1][0] != "_" and tablero[2][0] != "_" and tablero[0][1] != "_" and tablero[1][1] != "_" and tablero[2][1] != "_" and tablero[0][2] != "_" and tablero[1][2] != "_" and tablero[2][2] != "_" and tablero[0][0] != "_" and tablero[1][1] != "_" and tablero[2][2] != "_" and tablero[0][2] != "_" and tablero[1][1] != "_" and tablero[2][0] != "_":
            print("\nNO HAY NINGÚN GANADOR!! :(\n")
            mostrar_tablero()
            RepetirJuego = 2
            RepetirJuego = int(input("\n¿Quieres jugar de nuevo?, Si=1, No=2: "))
            LimpiarTablero()
        else:
            os.system("cls")
            mostrar_tablero()
            print("")
            turno_de_o()
            if tablero[0][0] == "O" and tablero[0][1] == "O" and tablero[0][2] == "O" or tablero[1][0] == "O" and tablero[1][1] == "O" and tablero[1][2] == "O" or tablero[2][0] == "O" and tablero[2][1] == "O" and tablero[2][2] == "O" or tablero[0][0] == "O" and tablero[1][0] == "O" and tablero[2][0] == "O" or tablero[0][1] == "O" and tablero[1][1] == "O" and tablero[2][1] == "O" or tablero[0][2] == "O" and tablero[1][2] == "O" and tablero[2][2] == "O" or tablero[0][0] == "O" and tablero[1][1] == "O" and tablero[2][2] == "O" or tablero[0][2] == "O" and tablero[1][1] == "O" and tablero[2][0] == "O":
                print("\nEL GANADOR ES 'O'!!....")
                mostrar_tablero()
                RepetirJuego = 2
                RepetirJuego = int(input("\n¿Quieres jugar de nuevo?, Si=1, No=2: "))
                LimpiarTablero()
