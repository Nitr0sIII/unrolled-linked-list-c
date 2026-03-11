all: unrolledLinkedListNormal unrolledLinkedListDynamic

unrolledLinkedListNormal: unrolledLinkedListNormal.o listManagement.o
	gcc -o unrolledLinkedListNormal unrolledLinkedListNormal.o listManagement.o

unrolledLinkedListDynamic: unrolledLinkedListDynamic.o listManagementDynamic.o
	gcc -o unrolledLinkedListDynamic unrolledLinkedListDynamic.o listManagementDynamic.o

#########################################################################

unrolledLinkedListDynamic.o: unrolledLinkedListDynamic.c 
	gcc -c unrolledLinkedListDynamic.c

listManagementDynamic.o: ./src/listManagementDynamic.c
	gcc -c ./src/listManagementDynamic.c

#########################################################################

unrolledLinkedListNormal.o: unrolledLinkedListNormal.c 
	gcc -c unrolledLinkedListNormal.c

listManagement.o: ./src/listManagement.c
	gcc -c ./src/listManagement.c

#########################################################################

clean:
	rm -f ./*.o unrolledLinkedListNormal unrolledLinkedListDynamic
	clear