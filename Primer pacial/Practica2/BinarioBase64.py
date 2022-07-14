# -*- coding: utf-8 -*-
"""
Nombre: Ortega Silva Jorge Eduardo
Fecha: 03/03/2022
Descripción: uso de las funciones de generador de numeros pseudoaleatorios para criptografia
asi como convertir una cadena binaria a cadena en base 64.
"""

#numeros binarios pseudoaleatorios
import secrets
import base64

def bitsaleatorios(n):
    print("Bits pseudoaleatorio")
    for i in range(0, n+1):
        print("Bit pseudoaleatorio ",i,": ",secrets.randbits(1),"\n")#numero aleatorio de un bit


#funcion para convertir de binario a base64
def binarioBase64(bnr):
    #variables para la conversion de binario a decimal
    posicion = 0
    decimal = 0
    start=0
    long=len(bnr)# longitud de la cadena binaria
    binario="" #bloques de 8 bits
    texto="" #cadena de texto
    if(long%8!=0):#agregar ceros faltantes a la cadena
        ceros=8-long%8
        bnr=bnr[::-1]
        for i in range (0, ceros):
            bnr+='0'
        bnr=bnr[::-1]
    long=len(bnr) 
    while(start!=long):#Convertir de binario a decimal
        for i in range(start, start+8):
            binario+=str(bnr[i])
        binario = binario[::-1]#invertir la cadena
        for digito in binario:    
            decimal += int(digito) * 2**posicion # Elevar 2 a la posición actual y multiplicar por el bit
            posicion += 1
            
        texto+=chr(decimal)#convertir de decimal a caracter
        
        start=start+8
        binario=""
        decimal=0
        posicion=0
    mensaje_bytes = texto.encode('UTF-8') #mensaje en tipo bytes
    base64_bytes = base64.b64encode(mensaje_bytes)#arreglo de bytes en base 64
    base64_mensaje = base64_bytes.decode('UTF-8') #texto en base 64
    return base64_mensaje



#probando la funcion de n bits aleatorios
bitsaleatorios(8)


#probando la funcion binario a base 64
varBase64=binarioBase64("1001010011011110111100100110011101100101")
print("Texto en base 64: ",varBase64)


