# -*- coding: utf-8 -*-
"""
Created on Mon May  9 15:58:41 2022

@author: Jorge Ortega

Descripcion: generacion de los 3 tamaños de llaves en AES en base 64
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

#Generador de claves AES 128 bits en base 64
keyAES128 = os.urandom(16)#numero de bytes
llave128Base64=bytesBase64(keyAES128) 
with open ("LlaveAES128.txt", "w") as doc:#escritura de la llave en txt
    doc.write(llave128Base64)
    doc.close

#Generador de claves DES 192 bits en base 64
keyAES192 = os.urandom(24)

llave192Base64=bytesBase64(keyAES192) 
with open ("LlaveAES192.txt", "w") as doc:#escritura de la llave en txt
    doc.write(llave192Base64)
    doc.close


#Generador de claves DES 256 bits en base 64
keyAES256 = os.urandom(32)

llave256Base64=bytesBase64(keyAES256) 
with open ("LlaveAES256.txt", "w") as doc:#escritura de la llave en txt
    doc.write(llave256Base64)
    doc.close