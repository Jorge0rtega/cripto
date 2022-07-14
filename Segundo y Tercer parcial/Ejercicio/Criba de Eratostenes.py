# -*- coding: utf-8 -*-
"""
Created on Thu May 12 12:02:41 2022

@author: Jorge Ortega
"""
 
def cribaEratostenes(n): 
    numeros=[]
    for i in range(2, n+1):
        numeros.append(i)
    i=0
    while(numeros[i]*numeros[i]<=n):
        for j in numeros:
            if((j%numeros[i])==0 and j!=numeros[i]):
                numeros.remove(j)
        i=i+1
    return numeros


primos=cribaEratostenes(10000)
with open ("Primos.txt", "w") as doc:
    doc.write(str(primos))
    doc.close
