# -*- coding: utf-8 -*-
"""
Created on Mon May  9 18:54:08 2022

@author: Jorge Eduardo Ortega Silva

Descripcion: Descifrado DES de un txt, en base 64, en modo de operacion CBC
"""


import base64


from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import padding


def bytesBase64(bits):
    base64_bytes = base64.b64encode(bits)#arreglo de bytes en base 64
    base64_mensaje = base64_bytes.decode('UTF-8') #texto en base 64
    return base64_mensaje
    
def base64Bytes(cadenaBase64):
    base64_bytes = cadenaBase64.encode("UTF-8")#pasar de base 64 a texto
    mensaje_bytes = base64.b64decode(base64_bytes)       
    return mensaje_bytes


def descifradoDES(archivo, key, iv):
    backend = default_backend()
    with open (iv, "r") as doc:
        IV=doc.readline()#vector de inicializacion
        doc.close
    ivBits=base64Bytes(IV)
    with open (key, "r") as doc:
        KEY=doc.readline()#llave    
        doc.close
    keyBits=base64Bytes(KEY)
    with open (archivo, "r") as doc:
        mensaje=doc.read()#archivo cifrado
        mensaje_bytes = base64Bytes(mensaje)       
        doc.close
    cipher = Cipher(algorithms.TripleDES(keyBits), modes.CBC(ivBits), backend=backend)
    decryptor = cipher.decryptor()
    resultado=decryptor.update(mensaje_bytes) + decryptor.finalize()
    #decifrado con el padding
    #quita el padding
    unpadder = padding.PKCS7(128).unpadder()
    unpadder_data = unpadder.update(resultado) + unpadder.finalize()
    # de bytes a string
    cadena=unpadder_data.decode("utf-8")
    with open ("Descifrado_DES.txt", "w") as doc:#escritura del mensaje descifrado en txt
        doc.write(cadena)
        doc.close
    

    
print("Instrucciones: ingrese los nombres con extencion .txt\n")    
archivo=input("Nombre del archivo txt cifrado: ")
llave=input("Nombre del archivo con la llave: ")
iv=input("Nombre del archivo con el vector de inicializacion: ")
descifradoDES(archivo, llave, iv)       