# -*- coding: utf-8 -*-
"""
Created on Thu May 26 20:44:09 2022

@author: Jorge Ortega
"""

def PLD(p, g, y):
    numeros=[]
    for i in range(1, p):
        numeros.append(i)
    for i in range(0, p-1):
        if((pow(g,numeros[i])%p)==y):
            return numeros[i]
    return 0


print("El valor de x es: ",PLD(109, 23, 77))