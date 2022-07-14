# -*- coding: utf-8 -*-
"""
Created on Thu May 19 12:21:43 2022

@author: Jorge Ortega
"""
import base64

def bytesBase64(bits):
    base64_bytes = base64.b64encode(bits)#arreglo de bytes en base 64
    base64_mensaje = base64_bytes.decode('UTF-8') #texto en base 64
    return base64_mensaje
    
def base64Bytes(cadenaBase64):
    base64_bytes = cadenaBase64.encode("UTF-8")#pasar de base 64 a texto
    mensaje_bytes = base64.b64decode(base64_bytes)       
    return mensaje_bytes

def funcionHash(archivo):
    with open (archivo, "rb") as doc:
        mensaje=doc.read()
        doc.close
    msj=bytearray(mensaje)

    if(len(msj)%4!=0):#completar la cadena de bits para bloques de 32 bits
        for i in range(0, 4-(len(msj)%4)):
            msj.append(0)# agregar para completar

    i=0
    j=4
    #4bytes de ceros
    rxor=bytearray(b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
    while(i!=len(msj)):
        rxor=bytes(a ^ b for (a, b) in zip(rxor, msj[i:j]))#XOR
        i=i+4
        j=j+4  
    resultado=bytesBase64(rxor)#conversion a base64
    return resultado

txt=input("Ingrese el nombre del archivo de texto: ")
print("Resultado de la funcion hash: ",funcionHash(txt))