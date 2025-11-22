VG = 'Global'
def funcion_v1():
  print(VG)
funcion_v1()
print(VG)
def funcion_v2():
  VG = 'Local'
  ´print(VG)
funcion_v2()
print(VG)
def funcion_v3:
  print(VG)
  VG = 'Local'
  print(VG)
funcion_v3()
def funcion_v4():
  global VG
  print VG
  VG = 'Local'
  print(VG)

funcion_v4()
print(VG)

  
