//Codeforces 10.2q
#include <stdio.h>
#include <string.h>
#define MAX_WORDS 100  
#define WORD_LEN 4      
int main() {
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d", &t);
    while (t--) {
        int n;
        printf("\nEnter the number of words each player writes (max %d): ", MAX_WORDS);
        scanf("%d", &n);
        if (n > MAX_WORDS) {
            printf("\nError: You can't enter more than %d words!\n", MAX_WORDS);
            return 1;
        }
        char player[3][MAX_WORDS][WORD_LEN];  
        int points[3] = {0, 0, 0};  
        for (int i = 0; i < 3; i++) {
            printf("\nEnter %d words for Player %d (3 letters each):\n", n, i + 1);
            for (int j = 0; j < n; j++) {
                scanf("%3s", player[i][j]);
            }
        }
        for (int i = 0; i < 3; i++) {     
            for (int j = 0; j < n; j++) {    
                char *word = player[i][j];
                int count = 0;
                for (int k = 0; k < 3; k++) {
                    if (k == i) continue;    
                    for (int l = 0; l < n; l++) {
                        if (strcmp(word, player[k][l]) == 0) {
                            count++;
                        }
                    }
                }
                if (count == 0) {
                    points[i] += 3;   
                } else if (count == 1) {
                    points[i] += 1;  
                }
            }
        }
        printf("\nPoints for this test case: %d %d %d\n", points[0], points[1], points[2]);
    }
    return 0;
}