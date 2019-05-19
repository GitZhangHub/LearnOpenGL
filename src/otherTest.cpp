#include <iostream>
#include "learnopengl/OpenGL330AP.h"
#include <vector>
int bigOrLittle()
{
    char * string = "abc中文123";
    std::cout<<"pointer address:"<<static_cast<void*> (&string) <<std::endl;
        std::cout<<"pointer address:"<<static_cast<void*> (string) <<std::endl;
    for(int i=0 ;i<12;i++)
    {
//        std::cout<<"address:"<<static_cast<void*> (&(string[i]))<<"  ;value:"<<string[i]<<std::endl;
        printf("value address :%x  ;value:%c\n",&(string[i]),string[i]);

    }

    int a = 0x12345678;

    if(*(unsigned char*)&a == 0x12)
    {
        printf("Big Endian\n");

    }else if(*(unsigned char*)&a == 0x78)
    {
        printf("little Endian\n");
    }else{
        printf("o no ~\n");
    }
}

int bigOrLittle2()
{
    union check
    {
        int intValue;
        char charValue;
    } Endian;
    Endian.intValue=1;
    if(1 == Endian.charValue)
        printf("little Endian.\n");
    else
        printf("big Endian.\n");


}





int A::getKey() const
{
return _key;
}

void A::setKey(int key)
{
    _key = key;
}

void A::getSelf()
{
    printf("A::getSelf().\n");
}

//std::string A::getCode() const
//{
//return _code;
//}

//void A::setCode(const std::string &code)
//{
//_code = code;
//}


B::B()
    :_selfKeep(12345)
{

}

void B::getSelf()
{
    printf("B::getSelf()\n");
}

int B::getSelfKeep()
{
    return _selfKeep;
}


//array[row][column]
int minPathSum(int (*array)[4],int row,int column)
{
    if(array ==NULL || array[0]==NULL )
        return 0;
    int** result = new int*[row];
    for(int i=0;i<row;++i)
    {
        result[i]= new int[column];
    }
    result[0][0]= array[0][0];
    for(int n =1;n<column;n++)
        result[0][n]=result[0][n-1]+array[0][n];
    for(int m=1;m<row;m++)
        result[m][0]=result[m-1][0]+ array[m][0];
    for(int m =1;m<row;m++)
        for(int n=1;n<column;n++)
            result[m][n]=std::min(result[m][n-1],result[m-1][n])+array[m][n];


    return result[row-1][column-1];
}

int minPathSum2(int* pArray,int row,int column)
{
   if(pArray == nullptr)
       return 0;
   int m=0 , n=0;

   int* result = new int[column];
   //pos: aArray[m*column+n]
   result[0]=pArray[0];
   for(n= 1;n<column;++n)
       result[n]=result[n-1]+pArray[m*column+n];

   for(m=1;m<row;++m)
   {
       result[0]+=pArray[m*column];
       for(n=1;n<column;++n)
           result[n]=std::min(result[n-1],result[n])+pArray[m*column+n];
   }
    return result[column-1];




}


int minCoins(int* arr,int aim)
{


}












