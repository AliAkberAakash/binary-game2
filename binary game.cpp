#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,point=7,q;
    char ch, s[10000],lo;
    FILE* f1;
    f1=fopen("score.txt","a");

    srand(time(NULL));

    int d=rand()%100;

    printf("The computer will guess a number from 1 t0 100. U will have to guess the number in 7 choices.\n7 points for 1st choisce 6 for 2nd and so on\n");
    printf("If u can't find it in 7 terms u loose\n");


    start:

    printf("Enter y to start\n");

    scanf("%c", &ch);

    if(ch=='y')
    {

        system("cls");

        for(i=0; i<7; i++)
        {
            printf("\n\nEnter the number you guessed\n");

            scanf("%d", &q);
            getchar();
            if(q==d)
            {
                printf("You got it! your point is %d\n", point);

                printf("Enter your name:\n");
                gets(s);

                fprintf(f1,"%s : %d\n", s,point);
                fclose(f1);
                f1=fopen("score.txt", "r");
                printf("The scores are: \n");
                while(fscanf(f1,"%c", &lo)!=EOF)
                {
                    printf("%c", lo);
                }

                fclose(f1);

                break;
            }
            else
            {
                if(i!=6)
                {
                    printf("Wrong answer!!!\n\n Hint: ");
                    if(q>d)
                    printf("Pick a smaller number\n");
                    else
                    printf("Pick a larger number\n");

                    point--;
                }
                else
                printf("Game over!!!\n");

            }
        }


    }
    else
    {
        system("cls");
        printf("Invalid choice\n");
        goto start;
    }

    return 0;
}
