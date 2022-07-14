# -*- coding: utf-8 -*-
"""
Nombre: Ortega Silva Jorge Eduardo
Fecha: 03/03/2022
Descripción: funcion que simule el descifrado One-time pad
"""

#numeros binarios pseudoaleatorios
import secrets
import base64
"""
print("Bits pseudoaleatorio")
for i in range(0, 6):
    print("Bit pseudoaleatorio ",i,": ",secrets.randbits(1),"\n")#numero aleatorio de un bit
"""

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

def base64Binario(texto):
    base64_bytes = texto.encode("UTF-8")#pasar de base 64 a texto
    mensaje_bytes = base64.b64decode(base64_bytes)
    mensaje = mensaje_bytes.decode("UTF-8")
    txtBinario=conversoBinario(mensaje)#pasar de texto a binario
        
    return txtBinario
    
def conversoBinario(texto):
    txtBin=""
    txtBinCaracter=""
    
    long=len(texto)
    for i in range(0, long):
        
        decimal=ord(texto[i])
        
        while decimal != 0: # mientras el número de entrada sea diferente de cero
            modulo = decimal % 2
            cociente = decimal // 2
            txtBinCaracter+=str(modulo)
            decimal = cociente # el cociente pasa a ser el número de entrada

        tamBloque=len(txtBinCaracter)        
        if(tamBloque%8!=0):#agregar ceros faltantes a la cadena
            ceros=8-tamBloque%8
            for i in range (0, ceros):
                txtBinCaracter+='0'

        txtBin+=txtBinCaracter[::-1]#boltear cada binario para su lectura final
        txtBinCaracter=""
    return txtBin


def keyTOP(longitud):
    key=""
    for i in range(0, longitud):#numeros aleatorios del tamaño de longitud
        key+=str(secrets.randbits(1))
    return key

   
def descifradoTOP(texto, clave):
    #operacion xor
    textoBin=base64Binario(texto)#convertir la base 64 en binario
    clave=base64Binario(clave)#convertir la base 64 en binario
    long=len(textoBin)
    descifrado=""# guardar el texto cifrado
    for i in range(0, long):#aplicar xor para descifrar
        if(textoBin[i]==clave[i]):
            descifrado+='0'
        else:
            descifrado+='1'
    txtBase64=binarioBase64(descifrado)#convertir el binario descifrado a base 64
    base64_bytes = txtBase64.encode("UTF-8")#pasar de base 64 a caracteres
    mensaje_bytes = base64.b64decode(base64_bytes)
    mensaje = mensaje_bytes.decode("UTF-8")
    return mensaje #mensaje final


msjCifrado=input("Ingrese el texto a descifrar: ")
#definir llave
llave=input("Ingrese la llave: ")

msjDescifrado=descifradoTOP(msjCifrado, llave)
print("Mensaje descifrado: ",msjDescifrado)







