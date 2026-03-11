#include "./include/listManagementDynamic.h"

INIT_LIST(int)
INIT_LIST(float)
INIT_LIST(char)

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  UnrolledListint list = constructorListInitint();

  insertint(&list, 5);
  insertint(&list, 2);
  insertint(&list, 78);
  printUnrolledListint(&list);

  freeAllPagesint(list.head);
  return 0;
}