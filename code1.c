#include <stdio.h>

// function that will figure out all the ways to reach a certain score in a football game.
void findCombinations(int score) {
     // These are like boxes that will hold numbers for each type of football score (TD means touchdown, FG means field goal, safety is another type of score).
    int TD, TD_1pt, TD_2pt, FG, safety;
//prints the message to say what the score is
    printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

    for (TD_2pt = 0; TD_2pt <= score / 8; TD_2pt++) {//counting how many touchdowns with 2 point conversion(8 pts)
        for (TD_1pt = 0; TD_1pt <= score / 7; TD_1pt++) { //counting touchdowns with a 1-point field goal (7pts)
            for (TD = 0; TD <= score / 6; TD++) { //counting regular touchdowns (6pts)
                for (FG = 0; FG <= score / 3; FG++) {//counting field goals (3pts)
                    for (safety = 0; safety <= score / 2; safety++) { // counting safeties(2pts)
                        if (8 * TD_2pt + 7 * TD_1pt + 6 * TD + 3 * FG + 2 * safety == score) { //making sure that it all adds up to the score that user wants
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", //If the total points equal the score, the computer tells us how many of each type we need.
                                   TD_2pt, TD_1pt, TD, FG, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;//holds score

    while (1) { //loops until user tells it to stop
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");//asking user to enter score
        scanf("%d", &score);//reads the score

        if (score <= 1) { //program stops running because user type 0 or 1
            break; 
        }

        findCombinations(score);//if the score is bigger than one all the possible combinations are found
    }

    return 0; //program is finished
}