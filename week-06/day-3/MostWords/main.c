#include <stdio.h>
#include <string.h>

typedef struct {
    char word[20];
    int occurence;
}word_count_t;

// Find the most common word in file.txt
// You need to make sure that characters like commas, colons, etc are not part of the words.
// Also make it case sensitive so words that only different in case sensitivity are the same.

int main()
{
    FILE* my_file = fopen("../file.txt", "r");

    word_count_t result[1000];
    //char unique_words[10000];
    //int occurence[1000];   //egyedi szavak hányszor fordultak elő

    int word_count = 0;
    int unique_word_count = 0;
    char buffer[256];
    char* words;

    while (fgets(buffer, 256, my_file) != NULL) {

        words = strtok(buffer, " ,!?;:.-\n");
        //strcpy(unique_words, word);

        while (words != NULL) {
            printf("%s\n", words);
            words = strtok(NULL, " ,!?;:.-\n");

            if(words != NULL && strcasestr(unique_words, words) == NULL) {
                strcat(unique_words, word);
                unique_word_count++;
            } else {

            }

            word_count++;

            //honnan lehet tudni, hogy ha már volt a szó, akkor hanyadik elemét kell frissíteni az occurence table-nek?
            //mekkorák legyenek a tömbök?
            //megoldani structtal?
        }
    }

    printf("%s\n", unique_words);
    printf("Total number of words: %d, unique number of words: %d\n", word_count, unique_word_count);

    fclose(my_file);
    return 0;
}


//1. hány egyedi eleme van a listának?
//2. result struct tömb létrehozása megfelelő mérettel
//3. végigmenni még egyszer a szavakon - meg kell nézni, hogy benne van-e már a result struct-ban - return value előfordulás indexe
//4. ha benne van, akkor megkeresni az elem indexét, és megnöveli a count-ot eggyel
//5. ha nincs benne, akkor hozzáadni