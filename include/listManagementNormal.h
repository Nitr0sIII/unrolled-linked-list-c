#ifndef LIST_MANAGEMENT_H
#define LIST_MANAGEMENT_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INIT_VALUE -1

typedef struct Page Page;

struct Page {
  int *values;
  uint8_t bitmap;
  Page *next;
};

typedef struct PagedBitmapList {
  int pageCapacity;
  int itemCount;
  int pageCount;
  Page *head;
} PagedBitmapList;

typedef struct ElementLocation {
  int value;
  int index;
  Page *pageRef;
} ElementLocation;

typedef struct SearchResult {
  ElementLocation *founds;
  int number;
} SearchResult;

//////////////////////////////////////////////////////////////////////

PagedBitmapList constructorListInit();
Page *constructorPageInit(int pageCapacity);
int askPageCapacity();

void insert(PagedBitmapList *list, int value);
void removeAtLocation(PagedBitmapList *list, ElementLocation position);
void compact(PagedBitmapList *list);

SearchResult research(PagedBitmapList *list, int value);

void printLocations(SearchResult occurrences);
void printPagedBitmapList(PagedBitmapList *list);

void freeAllPages(Page *head);

#endif