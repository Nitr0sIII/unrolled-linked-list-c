all: pagedBitmapListNormal pagedBitmapListDynamic

pagedBitmapListNormal: pagedBitmapListNormal.o listManagementNormal.o
	gcc -o pagedBitmapListNormal pagedBitmapListNormal.o listManagementNormal.o

pagedBitmapListDynamic: pagedBitmapListDynamic.o listManagementDynamic.o
	gcc -o pagedBitmapListDynamic pagedBitmapListDynamic.o listManagementDynamic.o

#########################################################################

pagedBitmapListDynamic.o: pagedBitmapListDynamic.c 
	gcc -c pagedBitmapListDynamic.c

listManagementDynamic.o: ./src/listManagementDynamic.c
	gcc -c ./src/listManagementDynamic.c

#########################################################################

pagedBitmapListNormal.o: pagedBitmapListNormal.c 
	gcc -c pagedBitmapListNormal.c

listManagementNormal.o: ./src/listManagementNormal.c
	gcc -c ./src/listManagementNormal.c

#########################################################################

clean:
	rm -f ./*.o pagedBitmapListNormal pagedBitmapListDynamic
	clear