# -*- coding: utf-8 -*-
"""
Created on Thu May 26 12:24:37 2022

@author: Jorge Ortega
"""

def generadores(primo):
    numeros=[]
    ocupado=[]
    generadores=[]
    cont=0
    for i in range(1, primo):
        numeros.append(i)
    i=0
    #print(numeros)
    for i in range(1, primo):
        ocupado.append(1)
    #print(ocupado)
    i=0
    for i in range(0, primo-1):
        for j in range(1, primo):
            var=(pow(numeros[i],j)%primo)-1
            if(ocupado[var]==1):
                ocupado[var]=0
        #print(ocupado)
        for j in range(0, primo-1):
            if(ocupado[j-1]==0):
                cont=cont+1
            ocupado[j-1]=1
            
        if(cont==primo-1):
            generadores.append(i+1)
        cont=0
    #print(generadores)
    with open ("Generadores.txt", "w") as doc:
        doc.write(str(generadores))
        doc.close
    
    
generadores(647)