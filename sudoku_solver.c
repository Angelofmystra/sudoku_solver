#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * TODO: check various functions for algorithmic issues
 * TODO: facilitate code reuse by making algorithms more general
 *
 *
 */

/*
 * Reads a csv file in the cwd named sudoku.csv to a stream and store it in a 2d array. It must be formatted with commas, and be 9 col and 9 row.
 */
int read_sudoku()
{
    char buffer[1024];
    char *record,*line;
    int i=0, j=0;
    int size;
    int puzzle[size][size];
    FILE* stream = fopen("sudoku.csv", "r");
    if(fstream == NULL)
    {
        printf("\n file open failed");
        return -1;
    }
    while((line=fgets(buffer, sizeof(buffer),fstream))!= NULL)
    {
        record = strtok(line,",");
        while(record != NULL)
        {
            printf("record : %s", record);
            puzzle[i][j++] = atoi(record);
            record = strtok(line,",");
        }
        ++i;
    }
    return 0;
}

int only_one_choice_rule(int start, int end)
{
    int accum = 0;
    for(int i = start; i < end; i++)
    {
        for(int j = start; j < end; j++)
        {
            if(!(puzzle[i][j] == 0))
            {
                accum++;
            }
        }
    }
    if(accum == 8)
    {
        // solve task
    }
    return 0;
}

int single_possibility_horizontal_rule(int x, int y)
{
    int accum = 0;
    for(int i = x; i < size; i++)
    {
        if(!(puzzle[x][y] == 0))
        {
            accum++;
        }
    }
    if(accum == 8){
        return 0;
    }
    return -1;
}

int single_possibility_vertical_rule(int x, int y)
{
    return 0;

}

int only_square_rule()
{
   int accum = 0;
   int options[9];

   for(int i = 0; i < size; i++)
   {
       for(int j = 0; j < size; j++)
       {
           accum++;
           options[puzzle[i][j]] = 0;
       }
       if(accum == 7){
           int option_a = 0;
           int option_b = 0;
           for(int k = 0; k < size; k++)
           {
               if(!(options[k] == 0)){
                   if(option_a == 0){
                       option_a = options[k];
                   }else{
                       option_b == options[k];
                   }
               }
           }
           for(int k = 0; k < size; k++)
           {
               if(puzzle[i][k] == 0)
               {
                   // found col
                   // is option_a on this col? look up, then look down
                   for(int n = i; n < 0; n--)
                   {
                       if(puzzle[n][k] == option_a)
                       {
                           // therefore, option_b
                       }
                   }
               }
           }
       }
   }
   return 0;
}

int two_out_of_three_rule()
{
    // loop through every number in the slicing and slotting rule
    for(int i = 0; i < size; i++)
    {
        // check how many i exist in each 3 rows
        for(int j = 0; j < (size/3); j++)
        {
            int row_block_1 = 0;
            // check rows 1-3, iterate down each col

            int where_j = 5; // logic gate, yoloswag!
            // if 1 and 2, then where = 2
            // if 1 and 3, then where = 1
            // if 2 and 3, then where = 0

            int where_k = 55; // sum total of 1-9
            int temp_where_k = 55; // this is implemented to solve a problem.
            for(int k = 0; k < size; k++)
            {
                if(puzzle[j][k] == i){
                    row_block_1++;
                    temp_where_j = temp_where_j - (j+1); // because index starts at 0
                    temp_where_k = temp_where_k - (k+1); // likewise
                } 
                if((k == 8) && (temp_where_k == 0)) // at end of the row
                {
                    temp_where_k == 55; // reset if no answer is found
                }
                if((k == 8) && !(temp_where_k == 0))
                {
                    where_k = temp_where_k;
                }
            }
            if(row_block_1 == 2){
                // check if empty row block
                puzzle[where_j-1][where_k-1] = i;

            }
            // check rows 4-6
            int row_block_2 = 0;
            for(int k = 0; k < size; k++)
            {
                if(puzzle[j+3][k] == i)
                    row_block_1++;
            }
            if(row_block_2 == 2){
                // shit to do
            }
            // check rows 7-9
            int row_block_3 = 0;
            for(int k = 0; k < size; k++)
            {
                if(puzzle[j+6][k] == i)
                    row_block_3++;
            }
            if(row_block_3 == 2){
                // shit to do
            }
        }
    }
}

int sub_group_exclusion_rule()
{
    return 0;
}

int hidden_twin_exclusion_rule()
{
    return 0;
}

int naked_twin_exclusion_rule()
{
    return 0;
}

int x_wing_strategy()
{
    return 0;
}

int swordfish_strategy()
{
    return 0;
}

int x_y_wing_or_hook_strategy()
{
    return 0;
}

int alternate_pair_strategy()
{
    return 0;
}

/*
 * Attempt to solve the sudoku puzzle without using brute force methods.
 */
int solve_puzzle()
{
    return 0;
}

int print_sudoku(int puzzle[][], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; j < n; j++)
            printf("%s", puzzle[i][j]);
        printf("\n");
    }
}

int check_validity_of_proposed_solution()
{
    for(int k = 0; k < 9; k++)
    {
        int l = 0;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(puzzle[i][j] == k)
                {
                    l++;
                }
            }
        }
        if(!(l == 9))
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    int exit = 0;
    exit = read_sudoku();
    exit = solve_puzzle();
    exit = check_validity_of_proposed_solution();
    return exit;
}

