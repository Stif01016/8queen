#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#define SIZE 8
//������� ��� ������ ���������� ��������. ����.
void evristic( int e_dos[][ SIZE ], int dos[][ SIZE ], 
const int hor[ SIZE ], const int vert[ SIZE ]);

int main()
{
   int strk, stlb, hod = 0, x,y,z,i,c,v=0,n=0,m, vr_s, vr_st;
   
   int doska[ SIZE ][ SIZE ] = { 0 }; //������ ��� ������ "������� ������"
   int evr_doska[ SIZE ][ SIZE ] = { 0 }; //������ ��� ������ ���������� ��������. ����.
   
   const int horizont[ SIZE ]= {0, 1,1,1,0,-1,-1,-1 }; //������� ��������� �����
   const int vertical[ SIZE ]= {-1, -1,0,1,1,1,0,-1 }; 
   
   srand( time( NULL ) ); 
   
   for ( c = 1; c <= 8; ++c ) { //��������� 8 ������ � �������� ��� ������ ��.i
      
      evristic( evr_doska, doska, horizont, vertical );//� ������ ���. ����.
      z = 28;//��� ������ �������. ���. ����.
      
      m = 1 +  rand() % 3;
      
     //��������� 64 ���� ��� ������ ����. � ����. ���. ����. ������
      for ( x = 0; x <=7; ++x ) { 
      
         for ( y = 0; y <=7; ++y) { 
         
            if ( doska[ x ][ y ] == 0 ){
         
               if ( (evr_doska[ x ][ y ]<= z) && (n <= m) ){
                    
                  ++n;
                  z = evr_doska[ x ][ y ];  
                  strk = x;
                  stlb = y;
                  v = 1;
               }
            }
         }    
      } 
      n = 0;
      if  ( v == 1 ){ 
          
         doska[ strk ][ stlb ] = c;
         vr_s = strk;// ����. ��� ����. �����. �� ���. ���.
         vr_st = stlb;// ��� �����. �� ���. ���.
         //���������  ���� ��� ������ ���� ����., ���., ����., ��������� ������� 
         for ( hod = 0; hod < SIZE; ++hod ) {
         
            for ( i = 1; i < SIZE; ++i ) {
            
               strk += vertical[ hod ]*i;// �������� ����� ���.
               stlb += horizont[ hod ]*i;// �������� ����� ���.
               // ��������� ������� � ������� ����. �����
               if ( strk >= 0 && stlb >= 0 && strk <= 7 && stlb <= 7 
               && doska[ strk ][ stlb ] == 0 ){
                    
                  doska[ strk ][ stlb ] = -1;
               }
               strk = vr_s;// �����. �� ���. ���.
               stlb = vr_st;      
            }
         }  
      }
      v = 0;
   }
   printf( "\n\n" );
    for ( x = 0; x < SIZE; ++x ) {
      
       printf( "\n\n" ); 
      
       for ( y = 0; y < SIZE; ++y ) {
           
           if (doska[ x ][ y ]==-1)
              printf( "*  ", doska[ x ][ y ] );
          else
             printf( "%d  ", doska[ x ][ y ] );
       } 
   }


   printf( "\n\n" );
   system("PAUSE"); 
   return 0;  

} 

void evristic( int e_dos[][ SIZE ], int dos[][ SIZE ], 
const int hor[ SIZE ], const int vert[ SIZE ]){

  int strk, stlb, hod, x,y,z=0,b,i;
  
   for ( x = 0; x < SIZE; ++x ) { 
      
      for ( y = 0; y < SIZE; ++y) { 
         
         z = 0;// ���� ������ �� ������, �� �����. 0
         if ( dos[ x ][ y ] == 0 ){
         
            strk = x;
            stlb = y; 
            ++z;
            
            for ( hod = 0; hod < SIZE; ++hod ) {
                
               for ( i = 1; i < SIZE; ++i ) {
                  strk += vert[ hod ]*i;// �������� ����� ���.
                  stlb += hor[ hod ]*i;// �������� ����� ���.
                  // ��������� ������� � ������� ����. �����
                  if ( strk >= 0 && stlb >= 0 && strk <= 7 && stlb <= 7 
                  && dos[ strk ][ stlb ] == 0 ){
                     ++z; // ������. ���. ����. �����
                     
                  }
                  strk = x;// �����. �� ���. ���.
                  stlb = y;       
               }
            }
         }
         e_dos[ x ][ y ] = z; // �����. ���. ����. �����
      }  
   }
   printf( "\n\n" ); 
   for ( x = 0; x < SIZE; ++x ) {
      
      printf( "\n\n" ); 
      
      for ( y = 0; y < SIZE; ++y ) {
          
         if ( y < 10 )
            printf( "%2d  ", e_dos[ x ][ y ] );
         else 
            printf( "%d  ", e_dos[ x ][ y ] );
      } 
   }






   
}
