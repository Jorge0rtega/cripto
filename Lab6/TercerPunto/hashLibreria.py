# -*- coding: utf-8 -*-
"""
Created on Thu May 19 19:12:08 2022

@author: Jorge Ortega
"""

from cryptography.hazmat.primitives import hashes
import base64


def bytesBase64(bits):
    base64_bytes = base64.b64encode(bits)#arreglo de bytes en base 64
    base64_mensaje = base64_bytes.decode('UTF-8') #texto en base 64
    return base64_mensaje

def funcionhash(archivo):
    digest = hashes.Hash(hashes.SHA256()) #SHA-2 (256 bits)
    with open (archivo, "rb") as doc:
        mensaje=doc.read()
        doc.close
    msj=bytearray(mensaje)
    digest.update(msj)   
    resultado=digest.finalize()#devuelve el resultado en bits
    print("Resultado de la funcion hash bits: ",resultado)
    print("Resultado de la funcion hash Base64: ",bytesBase64(resultado))
    
print("Archivo de texto\n")
funcionhash("texto.txt")
print("\n")
print("Imagen\n")
funcionhash("imagen.jpg")
print("\n")
print("Video\n")
funcionhash("video.mp4")