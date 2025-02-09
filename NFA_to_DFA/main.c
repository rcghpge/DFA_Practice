#include <stdio.h>
#include <string.h>

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
	char *input = getln();

	int input_len = strlen(input);

	for (int i = 0; i < input_len; i++)
	{
		if(q0)
		{
			q0 = false
			if(input[i] == "a")
			{
				q1 = true
			}
			else
			{
				q3 = true	
			}
		}

		if(q1)
		{
			if(input[i] == "b")
			{
				q1 = false;
				q2 = true
			}
		}

		/* q2 is final state that goes to itself
		if(q2)
		{

		}
		*/

		if(q3)
		{
			if(input[i] == "a")
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


char *getln()
{
    char *line = NULL, *tmp = NULL;
    size_t size = 0, index = 0;
    int ch = EOF;

    while (ch) {
        ch = getc(stdin);

        /* Check if we need to stop. */
        if (ch == EOF || ch == '\n')
            ch = 0;

        /* Check if we need to expand. */
        if (size <= index) {
            size += CHUNK;
            tmp = realloc(line, size);
            if (!tmp) {
                free(line);
                line = NULL;
                break;
            }
            line = tmp;
        }

        /* Actually store the thing. */
        line[index++] = ch;
    }

    return line;
}
