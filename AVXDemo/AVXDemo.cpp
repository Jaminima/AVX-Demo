#include "Header.h"

using namespace std;

int main()
{
    //std::cout << "Hello World!\n";

    unsigned int RowExample[] = { 0, 1, 1, 1, 1, 1, 1, 0 };

    __m256i Row_0, Row_1;

    //Loads 8 Values in order into memory starting from the index in RowExample
    Row_0 = _mm256_loadu_si256((__m256i*) & RowExample[0]);

    //Loads 8 Given values into memory in REVERSE order
    Row_1 = _mm256_set_epi32(0, 1, 2, 3, 4, 5, 6, 7);

    __m256i Sum, Multiply_Low, Multiply_High, HorizontalAdd;

    //Adds items in the same position to one another eg: [0,1,2] + [1,3,4] = [1,4,6]
    Sum = _mm256_add_epi32(Row_0,Row_1);

    //Multiply items in the same postion together eg: [0,1,2] + [1,3,4] = [0,3,8]
    Multiply_Low = _mm256_mullo_epi16(Row_0, Row_1); //Returns the lowest 16 bits ie 0->65535
    
    Multiply_High = _mm256_mulhi_epi16(Row_0, Row_1); //Returns highest 16 bits 65535->4294967295

    //Adds items adjacent to each other eg: [0,1,2,3] + [4,5,6,7] = [1,5,9,13]
    HorizontalAdd = _mm256_hadd_epi32(Row_0, Row_1);

    //Retrives the value at the given postion
    std::cout << _mm256_extract_epi32(Sum,0);
}
