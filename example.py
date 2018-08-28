# tamanho e identificadores da fila
N = int(input(""))
lista = [str(input("")).split() for i in range(N)]


# items a se remover
M = int(input(""))
if M > N or N > 50000 or M > 50000:
    exit(1)
remove = [str(input("")).split() for j in range(M)]

#checa os itens para remover da lista principal
for i in lista:
    for j in remove:
        if lista[i] == remove[j]:
            lista.remove(lista[i])
            print("infinito")

print(" ".join(lista))
