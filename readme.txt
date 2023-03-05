Task 0
In Task 0, i simply initialize the board and print it.

Task 1
I read n words, and then get each word's coordinate, and i put them on the board.

Task 2
I read n words, and then i use the array of points to calculate the score for the both players. More details in the code

Task 3
Same as in Task2, but here i calculate the score for one word, then i check whether he contains the given strings. If he contains a string or two, i calculate the bonus the word gets,
by using the bonus board.

Task 4
I read n words and two substrings. I have created an array of strings which keeps the words that have already been put on the board. In this way, i can check if a specific words has or
has not been used yet. Afterwards, i loop through the 100 words in the words array, i check if the word at the index i has been used. If he hasn't i check if his first letter is somewhere
on the board, and then if i can place him to the right, or downwards. The program stops when i find the first elidgible word.

Task 5
Same as in Task4, but here the program doesnt stop at the first elidgible word. The idea here is to find the elidgible word which produces the biggest score. So, for each elidgible word i
find, i check whether he is bigger than the max value until that point. If it is bigger, i update the max value with that certain's word points, and save the word in a string, and
separately save his coordinates. After the loop ends, i check if the word + score 2 >= score 1 and then put the word on the table and print the word, otherwise Fail!.

Task 6
Task 6 is a combination of pretty much all tasks. I read n words for player 1, and add them to his score. After each word i read for player 1, i move on to player 2, where i find the word
that produces the biggest score, and is also elidgible. For each word i find or get, whether is for player 1 or 2, i save it so that i know i cannot use him anymore. After i read all the
words, i check which score is bigger, and print the winner.

