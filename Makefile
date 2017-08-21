all:
	gcc main.c selection.c insertion.c -o ordcomp
  
clean:
  rm -rf *o ordcomp
