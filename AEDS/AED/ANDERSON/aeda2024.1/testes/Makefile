all:
	@echo Informe o nome de um tipo de estrutura a ser testada
	@echo Exemplo: make fila_s

# Digite make abb para testar a árvore binária de busca
abb: abb_teste
	./abb_teste

abb_teste: abb_teste.o abb.o fila_e_abb.o item.o
	gcc abb_teste.o abb.o fila_e_abb.o item.o -o abb_teste

abb_teste.o: abb_teste.c
	gcc -c abb_teste.c

abb.o: ../ed/abb.c
	gcc -c ../ed/abb.c

fila_e_abb.o: ../ed/fila_e_abb.c
	gcc -c ../ed/fila_e_abb.c

# Digite make max_heap para testar a heap máxima
max_heap: max_heap_teste
	./max_heap_teste

max_heap_teste: max_heap_teste.o max_heap.o item.o
	gcc max_heap_teste.o max_heap.o item.o -o max_heap_teste

max_heap_teste.o: max_heap_teste.c
	gcc -c max_heap_teste.c

max_heap.o: ../ed/max_heap.c
	gcc -c ../ed/max_heap.c

# Digite make lista_s para testar a lista sequencial
lista_s: lista_s_teste
	@./lista_s_teste

lista_s_teste: lista_s_teste.o lista_s.o item.o
	gcc lista_s_teste.o lista_s.o item.o -o lista_s_teste

lista_s_teste.o: lista_s_teste.c
	gcc -c lista_s_teste.c

lista_s.o: ../ed/lista_s.c
	gcc -c ../ed/lista_s.c

# Digite make lista_s_ord para testar a lista sequencial ordenada
lista_s_ord: lista_s_ord_teste
	@./lista_s_ord_teste

lista_s_ord_teste: lista_s_ord_teste.o lista_s_ord.o item.o
	gcc lista_s_ord.o lista_s_ord_teste.o item.o -o lista_s_ord_teste

lista_s_ord_teste.o: lista_s_ord_teste.c
	gcc -c lista_s_ord_teste.c

lista_s_ord.o: ../ed/lista_s_ord.c
	gcc -c ../ed/lista_s_ord.c

# Digite make lista_e para testar a lista encadeada
lista_e: lista_e_teste
	@./lista_e_teste

lista_e_teste: lista_e_teste.o lista_e.o item.o
	gcc lista_e_teste.o lista_e.o item.o -o lista_e_teste

lista_e_teste.o: lista_e_teste.c
	gcc -c lista_e_teste.c

lista_e.o: ../ed/lista_e.c
	gcc -c ../ed/lista_e.c

# Digite make lista_de para testar a lista duplamente encadeada
lista_de: lista_de_teste
	@./lista_de_teste

lista_de_teste: lista_de_teste.o lista_de.o item.o
	gcc lista_de_teste.o lista_de.o item.o -o lista_de_teste

lista_de_teste.o: lista_de_teste.c
	gcc -c lista_de_teste.c

lista_de.o: ../ed/lista_de.c
	gcc -c ../ed/lista_de.c

# Digite make lista_circ para testar a lista circular
lista_circ: lista_circ_teste
	@./lista_circ_teste

lista_circ_teste: lista_circ_teste.o lista_s_circ.o item.o
	gcc lista_circ_teste.o lista_s_circ.o item.o -o lista_circ_teste

lista_circ_teste.o: lista_circ_teste.c
	gcc -c lista_circ_teste.c

lista_s_circ.o: ../ed/lista_s_circ.c
	gcc -c ../ed/lista_s_circ.c


# Digite make fila_s para testar a fila sequencial
fila_s: fila_s_teste
	@./fila_s_teste

fila_s_teste:	fila_s_teste.o fila_s.o item.o
	gcc fila_s_teste.o fila_s.o item.o -o fila_s_teste

fila_s_teste.o:	fila_s_teste.c
	gcc -c fila_s_teste.c

fila_s.o:	../ed/fila_s.c
	gcc -c ../ed/fila_s.c

# Digite make pilha_e para testar a pilha encadeada
pilha_e: pilha_e_teste
	@./pilha_e_teste

pilha_e_teste: pilha_e_teste.o pilha_e.o item.o  
	gcc pilha_e_teste.o pilha_e.o item.o -o pilha_e_teste

pilha_e_teste.o: pilha_e_teste.c
	gcc -c pilha_e_teste.c

pilha_e.o: ../ed/pilha_e.c
	gcc -c ../ed/pilha_e.c

# Código usado nas várias estruturas
item.o:	../ed/item.c
	gcc -c ../ed/item.c