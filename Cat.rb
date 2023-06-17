$tablero = [["_","_","_"],["_","_","_"],["_","_","_"]]


x = 0
y = 0

def mostrar_tablero()
  for i in (0..2)
    puts""
    for j in (0..2)
      print $tablero[i][j], " "
    end
  end
end


def validar(mensaje)
	i=gets.to_i
	while i==0
		if i==0
			print"Solamente se admiten números: "
			i=gets.to_i
		end
	end
	return i
end


def limpiartablero()
  $tablero[0][0] = "_"
  $tablero[0][1] = "_"
  $tablero[0][2] = "_"
  $tablero[1][0] = "_"
  $tablero[1][1] = "_"
  $tablero[1][2] = "_"
  $tablero[2][0] = "_"
  $tablero[2][1] = "_"
  $tablero[2][2] = "_"
end

def turno_de_x()
  $PedirDimenciones = 1
  while $PedirDimenciones == 1
    print("\nTURNO DE 'X'\n")
    print("\n")
    x = validar(print("Indica el Número de fila para 'X': "))
    x -= 1
    y = validar(print("Indica el Número de columna para 'X': "))
    y -= 1
    if x >= 3 or y >= 3
      print("\nNO PUEDE DAR VALORES MAYORES A 3!!, ELIGA ENTRE 1-3...")
      $PedirDimenciones = 1
    elsif $tablero[x][y] == "_"
      $tablero[x][y] = "X"
      $PedirDimenciones = 2
    else
      print("Casilla ocupada, Eliga otra por favor...")
      $PedirDimenciones = 1
    end
  end
end


def turno_de_o()
  $PedirDimenciones = 1
  while $PedirDimenciones == 1
    print("\nTURNO DE 'O'\n")
    print("\n")
    x = validar(print("Indica el Número de fila para 'O': "))
    x -= 1
    y = validar(print("Indica el Número de columna para 'O': "))
    y -= 1
    if x >= 3 or y >= 3
      print("\nNO PUEDE DAR VALORES MAYORES A 3!!, ELIGA ENTRE 1-3...")
      $PedirDimenciones = 1
    elsif $tablero[x][y] == "_"
      $tablero[x][y] = "O"
      $PedirDimenciones = 2
    else
      print("Casilla ocupada, Eliga otra por favor...")
      $PedirDimenciones = 1
    end
  end
end


$RepetirJuego = 1
while $RepetirJuego == 1
  system "cls"
  mostrar_tablero()
  print("")
  turno_de_x()
  if ($tablero[0][0] == "X" and $tablero[0][1] == "X" and $tablero[0][2] == "X") || ($tablero[1][0] == "X" and $tablero[1][1] == "X" and $tablero[1][2] == "X") || ($tablero[2][0] == "X" and $tablero[2][1] == "X" and $tablero[2][2] == "X") || ($tablero[0][0] == "X" and $tablero[1][0] == "X" and $tablero[2][0] == "X") || ($tablero[0][1] == "X" and $tablero[1][1] == "X" and $tablero[2][1] == "X") || ($tablero[0][2] == "X" and $tablero[1][2] == "X" and $tablero[2][2] == "X") || ($tablero[0][0] == "X" and $tablero[1][1] == "X" and $tablero[2][2] == "X") || ($tablero[0][2] == "X" and $tablero[1][1] == "X" and $tablero[2][0] == "X")
    puts"EL GANADOR ES 'X'!!...."
    mostrar_tablero()
    $RepetirJuego = 2
    puts"\n"
    print"\n¿Quieres jugar de nuevo?, Si=1, No=2: "
    $RepetirJuego = gets.to_i
    limpiartablero()
  else
    if $tablero[0][0] != "_" and $tablero[0][1] != "_" and $tablero[0][2] != "_" and $tablero[1][0] != "_" and $tablero[1][1] != "_" and $tablero[1][2] != "_" and $tablero[2][0] != "_" and $tablero[2][1] != "_" and $tablero[2][2] != "_" and $tablero[0][0] != "_" and $tablero[1][0] != "_" and $tablero[2][0] != "_" and $tablero[0][1] != "_" and $tablero[1][1] != "_" and $tablero[2][1] != "_" and $tablero[0][2] != "_" and $tablero[1][2] != "_" and $tablero[2][2] != "_" and $tablero[0][0] != "_" and $tablero[1][1] != "_" and $tablero[2][2] != "_" and $tablero[0][2] != "_" and $tablero[1][1] != "_" and $tablero[2][0] != "_"
      print("\nNO HAY NINGÚN GANADOR!! :(\n")
      mostrar_tablero()
      $RepetirJuego = 2
      puts"\n"
      print"\n¿Quieres jugar de nuevo?, Si=1, No=2: "
      $RepetirJuego = gets.to_i
      limpiartablero()
    else
      system "cls"
      mostrar_tablero()
      print("")
      turno_de_o()
      if ($tablero[0][0] == "O" and $tablero[0][1] == "O" and $tablero[0][2] == "O") or ($tablero[1][0] == "O" and $tablero[1][1] == "O" and $tablero[1][2] == "O") or ($tablero[2][0] == "O" and $tablero[2][1] == "O" and $tablero[2][2] == "O") or ($tablero[0][0] == "O" and $tablero[1][0] == "O" and $tablero[2][0] == "O") or ($tablero[0][1] == "O" and $tablero[1][1] == "O" and $tablero[2][1] == "O") or ($tablero[0][2] == "O" and $tablero[1][2] == "O" and $tablero[2][2] == "O") or ($tablero[0][0] == "O" and $tablero[1][1] == "O" and $tablero[2][2] == "O") or ($tablero[0][2] == "O" and $tablero[1][1] == "O" and $tablero[2][0] == "O")
        print("\nEL GANADOR ES 'O'!!....\n")
        mostrar_tablero()
        $RepetirJuego = 2
        puts"\n"
        print"\n¿Quieres jugar de nuevo?, Si=1, No=2: "
        $RepetirJuego = gets.to_i
        limpiartablero()
      end
    end
  end
end
