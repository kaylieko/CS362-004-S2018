#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	// space to special character } 
	// space=32 to }=125
	int range = 125 - 32 + 1;
	int randNum = rand()%range + 32;

	//convert a random number to a char type.
	char randChar = (char) randNum;

	return randChar;
}

//reference https://www.geeksforgeeks.org/program-generate-random-alphabets/
char *inputString()
{
	int i;
	int numPredefinedString = 5; //size of predefined string = 'reset'
	char isString[numPredefinedString+1]; // C string with max. 5 chars + NULL terminator 
		
	//generate 5 random characters in a string
	for (i = 0; i < numPredefinedString; i++) {
		// a=97 to z=122
		int range = 122 - 97 + 1;
		// generate random number in the range
		int randNum = rand()%range + 97;
		// convert a random number to a char type.
		char randChar = (char) randNum;
		isString[i] = randChar;
	}
	//set the last character as trailing null
	isString[5] = '\0';
	char *randString = isString;
	//returns a string composed of randomly chosen characters.
	return randString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;

  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' ' && state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    //string 'reset\0'
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
