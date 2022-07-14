# -*- coding: utf-8 -*-
"""
Created on Sat Jun 11 20:03:36 2022

@author: Israel Hernández, Jorge Ortega, Juan Sarmiento
"""

import base64
import numpy as np

def binarioBase64(bnr):#funcion para convertir de binario a base64
    #variables para la conversion de binario a decimal
    posicion = 0
    decimal = 0
    start=0
    long=len(bnr)# longitud de la cadena binaria
    binario="" #bloques de 8 bits
    texto="" #cadena de texto
    if(long%8!=0):#agregar ceros faltantes a la cadena
        ceros=8-long%8
        bnr=bnr[::-1]
        for i in range (0, ceros):
            bnr+='0'
        bnr=bnr[::-1]
    long=len(bnr) 
    while(start!=long):#Convertir de binario a decimal
        for i in range(start, start+8):
            binario+=str(bnr[i])
        binario = binario[::-1]#invertir la cadena
        for digito in binario:    
            decimal += int(digito) * 2**posicion # Elevar 2 a la posición actual y multiplicar por el bit
            posicion += 1
            
        texto+=chr(decimal)#convertir de decimal a caracter
        
        start=start+8
        binario=""
        decimal=0
        posicion=0
    mensaje_bytes = texto.encode('UTF-8') #mensaje en tipo bytes
    base64_bytes = base64.b64encode(mensaje_bytes)#arreglo de bytes en base 64
    base64_mensaje = base64_bytes.decode('UTF-8') #texto en base 64
    return base64_mensaje

def base64Binario(texto):#pasar de base64 a binaria
    base64_bytes = texto.encode("UTF-8")#pasar de base 64 a texto
    mensaje_bytes = base64.b64decode(base64_bytes)
    mensaje = mensaje_bytes.decode("UTF-8")
    txtBinario=conversoBinario(mensaje)#pasar de texto a binario
        
    return txtBinario

def conversoBinario(texto):#pasar de texto plano a binario en forma de cadena
    txtBin=""
    txtBinCaracter=""
    
    long=len(texto)
    for i in range(0, long):
        
        decimal=ord(texto[i])
        
        while decimal != 0: # mientras el número de entrada sea diferente de cero
            modulo = decimal % 2
            cociente = decimal // 2
            txtBinCaracter+=str(modulo)
            decimal = cociente # el cociente pasa a ser el número de entrada

        tamBloque=len(txtBinCaracter)        
        if(tamBloque%8!=0):#agregar ceros faltantes a la cadena
            ceros=8-tamBloque%8
            for i in range (0, ceros):
                txtBinCaracter+='0'

        txtBin+=txtBinCaracter[::-1]#boltear cada binario para su lectura final
        txtBinCaracter=""
    return txtBin

def multBin(b1, b2): #multiplicacion de dos cadena binarias "0011" de 4 bits
    cont=0
    aux=0
    unos=0
    copyB2=list("")
    auxB2=list("")
    b1=list(b1)
    b2=list(b2)
    r="0011" #residuo del polinomio irreducible x^4+x+1	
    mult=np.identity(4, str)
    listaMult=np.identity(4, str)
    resultado=list("0000")
    res=""
    
    for i in range(0, 4):
        mult[i]="0000"
    for i in range(0, 4):
        listaMult[i]="0000"
        
    for i in range(0, 4):
        mult[0][i]=b2[i]
    auxB2=b2.copy()
    for j in range(0, 3):
        copyB2=b2.copy()
        if(b2[0]=='0'):
            b2[3]='0'
            for i in range(0, 3):
                b2[i]=copyB2[i+1]
        else:
            b2[3]='0'
            for i in range(0, 3):
                b2[i]=copyB2[i+1]
            for i in range(0, 4):
                if (b2[i]==r[i]):
                    b2[i]='0'
                else:
                    b2[i]='1'
        #print(b2)     
        mult[j+1]=b2
    b2=auxB2.copy()
    aux=3
    #print(mult)
    
    for i in range(0, 4):
        if(b1[i]=='1'):
            for j in range(0, 4):
                listaMult[cont][j]=mult[aux][j]
            cont=cont+1
        aux=aux-1
    #print("--------")
    #print(listaMult)
    for i in range(0, 4):
        unos=0
        for j in range(0, cont):
            if(listaMult[j][i]=='1'):
                unos=unos+1
        #print(unos)        
        if((unos%2)==1):
            resultado[i]='1'
        else:
            resultado[i]='0'
    for i in range(0, 4):
        res=res+resultado[i]
    return res

def xor(v1, v2):#funcion de xor de dos cadenas binarias "0011"
    r=""
    for i in range(0, 4):
        if (v1[i]==v2[i]):
            r=r+'0'
        else:
            r=r+'1'
    return r

def binarioDecimal(binNum):
	decNum = 0 
	for i, j in enumerate(binNum[::-1]):
		decNum += int(j) * 2 ** i
	return decNum

def nibbleSubInv(a):#4 nibble
    sbox=["1110","0011","0100","1000","0001","1100","1010","1111",
          "0111","1101","1001","0110","1011","0010","0000","0101"]
    b=[]
    for i in range(0, 4):
        for j in range(0, 16):
            if(binarioDecimal(a[i])==j):
                b.append(sbox[j])
    return b

def shiftRow(b):
    c=[]
    c.append(b[0])
    c.append(b[3])
    c.append(b[2])
    c.append(b[1])
    return c

def mixColumn(c):#funcion de mixColumn
    cons03="0011"#matris constante del articulo
    cons12="0010"
    d=[]
    d01=multBin(cons03, c[0])#aplicacion de la multiplicacion binaria
    d02=multBin(cons12, c[1])
    d.append(xor(d01, d02))#aplicacion xor de ambos resultados
    
    d11=multBin(cons12, c[0])
    d12=multBin(cons03, c[1])
    d.append(xor(d11, d12))
    
    d21=multBin(cons03, c[2])
    d22=multBin(cons12, c[3])
    d.append(xor(d21, d22))
    
    d31=multBin(cons12, c[2])
    d32=multBin(cons03, c[3])
    d.append(xor(d31, d32))
    
    return d
    

def keyAddition(k, d):#funcion de key addition
    e=[]
    for i in range(0, 4):
        e.append(xor(k[i], d[i]))
    return e

def nibbleSub1(cadenaBit):#1 nibble
    s_Box_MiniAES = {
                        '0000':'1110', '1000':'0011',
                        '0001':'0100', '1001':'1010',
                        '0010':'1101', '1010':'0110',
                        '0011':'0001', '1011':'1100',
                        '0100':'0010', '1100':'0101',
                        '0101':'1111', '1101':'1001',
                        '0110':'1011', '1110':'0000',
                        '0111':'1000', '1111':'0111'
                    };
    nibbleSub = s_Box_MiniAES.get(cadenaBit);
    return nibbleSub;

def key_Schedule(key):
    
    if( isinstance(key, bytes) ):
       key = int.from_bytes(key, byteorder='big');
       
    key = bin(key);
    keysustraer = key[2:];
    keyPadding = keysustraer.zfill(16);
    k0 = keyPadding[0:4];
    k1 = keyPadding[4:8];
    k2 = keyPadding[8:12];
    k3 = keyPadding[12:16];
    
    k= [k0, k1, k2, k3];

    tamano = len(k);
    W = [];

    #Numero de ronda
    numeroRondas=2;
    rcon=1; #Constante de ronda
    index=0;
    for i in range(0, numeroRondas+1 ):
        for j in range(0, tamano):
            if(i==0):
                W.append(k[j]);
            else:
                if(j==0):
                    w=(int( W[index], 2))^(int( nibbleSub1( W[index+3] ), 2) )^( rcon );
                    W.append(bin(w)[2:].zfill(4));
                    index = index+1;
                    rcon = rcon+1;
                else:
                    w=(int( W[index], 2))^(int( W[index+3], 2));
                    W.append(bin(w)[2:].zfill(4));
                    index = index+1;

    K0=[W[0], W[1], W[2], W[3] ];
    K1=[W[4], W[5], W[6], W[7] ];
    K2=[W[8], W[9], W[10], W[11] ];

    K = [ K0, K1, K2 ];
    
    return K;

def hacerNibble(c):
    n=[]
    for i in range(0, len(c),4):
        n.append(c[i]+c[i+1]+c[i+2]+c[i+3])
    return n


def descifrado16Bits(cadena, llave):
    
    #cadena="1001110001100011"#mensaje del ejemplo del articulo para cifrado
    c=hacerNibble(cadena)#convirtiendo a nibble
    
    #Obteniendo las claves de ronda
    claveR=key_Schedule(llave)
    
    #Aplicando keyAddition
    H=keyAddition(claveR[2], c)
    G=shiftRow(H)
    F=nibbleSubInv(G)
    E=keyAddition(claveR[1], F)
    D=mixColumn(E)
    C=shiftRow(D)
    B=nibbleSubInv(C)
    A=keyAddition(claveR[0], B)

    
    #quitamos formato nibble a cadena
    descifrado=A[0]+A[1]+A[2]+A[3]
    return descifrado
    
def descifradoAESMini(archivo, llave):
    bloques=[]
    descifrado=""
    cont=0
    with open (archivo, "r") as doc:#lectura del archivo
        mensaje=doc.read()#lectura en binario
        doc.close
    m=base64Binario(mensaje)#mensaje en forma de binario
    with open (llave, "r") as doc:#lectura del archivo
        llaveCadena=doc.read()#lectura en binario
        doc.close
    llave = llaveCadena.encode("UTF-8")
    clave = base64.b64decode(llave)#llave en bits
    
    #si no es multiplo de 16 aplicar padding
    if((len(m)%16)!=0):
        m=m+"00000000"
    #dividir en bloques de 16 bits
    for i in range(0, len(m),16):
        bloques.append(m[i]+m[i+1]+m[i+2]+m[i+3]+m[i+4]+m[i+5]+m[i+6]+m[i+7]+m[i+8]
                       +m[i+9]+m[i+10]+m[i+11]+m[i+12]+m[i+13]+m[i+14]+m[i+15])
    
    #cifrar cada bloque y 
    for i in range(0, len(bloques)):
        descifrado=descifrado+descifrado16Bits(bloques[i], clave)
        
    for i in range((len(descifrado)-8), len(descifrado)):#Contar los 8 ceros al final
        if(descifrado[i]=='0'):
            cont=cont+1
    if cont==8:#si son 8 ceros, eliminarlos de la cadena final
        descifrado=descifrado[0:len(descifrado)-8]
        
    return descifrado

"""
prueba = 0b1100001111110000;
print(descifrado16Bits("0111001011000110", prueba))

"""   
txt=input("Ingrese el nombre del archivo de texto a descifrar: ")
clave=input("Ingrese el nombre del archivo de texto que contiene la llave: ")
decipher=""
decipherBin=descifradoAESMini(txt+".txt", clave+".txt")

for i in range(0, len(decipherBin), 8):    
    aux = decipherBin[i:i + 8]
    deciperDecimal=binarioDecimal(aux)
    decipher = decipher + chr(deciperDecimal) 

nombreArchivo=input("Como se llamara el archivo de texto descifrado: ")
with open (nombreArchivo+".txt", "w") as doc:#escritura de la llave en txt
    doc.write(decipher)
    doc.close


