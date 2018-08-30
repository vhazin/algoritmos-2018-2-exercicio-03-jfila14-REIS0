# tamanho e identificadores da fila
N = int(input(""))
fila = str(input("")).split()

# itens a se remover
M = int(input(""))
#conicional
if M > N or N > 50000 or M > 50000 or M < 1 or N < 1 :
    exit(1)
remove = str(input("")).split()
#condicional
if len(fila) > N or len(remove) > M:
    exit(1)

#checa os itens para remover da lista principal
for i in fila:
    if int(i) > 100000:
        exit(1)
    for j in remove:
        if int(j) > 100000:
            exit(1)
        elif i == j:
            fila.remove(i)

print(" ".join(fila))
