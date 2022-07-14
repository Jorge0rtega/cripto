# -*- coding: utf-8 -*-
"""
Created on Mon May  9 18:54:08 2022

@author: Jorge Ortega

Descripcion: Descifrado AES de un txt en base 64, en modo de operacion CTR
"""



import base64


from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend

def bytesBase64(bits):
    base64_bytes = base64.b64encode(bits)#arreglo de bytes en base 64
    base64_mensaje = base64_bytes.decode('UTF-8') #texto en base 64
    return base64_mensaje
    
def base64Bytes(cadenaBase64):
    base64_bytes = cadenaBase64.encode("UTF-8")#pasar de base 64 a texto
    mensaje_bytes = base64.b64decode(base64_bytes)       
    return mensaje_bytes


def descifradoAES(archivo, key, iv):
    backend = default_backend()
    with open (iv, "r") as doc:
        IV=doc.readline()# lectura vector de inicializacion
        doc.close
    ivBits=base64Bytes(IV)
    with open (key, "r") as doc:
        KEY=doc.readline() #lectura llave    
        doc.close
    keyBits=base64Bytes(KEY)
    with open (archivo, "r") as doc:
        mensaje=doc.read() #lectura mensaje cifrado
        mensaje_bytes = base64Bytes(mensaje)      
        doc.close
    cipher = Cipher(algorithms.AES(keyBits), modes.CTR(ivBits), backend=backend)
    decryptor = cipher.decryptor()
    resultado=decryptor.update(mensaje_bytes) + decryptor.finalize()
    cadena=resultado.decode("utf-8")
    
    with open ('Descifrado_AES.txt', 'w') as doc:#escritura del mnesaje descifrado en txt
        doc.write(cadena)
        doc.close

    

print("Instrucciones: ingrese los nombres con extencion .txt\n")    
archivo=input("Nombre del archivo txt cifrado: ")
llave=input("Nombre del archivo con la llave: ")
iv=input("Nombre del archivo con el vector de inicializacion: ")
descifradoAES(archivo, llave, iv)    
    