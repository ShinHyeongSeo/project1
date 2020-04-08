#include "items.h"
#include <string.h>

T_Record* items[MAX_ITEMS]; // 상품정보데이터 (전역)
int _count = 0;

int m_is_available()
{
    int i;
    for(i=0; i<MAX_ITEMS; i++)
    {
       if(items[i]==NULL)
       {
         return 1;
       }
    }
    return 0;
}

int m_first_available()
{
    int i;
    for(i=0; i<MAX_ITEMS; i++)
    {
        if(items[i]==NULL)
        {
          return i;
        }
    }
    return -1;
}

int m_count()
{
    return _count;
}

void m_create(char* n, char* cat, char* com, int p, int s, int s_p)
{
    int index = m_first_available();
    items[index] = (T_Record*)malloc(sizeof(T_Record));
    T_Record* k = items[index];
    strcpy(k->name, n);  
    strcpy(k->category, cat);
    strcpy(k->company,com);
    k->price = p;
    k->sell = s;
    k->sum_price = s_p;
    _count++;
    
    #ifdef DEBUG
       printf("\n[DEBUG] %s의 상품정보 생성완료.\n",n);
       printf("%s / %s / %s / %d / %d / %d\n", k->name, k->category, k->company, k->price, k->sell, k->sum_price);
    #endif
}

T_Record* m_search_by_name(char* n)
{
    int i;
    for(i=0; i<_count; i++)
    {
        if(items[i]!=NULL && strcmp(items[i]->name, n)==0)
        {
            #ifdef DEBUG
               printf("\n[DEBUG] %s와 일치하는 상품명이 %d번째 인덱스에 있음.\n",n,i);
            #endif
            return items[i];
        }
    }
    return NULL;
}

char* m_to_string(T_Record* k){
    static char str[80];
    sprintf(str, "%s / %s / %s / %d / %d / %d", k->name, k->category, k->company, k->price, k->sell, k->sum_price);
    return str;
}
char* m_to_string_save(T_Record* k) {
   static char str[80];
   sprintf(str,"%s %s %s %d %d %d",k->name, k->category, k->company, k->price, k-> sell, k->sum_price);
   #ifdef DEBUG
      printf("\n[DEBUG] %s의 상품정보 저장완료.\n",k->name);
   #endif
   return str;
}

void m_get_all(T_Record* a[])
{
   int i, c = 0;
   for(i = 0; i < MAX_ITEMS; i++)
   {
      if(items[i] != NULL)
      {
         a[c] = items[i];
         c++;
      }
   }

   #ifdef DEBUG
      printf("\n[DEBUG] 총 상품 개수 : %d개\n",c);
   #endif
}

int m_get_all_by_category(T_Record* a[], char* cat)
{
    // 상품카테고리가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기    
    int i, c=0;
    for(i=0; i<_count; i++){
        if(items[i]!=NULL && strcmp(items[i]->category, cat) == 0)
        {
            a[c]=items[i];
            c++;
        }
    }
    #ifdef DEBUG
      printf("\n[DEBUG] 카테고리가 일치하는 상품 개수: %d개\n",c);
    #endif
    return c;
}
int m_get_all_by_company(T_Record* a[], char* com)
{
    // 상품제조사가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기    
    int i, c=0;
    for(i=0; i<_count; i++){
        if(items[i]!=NULL && strcmp(items[i]->company, com) == 0)
        {
            a[c]=items[i];
            c++;
        }
    }
    #ifdef DEBUG
      printf("\n[DEBUG] 제조사가 일치하는 상품 개수: %d개\n",c);
    #endif
    return c;
}
int m_get_all_by_sell(T_Record* a[], int p1, int p2)
{
    // 상품판매량의 범위가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기    
    int i, c=0;
    for(i=0; i<_count; i++){
        if(items[i]!=NULL && p1 <= items[i]->sell && items[i]->sell <= p2)
        {
            a[c]=items[i];
            c++;
        }
    }
    #ifdef DEBUG
       printf("\n[DEBUG] 판매량의 범위가 일치하는 상품 개수 : %d개\n",c);
    #endif
    return c;
}

void m_delete_all()
{
    // 모든 레코드 제거    
    int i;
    for(i=0; i<MAX_ITEMS; i++){
        if(items[i]!=NULL) {
            free(items[i]);
        }
        #ifdef DEBUG
           if(items[i]->name != NULL) {
              printf("\n[DEBUG] %s 상품정보 삭제완료\n",items[i]->name);
           }
        #endif
        items[i] = NULL;
    }
    _count = 0;

} 

char* m_info_all()
{
   static char str[1024];
   int i, size;
   int all_price = 0;
   size = m_count();

   for(i = 0; i < size; i++)
   {
      all_price += items[i]->sum_price;
   }

   sprintf(str, "총 상품 개수 : %d개\n총 판매수익 : %d원\n\n",size, all_price);
   #ifdef DEBUG
      printf("\n[DEBUG] 총 상품%d개에 대한 보고서 작성 완료\n",size);
   #endif
   return str;
}

char* m_info_category(T_Record* k, int index)
{
   static char str[100];
   int i, size;
   int all_price = 0, size2 = 0;
   size = m_count();

   for(i = 0; i < size; i++)
   {
      if(strcmp(k->category, items[i]->category) == 0)
      {
         if(i >= index)
         {
            size2++;
            all_price += items[i]->sum_price;
         }
         else
         {
            return 0;
         }
      }
   }
   sprintf(str,"%s카테고리의 상품 개수 : %d개\n%s카테고리의 총 판매수익 : %d원\n\n",k->category,size2,k->category,all_price);
   #ifdef DEBUG
      printf("\n[DEBUG] %s 카테고리의  보고서 작성 완료\n",k->category);
   #endif

   return str;
}
char* m_info_company(T_Record* k, int index)
{
   static char str[100];
   int i, size;
   int all_price = 0, size2 = 0;
   size = m_count();

   for(i = 0; i < size; i++)
   {
      if(strcmp(k->company, items[i]->company) == 0)
      {
         if(i >= index)
         {
            size2++;
            all_price += items[i]->sum_price;
         }
         else
         {
            return 0;
         }
      }
   }
   sprintf(str,"%s제조사의 상품 개수 : %d개\n%s제조사의 총 판매수익 : %d원\n\n", k->company, size2, k->company, all_price);


   #ifdef DEBUG
      printf("\n[DEBUG] %s제조사의  보고서 작성 완료\n",k->company);
   #endif


   return str;
}
