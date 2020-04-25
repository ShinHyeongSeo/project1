#include "items.h"

void create_record();
void read_record();
void list_record();
void update_record();
void delete_record();
void all_info_record();
void load_file();
void save_file();
void save_info_record();
void optimize_record();
void sort_record();
int main()
{
   m_delete_all();
   int menu;
   while(1)
   {
      printf("\nMenu : 1.Create 2.Read 3.Update 4.Delete 5.List 6.Report 7.Load file 8.Save file 9.Save Report 10.Optimize Record 11.Sort Record  0.Quit > ");
      scanf("%d",&menu);
      printf("\n");
      
      switch(menu)
      {
         case 1:
            create_record();
            break;
         case 2:
            read_record();
            break;
         case 3:
            update_record();
            break;
         case 4:
            delete_record();
            break;
         case 5:
            list_record();
            break;
         case 6:
            all_info_record();
            break;
         case 7:
            load_file();
            break;
         case 8:
            save_file();
            break;
         case 9:
            save_info_record();
            break;
         case 10:
            optimize_record();
            break;
         case 11:
            sort_record();
            break;
         case 0:
         default:
            return 0;
      }
   }
   return 0;
}

void create_record()
{
   char name[100], category[100], company[100];
   int price, sell, sum_price;

   if(!m_is_available())
   {
      printf("상품정보를 추가할 공간이 부족합니다!\n");
      return;
   }

   printf("새로운 상품의 정보를 입력해주세요.\n");
   printf("상품명 > ");
   scanf("%s",name);
	
   if(m_search_by_name(name))
   {
      printf("상품명이 중복됩니다!\n");
      return;
   }

   printf("카테고리 > ");
   scanf("%s", category);
   printf("제조사 > ");
   scanf("%s",company);
   printf("가격(원) > ");
   scanf("%d",&price);
   printf("판매량 > ");
   scanf("%d",&sell);
   sum_price = price * sell;
	
   m_create(name, category, company, price, sell, sum_price);
}

void read_record()
{
   int menu, size = 0, i;
   char name[100];
   char category[100];
   char company[100];
   int min_sell, max_sell;

   T_Record* records[MAX_ITEMS];
   T_Record* k;

   printf("Menu : 1.상품명 2.카테고리 3.제조사 4.판매량 >  ");
   scanf("%d",&menu);

   switch(menu)
   {
      case 1:
         printf("상품명을 입력해주세요 > ");
         scanf("%s",name);
         k = m_search_by_name(name); // 일치하는 상품명 찾기

         if(k) // 일치하는 상품명이 있으면
         {
            printf("%s\n",m_to_string(k));
         }
         else // 일치하는 상품명이 없으면
         {
            printf("해당하는 상품이 없습니다!.\n");
         }
         break;
      case 2:
         printf("카테고리를 입력해주세요 > ");
         scanf("%s",category);
         size = m_get_all_by_category(records, category); // 카테고리가 일치하는 상품정보레코드들 records에 저장 후 size에 크기 저장
         break;
      case 3:
         printf("제조사를 입력해주세요 > ");
         scanf("%s",company);
         size = m_get_all_by_company(records, company); // 제조사가 일치하는 상품정보레코드들 records에 저장 후 size에 크기 저장
         break;
      case 4:
         printf("최소 판매량을 입력해주세요 > ");
         scanf("%d", &min_sell);
         printf("최대 판매량을 입력해주세요 > ");
         scanf("%d", &max_sell);
         size = m_get_all_by_sell(records, min_sell, max_sell); // 제조사가 일치하는 상품정보레크드들 records에 저장 후 size에 크기 저장
         break;
      default:
         printf("잘못된 메뉴번호를 입력하였습니다!!");
   }

   if(menu != 1)
   {
      if(size == 0)
      {
         printf("해당하는 상품이 없습니다!!");
      }
      else
      {
         printf("%d 개의 해당하는 상품을 찾았습니다.\n", size);
         for(i = 0; i < size; i++)
         {
            k = records[i];
            printf("%d. %s\n", i+1, m_to_string(k)); // 입력값과 일치하는 상품정보레코드들 출력
         }
      }
   }
}
void update_record()
{
   int menu,size = 0, i;
   char name[100];
   char category[100];
   char company[100];
   int min_sell, max_sell;
   int price, sell, sum_price = 0;
   T_Record* records[MAX_ITEMS];
   T_Record* k;

   printf("Menu : 1.상품명 2.카테고리 3.제조사 4.판매량 5.전체 >  ");
   scanf("%d",&menu);

   switch(menu)
   {
      case 1:
         printf("상품명을 입력해주세요 >");
         scanf("%s",name);
         k = m_search_by_name(name); // 일치하는 상품명 찾기
         if(k) { // 일치하는 상품명이 있으면
            printf("변경할 정보를 입력해주세요\n"); // 변경할 정보 입력
            printf("상품명 > ");
            scanf("%s",name);
            printf("카테고리 > ");
            scanf("%s",category);
            printf("제조사 > ");
            scanf("%s",company);
            printf("가격 > ");
            scanf("%d",&price);
            printf("판매량 > ");
            scanf("%d",&sell);
            sum_price = price * sell;
            m_update_by_name(k,name,category,company,price,sell,sum_price);
            printf("해당 레코드의 정보가 변경되었습니다!\n");
         }
         else { // 일치하는 상품명 없으면
            printf("해당하는 상품이 없습니다!\n");
         }
         break;
      case 2:
         printf("카테고리를 입력해주세요 > ");
         scanf("%s",category);
         size = m_get_all_by_category(records,category); 
         break;
      case 3:
         printf("제조사를 입력해주세요 > ");
         scanf("%s",company);
         size = m_get_all_by_company(records,company);  
         break;
      case 4:
         printf("최소 판매량을 입력해주세요 > ");
         scanf("%d",&min_sell);
         printf("최대 판매량을 입력해주세요 > ");
         scanf("%d",&max_sell);
         size = m_get_all_by_sell(records,min_sell,max_sell);
         break;
      case 5:
          m_get_all(records);
          size = m_count();
         break;
      default:
         printf("잘못된 메뉴번호를 입력하였습니다!!");
   }
   if(menu == 2 || menu == 3 || menu == 4 || menu == 5) {
      if(size > 0) {
         printf("변경할 정보를 입력해주세요\n"); // 변경할 정보가 카테고리,제조사,판매량의 범위가 일치하는 상품정보레코드일때
         printf("카테고리 > ");
         scanf("%s",category);
         printf("제조사 > ");
         scanf("%s",company);
         printf("가격 > ");
         scanf("%d",&price);
         printf("판매량 > ");
         scanf("%d",&sell);
         sum_price = price * sell;
         for(i = 0; i < size; i++) {
            k = records[i];
            m_update_by_another(k,category,company,price,sell,sum_price);
         }
         printf("%d개의 레코드의 정보가 변경되었습니다!",size);
      }
      else {
        printf("해당하는 상품이 없습니다!\n");
      }
   }
}

void delete_record()
{
   int menu,size = 0, i;
   char name[100];
   char category[100];
   char company[100];
   int min_sell, max_sell;
   T_Record* records[MAX_ITEMS];
   T_Record* k;

   printf("Menu : 1.상품명 2.카테고리 3.제조사 4.판매량 5.전체 >  ");
   scanf("%d",&menu);

   switch(menu)
   {
      case 1:
         printf("상품명을 입력해주세요 >");
         scanf("%s",name);
         k = m_search_by_name(name);
         if(k) {
            m_delete(k,menu);
            printf("해당 레코드가 삭제되었습니다!\n");
         }
         else {
            printf("해당하는 상품이  없습니다!\n");
         }
         break;
      case 2:
         printf("카테고리를 입력해주세요 > ");
         scanf("%s",category);
         size = m_get_all_by_category(records,category);
         break;
      case 3:
         printf("제조사를 입력해주세요 > ");
         scanf("%s",company);
         size = m_get_all_by_company(records,company);
         break;
      case 4:
         printf("최소 판매량을 입력해주세요 > ");
         scanf("%d",&min_sell);
         printf("최대 판매량을 입력해주세요 > ");
         scanf("%d",&max_sell);
         size = m_get_all_by_sell(records,min_sell,max_sell);
         break;
      case 5:
         m_delete_all();
         printf("전체 레코드가 삭제되었습니다!\n");
         break;
      default:
         printf("잘못된 메뉴번호를 입력하였습니다!!");
   }
   if(menu == 2 || menu == 3 || menu == 4) {
      if(size > 0) {
         for(i = 0; i < size; i++) {
            k = records[i];
            m_delete(k,menu);
         }
         printf("%d개의 레코드가 삭제되었습니다!\n",size);
      }
      else {
        printf("해당하는 상품이 없습니다!\n");
      }
   }


}
void list_record()
{
   int i, size;
   printf("모든 상품정보레코드\n");
   T_Record* records[MAX_ITEMS];
   m_get_all(records); // 전체상품레코드 records에 저장
   size = m_count(); // size에 크기 저장

   for(i = 0; i < size; i++)
   {
      T_Record* k = records[i];
      printf("%d. %s\n",i+1,m_to_string(k));
   }
}

void all_info_record()
{
   int i,size,index;
   char* result;
   T_Record* records[MAX_ITEMS];
   T_Record* k;
   m_get_all(records); // 전체 상품정보레코드 records에 저장

   size = m_count(); // 크기 저장
   printf("%s",m_info_all());

   for(i = 0; i < size; i++)
   {  
      k = records[i];
      index = i;
      result = m_info_category(k,index); // 카테고리별 보고서 출력
      if(result != 0)
      {        
         printf("%s",result);
      }
   }

   for(i = 0; i < size; i++)
   {
      k = records[i];
      index = i;
      result = m_info_company(k,index); // 제조사별 보고서 출력
      if(result != 0)
      {
         printf("%s",result);
      }
   }
}
void load_file() {
   //데이터파일 읽기
   printf("모든 정보가 삭제되고 새로운 정보가 로드됩니다. ");
   printf("1.예 0.아니오");
   int option;
   scanf("%d",&option);
   if(option == 0) {
      return;
   }
   m_delete_all(); // 레코드 모두 제거

   FILE* f = fopen("items.txt","r");
   char name[100], category[100], company[100];
   int price, sell, sum_price;

   while(!feof(f)) {
      if(!m_is_available()) { // 데이터가 최대개수를 넘으면
         printf("%d개의 상품까지만 저장할 수 있습니다!\n",MAX_ITEMS);
         break;
      }
      int n = fscanf(f,"%s %s %s %d %d %d", name, category, company, &price, &sell, &sum_price);
      if(n < 6) {
         if(n >= 0) { // 파일의 형식이 잘못되었을 때
         printf("파일명/카테고리/제조사/가격/판매량/총 판매수익 순으로 파일을 다시 작성해주세요!\n");
         }
         break;
      }
      if(m_search_by_name(name)) { // 중복되는 상품명이 존재할 때
            printf("중복된 상품명(%s)의 상품은 한번만 저장됩니다.\n",name);
            continue;
      }
      m_create(name,category,company,price,sell,sum_price);
   }
   printf("%d개의 정보를 파일에서 읽어왔습니다!\n",m_count());
   fclose(f);
}
void save_file() {
   //데이터파일 저장
   FILE* f = fopen("items.txt","w");
   printf("모든 레코드를 items.txt 파일에 저장합니다.\n");
   int size = m_count();
   T_Record* records[MAX_ITEMS];
   m_get_all(records); // 전체 상품정보 레코드 records에 저장
   for(int i = 0; i < size; i++) {
      T_Record* k = records[i];
      fprintf(f,"%s\n",m_to_string_save(k));
   }
   fclose(f);
}
void save_info_record() {
  FILE* f = fopen("report.txt", "w");
  int i, size, index;
  char* result;
  T_Record* records[MAX_ITEMS]; // 전체상품레코드를 가져올 구조체 포인터 배열 MAX_ITEMS는 최대 크기
  T_Record* k;
  m_get_all(records); // 전체상품레코드를 가져옴
  size = m_count(); // 전체상품레코드의 크기를 가져옴
  printf("보고서를 report.txt 파일에 저장합니다.\n");
  fprintf(f,"%s\n",m_info_all());

  for(i = 0; i < size; i++)
  {
     k = records[i];
     index = i;
     result = m_info_category(k,index); // 구조체 포인터와 index값을 parameter로 넘겨서 가져온 보고서를 result에 저장
     if(result != 0) // 보고서의 내용이 존재하면 출력
     {
       fprintf(f,"%s\n",result);
     }
  }

  for(i = 0; i < size; i++)
  {
     k = records[i];
     index = i;
     result = m_info_company(k,index); // 구조체 포인터와 index값을 parameter로 넘겨서 가져온 보고서를 result에 저장
     if(result != 0) // 보고서의 내용이 존재하면 출력
     {
        fprintf(f,"%s\n",result);
     }
  }
  fclose(f); 
}

void optimize_record()
{
   int value;
   value = m_optimize_all();
   if(value == -1) {
      printf("레코드가 비어있어 최적화할 레코드가 없습니다!\n");
   }
   else if(value == 1) {
      printf("상품정보레코드가 이미 최적화되어있습니다.\n");
   }
  
   else {
      printf("모든 상품정보레코드가 최적화되었습니다!\n");
   }
}

void sort_record()
{
   m_sort_all();
   printf("모든 상품정보레코드를 카테고리순, 총 판매수익순으로 정렬했습니다.\n");
}
