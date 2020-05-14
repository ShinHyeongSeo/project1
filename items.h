#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct st_item { // item record
   char name[100];
   char category[100];
   char company[100];
   int price;
   int sell;
   int sum_price;
} T_Record;


int m_is_available(); // return there are any empty index
int m_first_available(); // return smallest empty index number
int m_count(); // all records count

void m_create(char* n, char* cat, char* com, int p, int s, int s_p); // create function

T_Record* m_search_by_name(char* n); // search record by name

void m_update_by_name(T_Record* k, char* n, char* cat, char* com , int p, int s, int s_p); // update record by name
void m_update_by_another(T_Record* k, char* cat, char* com, int p, int s, int s_p); // update record by category, company, range of sell
void m_delete(T_Record* k, int menu); // delete record
void m_delete_all(); // delete all records

char* m_to_string(T_Record *k); // change record to string
char* m_to_string_save(T_Record* k); // change record to string to save file

void  m_get_all(T_Record* a[]); // get all records
int m_get_all_by_name(T_Record* a[], char* n); // get records have same name
int m_get_all_by_category(T_Record* a[], char* cat); // get records have same category
int m_get_all_by_company(T_Record* a[], char* com); // get records have same company
int m_get_all_by_sell(T_Record* a[], int min_sell, int max_sell); // get records have same range of sell

char* m_info_all(); // report about all records
char* m_info_category(T_Record* k, int index); // report about category
char* m_info_company(T_Record* k, int index); // reports about company

int m_optimize_all(); // optimize record
int m_sort_all(); // sort record
