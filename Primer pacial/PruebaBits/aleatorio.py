# -*- coding: utf-8 -*-
"""
Created on Wed Mar  2 20:00:48 2022

@author: Jorge Ortega
"""

import secrets
print(secrets.randbits(1))#numero aleatorio de un bit
print(secrets.randbelow(2))#numero aleatorio entre [0, 2)

#Base 64 en cadenas
#cadenas a base
import base64
mensaje = "Python is fun"
mensaje_bytes = mensaje.encode('ascii')
print(mensaje_bytes)
print(mensaje_bytes[0])
print(format(mensaje_bytes[0], "b"))
base64_bytes = base64.b64encode(mensaje_bytes)
print(base64_bytes)
base64_mensaje = base64_bytes.decode('ascii')
print(f"{base64_mensaje}")


print(base64_mensaje)

#base a cadena

base64_mensaje="UHl0aG9uIGlzIGZ1bg=="
base64_bytes = base64_mensaje.encode('ascii')
print(base64_bytes)
mensaje_bytes = base64.b64decode(base64_bytes)
print(mensaje_bytes)
mensaje = mensaje_bytes.decode('ascii')



