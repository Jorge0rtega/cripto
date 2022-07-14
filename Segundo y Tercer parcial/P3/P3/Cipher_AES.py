# -*- coding: utf-8 -*-
"""
Created on Mon May  9 17:51:27 2022

@author: Jorge Ortega

Descripcion: Cifrado AES de un txt en base 64, en modo de operacion CTR
"""


import os
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

def cifradoAES(archivo):
    backend = default_backend()
    
    iv = os.urandom(16)#vector de inicializacion
    ivBase64=bytesBase64(iv)   
    
    #Generador de claves AES 128 bits en base 64
    keyAES128 = os.urandom(16) #llave 128 bits
    keyBase64=bytesBase64(keyAES128)
    
    with open ("Key_AES.txt", "w") as doc:#escritura de la llave en txt
        doc.write(keyBase64)
        doc.close
    with open ("IV_AES.txt", "w") as doc:#escritura del vector de inicializacion en txt
        doc.write(ivBase64)
        doc.close
    with open (archivo, "rb") as doc:
        mensaje=doc.read()
        doc.close

    #cifrado
    cipher = Cipher(algorithms.AES(keyAES128), modes.CTR(iv), backend=backend)
    encryptor = cipher.encryptor()
    ct = encryptor.update(mensaje) + encryptor.finalize()

    with open ("Cifrado_AES.txt", "w") as doc:#escritura del mensaje cifrado en txt
        base64_mensaje = bytesBase64(ct)
        doc.write(base64_mensaje)
        doc.close
    
print("Instrucciones: ingrese el nombre con extencion .txt\n")    
archivo=input("Nombre del archivo txt cifrado: ")
cifradoAES(archivo)