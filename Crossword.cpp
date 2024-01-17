#include <bits/stdc++.h>
using namespace std;

//number of ways to fill the grid
int ways=0;

//function to print matrix
void printMatrix(vector<string>& matrix, int n)
{
    for(int i=0; i<n; i++)
    cout << matrix[i] << endl;
}

//check on current word Horizontally, x= row, y-column
vector<string> checkHorizontal(int x, int y, vector<string> matrix, string currentWord)
{
    int n = currentWord.length();
    
    for(int i=0; i<n; i++)
    {
        if(matrix[x][y+i] == '#' || matrix[x][y+i] == currentWord[i])
           matrix[x][y+i] = currentWord[i];
        
        else
        {
            matrix[0][0] = '@';
            return matrix;
            //cannot be placed Horizontally
        }
    }
    return matrix;
}



//now check vertically
vector<string> checkVertical(int x, int y, vector<string> matrix, string currentWord)
{
    int n = currentWord.length();
    
    for(int i=0; i<n; i++)
    {
        if(matrix[x+i][y] == '#' ||
           matrix[x+i][y] == currentWord[i])
           
           matrix[x+i][y] = currentWord[i];
           
        else
        {
            matrix[0][0] = '@';
            return matrix;
            //cannot be placed vertically
        }
    }
    return matrix;
}


//recursively checks for every 
// word that can align vertically in one loop 
// and in another loop it checks for those words 
// that can align horizontally words 
void solvePuzzle(vector<string>& words, vector<string> matrix, int index, int n)
{
    if(index < words.size())
    {
        string currentWord = words[index];
        int maxLen = n - currentWord.length();
        
        //vertical
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= maxLen; j++)
            {
                vector<string> temp = checkVertical(j, i, matrix, currentWord);
                
                if(temp[0][0] != '@')
                {
                    solvePuzzle(words, temp, index + 1, n);
                    
                }
                
            }
            
        }
        //horizontal
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= maxLen; j++)
            {
                vector<string> temp = checkHorizontal(i, j, matrix, currentWord);
                
                if(temp[0][0] != '@')
                {
                    solvePuzzle(words, temp, index + 1, n);
                }
            }
        }
    }
    //fuction to print crossword
    else
    {
        cout << (ways + 1) << " way to solve the puzzle " << endl;
        printMatrix(matrix, n);
        cout << endl;
        
        //increase the ways
        ways++;
        return;
    }
}

//driver code
int main()
{
    //length of grid
    int n1 = 10;
    
    //matrix to hold the grid puzzle
    vector<string> matrix;
    
    //take the input of the puzzle and make n1 x n1 grid
    matrix.push_back("*#********");
    matrix.push_back("*#********");
    matrix.push_back("*#****#***");
    matrix.push_back("*##***##**");
    matrix.push_back("*#****#***");
    matrix.push_back("*#****#***");
    matrix.push_back("*#****#***");
    matrix.push_back("*#*######*");
    matrix.push_back("*#********");
    matrix.push_back("***#######");
    
    vector<string> words;
    
    //the words matrix will hold all words needed to fill the grid
    words.push_back("PUNJAB");
    words.push_back("JHARKHAND");
    words.push_back("MIZORAM");
    words.push_back("MUMBAI");
    
    //initialize the number of ways to zero
    ways = 0;
    
    //recursive function to solve the puzzle
    solvePuzzle(words, matrix, 0, n1);
    cout << "Number of ways to fill the grid is " << ways << endl;
    
    return 0;
}