# Nombre del ejecutable final
PROGRAMA := scanner2

# Compilador
CC := gcc

# Regla principal
all: $(PROGRAMA)

# Regla para construir el scanner
# Dependencias: scanner2.l (Flex genera lex.yy.c a partir de él)
$(PROGRAMA): scanner2.l
	flex scanner2.l

	$(CC) $(CFLAGS) lex.yy.c -o $(PROGRAMA)

# Regla para limpiar archivos generados
clean:
	rm -f $(PROGRAMA)
	rm -f lex.yy.c
	#         Archivos a eliminar: $(PROGRAMA) y lex.yy.c
	#         Usá rm -f

.PHONY: all clean
