
#include <stdio.h>
#define Num_quesitons 10

struct quiz
{
    char questions[100];
    char options[4][100];
    int correctAnswer;
};

int main()
{

    struct quiz quiz[Num_quesitons] = {
        {"1. Solve 16/4*2-8 ? ", {"1: -6", "2: 6", "3: 0", "4: -24"},3},
         {"2. What is 5*3? ", {"1: 15", "2: 10", "3: 5", "4: 30"}, 1},
        {"3. What is 10/2? ", {"1: 5", "2: 10", "3: 2", "4: 8"}, 1},
        {"4. What is 7+3? ", {"1: 10", "2: 7", "3: 5", "4: 9"}, 1},
        {"5. What is the square root of 81? ", {"1: 7", "2: 8", "3: 9", "4: 10"}, 3},
        {"6. What is 12*12? ", {"1: 144", "2: 121", "3: 132", "4: 169"}, 1},
        {"7. What is 100/25? ", {"1: 2", "2: 3", "3: 4", "4: 5"}, 3},
        {"8. What is the cube of 3? ", {"1: 9", "2: 18", "3: 27", "4: 81"}, 3},
        {"9. What is 15-7? ", {"1: 6", "2: 8", "3: 7", "4: 9"}, 2},
        {"10. What is 9*9? ", {"1: 72", "2: 81", "3: 90", "4: 99"}, 2}
    };

    int score = 0;
    int userAns;

    for (int i = 0; i < Num_quesitons; i++)
    {
        printf("\n%s\n", quiz[i].questions);
        for (int j = 0; j < 4; j++)
        {
            printf("%s\t", quiz[i].options[j]);
        }
        printf("your answer : ");
        scanf("%d", &userAns);

        if (userAns == quiz[i].correctAnswer)
        {
            printf("Correct!\n");
            score ++;
        }
        else
            {
                printf("oh sorry ! try next time \n");
            }
    }
 printf("your score is %d ", score);
    return 0;
}