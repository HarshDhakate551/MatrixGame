#include <stdio.h>
#include <stdlib.h>

int arr[4][4] = {0};

int random;

void Winning_matrix()
{
    int val = 1;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ((i == 0) || (i == 5))
            {
                printf("----");
            }
            else if ((i > 0 && j != 4) || (i < 5 && j != 4))
            {
                if (val == 16)
                {
                    printf("|    ");
                }

                if (val < 10)
                {
                    printf("|  %d ", val);
                    val++;
                }
                else if (val < 16)
                {
                    printf("| %d ", val);
                    val++;
                }
            }

            if (j == 4)
            {
                printf("|\n");
            }
        }
    }
}

int repeat_check(int val)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (val == arr[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void matrix()
{
    int val = 1;
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (val < 16)
            {
                if ((i > 0 && j != 4) && (i < 5 && j != 4))
                {
                    random = rand() % 16;

                    while (repeat_check(random) == 0)
                    {
                        random = rand() % 16;
                    }

                    arr[i - 1][j] = random;
                    if (arr[i - 1][j] < 10)
                    {
                        printf("| %d  ", arr[i - 1][j]);
                    }
                    else
                    {
                        printf("| %d ", arr[i - 1][j]);
                    }

                    val++;
                }
            }
            else if (val == 16)
            {
                printf("|    ");
                val++;
            }

            if (j == 4)
            {
                printf("|\n");
                break;
            }

            if (i == 0 || i == 5)
            {
                printf("-----");
            }
        }
    }
}

void game_matrix()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if ((i > 0 && j != 4) && (i < 5 && j != 4))
            {
                if (arr[i - 1][j] < 10)
                {
                    printf("| %d  ", arr[i - 1][j]);
                }
                else
                {
                    printf("| %d ", arr[i - 1][j]);
                }
            }
            else if (i == 0 || i == 5)
            {
                printf("----");
            }

            if (j == 4)
            {
                printf("|\n");
                break;
            }
        }
    }
}

int match_codition()
{
    int match = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == match && (i != 3 && j != 3))
            {
                match++;
            }
            else if (arr[i][j] == 16)
            {
                return 1;
            }
        }
    }
    return 0;
}

void key_w()
{
    int a, b, temp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                a = i;
                b = j;
                break;
            }
        }
    }

    temp = arr[a][b];
    arr[a][b] = arr[a - 1][b];
    arr[a - 1][b] = temp;
}

void key_s()
{
    int a, b, temp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                a = i;
                b = j;
                break;
            }
        }
    }

    temp = arr[a][b];
    arr[a][b] = arr[a + 1][b];
    arr[a + 1][b] = temp;
}

void key_a()
{
    int a, b, temp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                a = i;
                b = j;
                break;
            }
        }
    }

    temp = arr[a][b];
    arr[a][b] = arr[a][b - 1];
    arr[a][b - 1] = temp;
}

void key_d()
{
    int a, b, temp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == 0)
            {
                a = i;
                b = j;
                break;
            }
        }
    }

    temp = arr[a][b];
    arr[a][b] = arr[a][b + 1];
    arr[a][b + 1] = temp;
}

int game()
{
    system("cls");
    // game_matrix();
    int i = 3, j = 3, temp;

    do
    {
        game_matrix();

        printf("Enter your move : ");
        char key;
        fflush(stdin);
        scanf("%c", &key);

        switch (key)
        {
        case 119:
            key_w();
            // game_matrix();
            break;

        case 97:
            key_a();
            break;

        case 115:
            key_s();
            break;

        case 100:
            key_d();
            break;

        case 101:
            printf("Exit Successfull ...");
            return 0;

        case 69:
            printf("Exit Successfull ...");
            return 0;
        }

    } while (!match_codition());

    printf("----------- GAME COMPLETE YOU WON ------------");

    return 0;
}

int main()
{
    system("cls");
    printf("            MATRIX PUZZLE          \n\n");

    printf("\033[0;31m           RULE OF THE GAME          \033[0m \n");

    printf("\033[0;31m 1. You can move only 1 step at a time by arrow keys  \033[0m \n");

    printf("       Move UP : by Up arrow key\n");
    printf("       Move DOWN : by Down arrow key\n");
    printf("       Move LEFT : by Left arrow key\n");
    printf("       Move RIGHT : by Right arrow key\n");

    printf("\033[0;31m 2. You can move at empty space only  \033[0m \n\n");
    printf("\033[0;31m 3. For each valid move the total move will decrease by 1  \033[0m \n\n");
    printf("\033[0;31m 4. Winning Situation : Number in a 4*4 matrix should be in the order from 1 to 15  \033[0m \n\n");

    printf("WINNING SITUATION :\n");

    printf("\033[0;33m");
    Winning_matrix();
    printf("\033[0;0m\n");

    printf("\033[0;31m 5. You can exit at any time by pressing  '\033[0mE'\033[0;31m or '\033[0me\033[0;31m' \033[0m \n\n");
    printf("So try to move in least possible moves \n\n");

    printf("Enter S key to start ...");

    char start;
    scanf("%c", &start);

    matrix();

    if (start == 'S')
    {
        game();
    }

    return 0;
}