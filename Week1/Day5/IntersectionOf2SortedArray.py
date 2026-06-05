a=[1,2,3,4,5,8]
b=[3,6,7,8]

i=j=0

while i<len(a) and j<len(b):

  if a[i]==b[j]:
    print(a[i])
    i+=1
    j+=1

  elif a[i]<b[j]:
    i+=1

  else:
    j+=1
