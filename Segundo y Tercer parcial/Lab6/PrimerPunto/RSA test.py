# -*- coding: utf-8 -*-
"""
Created on Thu May 19 10:34:15 2022

@author: Jorge Ortega
"""

from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives import hashes
#llave privada
private_key = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
)
print(private_key)
#llave publica
public_key = private_key.public_key()
print(public_key)
#cifrado
message = b"Jorge0rtega"
ciphertext = public_key.encrypt(
    message,
    padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None
    )
)
print(ciphertext)

#descifrado
plaintext = private_key.decrypt(
    ciphertext,
    padding.OAEP(
        mgf=padding.MGF1(algorithm=hashes.SHA256()),
        algorithm=hashes.SHA256(),
        label=None
    )
)
print(plaintext)
print(plaintext == message)

#llaves 2

#llave privada
private_key1 = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
)
#llave publica
public_key1 = private_key.public_key()


#firma
message = b"Esta es mi firma"
signature = private_key.sign(
    message,
    padding.PSS(
        mgf=padding.MGF1(hashes.SHA256()),
        salt_length=padding.PSS.MAX_LENGTH
    ),
    hashes.SHA256()
)

public_key1.verify(
    signature,
    message,
    padding.PSS(
        mgf=padding.MGF1(hashes.SHA256()),
        salt_length=padding.PSS.MAX_LENGTH
    ),
    hashes.SHA256()
)