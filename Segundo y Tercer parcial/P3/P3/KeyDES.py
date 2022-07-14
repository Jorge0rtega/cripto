# -*- coding: utf-8 -*-
"""
Created on Mon May  9 15:58:41 2022

@author: Jorge Ortega

Descripcion: generacion de los 2 tamaños de llaves en DES en base 64
"""

import os
import base64


def bytesBase64(bits):
    base64_bytes = base64.b64encode(bits)#arreglo de bytes en base 64
    base64_mensaje = base64_bytes.decode('UTF-8') #texto en base 64
    return base64_mensaje
    
def base64Bytes(cadenaBase64):
    base64_bytes = cadenaBase64.encode("UTF-8")#pasar de base 64 a texto
    mensaje_bytes = base64.b64decode(base64_bytes)       
    return mensaje_bytes

#Generador de claves DES 112 bits en base 64
keyDES112 = os.urandom(14)#numero de bytes
llave112Base64=bytesBase64(keyDES112) 
with open ("LlaveDES112.txt", "w") as doc:#escritura de la llave en txt
    doc.write(llave112Base64)
    doc.close

#Generador de claves DES 168 bits en base 64
keyDES168 = os.urandom(21)
llave168Base64=bytesBase64(keyDES168) 
with open ("LlaveDES168.txt", "w") as doc:#escritura de la llave en txt
    doc.write(llave168Base64)
    doc.close



