# tamanho e identificadores da fila
N = int(input(""))
fila = str(input("")).split()

# items a se remover
M = int(input(""))
if M > N or N > 50000 or M > 50000:
    exit(1)
remove = str(input("")).split()

if len(fila) > N or len(remove) > M:
    exit(1)
#checa os itens para remover da lista principal
j = 0
i = 0
print(fila[i])
while j < M:
    if fila[i] == remove[j]:
        fila.remove(fila[i])
        j += 1
    i += 1

print(" ".join(fila))
