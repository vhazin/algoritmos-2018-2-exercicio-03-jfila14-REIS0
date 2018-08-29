# tamanho e identificadores da fila
N = int(input(""))
fila = str(input("")).split()

# itens a se remover
M = int(input(""))
#conicional
if M > N or N > 50000 or M > 50000:
    exit(1)
remove = str(input("")).split()
#condicional
if len(fila) > N or len(remove) > M:
    exit(1)

#checa os itens para remover da lista principal
for i in range(0, (len(fila) - 1)):
    for j in range(0, (len(remove) - 1)):
        if fila[i] == remove[j]:
            fila.remove(fila[i])
    print(i, j)

print(" ".join(fila))
