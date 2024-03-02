/* Name: fruitStrings.c
   Author: Courtney Scrimshaw
   Function: take in 10 fruit names, print the longest and shortest fruit, and print if a fruit is a substring to another fruit
   Compilation: gcc -Wall -std=c99 -o fruitStrings fruitStrings.c
   Execution: ./fruitStrings
   Date: created on Feb. 13, 2024
*/

#include <stdio.h>
#include <string.h>

#define MAX_FRUITS 10
#define MAX_LENGTH 16

//declare arrays and variables
int main() {
  char fruits[MAX_FRUITS][MAX_LENGTH];
  int i;
  int j;
  char shortest_fruit[MAX_LENGTH];
  char longest_fruit[MAX_LENGTH];
  int shortest_length = MAX_LENGTH;
  int longest_length = 0;
  int num_fruits = 0;

  printf("Enter 10 fruits or STOP to finish: \n");

  //loop to enter fruit names, fgets reads the input and stores into fruits array
  for (i = 0; i < MAX_FRUITS; i++) {
      printf("Enter fruit %d: ", i + 1);
      fgets(fruits[i], MAX_LENGTH, stdin);

      //checks if last character is newline and removes from string
      if (fruits[i][strlen(fruits[i]) - 1] == '\n') {
          fruits[i][strlen(fruits[i]) - 1] = '\0';
      }
      //checks if fruit name equals STOP, if so it terminates loop
      if (strcmp(fruits[i], "STOP") == 0) {
          break;
      }
      //increment num_fruits to count fruit names entered
      num_fruits++;

      // calculate length of current fruit name and compares with shortest/longest so far
      int length = strlen(fruits[i]);
      if (length < shortest_length) {
          shortest_length = length;
          strcpy(shortest_fruit, fruits[i]);
      }
      if (length > longest_length) {
          longest_length = length;
          strcpy(longest_fruit, fruits[i]);
      }
  }


  printf("\nThe fruit %s contains %d characters, which is the fruit with the least characters\n", shortest_fruit, shortest_length);
  printf("The fruit %s contains %d characters, which is the fruit with the most amount of characters\n", longest_fruit, longest_length);

  //checks if fruit is a substring of another fruit entered
  for (i = 0; i < num_fruits; i++) {
      for (j = 0; j < num_fruits; j++) {
          if (i != j && strstr(fruits[j], fruits[i]) != NULL) {
              printf("The fruit %s has the fruit %s in its name.\n", fruits[j], fruits[i]);
          }
      }
  }


  return 0;

}