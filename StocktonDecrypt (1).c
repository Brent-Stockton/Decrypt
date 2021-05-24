/** Program using decryption to print *hidden message
*  
*
* Completion time: 5 hrs
* 
* @author Brent Stockton
* @version 1.0
*
*/
#include <stdio.h>
#include <string.h>

#define CHUNK_LENGTH (20 + 1) //each chunk has twenty characters, we add 1 so

#define NUMBER_OF_CHUNKS 4 //the message is spread across 4 chunks.

#define DECRYPTION_SHIFT 5  //this is the ASCII table shift used for decryption.

void sort_chunks();
void decrypt_chunks();
void display_chunks();
void display2D(char arr[NUMBER_OF_CHUNKS][CHUNK_LENGTH]);
void display1D(char arr[], int size);
void bubble_sort(char array[], int size);
void swap_strings(char *x1, char *y1);


char chunks[NUMBER_OF_CHUNKS][CHUNK_LENGTH];

//Displays 2d Array
void display2D(char arr[NUMBER_OF_CHUNKS][CHUNK_LENGTH])
{
  for (int i = 0; i < NUMBER_OF_CHUNKS; i++)
  {
    for (int j = 0; j < CHUNK_LENGTH; j++)
    {
      printf("%c", arr[i][j]);
    }
    printf("\n");
  }
}

//displays 1d array
void display1D(char arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%c", arr[i]);
  }
  printf("\n");
}

//Bubble sort buggy **
void bubble_sort(char array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (array[i] > array[j])
      {
        int temp = array[i];
        array[i] = array[j];
       array[j] = temp;
      }
    }
  }
}

void swap_strings(char *x1, char *y1)
{

  char temp[CHUNK_LENGTH];

  strcpy(temp, x1);

  strcpy(x1, y1);

  strcpy(y1, temp);
}

void sort_chunks()
{

  int i, j;
  int min_idx;

  for (i = 0; i < NUMBER_OF_CHUNKS; i++)
  {

    min_idx = i;

    for ( j = i + 1; j < NUMBER_OF_CHUNKS; j++){

      int jID = chunks[j][0];
      int minID = chunks[min_idx][0];

      if(jID < minID){
         min_idx = j;
      }

    swap_strings(chunks[i], chunks[min_idx]);
      }
   }
}

void decrypt_chunks()
{
  for (int i = 0; i < NUMBER_OF_CHUNKS; i++)
  {
     char* str = chunks[i];

    for (int j = 1; j < CHUNK_LENGTH - 1; j++)
    {
      *(str + j) = *(str + j) - DECRYPTION_SHIFT;     
    }
  }
}

void display_chunks()
{
  int i;

  for(i = 0; i < NUMBER_OF_CHUNKS; i++){
     printf("%s", chunks[i]+1);
  }
}

int main()
{

	//copy message into memory.
	strcpy(chunks[0], "2i1%fsi%fs%jstwrtzx%");
	strcpy(chunks[1], "1'H%nx%vznwp~1%kqf|j");
	strcpy(chunks[2], "4R3%Wnyhmnj%%%%%%%%%");
	strcpy(chunks[3], "3xzhhjxx3'%2%Ijssnx%");

  printf("\n2D DISPLAY BEFORE DECRYPT: \n\n");
  display2D(chunks);
  char array2[84];
  int index = 0;

  for (int i = 0; i < NUMBER_OF_CHUNKS; i++)
  {
    for (int j = 0; j < CHUNK_LENGTH; j++)
    {
      array2[index++] = chunks[i][j];
    }
  }

  printf("\n1D DISPLAY BEFORE DECRYPT:\n\n");

  display1D(array2, 84);

  printf("\nFINAL DECRYPTION:\n\n");

  sort_chunks();

  decrypt_chunks();

  display_chunks();

  //Bubble sort answer - buggy
 /* printf("\n1D ARRAY CONVERSION:\n\n");
  
  display1D(array2, 84);

  bubble_sort(array2, 84);

  printf("\nSORTED ARRAY IN 1D:\n\n");
  display1D(array2, 84);

  decrypt_chunks();

  printf("\nFINAL DECRYPTION:\n\n");
  display_chunks();*/

  return 0;
}