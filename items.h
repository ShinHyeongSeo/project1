#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 5

typedef struct st_item {
   char name[100];
   char category[100];
   char company[100];
   int price;
   int sell;
   int sum_price;
} T_Record;


int m_is_available();
int m_first_available();
int m_count();

void m_create(char* n, char* cat, char* com, int p, int s, int s_p);

T_Record* m_search_by_name(char* n);

void m_update_by_name(T_Record* k, char* n, char* cat, char* com , int p, int s, int s_p);
void m_update_by_another(T_Record* k, char* cat, char* com, int p, int s, int s_p);
void m_delete(T_Record* k, int menu);
void m_delete_all();

char* m_to_string(T_Record *k);
char* m_to_string_save(T_Record* k);

void  m_get_all(T_Record* a[]);
int m_get_all_by_name(T_Record* a[], char* n);
int m_get_all_by_category(T_Record* a[], char* cat);
int m_get_all_by_company(T_Record* a[], char* com);
int m_get_all_by_sell(T_Record* a[], int min_sell, int max_sell);

char* m_info_all();
char* m_info_category(T_Record* k, int index);
char* m_info_company(T_Record* k, int index);

