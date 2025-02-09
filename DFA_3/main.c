#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// created my own bool
#define bool int
#define true 1
#define false 0

// let N = (Q, Sig, Tran, Start, Final) be an NFA which accepts lang L(N)
// // an equvilaent DFA existsts M = (Q1, Sig, Start1, Final1) 
// L(N) = L(M)


/*
 * Steps for converting NFA to DFA:
 *  * Step 1: Initially Q' = ϕ
 *  * Step 2: Add q0 of NFA to Q'. Then find the transitions from this start state.
 *  * Step 3: In Q', find the possible set of states for each input symbol. If this set of states is not in Q', then add it to Q'.
 *  * Step 4: In DFA, the final state will be all the states which contain F(final states of NFA)
 *
 * */
char *scan(char *string);

char *scan(char *string)
{
	int c; 
	string = malloc(sizeof(char)); // alloc memory
	
	string[0]='\0';

	// we use c to get each char, and make sure its not a newline or EOF 
	for( int i = 0; i < 100 && (c=getchar())!='\n' && c != EOF; i++)
	{
		string = realloc(string, (i+2)*sizeof(char)); //realoc to make space
		string[i] = (char) c; //type cast our int to be a char to store it in our string
		string[i+1] = '\0';   //insert null to make it a string
	}

	return string;
}

int main(int argc, char *argv)
{

	// Base case create a simple DFA and see if its accepted or not
	// L = { w | w has the substring ab } 
	// Sigma = "ab"

	bool q0 = true;
	bool q1 = false;
	bool q2 = false;
	bool q3 = false;

	// by default lets alloc 100 bytes for our user
	char *input = NULL; //pointer to hold string
	
	printf("Please enter a string to see if its in the language\nNote the alphabet is {a, b}");

	// get user input
	input = scan(input);

	int input_len = strlen(input);

	for (int i = 0; i < input_len; i++)
	{
		if(q0)
		{
			q0 = false;
			if(input[i] == 'a')
			{
				q1 = true;
			}
			else
			{
				q3 = true;
			}
		}

		if(q1)
		{
			if(input[i] == 'b')
			{
				q1 = false;
				q2 = true;
			}
		}

		if(q2)
		{
			q2 = true;
			break;
		}

		if(q3)
		{
			if(input[i] == 'a')
			{
				q3 = false;
				q1 = true;
			}
		}
	}


	if(q2)
	{
		printf("The string is in the language of substring ab\n");
	}
	else
	{
		printf("The string is not in the language\n");
	}
	

	return 0;
}


