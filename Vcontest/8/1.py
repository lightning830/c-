import math
a, b, c = map(int, input().split())
  
sa = math.sqrt(a)
sb = math.sqrt(b)
sc = math.sqrt(c)
  
if sa+sb < sc:
	print("Yes")
else:
	print("No")