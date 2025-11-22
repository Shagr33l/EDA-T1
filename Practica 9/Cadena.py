cadena1 = "Hola"
cadena2 = "mundo"
print(cadena1)
print(cadena2)
concat_cadenas = cadena1 + cadena2
print(concat_cadenas)
num_cadena = concat_cadenas +' '+ str(3) 
print(num_cadena)
num_cadena= "{}{}{}".format(cadena1, cadena2, 3)
print(num_cadena)
num_cadena= "CAMBIANDO EL ORDEN: {1}{2}{0}#".format(cadena1, cadena2, 3)
print(num_cadena)
