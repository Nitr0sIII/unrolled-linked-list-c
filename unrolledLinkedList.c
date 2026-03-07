#include <stdio.h>
#include <stdlib.h>

#define NB_ELEM 8

typedef struct Page Page;

struct Page {
  int element[NB_ELEM];
  __int8_t bitmap;
  Page *next;
};

Page *constructorInit();
void insert(Page *firstPage, int element);
void printAllPage(Page *first);

//////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
  Page *first = constructorInit();

  insert(first, 5);
  insert(first, 85);
  insert(first, 789);
  insert(first, 45);
  insert(first, 58);
  insert(first, 22);
  insert(first, 58);
  insert(first, 2201);
  insert(first, 5855);
  insert(first, 2278);

  printAllPage(first);
  return 0;
}

//////////////////////////////////////////////////////////////////////

Page *constructorInit() {
  Page *tmpPage = malloc(sizeof(Page));

  tmpPage->bitmap = 0;
  for (int i = 0; i < NB_ELEM; i++) {
    tmpPage->element[i] = -1;
  }
  tmpPage->next = NULL;

  return tmpPage;
}

void insert(Page *firstPage, int element) {
  if (firstPage == NULL) {
    return;
  }

  Page *current = firstPage;

  while (firstPage != NULL) {
    for (int i = 0; i < NB_ELEM; i++) {
      if (!(current->bitmap & (1ULL << i))) {
        current->element[i] = element;
        current->bitmap |= (1ULL << i);
        return;
      }
    }
    if (current->next == NULL) {
      current->next = constructorInit();
    }
    current = current->next;
  }
}

void printAllPage(Page *first) {
  Page *current = first;
  int currentPageIndex = 0;
  while (current != NULL) {
    printf("Page %d\n\n", currentPageIndex);
    for (int i = 0; i < NB_ELEM; i++) {
      printf("Elem %d : %d\n", i, current->element[i]);
    }
    printf("\n\n");
    current = current->next;
    currentPageIndex++;
  }
}