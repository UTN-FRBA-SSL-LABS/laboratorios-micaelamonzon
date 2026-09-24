# Nombre del ejecutable final
PROGRAMA := calc3

# Compilador
CC := gcc

# Regla principal
all: $(PROGRAMA)

# Regla para construir la calculadora a partir del parser y el scanner
# Bison genera: parser3.tab.c y parser3.tab.h
# Flex genera:  lex.yy.c
$(PROGRAMA): parser3.y scanner3.l
	bison -d parser3.y
	#         (la opción -d genera también el archivo de cabecera .tab.h)
	#         Comando: bison -d <archivo.y>

	flex scanner3.l
	#         Comando: flex <archivo.l>

	$(CC) $(CFLAGS) lex.yy.c parser3.tab.c -o $(PROGRAMA)
	# TODO 3: Compilá con gcc los dos archivos generados: lex.yy.c y parser3.tab.c
	#         Usá $(CC), ambos archivos .c, y el flag -o $(PROGRAMA)

# Regla para limpiar todos los archivos generados
clean:
	rm -f $(PROGRAMA)
	rm -f lex.yy.c
	rm -f parser3.tab.c
	rm -f parser3.tab.h
	# TODO 4: Eliminá el ejecutable y todos los archivos generados
	#         por Bison y Flex: $(PROGRAMA), lex.yy.c,
	#         parser3.tab.c y parser3.tab.h

.PHONY: all clean
