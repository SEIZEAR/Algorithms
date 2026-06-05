L=[3,1,2,5,8,7,9]

max_arr=[]
max_val=L[0]
min_arr=[]
min_val=L[-1]


for i in L:
  if max_val<i:
     max_val=i
  max_arr.append(max_val)

for i in range(len(L)-1,-1,-1):
  if min_val>L[i]:
    min_val=L[i]
  min_arr.insert(0,min_val)

for i in range(1,len(L)-1):
  if max_arr[i-1]<L[i]<min_arr[i+1]:
    print(L[i])