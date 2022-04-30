
from collections import deque
from Jugadores import jugador
import serial
import time

import tkinter as tk
from tkinter import ttk



arduino = serial.Serial('COM2', 9600)
arduinoDOS = serial.Serial('COM4', 9600)
time.sleep(2)

tablero = [
	[" ", " ", " "],
	[" ", " ", " "],
	[" ", " ", " "],
]
jugador1=  jugador("Jugador1(x)",[
	[" ", " ", " "],
	[" ", " ", " "],
	[" ", " ", " "],
],"x",1)
jugador2=  jugador("Jugador2(0)",[
	[" ", " ", " "],
	[" ", " ", " "],
	[" ", " ", " "],
],"0",0)
turno = deque([jugador1, jugador2])

def mostrar_tablero():
	print("Tablero tota;")
	for fila in tablero:		
		print (fila)

def mostrar_tablero_jugadores():
    print(" JUGADOR 2")
    for fila in jugador1.tablero:
        print(fila)
    print("JUGADOR 1")
    for fila in jugador2.tablero:
        print(fila)

def actualizar_tablero(posicion, jugador):
    jugador.tablero[posicion[0]][posicion[1]] = jugador.tipo
    tablero[posicion[0]][posicion[1]] = jugador.tipo
    

def rotar_turno():
	turno.rotate()
	return turno[0]


def procesar_posicion(posicion):
	fila, columna = posicion.split(",")
	return [int(fila)-1, int(columna)-1]

def posicion_correcta(posicion):
	if 0 <= posicion[0] <= 2 and 0 <= posicion[1] <= 2:
		if tablero[posicion[0]][posicion[1]] == " ":
			return True
	return False

def ha_ganado(j):
	#compara las filas del tablero
	if tablero[0] == [j,j,j] or tablero[1] == [j,j,j] or tablero[2] == [j,j,j]:
		return True
	#compara las columnas
	elif tablero[0][0] == j and tablero[1][0] == j and tablero[2][0] == j:
		return True
	elif tablero[0][1] == j and tablero[1][1] == j and tablero[2][1] == j:
		return True
	elif tablero[0][2] == j and tablero[1][2] == j and tablero[2][2] == j:
		return True
	#compara las diagonales
	elif tablero[0][0] == j and tablero[1][1] == j and tablero[2][2] == j:
		return True
	elif tablero[0][2] == j and tablero[1][1] == j and tablero[2][0] == j:
		return True
	return False

def juego():
	mostrar_tablero_jugadores()
	jugador = rotar_turno()
	while True:
		
		if jugador.numero == 1:
			#print("Le toca a 1 ")
			arduinoDOS.write(b'1')
		elif jugador.numero == 0:
			#print("Le toca a 2 ")
			arduinoDOS.write(b'0')
		#posicion = input("Juega {}, elige una posicion (fila, columna) de 1 a 3. ".format(jugador.no))
		print("Juega {}, elige una posicion (fila, columna) de 1 a 3. ".format(jugador.no))
		variable = arduino.readline()
		posicion = variable.decode('utf-8')
		popupmsg("Jugada: " + posicion)
		try:
			posicion_l = procesar_posicion (posicion)			
		except:
			print ("Error, posicion {} no es válida. ".format(posicion))
			continue
		if posicion_correcta(posicion_l):
			actualizar_tablero(posicion_l, jugador)
			mostrar_tablero_jugadores()
			if ha_ganado(jugador.no):
				arduinoDOS.write(b'3')
				print ("Jugador de {} ha ganado!!!".format(jugador.no))
				break
			jugador = rotar_turno()
		else:
			print ("Posicion {} no válida".format(posicion))

def popupmsg(msg):
	try:
		popup = tk.Tk()
		popup.wm_title("!")
		label = ttk.Label(popup, text=msg)
		label.pack(side="top", fill="x", pady=10)
		B1 = ttk.Button(popup, text="Okay", command = popup.destroy)
		B1.pack()
		popup.mainloop()
	except:
 	 	print("An exception occurred")
juego()