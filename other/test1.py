import H1Data

kamoku1 = dict()
kamoku1Fuka = dict()

datalist = H1Data.dataListH1
border = 60
subject = '科目1'

for k, v in datalist.items():
	if v[subject] >= border:
		kamoku1[k] = v[subject]
	else:
		kamoku1Fuka[k] = v[subject]

# a = {k:v[subject] for k, v in datalist.items() if v[subject] >= border}

ave_kamoku1 = sum(kamoku1.values()) / len(kamoku1)

# print('合格者の得点',kamoku1)
# print('合格者の平均点',ave_kamoku1)



a = input()
print(a)
