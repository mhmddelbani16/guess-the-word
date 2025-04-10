#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_COUNT 5
#define MAX_WORD_LENGTH 20

// Function to fill the char array with a random word and return its length
int fillRandomWord(char* arr) {
    // Array of predefined words
    const char* words[WORD_COUNT] = { "tiger", "lion", "elephant", "zebra", "camel" };

    // Randomly select a word index
    int randomIndex = rand() % WORD_COUNT;

    // Copy the selected word into the passed char array
    snprintf(arr, MAX_WORD_LENGTH, "%s", words[randomIndex]);

    // Return the length of the word
    return strlen(arr);
}

// Function to get the length of a word
int getWordLength(char* word) {
    int i = 0;
    while (word[i] != '\0') {
        i++;
    }
    return i;
}

// Function to guess the word letter by letter
void guessWordLetterByLetter(char* word) {
    int length = fillRandomWord(word);  // Get a random word
    char guess[length + 1];  // Allocate memory for the guess array
    memset(guess, 0, sizeof(guess));  // Initialize guess array with null characters
    int j = 0;
    
    printf("Guess the word, letter by letter!\n");

    // Loop until the whole word is guessed
    while (j < length) {
        printf("Enter your guess for letter %d: ", j + 1);
        
        // Read a single character input and handle newline
        scanf(" %c", &guess[j]);

        // Check if the guessed letter is correct
        if (word[j] == guess[j]) {
            printf("Correct letter!\n");
            j++;  // Move to the next letter
        } else {
            printf("Incorrect letter. Try again.\n");
        }
    }
    
    printf("Congratulations! You've guessed the word: %s\n", word);
}

int main() {
    srand(time(NULL));  // Initialize random number generator

    char randomWord[MAX_WORD_LENGTH];

    // Start the guessing game
    guessWordLetterByLetter(randomWord);

    return 0;
}
