# 상품판매내역 관리 프로그램 #     
     
이 프로그램은 상품 판매내역을 관리하는 프로그램입니다.     
각각의 레코드는 상품명 카테고리 제조사 가격 판매량 총 판매수익 으로 구성되어 있습니다.     
     
     
## 메뉴 구성 ##     
     

### 1. 레코드 추가
빈 레코드들 중 인덱스 번호가 가장 적은  레코드에 정보를 생성합니다.     
     
     
### 2. 레코드 읽어오기
특정 조건을 검색하여 입력 값과 일치하는 정보를 가진 레코드를 읽어와서 출력합니다.     
  * 하위 4개 메뉴     
    1. 상품명으로 검색     
    2. 카테고리로 검색     
    3. 제조사로 검색     
    4. 판매량의 범위     
    
    
### 3. 레코드 업데이트
특정 조건을 검색하여 입력 값과 일치하는 정보를 가진 레코드를 업데이트 합니다.          
  * 하위 4개 메뉴     
    1. 상품명으로 검색     
    2. 카테고리로 검색     
    3. 제조사로 검색     
    4. 판매량의 범위     
    
    
### 4. 레코드 삭제
특정 조건을 검색하여 입력 값과 일치하는 정보를 가진 레코드를 삭제합니다.     
  * 하위 4개 메뉴     
    1. 상품명으로 검색     
    2. 카테고리로 검색     
    3. 제조사로 검색     
    4. 판매량의 범위     
    
    
### 5. 전체 레코드 출력
현재 저장되어있는 전체 상품정보 레코드를 출력합니다.     
     
     
### 6. 전체 레코드에 관한 보고서 출력
현재 저장되어 있는 전체 상품정보 레코드에 관한 보고서     
(총 상품개수 및 판매수익, 카테고리별 상품개수 및 판매수익, 제조사별 상품개수 및 판매수익)를 출력합니다.     
     
     
### 7. 파일 불러오기
items.txt에 있는 데이터 파일들을 불러와 레코드를 생성합니다.     
     
     
### 8. 파일 저장하기
현재 프로그램에 있는 전체 상품정보 레코드를 items.txt 파일에 저장합니다.     
     
     
### 9. 보고서 파일 저장하기
현재 저장되어 있는 상품정보 레코드에 관한 보고서를 report.txt 파일에 저장합니다.     
     
     
### 10. 전체 레코드 최적화
전체 상품정보레코드 중 레코드 삭제로 인해 빈 레코드가 생긴경우, 빈 레코드를 끝으로 몰아서 최적화합니다.          
     
     
### 11. 전체 레코드 정렬
전체 상품정보레코드를 카테고리(오름차순), 총 판매수익(내림차순)으로 정렬합니다.     
     
     
     
## make 방법 ##
     
### 1. 단순 프로그램 실행 시
make main -----> ./main     
     
     
### 2. 프로그램 디버깅 실행 시
make main_debug -----> ./main     
     
     
### 3. 오브젝트 파일과 실행파일 삭제 시
make clean



2020-06-10 체크완료!  
     
     
     
     






