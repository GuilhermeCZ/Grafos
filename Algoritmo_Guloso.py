# UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
# PROFESSOR: DOGLAS ANDRÉ FINCO
# ALUNO: FELIPE AUGUSTO DA SILVA
# EMAIL: felipeaugustosilva94@gmail.com
# ALUNO: GUILHERME CAON ZAMBONIN
# EMAIL: guilhermecaonzambonin@gmail.com
# DESENVOLVIDO NO AMBIENTE LINUX
#

#TRABALHO 1 – GRAFOS (ALGORITMO GULOSO)


class Grafo():
    def __init__(self, linhaa, colunaa ):
        self.C = colunaa
        self.L = linhaa
        self.D = 0
        self.graph = [[0 for coluna in range(colunaa)]
    				for linha in range(linhaa)]


    #Percorre as arestas que saem do  vertice
    def percorre(self, soma, arestas):
        # Verifica se a matriz é adjacênte
        if adj == 0:
            mim = self.menorValor(arestas)
            for v in range(self.C):
                if arestas[v] == mim:
                    print("Origem: ", arestas)
                    print("Destino: ", g.graph[v])
                    soma = soma + arestas[v]
                    print("Soma: ",soma)
                    break

        # Caso a matriz seja incidênte
        else:
            mim = self.menorValor(arestas)
            #Procurar vertice destino
            for v in range(self.L):
                # Verifica se está no vertice correto
                if g.graph[v] != arestas and (g.graph[v][self.D] == arestas[self.D] or g.graph[v][self.D] == (arestas[self.D] * -1)):
                    print("Origem: ", arestas)
                    print("Destino: ", g.graph[v])
                    if arestas[self.D] > 0:
                        soma = soma + arestas[self.D]
                    print("Soma: ",soma)
                    break

        #Condição para parar o loop
        if g.graph[g.fin] != g.graph[v]:
            self.percorre(soma, g.graph[v])

    def menorValor (self, numeros):
        # Condição para definir mini como zero quando chegar no vertice final
        if g.graph[g.fin] != numeros:
            #Pegar o primeiro numero maior que zero da lista
            for f in range(self.C):
                if numeros[f] > 0:
                    mini = numeros[f]
                    self.D = f

            #Pega o menor numero da lista
            for f in range(self.C):
                if numeros[f] < mini and numeros[f] > 0:
                    mini = numeros[f]
                    self.D = f

        else:
            mini = 0
        return mini


# Menu improvisado
x = 0
while x == 0:
    print("Menu Grafos")
    print("1 - Grafo 1")
    print("2 - Grafo 2")
    adj = 0
    x = int(input("Qual grafo: "))
    if x == 1:
        print("1 - matriz de adjacência" )
        print("2 -  matriz de incidência" )
        m = int(input("Qual grafo: "))
        if m == 1:
            # Grafo 1
            g = Grafo(5, 5)
            g.graph =[[0, 30, -15, 0, 20],
                		[-30, 0, -10, 50, 0],
                		[15, 10, 0, 5, -10],
                		[0, 50, -5, 0, -30],
                		[-20, 0, 10, 30, 0]];

        elif m == 2:
            g = Grafo(5, 8)
            g.graph = [[30, 0, 0, 20, 0, 0, -15, 0],
                     	[-30, 50, 0, 0,	0, -10, 0, 0],
                     	[0, 0, 0, 0, -10, 10, 15, 5],
                     	[0, 50, -30, 0, 0, 0, 0, -5],
                    	[0, 0, 30, -20, 10, 0, 0, 0]];
            adj = 1
        else:
            print("Opção invalida")
    elif x == 2:
        print("1 - matriz de adjacência" )
        print("2 -  matriz de incidência" )
        m = int(input("Qual grafo: "))
        if m == 1:
            # Grafo 2
            g = Grafo(7, 7)
            g.graph = [[0, 2, 0, 6, 12, 0, 0],
                     [-2, 0, 1, 0, 0, 5, 0],
                     [0, -1, 0, 0, 0, 0, 40],
                     [-6, 0, 0, 0, 0, 4, 0],
                     [-12, 0, 0, 0, 0, 0, 30],
                     [0, -5, 0, -4, 0, 0, 8],
                     [0, 0, -40, 0, -30, -8, 0]];

        elif m == 2:
            g = Grafo(7, 9)
            g.graph = [[2, 0, 12, 0, 0, 6, 0, 0, 0],
						 [-2, 1, 0, 0, 0, 0, 0, 0, 5],
						 [0, -1, 0, 40, 0, 0, 0, 0, 0],
						 [0, 0, 0, 0, 0, -6, 4, 0, 0],
						 [0, 0, -12, 0, 30, 0, 0, 0, 0],
						 [0, 0, 0, 0, 0, 0, -4, 8, -5],
						 [0, 0, 0, -40, -30, 0, 0,-8,0]];
            adj = 1

        else:
            print("Opção invalida")
    g.Ini = int(input("Qual o Vertice inicial: "))
    g.fin = int(input("Qual o Vertice final: "))
    soma = 0
    g.percorre(soma, g.graph[g.Ini])
