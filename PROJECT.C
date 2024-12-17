#include <stdio.h>
#include <string.h>
#define MQ 5
#define MO 4

// Structure to hold question, option, and correct option 
struct Question 
{
    char qt[454];
    char o[MO][200];
    char ca; 
};

// Function to display question
void disque(struct Question q) 
{
    printf("%s\n", q.qt);
    for (int i = 0; i < MO; i++) 
    {
        printf("%s\n", q.o[i]);
    }
}

// Function to calculate score
int cals(struct Question que[], char userans[]) 
{
    int s = 0;
    printf("\nResult:\n");
    for (int i = 0; i < MQ; i++) 
    {
        printf("Question %d: %s\n", i + 1, que[i].qt);
        if (userans[i] == que[i].ca) 
        {
            s++;
            printf("Your answer: %s (Correct)\n", que[i].o[userans[i] - 'A']);
        }
        else 
        {
            printf("Your answer: %s (Incorrect, Correct: %s)\n", que[i].o[userans[i] - 'A'], que[i].o[que[i].ca - 'A']);
        }
    }
    return s;
}

// Function to display all the questions and calculate sco
int main() 
{
    struct Question que[MQ] = {
        {
            "What is the capital of INDIA?",
            {"A) GOA", "B) Delhi", "C) Bihar", "D) Pakistan"},
            'B'
        },
        {
            "Best thing to do in the world?",
            {"A) Sleeping", "B) Call of Duty", "C) BGMI", "D) Roaming with friends"},
            'D'
        },
        {
            "Who is the winner of IPL 2025?",
            {"A) MI", "B) CSK", "C) RCB", "D) GT"},
            'B'
        },
        {
            "World's saddest day?",
            {"A) When you were born", "B) 15 of AUGUST", "C) 19 NOVEMBER", "D) 2nd October"},
            'C'
        },
        {
            "Most hated subject in sem 1?",
            {"A) Linux", "B) C", "C) Maths", "D) Problem Solving"},
            'A'
        },
    };

    char userans[MQ];
    for (int i = 0; i < MQ; i++) 
    {
        disque(que[i]);
        printf("Please enter the letter of your answer (A/B/C/D): ");
        scanf(" %c", &userans[i]); 
    }

    int s = cals(que, userans);
    printf("You scored %d out of %d\n", s, MQ);
    return 0;

    }