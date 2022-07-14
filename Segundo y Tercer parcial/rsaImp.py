# -*- coding: utf-8 -*-
"""
Created on Thu May 26 10:33:31 2022

@author: Jorge Ortega
"""
import rsa
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
    rxor=bytearray(b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
    while(i!=len(msj)):
        rxor=bytes(a ^ b for (a, b) in zip(rxor, msj[i:j]))#XOR
        i=i+4
        j=j+4
    resultado=bytesBase64(rxor)#conversion a base64
    return resultado
 
def generallaves(name):
    (pubKey, privKey) = rsa.newkeys(1024)
    with open(f'keys/pubkey{name}.pem', 'wb') as f:
        f.write(pubKey.save_pkcs1('PEM'))
 
    with open(f'keys/privkey{name}.pem', 'wb') as f:
        f.write(privKey.save_pkcs1('PEM'))
 
def obtenllaves(name):
    with open(f'keys/pubkey{name}.pem', 'rb') as f:
        pubKey = rsa.PublicKey.load_pkcs1(f.read())
 
    with open(f'keys/privkey{name}.pem', 'rb') as f:
        privKey = rsa.PrivateKey.load_pkcs1(f.read())
 
    return pubKey, privKey
 
def encrypt(msg, key):
    return rsa.encrypt(msg.encode('ascii'), key)
 
def decrypt(ciphertext, key):
    try:
        return rsa.decrypt(ciphertext, key).decode('ascii')
    except:
        return False
 
generallaves('Jorge')
generallaves('Juan')
pubKey, privKey = obtenllaves('Juan')
 
message = funcionHash('hola.txt')
ciphertext = encrypt(message, pubKey)
#print(f'Texto Cifrado: {ciphertext}')
with open('cipher.txt', 'wb') as f:
    f.write(bytes(bytesBase64(ciphertext),'ascii'))
 
with open('cipher.txt', "rb") as f:
    cipherFile=f.read()
    f.close
 
plaintext = decrypt(base64Bytes(cipherFile.decode('utf-8')), privKey)
 
if plaintext:
    print(f'HASH: {plaintext}')
else:
    print('Error no se pudo descifrar')
