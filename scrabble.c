#include "util/scrabble.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/print_board.h"
#define lung 26
//v is an array of points.Each index is the index 
    //for the specific letter. Ex: 1 is for A, 3 is for B and so on
  int v[lung] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
               1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int functie(char *words) 

{
    int numar = 0;
   
    for (int k = 0; k < (int)(strlen(words)); k++) {
                    char schimbb;
                    schimbb = words[k];
                    numar = numar + v[schimbb - 'A'];
                    }
     return numar;           
}
//function functie calculates the score for a certain word, without the bonuses
int functie2(char *p, int x, int y, int d, char yy[2], char xx[2])
{   
    /*this function receives as parameters a pointer to a word, the 3 
    coordinates, and the substrings yy and xx. I calculate the default
    score for a word, using functie, and then i check if the word contains
    the yy substring at the end, and if it does, i look for the bonuses in
    the bonus board. If the words contains substring xx, i do the same thing
    here, according to the bonus rules. Then, i return the score for the word*/
    int i, j;
    int numar1 = functie(p);//
    int length2 = strlen(p);
    if (p[length2 - 2] == yy[0] &&  p[length2 - 1] == yy[1])  
        {
              if (d == 1) {
            for (i = x; i <= x + length2 - 1; i++) {
              if (bonus_board[i][y] == 2) numar1 = numar1 * 3;
            }
          } else {
            if (d == 0) {
              for (j = y; j <= y + length2 - 1; j++) {
                if (bonus_board[x][j] == 2) numar1 = numar1 * 3;
              }
            }
          }
        }

         if (strstr(p, xx) != 0)
         {
          if (d == 1) {
            for (i = x; i <= x + length2 - 1; i++) {
              if (bonus_board[i][y] == 1) numar1 = numar1 * 2;
            }
          }
          if (d == 0) {
            for (j = y; j <= y + length2 - 1; j++) {
              if (bonus_board[x][j] == 1) numar1 = numar1 * 2;
            }
          }
         }
         return numar1;     
}
//function functie2 calculates the score of a certain word, including the bonus
void Task1(char a[ PRINT_BOARD_SIZE][ PRINT_BOARD_SIZE])
{ 
  /*In this task, i read n words and their coordinates, and then place them*/ 

    char c[4];
    fgets(c, 4, stdin);
    int n;
    n = atoi(c);
    
    int z;
        //i read n words and coordinates
    for (z = 1; z <= n; z++) {
      char str[20];
      char *p;
      fgets(str, 20, stdin);
        //setting the terminator
      int length = strlen(str);
      str[length - 1] = '\0';
        //getting the x
      p = strtok(str, " ");
      int x = atoi(p);
      p = strtok(NULL, " ");

        //getting the y
      int y = atoi(p);
      p = strtok(NULL, " ");

        //getting the d
      int d = atoi(p);
        
        //getting the word
      p = strtok(NULL, " ");
      
      int length2 = strlen(p);
     
        //i place the words on the table depending on d
      if (d == 0)  
      {
        int contor = 0;
        for (int j = y; j <= y + length2 - 1; j++) {
          a[x][j] = p[contor];
          contor++;
        }
      }
      if (d == 1)  
      {
        int contor2 = 0;
        for (int i = x; i <= x + length2 - 1; i++) {
          a[i][y] = p[contor2];
          contor2++;
        }
      }

      if (z == n) 
      print_board(a);
    }
}

void Task2()
{   /*in this task, i dont need the words' coordintates. Here, i just use
    the arrays of points to calculate the score for a word by adding the 
    score of each particular letter.*/
    char c[4];
    fgets(c, 4, stdin);

    int n;
    n = atoi(c);
    int numar1, numar2;
    numar1 = 0;
    numar2 = 0;
    int i = 0;
    for (int z = 1; z <= n; z++) {
      char str[20];
      char *p;
      fgets(str, 20, stdin);

      int length = strlen(str);
      str[length - 1] = '\0';
        //in this particular task, i dont really care about the coordintates 
        //the specific words, so i go straight to the word itself
      p = strtok(str, " ");
      p = strtok(NULL, " ");
      p = strtok(NULL, " ");
      p = strtok(NULL, " ");
    
        //i is used to check whether is player 1 or player 2
      if (i % 2 == 0) {
          numar1 = numar1 + functie(p);
      }

      if (i % 2 != 0) {
        numar2 = numar2 + functie(p);
      }
      i++;//it goes to the next player
      if (z == n) {
        printf("Player 1: %d Points\n", numar1);
        printf("Player 2: %d Points\n", numar2);
      }
    }
}

void Task3(char a[ PRINT_BOARD_SIZE][ PRINT_BOARD_SIZE])
{   /*in this task, i place the words on the table, and then i used functie2
    to calculate the score, including the bonus, for each word, and then,
    i add them to the final score depeding on the player.*/
    char xx[4];
        fgets(xx, 4, stdin);
        int lengthx = strlen(xx);
        if( xx[lengthx - 1] == '\n')
        xx[lengthx - 1] = '\0';
       
        char yy[4];
        fgets(yy, 4, stdin);
        int lengthy = strlen(yy);
         if( yy[lengthy - 1] == '\n')
        yy[lengthy - 1] = '\0';
        
        char c[4];
        fgets (c, 4, stdin);
        int n;
        n = atoi(c);//n

        int numar1, numar2;
        numar1 = 0;
        numar2 = 0;//the scores for a word

        int z;
        int scor1 = 0;
        int scor2 = 0;
        int player = 0;//player 1 or player 2
        int i, j;
        for(z = 1; z <=n; z++)
        {
                char str[20];
                char *p;
                fgets(str, 20, stdin);
                int length = strlen(str);
                if(str[length - 1] == '\n')
                str[length - 1] = '\0';
                
                p = strtok(str, " ");
                int x = atoi(p);
                p = strtok(NULL, " ");
                int y = atoi(p);
                p = strtok(NULL, " ");
                int d = atoi(p);
                p = strtok(NULL, " ");
                int length2 = strlen(p);
                
                if(d == 0)
            {   
                int contor = 0;
                for(j = y; j <= y + length2 - 1; j++)
                {
                    a[x][j] = p[contor];
                    contor ++;
                }
            }
            if(d == 1)
            {
                int contor2 = 0;
                for(i = x; i <= x + length2 - 1; i++)
                {
                    a[i][y] = p[contor2];
                    contor2 ++;
                }
            }
                if((player % 2) == 0)//checking the player
                numar1 = functie2(p, x, y, d, yy, xx);
               
                if((player % 2) != 0)
                numar2 = functie2(p, x, y, d, yy, xx);

                
 
               if(player % 2 == 0)
               scor1 = scor1 + numar1;
               else
               {
                   scor2 = scor2 + numar2;
               }
               
                if(z == n)
                {
                    printf("Player 1: %d Points\n", scor1);
                    printf("Player 2: %d Points\n", scor2);
                }
                //i reinitialize the scores for a word,
                //so i can start calculating a score for a word again       
        numar1 = 0;
        numar2 = 0;
        player++;//switching the player
        }
}

void Task4(char a[ PRINT_BOARD_SIZE][ PRINT_BOARD_SIZE])
{   
    /*In this task, i read the words, put them on the table, and, for each
    word i put on the table, i add him to the array of strings i have created
    so that i will know whether i have used it or not. Afterwards, i start 
    looping through the possible 100 words. For each word, i check if he
    hasn't been used already, and if not, if his first letter exists on the
    table, and if it does, then i check if he fits to the right or downwards.
    If he does, i put him on the table, and then the program ends, because
    i have found the first elidgible word.*/ 

    char matrice[100][100];//this is the array for the used strings
    char xx[4];
    fgets(xx, 4, stdin);
    int lengthx = strlen(xx);
    xx[lengthx - 1] = '\0';

    char yy[4];
    fgets(yy, 4, stdin);
    int lengthy = strlen(yy);
    yy[lengthy - 1] = '\0';

    char c[4];
    fgets(c, 4, stdin);
    int n;
    n = atoi(c); 
    int z;
    int contor3 = 0;
    
    for (z = 1; z <= n; z++) {
      char str[20];
      char *p;

      fgets(str, 20, stdin);

      int length = strlen(str);
      if( str[length - 1] == '\n')
      {
      str[length - 1] = '\0';
      }

      p = strtok(str, " ");
      int x = atoi(p);

      p = strtok(NULL, " ");
      int y = atoi(p);

      p = strtok(NULL, " ");
      int d = atoi(p);

      p = strtok(NULL, " ");
      int length2 = strlen(p);
      
      if (d == 0)  
      {
        int contor = 0;
        for (int j = y; j <= y + length2 - 1; j++) {
          a[x][j] = p[contor];
          contor++;
        }
      }
      if (d == 1)  
      {
        int contor2 = 0;
        for (int i = x; i <= x + length2 - 1; i++) {
          a[i][y] = p[contor2];
          contor2++;
        }
      }

      strcpy(matrice[contor3], p); 
      contor3++;   
    }

    int i;
    int check = 1;//check is used to end the program as soon as i find
                  //the elidgible word
    for (i = 0; i <  NUM_WORDS && check; i++) 
    {
      int OK = 0;
      int check2 = 1;//check2 is used to make sure that a word is just once
      //put on the table, because a word may be put in several other places
      //on the table
      //i check if the words has been used
      for (int j = 0; j < contor3; j++) {
        if (strcmp(matrice[j], words[i]) == 0) {
          OK = 1;
        }
      }

      if (OK == 0)  
      {                                           ;
        for (int linie = 0; linie <  PRINT_BOARD_SIZE && check2; linie++)  
        {
          for (int coloana = 0; coloana <  PRINT_BOARD_SIZE && check2; coloana++)  
          { //i used loc1 and loc2 to assume if a word can be placed on
          //horizontal or vertical. If the asuption is false, they became 0,
          //and are reinitialized for every word. If loc or loc2 dont change
          //their value, it means that the word can be placed on the table.
            int loc = 1;
            int loc2 = 1;
            if (a[linie][coloana] == words[i][0])  
            {                 
              if (coloana + strlen(words[i]) <=  PRINT_BOARD_SIZE) 
              {
                for (int z = coloana + 1; z < coloana + (int)(strlen(words[i])); z++) 
                {
                  if (a[linie][z] != '.') loc = 0;
                }
                if (loc == 1) 
                {
                  check2 = 0;
                  check = 0;
                  int contor = 0;
                  for (int m = coloana; m <= coloana + (int)(strlen(words[i]) - 1); m++) {
                    a[linie][m] = words[i][contor];
                    contor++;
                  }
                }
              }
              else
              {
                loc = 0;
              }
              if (loc == 0) {
                if (linie + strlen(words[i]) <=  PRINT_BOARD_SIZE)  
                {
                  for (int zz = linie + 1; zz < (int)(linie + strlen(words[i]));
                       zz++) {
                    if (a[zz][coloana] != '.') loc2 = 0;
                  }
                  if (loc2 == 1) {
                    check = 0;
                    check2 = 0;
                    int contor2 = 0;
                    for (int mm = linie; mm <= (int)(linie + strlen(words[i]) - 1);
                         mm++) {
                      a[mm][coloana] = words[i][contor2];
                      contor2++;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    print_board(a);
  }

void Task5(char a[ PRINT_BOARD_SIZE][ PRINT_BOARD_SIZE])
{     /*In this task, i put the words on the table and calculate the score for
  both players. Same thing i have done in task 4, i keep the words which have
  been put on the table. Then, i start looping throught the 100 words, check if
  the specific word at the count has been used or not. If he has not been used,
  i check if he fits. If he fits, i calculate his iphotetical score including 
  the bonus, using functie2. The point here is that i need to find the word that
  produces the biggest score, on the best position, because a word may fit in 2 
  or more spots, but he will not produce the same score. For each elidgible word 
  i find, i check if the score he produces is bigger than the previos maximum
  score. If it is, i save the word and its coordinates. I can say that i 
  "update" the maximum and its coordinates. After the loop ends, i check  if 
  the maximum score + score2 > score1, and if it does, i place the word on the 
  table according to its coordinates and then print the board. If not, i print 
  the "Fail!" message*/   
    char matrice[100][100];
    char xx[4];
    fgets(xx, 4, stdin);
    int lengthx = strlen(xx);
    xx[lengthx - 1] = '\0';

    char yy[4];
    fgets(yy, 4, stdin);
    int lengthy = strlen(yy);
    yy[lengthy - 1] = '\0';

    char c[4];
    fgets(c, 4, stdin);
    int n;
    n = atoi(c);  

    int numar1, numar2;
    numar1 = 0;
    numar2 = 0;  

    int z;
    int scor1 = 0;
    int scor2 = 0;
    int player = 0;  
    int contor3 = 0;
    for (z = 1; z <= n; z++) {
      char str[30];
      char *p;

      fgets(str, 30, stdin);

      int length = strlen(str);
      str[length - 1] = '\0';

      p = strtok(str, " ");
      int x = atoi(p);

      p = strtok(NULL, " ");
      int y = atoi(p);

      p = strtok(NULL, " ");
      int d = atoi(p);

      p = strtok(NULL, " ");
      int length2 = strlen(p);

        if (d == 0)  
        {
          int contor = 0;
          for (int j = y; j <= y + length2 - 1; j++) {
            a[x][j] = p[contor];
            contor++;
          }
        }
        if (d == 1)  
        {
          int contor2 = 0;
          for (int i = x; i <= x + length2 - 1; i++) {
            a[i][y] = p[contor2];
            contor2++;
          }
        }
        if ((player % 2) == 0) 
          numar1 = functie2(p, x, y, d, yy, xx);

        if ((player % 2) != 0)  // verific jucatorul
          numar2 = functie2(p, x, y, d, yy, xx);
      
        strcpy(matrice[contor3], p);  
        contor3++;

        if (player % 2 == 0)
          scor1 = scor1 + numar1;
        else {
          scor2 = scor2 + numar2;
      }
        numar1 = 0;
        numar2 = 0;
        player++;
      }

      int i;
      int max = 0;
      char cuvant[20];
      int x, y, d;
     for (i = 0; i < NUM_WORDS; i++) {
      int OK = 0;
     
      for (int j = 0; j < contor3; j++) {
        if (strcmp(matrice[j], words[i]) == 0) {
          OK = 1;
        }
      }
     
      if (OK == 0)         
      {                                          
        for (int linie = 0; linie < PRINT_BOARD_SIZE ; linie++)  
        {
          for (int coloana = 0; coloana < PRINT_BOARD_SIZE ; coloana++) 
          { int loc = 1;
              int loc2 = 1;
            if (a[linie][coloana] == words[i][0])  
            {                
              if (coloana + strlen(words[i]) <= PRINT_BOARD_SIZE)  
              {
               
                for (int z = coloana + 1; z < coloana + (int)strlen(words[i]); z++) {
                  if (a[linie][z] != '.') loc = 0;
                }
                if (loc == 1) {
                    if(functie2(words[i], linie, coloana, 0, yy, xx) > max)
                    {
                      max = functie2(words[i], linie, coloana, 0, yy, xx);
                      x = linie;
                      y = coloana;
                      d = 0;
                      strcpy(cuvant, words[i]);
                    }
                    if(functie2(words[i], linie, coloana, 0, yy, xx) == max)
                      if(linie < x)
                      {
                          max = functie2(words[i], linie, coloana, 0, yy, xx);
                          x = linie;
                          y = coloana;
                          d = 0;
                          strcpy(cuvant, words[i]);
                      }
                }
              }
              else
              {
                loc = 0;
              }
              if (loc == 0) {
                if (linie + strlen(words[i]) <= PRINT_BOARD_SIZE) 
                {
                  for (int zz = linie + 1; zz < linie + (int)strlen(words[i]) ; zz++) {
                    
                    if (a[zz][coloana] != '.') loc2 = 0;
                  }
                  if (loc2 == 1) {
                   if(functie2(words[i], linie, coloana, 1, yy, xx) > max)
                    {
                      max = functie2(words[i], linie, coloana, 1, yy, xx);
                      x = linie;
                      y = coloana;
                      d = 1;
                      strcpy(cuvant, words[i]);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
      if(scor2 + max < scor1)
        {
          printf("Fail!\n");
        }
        else
        {
          if(d == 0)
          {
              int contor = 0;
                  for (int m = y; m <= y + (int)strlen(cuvant) - 1; m++) {
                    a[x][m] = cuvant[contor];
                    contor++;
                  }
          }
          else
          {
              int contor2 = 0;
                    for (int mm = x; mm <= x + (int)strlen(cuvant) - 1; mm++) {
                      a[mm][y] = cuvant[contor2];
                      contor2++;
                    }
          }
          print_board(a);
        }
  }

void Task6(char a[ PRINT_BOARD_SIZE][ PRINT_BOARD_SIZE])
{ /* In this task, i read the xx and yy sbutrings, and n. Afterwards, i read n
  words, and their coordintes. For each particular word i find, i put him on 
  the board, and then put him in "matrice", so i that i know it has already
  been used. For the words i read, i sum their score and add it to score1, 
  which is the score for player 1. 
  After i do this, i loop through the words array and find the word
  that has not been used yet and produces the biggest score, and is also
  elidgible, of course. After this, i add his score to score2, which is the
  score for player2, and also save the word in "matrice", so that i know i
  cannot use it again. After i read the n words, i check whose score is bigger,
  and then print the winner.*/
  char matrice[100][100];
      char xx[4];
      fgets(xx, 4, stdin);
      int lengthx = strlen(xx);
      xx[lengthx - 1] = '\0';
      char yy[4];
      fgets(yy, 4, stdin);
      int lengthy = strlen(yy);
      yy[lengthy - 1] = '\0';
      char c[4];
      fgets(c, 4, stdin);
      int n;
      n = atoi(c); 

      int numar1 = 0;
      int scor1 = 0;
      int scor2 = 0;
      int contor3 = 0;
      for (int ii = 0; ii <= n - 1; ii++)
      {
            char str[30];
            char *p;

            fgets(str, 30, stdin);
            int length = strlen(str);
            str[length - 1] = '\0';

            p = strtok(str, " ");
            int x = atoi(p);

            p = strtok(NULL, " ");
            int y = atoi(p);

            p = strtok(NULL, " ");
            int d = atoi(p);

            p = strtok(NULL, " ");
            int length2 = strlen(p);

            if (d == 0)  
            {
              int contor = 0;
              for (int j = y; j <= y + length2 - 1; j++) {
                a[x][j] = p[contor];
                contor++;
              }
            }
            if (d == 1)  
            {
              int contor2 = 0;
              for (int i = x; i <= x + length2 - 1; i++) {
                a[i][y] = p[contor2];
                contor2++;
              }
            }

            numar1 = functie2(p, x, y, d, yy, xx);
            scor1 = scor1 + numar1;
            strcpy(matrice[contor3], p);   
            contor3++;
            numar1 = 0;
         
        //done for the index ii word of player 1

        int max = 0;
        char cuvant[20];
        int x2, y2, d2;
        x2 = 0;
        y2 = 0;
        for (int i = 0; i < 100; i++) {
        int OK = 0;
      
        for (int j = 0; j < contor3; j++) {
          if (strcmp(matrice[j], words[i]) == 0) {
            OK = 1;
          }
        }
        if (OK == 0) 
        {                                          
        for (int linie = 0; linie < 15 ; linie++) 
        {
          for (int coloana = 0; coloana < 15 ; coloana++)  
          { int loc = 1;
              int loc2 = 1;
            if (a[linie][coloana] == words[i][0])  
            {          
              if (coloana + strlen(words[i]) <= 15)  
              {
                for (int z = coloana + 1; z < coloana + (int)strlen(words[i]); z++) {
                  if (a[linie][z] != '.') loc = 0;
                }
               
                if (loc == 1) {
                    if(functie2(words[i], linie, coloana, 0, yy, xx) > max)
                    {
                      max = functie2(words[i], linie, coloana, 0, yy, xx);
                      x2 = linie;
                      y2 = coloana;
                      d2 = 0;
                      strcpy(cuvant, words[i]);
                    }
                    if(functie2(words[i], linie, coloana, 0, yy, xx) == max)
                      if(linie < x2)
                      {
                          max = functie2(words[i], linie, coloana, 0, yy, xx);
                          x2 = linie;
                          y2 = coloana;
                          d2 = 0;
                          strcpy(cuvant, words[i]);
                      }
                }
              }
              else
              {
                loc = 0;
              }
              if (loc == 0) {
                if (linie + strlen(words[i]) <= 15) 
                {
                  for (int zz = linie + 1; zz < linie + (int)strlen(words[i]) ; zz++) {
                    if (a[zz][coloana] != '.') loc2 = 0;
                  }
                  if (loc2 == 1) {
                    
                   if(functie2(words[i], linie, coloana, 1, yy, xx) > max)
                    {
                      max = functie2(words[i], linie, coloana, 1, yy, xx);
                      x2 = linie;
                      y2 = coloana;
                      d2 = 1;
                      strcpy(cuvant, words[i]);
                    }
                      if(functie2(words[i], linie, coloana, 1, yy, xx) == max)
                      if(coloana < y2)
                      {
                          max = functie2(words[i], linie, coloana, 1, yy, xx);
                          x2 = linie;
                          y2 = coloana;
                          d2 = 1;
                          strcpy(cuvant, words[i]);
                      } 
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if(d2 == 0)
          {
              int contor = 0;
                  for (int m = y2; m <= y2 + (int)strlen(cuvant) - 1; m++) {
                    a[x2][m] = cuvant[contor];
                    contor++;
                  }
          }
          else
          {
              int contor2 = 0;
                    for (int mm = x2; mm <= x2 + (int)strlen(cuvant) - 1; mm++) {
                      a[mm][y2] = cuvant[contor2];
                      contor2++;
                    }
          }
            scor2 = scor2 + max;
            strcpy(matrice[contor3], cuvant);  
            contor3++;
            max = 0;
      }//done for the word of player 2 in index ii
        print_board(a);
        if(scor1 > scor2)
        {
        printf("Player 1 Won!\n");
        }
        else
        {
          printf("Player 2 Won!\n");
        }
}

int main() {
  char a[PRINT_BOARD_SIZE][PRINT_BOARD_SIZE];
  int i, j;

  for (i = 0; i < PRINT_BOARD_SIZE; i++) {
    for (j = 0; j < PRINT_BOARD_SIZE; j++) a[i][j] = '.';
  }
    //i have initialized the board 

    //i read the number of the task
  char s[3];
  fgets(s, 3, stdin);
  int val;
  val = atoi(s);

    //TASK 0
    if (val == 0) 
    print_board(a);
  
     //TASK1
    if (val == 1) 
      Task1(a);
  
  
    //TASK 2
    if (val == 2) 
      Task2();
  

    //TASK 3
    if(val == 3)
      Task3(a);
   
    //TASK 4
    if (val == 4) 
        Task4(a);

    //TASK 5
    if(val == 5)
        Task5(a);

    //TASK 6
    if(val == 6)
        Task6(a);
      
   

  return 0;
}