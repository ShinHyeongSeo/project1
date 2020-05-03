#include "items.h"
#include <string.h>

T_Record* items[MAX_ITEMS]; // 상품정보데이터 (전역)
int _count = 0;

int m_is_available() // 레코드에 정보를 저장할 공간이 있는지 확인
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

int m_first_available() // 레코드의 빈 공간 중 인덱스 번호가 가장 빠른 번호 찾기
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

int m_count() // 현재 저장되어있는 데이터의 개수 확인
{
    return _count;
}

void m_create(char* n, char* cat, char* com, int p, int s, int s_p) // 레코드 생성
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

T_Record* m_search_by_name(char* n) // 이름이 일치하는 레코드 찾기
{
    int i;
    for(i=0; i<MAX_ITEMS; i++)
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

void m_update_by_name(T_Record* k, char* n, char* cat, char* com, int p, int s, int s_p) { // 이름이 일치하는 레코드 업데이트
   strcpy(k->name,n);
   strcpy(k->category,cat);
   strcpy(k->company,com);
   k->price = p;
   k->sell = s;
   k->sum_price = s_p;
   #ifdef DEBUG
      printf("[DEBUG] %s 상품 정보 업데이트 완료\n",k->name);
   #endif
}

void m_update_by_another(T_Record* k, char* cat, char* com, int p, int s, int s_p) { // 카테고리, 제조사, 판매량의 범위가 일치하는 레코드 업데이트
   strcpy(k->category,cat);
   strcpy(k->company,com);
   k->price = p;
   k->sell = s;
   k->sum_price = s_p;
   #ifdef DEBUG
      printf("[DEBUG] %s 상품 정보 업데이트 완료\n",k->name);
   #endif
}
char* m_to_string(T_Record* k){ // 레코드를 상품명/카테고리/제조사/가격/판매량/총 판매수익 순으로 나타내줌
    static char str[80];

    sprintf(str, "%s / %s / %s / %d / %d / %d", k->name, k->category, k->company, k->price, k->sell, k->sum_price);
    return str;
}
char* m_to_string_save(T_Record* k) { // 레코드를 상품명/카테고리/제조사/가격/판매량/ 총 판매수익 순으로 나타내고 파일에 저장
   static char str[80];
   sprintf(str,"%s %s %s %d %d %d",k->name, k->category, k->company, k->price, k-> sell, k->sum_price);
   #ifdef DEBUG
      printf("\n[DEBUG] %s의 상품정보 저장완료.\n",k->name);
   #endif
   return str;
}

void m_get_all(T_Record* a[]) // 저장되어잇는 레코드 모두 가져오기
{
   int i, c = 0;
   for(i = 0; i < MAX_ITEMS; i++)
   {
      if(items[i] != NULL) {
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
    for(i=0; i<MAX_ITEMS; i++){
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
    for(i=0; i<MAX_ITEMS; i++){
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
int m_get_all_by_sell(T_Record* a[], int s1, int s2)
{
    // 상품판매량의 범위가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기    
    int i, c=0;
    for(i=0; i<MAX_ITEMS; i++){
        if(items[i]!=NULL && s1 <= items[i]->sell && items[i]->sell <= s2)
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

void m_delete(T_Record* k, int menu) // 레코드 삭제
{
   int i, index;
   for(i=0; i<MAX_ITEMS; i++) {
      if(menu == 1 && items[i]->name == k->name) {
         index=i;
         break;
      }
      else if(menu == 2 && items[i]->category == k->category) {
         index = i;
         break;
      }
      else if(menu == 3 && items[i]->company == k->company) {
         index = i;
         break;
      }
      else if(menu == 4 && items[i] != NULL && items[i]->sell == k->sell) {
         index = i;
         break;
      }
   }
   free(k);
   items[index] = NULL;
   _count--;
   #ifdef DEBUG
      printf("\n[DEBUG] %d번째 레코드 삭제 \n",index);
   #endif
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

char* m_info_all() // 전체 레코드에 대한 보고서
{
   static char str[1024];
   int i,size;
   long all_price = 0;
   size = m_count();

   for(i = 0; i < MAX_ITEMS; i++)
   {
      if(items[i] != NULL) {
         all_price += items[i]->sum_price;
      }
   }

   sprintf(str, "총 상품 개수 : %d개\n총 판매수익 : %ld원\n\n",size, all_price);
   #ifdef DEBUG
      printf("\n[DEBUG] 총 상품%d개에 대한 보고서 작성 완료\n",size);
   #endif
   return str;
}

char* m_info_category(T_Record* k, int index) // 카테고리별 보고서
{
   static char str[100];
   int i;
   long all_price = 0;
   int size = 0,size2 = 0;
   T_Record* a[MAX_ITEMS];
   m_get_all(a);
   size = m_count();

   for(i = 0; i < size; i++)
   {
      if(strcmp(a[i]->category,k->category) == 0) {
         if(i >= index)
         {
             size2++;
             all_price += a[i]->sum_price;
         }
         else
         {
             return 0;
         }
      }
   }
   sprintf(str,"%s카테고리의 상품 개수 : %d개\n%s카테고리의 총 판매수익 : %ld원\n\n",k->category,size2,k->category,all_price);
   #ifdef DEBUG
      printf("\n[DEBUG] %s 카테고리의  보고서 작성 완료\n",k->category);
   #endif

   return str;
}
char* m_info_company(T_Record* k, int index) // 제조사별 보고서
{
   static char str[100];
   int i;
   long all_price = 0;
   int size = 0,size2 = 0;
   T_Record* a[MAX_ITEMS];
   m_get_all(a);
   size = m_count();

   for(i = 0; i < size; i++)
   {
      if(strcmp(a[i]->company,k->company) == 0) {
         if(i >= index && strcmp(a[i]->company,k->company) == 0)
         {
            size2++;
            all_price += a[i]->sum_price;
         }
         else
         {
            return 0;
         }
      }
   }
   sprintf(str,"%s제조사의 상품 개수 : %d개\n%s제조사의 총 판매수익 : %ld원\n\n", k->company, size2, k->company, all_price);


   #ifdef DEBUG
      printf("\n[DEBUG] %s제조사의  보고서 작성 완료\n",k->company);
   #endif

   return str;
}

int m_optimize_all() // 전체 레코드 최적화
{ 
    int i,j,count = 0;
    if(_count == 0) { // 전체 레코드가 비어있으면 -1 리턴
       return -1;
    }

    for(i = 0; i < _count; i++) { // 이미 전체레코드가 최적화되어있는지 검사
       if(items[i] == NULL) {
          count++;
       }
    }
    if(count == 0) { // 이미 최적화가 되어있으면 1 리턴
       return 1;
    }

    else { // 전체 레코드 최적화가 필요한 경우
       for(i = 0; i < MAX_ITEMS; i++) {
          if(items[i] == NULL) { // 빈 레코드를 만나면
             for(j = i; j < MAX_ITEMS; j++) {
                if(items[j] != NULL) { // 다음 레코드가 빈 레코드가 아니라면
                   items[i] = items[j]; // 다음 레코드의 값을 현재 레코드에 저장 후
                   items[j] = NULL; // 원래 다음에 있던 레코드를 NULL로 만든다 (NULL은 값을 서로 바꿀 수 없기 때문에 이 방법을 사용) 
                   break; // 제일 가까운 비어있지 않은 레코드를 하나만 바꿔야하므로  break
                }
             }
          }   
       }
    }  


   #ifdef DEBUG // 디버그
   printf("[DEBUG] 저장된 상품명 순서 : ");
   for(i = 0; i < MAX_ITEMS; i++) {
      printf("%s ",items[i]->name); // 저장되어있는 상품명을 출력해 제대로 최적화가 되었는지 확인
   }
   printf("\n");
   #endif

   return 0; // 최적화를 마쳤으면 0리턴
}

int m_sort_all() { // 전체 레코드 카테고리순, 총 판매수익 순으로 정렬
   int i,j;
   T_Record* temp;
   
   if(_count == 0) { // 전체 레코드가 비어있으면 -1 리턴
      return -1;
   }

   for(i = 0; i < MAX_ITEMS; i++) {
      for(j = i+1; j < MAX_ITEMS; j++) {
         if(items[i] != NULL && items[j] != NULL) { // 현재 레코드와 비교할 레코드가 NULL값이 아니면
            if(strcmp(items[i]->category,items[j]->category) > 0 || (strcmp(items[i]->category,items[j]->category) == 0 && items[i]->sum_price < items[j]->sum_price)) { // 카테고리 오름차순으로 정렬, 만약 카테고리가 같다면 총 판매수익 내림차순으로 정렬
               temp = items[i];
               items[i] = items[j];
               items[j] = temp;
          }
        }
     }
   }
   return 0; // 정렬이 완료되었다면 0리턴
}




