#include <stdio.h>
#include <stdlib.h>

//transfer

int totalfare = 0;
float totaldistance = 0;
char* stationspassed[100];
int switching = 0;
int origin, destination;

void lrt1_beepcard();
void lrt1_sjt();
void lrt1_beepTMcard();

void lrt2_beepcard();
void lrt2_sjt();
void lrt2_beepTMcard();

void mrt3_beepcard();
void mrt3_sjt();
void mrt3_beepTMcard();

char temp[10];
int balance;
char sure;

void getBalance(){
    for(;;){
        printf("\nEnter amount: ");
        if(scanf("%d", &balance) != 1){
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid Input\n");
            continue;
        }
        return;
    }
}

void topUpBalance(int payment){
    char yesorno;
    char temp[20];
    int topUp;

    printf("\nBalance is inefficient\n");
    while (getchar() != '\n'); // Clear invalid input
    for(;;){
        printf("\nWould you like to top up your balance?(y/n): ");
        scanf("%c", &yesorno);

        if(yesorno == 'y' || yesorno == 'Y'){
            for(;;){
                printf("\nEnter amount you would like to top up: ");
                if(scanf("%d", &topUp) != 1){
                    while (getchar() != '\n'); // Clear invalid input
                }

                if((topUp + balance) >= payment){
                    balance += topUp;
                    while (getchar() != '\n'); // Clear invalid input
                    return;
                }
                printf("\nInvalid Input\n");
            }
        }else if(yesorno == 'n' || yesorno == 'N'){
            //output();
            exit(0);
        }else{
            printf("\nInvalid Input\n");
        }
    }
}

float lrt1_distances[]= {
        0.588, 1.01, 0.73, 1.061, 0.827, 0.794,
        0.754, 1.214, 0.725, 0.685, 0.648, 0.618,
        0.671, 0.927, 0.66, 0.954, 1.087, 2.25,
        1.87
    };

float lrt2_distances[] = {
        1.05, 1.38, 1.35, 1.23,
        0.92, 1.07, 1.16, 1.43,
        0.95, 1.97, 1.79, 2.23
    };

float mrt3_distances[] = {
        1.22, 0.94, 1.85, 1.45,
        2.31, 0.77, 0.98, 0.77,
        1.83, 0.88, 1.19, 1.89
    };

int main() {
    int choice;
    char input1, input2, input3;
    char cc1, cc2, cc3;
    char continue_Program;

do {
    printf("\033[1;32mWelcome to the Rail Transit of the Philippines!\033[0m\n\n");

    printf("1. Lrt 1\n2. Lrt 2\n3. Mrt 3\n\n");
    printf("\033[1;33mEnter what train line you are currently at: \033[0m");
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            printf("\033[1;32mWe currently have 3 types of card:\033[0m\n\n1.Single Journey Ticket(S)\n2.Beep Card (B) \n3.Concessionary Card (C)\n");
            printf("\033[1;33m\nWhat card do you have?: \033[0m");
            scanf(" %c", &input1);

            if (input1 == 'S' || input1 == 's') {
                printf("\n");
                lrt1_sjt();
                break;
            }

            else if (input1 == 'B' || input1 == 'b') {
                printf("\n");
                getBalance();
                lrt1_beepcard();
                break;
            }

            else if (input1 == 'C' || input1 == 'c') {
                printf("\n");
                printf("\033[1;32mAre you a..\033[0m\n1.PWD (P) \n2.Senior (S) \n3.Student (T)\n");
                printf("\nEnter the corresponding letter: ");
                scanf(" %c", &cc1);

                if (cc1 == 'P' || cc1 == 'p' || cc1 == 'S' || cc1 == 's' || cc1 == 'T' || cc1 == 't') {
                    printf("\n");
                    getBalance();
                    lrt1_beepTMcard();
                    break;
                }

                else {
                    printf("\033[1;31mInvalid input.\033[0m\n");
                    break;
                }

            }

            else {
                printf("\033[1;31mInvalid input.\033[0m\n");
                break;
            }

        case 2:
            printf("\n\033[0;32mWe currently have 3 types of card: \033[0m\n\n1.Single Journey Ticket (S)\n2.Beep Card (B) \n3.Concessionary Card (C)\n");
            printf("\n\033[0;33mWhat card do you have? \033[0m");
            scanf(" %c", &input2);

            if (input2 == 'S' || input2 == 's') {
                printf("\n");
                lrt2_sjt();
                break;
            }

            else if (input2 == 'B' || input2 == 'b') {
                printf("\n");
                getBalance();
                lrt2_beepcard();
                break;
            }

            else if (input2 == 'C' || input2 == 'c') {
                printf("\n");
                printf("\033[0;32mAre you a...\033[0m\n1.PWD (P) \n2.Senior (S) \n3.Student (T)\n");
                printf("\n\033[0;33mEnter the corresponding letter: \033[0m");
                scanf(" %c", &cc2);

                if (cc2 == 'P' || cc2 == 'p' || cc2 == 'S' || cc2 == 's' || cc2 == 'T' || cc2 == 't') {
                    printf("\n");
                    lrt2_beepTMcard();
                    break;
                }

                else {
                    printf("\033[0;31mInvalid input.\033[0m\n");
                    break;
                }
            }

            else {
                printf("\033[0;31mInvalid input.\033[0\n");
                break;
            }

        case 3:
            printf("\n\033[0;32mWe currently have 3 types of card:\033[0m\n\n1.Single Journey Ticket(S)\n2.Beep Card (B) \n3.Concessionary Card (C)\n");
            printf("\n\033[0;33mWhat card do you have? \033[0m");
            scanf(" %c", &input3);

            if (input3 == 'S' || input3 == 's') {
                printf("\n");
                mrt3_sjt();
                break;
            }

            else if (input3 == 'B' || input3 == 'b') {
                printf("\n");
                getBalance();
                mrt3_beepcard();
                break;
            }

            else if (input3 == 'C' || input3 == 'c') {
                printf("\n");
                printf("\033[0;32mAre you a...\033[0m\n1.PWD (P) \n2.Senior (S) \n3.Student (T)\n");
                printf("\nEnter the corresponding letter: ");
                scanf(" %c", &cc3);

                if (cc3 == 'P' || cc3 == 'p' || cc3 == 'S' || cc3 == 's' || cc3 == 'T' || cc3 == 't') {
                    printf("\n");
                    mrt3_beepTMcard();
                    break;
                }

                else {
                    printf("\033[0;31mInvalid input.\033[0m\n");
                    break;
                }
            }

            else {
                printf("\033[0;31mInvalid input.\033[0m");
                break;
            }

        default:
            printf("\033[0;30mInvalid input. Exiting the program...\033[0m");
            break;
    }

    printf("\033[1;34mDo you want to switch station? (Y/N): \033[0m");
    scanf(" %c", &continue_Program);
    if(continue_Program == 'N' || continue_Program == 'n'){
        printf("Are you sure? (Y/N): ");
        scanf(" %c", &continue_Program);
    }
}
    while (continue_Program == 'N' || continue_Program == 'n');

        if (continue_Program == 'y' || continue_Program == 'Y') {

            printf("\033[1;32mThank you for using the Rail Transit of the Philippines.\033[0m");
        }

        else {
            printf("\033[1;30mExiting the program...\033[0m");
        }

return 0;
}

void lrt1_sjt() {
    int fareMatrix[20][20] = {
        {15, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 30, 30, 30, 35, 35},
        {15, 15, 15, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 30, 35, 35},
        {15, 15, 15, 15, 15, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 35, 35},
        {20, 15, 15, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 25, 30, 30, 30, 35},
        {20, 20, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30, 35},
        {20, 20, 20, 20, 15, 15, 15, 15, 20, 20, 20, 20, 20, 25, 25, 25, 25, 25, 30, 30},
        {20, 20, 20, 20, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 25, 25, 25, 25, 30, 30},
        {20, 20, 20, 20, 20, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 25, 25, 25, 30, 30},
        {25, 25, 20, 20, 20, 20, 20, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 25, 25, 30},
        {25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 15, 15, 20, 20, 20, 20, 20, 25, 25, 30},
        {25, 25, 25, 25, 20, 20, 20, 20, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 25, 25},
        {25, 25, 25, 25, 20, 20, 20, 20, 20, 25, 25, 15, 15, 15, 20, 20, 20, 20, 25, 25},
        {25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 20, 20, 20, 25, 25},
        {30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 20, 20, 20, 25},
        {30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 20, 20, 25},
        {30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 15, 15, 15, 15, 20, 20, 25},
        {30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 15, 15, 15, 15, 20, 20},
        {30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 15, 20, 20, 20},
        {35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 20, 20, 20, 20, 20, 20, 20},
        {35, 35, 35, 35, 35, 30, 30, 30, 30, 30, 25, 25, 25, 25, 25, 25, 20, 20, 20, 20}
    };

    char* stations[20] = {
        "Baclaran", "EDSA", "Libertad", "Gil Puyat",
        "Vito Cruz", "Quirino", "Pedro Gil", "UN Avenue",
        "Central", "Carriedo", "D. Jose", "Bambang", "Tayuman",
        "Bluementritt", "Abad Santos", "R. Papa", "5th Avenue",
        "Monumento", "balintawak", "Fernando Poe Jr."
    };
    char discount;
    char rideAgain;
    char again;
    int stationindex = 0;

        printf("\n\033[0;32mAre you a..\033[0m\nPWD (P)\nSenior Citizen (S)\nStudent (T)\nNone (N)\n");
        printf("\n\033[0;33mWhat discount do you want to avail: \033[0m");
        scanf(" %c", &discount);

            if (discount == 'P' || discount == 'p' || discount == 'S' || discount == 's' || discount == 'T' || discount == 't') {
                    discount;
                }

                else if (discount == 'N' || discount == 'n') {
                    origin, destination;
                }

                else {
                    printf("\033[0;31mInvalid input.\033[0m");
                    return;
                }

        printf("\033[0;32mWelcome to the Light Rail 1 Stations!\033[0m\n");
        for (int i = 0; i < 20; i++) {
        printf("%d - %s\n", i + 1, stations[i]);
    }
        if(switching == 0){
            printf("\n\033[0;33mEnter the origin (1-20): \033[0m");
            scanf("%d", &origin);
            origin -= 1;
        }

    do {
        printf("\033[0;33mEnter the destination (1-20): \033[0m");
        scanf("%d", &destination);
        destination -= 1;

        if (origin >= 0 && origin < 20 && destination >= 0 && destination < 20) {
            int fare = fareMatrix[origin][destination];
            int final = fare;

            if (discount == 'P' || discount == 'p' || discount == 'S' || discount == 's' || discount == 'T' || discount == 't') {
                final *= 0.80;
            }

            else if (discount == 'N' || discount == 'n') {
                final = fare;
            }

            else {
                printf("\033[0;31mInvalid input.\033[0m");
                return;
            }

        printf("\033[1;32mYour fare from %s to %s is: %d PHP\n\033[0m", stations[origin], stations[destination], final);
        totalfare += final;

        for (int i = origin; i < destination; ++i) {
            totaldistance += lrt1_distances[i];
        }

        stationspassed[stationindex++] = stations[origin];
        stationspassed[stationindex++] = stations[destination];
    }

        else if (origin < 0 || origin > 20 || destination < 0 || destination > 20) {
            printf("\n\033[0;31mInvalid station selection.\033[0m\n");
            printf("\033[0;31mYou will be redirected back to the Rail Transit\033[0m\n");
            printf("\033[0;34mDo you wish to continue (Y/N): \033[0m");
            scanf(" %c" ,&again);

                if (again == 'Y' || again == 'y') {
                    main ();
                }

                else {
                    printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
                    printf("\033[1;32mYou will be redirected to the program.\033[0m\n");
                    main ();
                }
        }

        printf("\033[0;32mDo you want to ride again on the current station? (Y/N): \033[0m");
        scanf(" %c", &rideAgain);

        if (rideAgain == 'Y' || rideAgain == 'y') {
            switch (destination + 1){
                case 2:
                    printf("\033[0;32mDo you want to switch to MRT 3? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 13;
                        switching = 1;
                        mrt3_sjt();
                        exit(0);
                    }
                    break;
                case 11:
                    printf("\033[0;32mDo you want to switch to LRT 2? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 1;
                        switching = 1;
                        lrt2_sjt();
                        exit(0);
                    }
                    break;
                default:
                    break;
            }
            origin = destination;
            destination = 0;
        }else {
            printf("Are you sure? (Y/N): ");
            scanf(" %c", &sure);
            if(sure == 'Y' || sure == 'y'){
                printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
            }else{
                rideAgain = 'Y';
            }
        }

    } while (rideAgain == 'Y' || rideAgain == 'y');

    printf("\033[0;34mYour total payment is: %d PHP\033[0m\n", totalfare);
    printf("\033[0;34mTotal distance traveled: %.2f km\033[0m\n", totaldistance);
    printf("\033[0;34mStations passed: \033[0m");
    for (int i = 0; i < stationindex; i++) {
        printf("%s ", stationspassed[i]);
    }
    printf("\n");
}

void lrt1_beepcard() {
    int fareMatrix[20][20] = {
        {13, 14, 15, 16, 17, 18, 19, 20, 22, 23, 23, 24, 25, 26, 27, 28, 29, 30, 33, 35},
        {14, 13, 15, 15, 17, 18, 19, 20, 21, 22, 23, 24, 24, 25, 26, 27, 28, 29, 32, 34},
        {15, 15, 13, 14, 15, 16, 17, 18, 20, 21, 22, 22, 23, 24, 25, 26, 27, 28, 31, 33},
        {16, 15, 14, 13, 15, 16, 17, 17, 19, 20, 21, 21, 22, 23, 24, 25, 26, 27, 30, 32},
        {17, 17, 15, 15, 13, 14, 15, 16, 18, 19, 19, 20, 21, 22, 23, 24, 25, 26, 29, 31},
        {18, 18, 16, 16, 14, 13, 14, 15, 17, 18, 18, 19, 20, 21, 22, 23, 24, 25, 28, 30},
        {19, 19, 17, 17, 15, 14, 13, 14, 16, 17, 17, 18, 19, 20, 21, 22, 23, 24, 27, 29},
        {20, 20, 18, 17, 16, 15, 14, 13, 15, 16, 16, 17, 18, 19, 20, 21, 22, 23, 26, 28},
        {22, 21, 20, 19, 18, 17, 16, 15, 13, 14, 15, 16, 17, 17, 18, 19, 20, 22, 24, 27},
        {23, 22, 21, 20, 19, 18, 17, 16, 14, 13, 14, 15, 16, 16, 18, 18, 20, 21, 24, 26},
        {23, 23, 22, 21, 19, 18, 17, 16, 15, 14, 13, 14, 15, 16, 17, 18, 19, 20, 23, 25},
        {24, 24, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 14, 15, 16, 17, 18, 19, 22, 24},
        {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 14, 15, 16, 17, 18, 21, 23},
        {26, 25, 24, 23, 22, 21, 20, 19, 17, 16, 16, 15, 14, 13, 14, 15, 16, 18, 20, 23},
        {27, 26, 25, 24, 23, 22, 21, 20, 18, 18, 17, 16, 15, 14, 13, 14, 15, 17, 19, 22},
        {28, 27, 26, 25, 24, 23, 22, 21, 19, 18, 18, 17, 16, 15, 14, 13, 14, 16, 18, 21},
        {29, 28, 27, 26, 25, 24, 23, 22, 20, 20, 19, 18, 17, 16, 15, 14, 13, 15, 17, 20},
        {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 18, 17, 16, 15, 13, 16, 18},
        {33, 32, 31, 30, 29, 28, 27, 26, 24, 24, 23, 22, 21, 20, 19, 18, 17, 16, 13, 16},
        {35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 23, 22, 21, 20, 18, 16, 13}
    };

    char* stations[20] = {
        "Baclaran", "EDSA", "Libertad", "Gil Puyat",
        "Vito Cruz", "Quirino", "Pedro Gil", "UN Avenue",
        "Central", "Carriedo", "D. Jose", "Bambang", "Tayuman",
        "Bluementritt", "Abad Santos", "R. Papa", "5th Avenue",
        "Monumento", "balintawak", "Fernando Poe Jr."
    };

    char rideAgain;
    char again;
    int stationindex = 0;

    printf("\033[0;32mWelcome to the Light Rail 1 Stations!\033[0m\n");
    for (int i = 0; i < 20; i++) {
        printf("%d - %s\n", i + 1, stations[i]);
    }
    if(switching == 0){
        printf("\n\033[0;33mEnter the origin (1-20): \033[0m");
        scanf("%d", &origin);
        origin -= 1;
    }

    do {
        printf("\033[0;33mEnter the destination (1-20): \033[0m");
        scanf("%d", &destination);

        destination -= 1;

        if (origin >= 0 && origin < 20 && destination >= 0 && destination < 20) {
            int fare = fareMatrix [origin][destination];
            totalfare += fare;
            if(balance - fare < 0){
                topUpBalance(fare);
            }

            balance -= fare;

            for (int i = origin; i < destination; ++i) {
                totaldistance += lrt1_distances[i];
            }

            stationspassed[stationindex++] = stations[origin];
            stationspassed[stationindex++] = stations[destination];
            printf("The fare from %s to %s is: %d PHP\nCurrent Balance: %d\n", stations[origin], stations[destination], fare, balance);
        }

        else if (origin < 0 || origin > 20 || destination < 0 || destination > 20) {
            printf("\n\033[0;31mInvalid station selection.\033[0m\n");
            printf("\033[0;31mYou will be redirected back to the Rail Transit\033[0m\n");
            printf("\033[0;34mDo you wish to continue (Y/N): \033[0m");
            scanf(" %c" ,&again);

                if (again == 'Y' || again == 'y') {
                    main ();
                }

                else {
                    printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
                    printf("\033[1;32mYou will be redirected to the program.\033[0m\n");
                    main ();
                }
        }

        printf("\033[0;34mDo you want to ride again on the current station? (Y/N): \033[0m");
        scanf(" %c", &rideAgain);

        if (rideAgain == 'Y' || rideAgain == 'y') {
            switch (destination + 1){
                case 2:
                    printf("\033[0;32mDo you want to switch to MRT 3? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 13;
                        switching = 1;
                        mrt3_beepcard();
                        exit(0);
                    }
                    break;
                case 11:
                    printf("\033[0;32mDo you want to switch to LRT 2? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 1;
                        switching = 1;
                        lrt2_beepcard();
                        exit(0);
                    }
                    break;
                default:
                    break;
            }
            origin = destination;
            destination = 0;
        }

        else {
            printf("Are you sure? (Y/N): ");
            scanf(" %c", &sure);
            if(sure == 'Y' || sure == 'y'){
                printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
            }else{
                rideAgain = 'Y';
            }
        }

    } while (rideAgain == 'Y' || rideAgain == 'y');

    printf("\033[0;32mYour total payment is: %d PHP\033[0m\n", totalfare);
    printf("\033[0;32mTotal distance traveled: %.2f km\033[0m\n", totaldistance);
    printf("\033[0;32mStations passed: \033[0m");
    for (int i = 0; i < stationindex; i++) {
        printf("%s ", stationspassed[i]);
    }
    printf("\n");
}

void lrt1_beepTMcard() {
    int fareMatrix[20][20] = {
    {12, 12, 12, 16, 16, 16, 16, 16, 20, 20, 20, 20, 20, 24, 24, 24, 24, 24, 28, 28},
    {12, 12, 12, 12, 16, 16, 16, 16, 20, 20, 20, 20, 20, 20, 24, 24, 24, 24, 28, 28},
    {12, 12, 12, 12, 12, 16, 16, 16, 16, 20, 20, 20, 20, 20, 20, 24, 24, 24, 28, 28},
    {16, 12, 12, 12, 12, 16, 16, 16, 16, 16, 20, 20, 20, 20, 20, 20, 24, 24, 24, 28},
    {16, 16, 12, 12, 12, 12, 12, 16, 16, 16, 16, 16, 20, 20, 20, 20, 20, 24, 24, 28},
    {16, 16, 16, 16, 12, 12, 12, 12, 16, 16, 16, 16, 16, 20, 20, 20, 20, 20, 24, 24},
    {16, 16, 16, 16, 12, 12, 12, 12, 16, 16, 16, 16, 16, 16, 20, 20, 20, 20, 24, 24},
    {16, 16, 16, 16, 16, 12, 12, 12, 12, 16, 16, 16, 16, 16, 16, 20, 20, 20, 24, 24},
    {20, 20, 16, 16, 16, 16, 16, 12, 12, 12, 12, 16, 16, 16, 16, 16, 16, 20, 20, 24},
    {20, 20, 20, 16, 16, 16, 16, 16, 12, 12, 12, 12, 16, 16, 16, 16, 16, 20, 20, 24},
    {20, 20, 20, 20, 16, 16, 16, 16, 12, 12, 12, 12, 12, 16, 16, 16, 16, 16, 20, 20},
    {20, 20, 20, 20, 16, 16, 16, 16, 16, 20, 20, 12, 12, 12, 16, 16, 16, 16, 20, 20},
    {20, 20, 20, 20, 20, 16, 16, 16, 16, 16, 12, 12, 12, 12, 12, 16, 16, 16, 20, 20},
    {24, 20, 20, 20, 20, 20, 16, 16, 16, 16, 16, 12, 12, 12, 12, 12, 16, 16, 16, 20},
    {24, 24, 20, 20, 20, 20, 20, 16, 16, 16, 16, 16, 12, 12, 12, 12, 12, 16, 16, 20},
    {24, 24, 24, 20, 20, 20, 20, 20, 16, 16, 16, 16, 16, 12, 12, 12, 12, 16, 16, 20},
    {24, 24, 24, 24, 20, 20, 20, 20, 16, 16, 16, 16, 16, 16, 12, 12, 12, 12, 16, 16},
    {24, 24, 24, 24, 24, 20, 20, 20, 20, 20, 16, 16, 16, 16, 16, 16, 12, 12, 16, 16},
    {28, 28, 28, 24, 24, 24, 24, 24, 20, 20, 20, 20, 20, 16, 16, 16, 16, 16, 16, 16},
    {28, 28, 28, 28, 28, 24, 24, 24, 24, 24, 20, 20, 20, 20, 20, 20, 16, 16, 16, 16},
};

char* stations[20] = {
        "Baclaran", "EDSA", "Libertad", "Gil Puyat",
        "Vito Cruz", "Quirino", "Pedro Gil", "UN Avenue",
        "Central", "Carriedo", "D. Jose", "Bambang", "Tayuman",
        "Bluementritt", "Abad Santos", "R. Papa", "5th Avenue",
        "Monumento", "balintawak", "Fernando Poe Jr."
    };

    char rideAgain;
    char again;
    int stationindex = 0;

    printf("\n\033[0;34mThank you for confirming.\033[0m\n");
    printf("\n\033[0;32mWelcome to the Light Rail 1 Stations!\033[0m\n");
    for (int i = 0; i < 20; i++) {
        printf("%d - %s\n", i + 1, stations[i]);
    }
    if(switching == 0){
        printf("\n\033[0;33mEnter the origin (1-20): \033[0m");
        scanf("%d", &origin);
        origin -= 1;
    }

    do {
        printf("\033[0;33mEnter the destination (1-20): \033[0m");
        scanf("%d", &destination);

        destination -= 1;

        if (origin >= 0 && origin < 20 && destination >= 0 && destination < 20) {
            int fare = fareMatrix [origin][destination];
            totalfare += fare;
            if(balance - fare < 0){
                topUpBalance(fare);
            }

            balance -= fare;
            for (int i = origin; i < destination; ++i) {
                totaldistance += lrt1_distances[i];
            }

            stationspassed[stationindex++] = stations[origin];
            stationspassed[stationindex++] = stations[destination];
            printf("\033[1;32mThe fare from %s to %s is: %d PHP\033[0m\nCurrent Balance: %d\n", stations[origin], stations[destination], fare, balance);
        }

        else if (origin < 0 || origin > 20 || destination < 0 || destination > 20) {
            printf("\n\033[0;31mInvalid station selection.\033[0m\n");
            printf("\033[0;31mYou will be redirected back to the Rail Transit\033[0m\n");
            printf("\033[0;34mDo you wish to continue (Y/N): \033[0m");
            scanf(" %c" ,&again);

                if (again == 'Y' || again == 'y') {
                    main ();
                }

                else {
                    printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
                    printf("\033[1;32mYou will be redirected to the program.\033[0m\n");
                    main ();
                }
        }

        printf("\033[0;34mDo you want to ride again on the current station? (Y/N): \033[0m");
        scanf(" %c", &rideAgain);

        if (rideAgain == 'Y' || rideAgain == 'y') {
            switch (destination + 1){
                case 2:
                    printf("\033[0;32mDo you want to switch to MRT 3? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 13;
                        switching = 1;
                        mrt3_beepTMcard();
                        exit(0);
                    }
                    break;
                case 11:
                    printf("\033[0;32mDo you want to switch to LRT 2? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 1;
                        switching = 1;
                        lrt2_beepTMcard();
                        exit(0);
                    }
                    break;
                default:
                    break;
            }

            origin = destination;
            destination = 0;
        }

        else {
            printf("Are you sure? (Y/N): ");
            scanf(" %c", &sure);
            if(sure == 'Y' || sure == 'y'){
                printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
            }else{
                rideAgain = 'Y';
            }
        }

    } while (rideAgain == 'Y' || rideAgain == 'y');

    printf("\033[0;32mYour total payment is: %d PHP\033[0m\n", totalfare);
    printf("\033[0;32mTotal distance traveled: %.2f km\033[0m\n", totaldistance);
    printf("\033[0;32mStations passed: \033[0m");
    for (int i = 0; i < stationindex; i++) {
        printf("%s ", stationspassed[i]);
    }
    printf("\n");
}

void lrt2_sjt() {
    int fareMatrix[13][13] = {
        {15, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35, 35},
        {15, 15, 15, 20, 20, 20, 25, 25, 25, 25, 30, 30, 35},
        {20, 15, 15, 15, 20, 20, 20, 20, 25, 25, 30, 30, 30},
        {20, 20, 15, 15, 15, 20, 20, 20, 20, 25, 25, 30, 30},
        {20, 20, 20, 15, 15, 15, 20, 20, 20, 20, 25, 25, 30},
        {25, 20, 20, 20, 15, 15, 15, 20, 20, 20, 25, 25, 30},
        {25, 25, 20, 20, 20, 15, 15, 15, 20, 20, 20, 25, 25},
        {25, 25, 20, 20, 20, 20, 15, 15, 15, 20, 20, 25, 25},
        {25, 25, 25, 20, 20, 20, 20, 15, 15, 15, 20, 20, 25},
        {30, 25, 25, 25, 20, 20, 20, 20, 15, 15, 20, 20, 25},
        {30, 30, 30, 25, 25, 25, 20, 20, 20, 20, 15, 15, 20},
        {35, 30, 30, 30, 25, 25, 25, 25, 20, 20, 15, 20, 20},
        {35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20}
    };

    char* stations[13] = {
        "Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz",
        "Gilmore", "Betty Go", "Cubao", "Anonas",
        "Katipunan", "Santolan", "Marikina", "Antipolo"
    };

    char discount;
    char rideAgain;
    char again;
    int stationindex = 0;

    printf("\n\033[0;32mAre you a..\033[0m\nPWD (P)\nSenior Citizen (S)\nStudent (T)\nNone (N)\n");
    printf("\n\033[0;33mWhat discount do you want to avail: \033[0m");
    scanf(" %c", &discount);

        if (discount == 'P' || discount == 'p' || discount == 'S' || discount == 's' || discount == 'T' || discount == 't') {
                    discount;
                }

                else if (discount == 'N' || discount == 'n') {
                    origin, destination;
                }

                else {
                    printf("\033[0;31mInvalid input.\033[0m");
                    return;
                }

    printf("\033[0;32mWelcome to the Light Rail 2 Stations!\033[0m\n");
    for (int i = 0; i < 13; i++) {
        printf("%d - %s\n", i + 1, stations[i]);
    }
    if(switching == 0){
        printf("\n\033[0;33mEnter the origin (1-13): \033[0m");
        scanf("%d", &origin);
        origin -= 1;
    }

    do {
            printf("\033[0;33mEnter the destination (1-13): \033[0m");
            scanf("%d", &destination);
            destination -= 1;

            if (origin >= 0 && origin < 13 && destination >= 0 && destination < 13) {
                int fare = fareMatrix[origin][destination];
                int final = fare;

                if (discount == 'P' || discount == 'p' || discount == 'S' || discount == 's' || discount == 'T' || discount == 't') {
                    final *= 0.80;
                }

                else if (discount == 'N' || discount == 'n') {
                    final = fare;
                }

                else {
                    printf("\033[0;31mInvalid input.\033[0m");
                    return;
                }

            printf("\033[1;32mYour fare from %s to %s is: %d PHP\033[0m\n", stations[origin], stations[destination], final);
            totalfare += final;

            for (int i = origin; i < destination; ++i) {
                totaldistance += lrt2_distances[i];
            }

            stationspassed[stationindex++] = stations[origin];
            stationspassed[stationindex++] = stations[destination];
        }

            else if (origin < 0 || origin > 13 || destination < 0 || destination > 13) {
                printf("\n\033[0;31mInvalid station selection.\033[0m\n");
                printf("\033[0;31mYou will be redirected back to the Rail Transit\033[0m\n");
                printf("\033[0;34mDo you wish to continue (Y/N): \033[0m");
                scanf(" %c" ,&again);

                    if (again == 'Y' || again == 'y') {
                    main ();
                    }

                    else {
                        printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
                        printf("\033[1;32mYou will be redirected to the program.\033[0m\n");
                        main ();
                    }
            }

            printf("\033[0;34mDo you want to ride again on the current station? (Y/N): \033[0m");
            scanf(" %c", &rideAgain);

            if (rideAgain == 'Y' || rideAgain == 'y') {
                switch (destination + 1){
                case 1:
                    printf("\033[0;32mDo you want to switch to LRT 1? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 11;
                        switching = 1;
                        lrt1_sjt();
                        exit(0);
                    }
                    break;
                case 8:
                    printf("\033[0;32mDo you want to switch to MRT 3? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 4;
                        switching = 1;
                        mrt3_sjt();
                        exit(0);
                    }
                    break;
                default:
                    break;
            }
                origin = destination;
                destination = 0;
            }

            else {
                printf("Are you sure? (Y/N): ");
            scanf(" %c", &sure);
            if(sure == 'Y' || sure == 'y'){
                printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
            }else{
                rideAgain = 'Y';
            }
        }

        } while (rideAgain == 'Y' || rideAgain == 'y');

        printf("\033[0;33mYour total payment is: %d PHP\033[0m\n", totalfare);
        printf("\033[0;33mTotal distance traveled: %.2f km\033[0m\n", totaldistance);
        printf("\033[0;33mStations passed: \033[0m");

        for (int i = 0; i < stationindex; i++) {
            printf("%s ", stationspassed[i]);
        }
        printf("\n");
    }

void lrt2_beepcard() {
    int fareMatrix[13][13] = {
        {13, 15, 16, 18, 19, 21, 22, 23, 25, 26, 28, 31, 33},
        {15, 13, 15, 17, 18, 19, 21, 22, 24, 25, 27, 29, 32},
        {16, 15, 13, 15, 16, 18, 19, 20, 22, 23, 26, 28, 30},
        {18, 17, 15, 13, 15, 16, 17, 19, 20, 22, 24, 26, 29},
        {19, 18, 16, 15, 13, 14, 16, 17, 19, 20, 22, 24, 27},
        {21, 19, 18, 16, 14, 13, 15, 16, 18, 19, 21, 23, 26},
        {22, 21, 19, 17, 16, 15, 13, 15, 16, 18, 20, 22, 25},
        {23, 22, 20, 19, 17, 16, 15, 13, 15, 16, 19, 21, 23},
        {25, 24, 22, 20, 19, 18, 16, 15, 13, 14, 17, 19, 22},
        {26, 25, 23, 22, 20, 19, 18, 16, 14, 13, 16, 18, 21},
        {28, 27, 26, 24, 22, 21, 20, 19, 17, 16, 13, 15, 18},
        {31, 29, 28, 26, 24, 23, 22, 21, 19, 18, 15, 13, 16},
        {33, 32, 30, 29, 27, 26, 25, 23, 22, 21, 18, 16, 13}
    };

    char* stations[13] = {
        "Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz",
        "Gilmore", "Betty Go", "Cubao", "Anonas",
        "Katipunan", "Santolan", "Marikina", "Antipolo"
    };

    char rideAgain;
    char again;
    int stationindex = 0;

    printf("\033[0;32mWelcome to the Light Rail 2 Stations!\033[0m\n");
    for (int i = 0; i < 13; i++) {
        printf("%d - %s\n", i + 1, stations[i]);
    }
    if(switching == 0){
        printf("\n\033[0;33mEnter the origin (1-13): \033[0m");
        scanf("%d", &origin);
        origin -= 1;
    }

    do {
        printf("\033[0;33mEnter the destination (1-13): \033[0m");
        scanf("%d", &destination);

        destination -= 1;

        if (origin >= 0 && origin < 13 && destination >= 0 && destination < 13) {
            int fare = fareMatrix [origin][destination];
            totalfare += fare;

            for (int i = origin; i < destination; ++i) {
                totaldistance += lrt2_distances[i];
            }

            stationspassed[stationindex++] = stations[origin];
            stationspassed[stationindex++] = stations[destination];
            printf("\033[1;32mThe fare from %s to %s is: %d PHP\033[0m\nCurrent Balance: %d\n", stations[origin], stations[destination], fare, balance);
        }

        else if (origin < 0 || origin > 13 || destination < 0 || destination > 13) {
            printf("\n\033[0;31mInvalid station selection.\033[0m\n");
            printf("\033[0;31mYou will be redirected back to the Rail Transit\033[0m\n");
            printf("\033[0;34mDo you wish to continue (Y/N): \033[0m");
            scanf(" %c" ,&again);

                if (again == 'Y' || again == 'y') {
                    main ();
                }

                else {
                    printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
                    printf("\033[1;32mYou will be redirected to the program.\033[0m\n");
                    main ();
                }
        }

        printf("\033[0;34mDo you want to ride again on the current station? (Y/N): \033[0m");
        scanf(" %c", &rideAgain);

        if (rideAgain == 'Y' || rideAgain == 'y') {
            switch (destination + 1){
                case 1:
                    printf("\033[0;32mDo you want to switch to LRT 1? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 11;
                        switching = 1;
                        lrt1_beepcard();
                        exit(0);
                    }
                    break;
                case 8:
                    printf("\033[0;32mDo you want to switch to MRT 3? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 4;
                        switching = 1;
                        mrt3_beepcard();
                        exit(0);
                    }
                    break;
                default:
                    break;
            }
            origin = destination;
            destination = 0;
        }

        else {
            printf("Are you sure? (Y/N): ");
            scanf(" %c", &sure);
            if(sure == 'Y' || sure == 'y'){
                printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
            }else{
                rideAgain = 'Y';
            }
        }

    } while (rideAgain == 'Y' || rideAgain == 'y');

    printf("\033[0;33mYour total payment is: %d PHP\033[0m\n", totalfare);
    printf("\033[0;33mTotal distance traveled: %.2f km\033[0m\n", totaldistance);
    printf("\033[0;33mStations passed: \033[0m");
    for (int i = 0; i < stationindex; i++) {
        printf("%s ", stationspassed[i]);
    }
    printf("\n");
}

void lrt2_beepTMcard() {
    int fareMatrix [13][13] = {
        {12, 12, 16, 16, 16, 20, 20, 20, 20, 24, 24, 28, 28},
        {12, 12, 12, 16, 16, 16, 20, 20, 20, 20, 24, 24, 28},
        {16, 12, 12, 12, 16, 16, 16, 16, 20, 20, 24, 24, 24},
        {16, 16, 12, 12, 12, 16, 16, 16, 16, 20, 20, 24, 24},
        {16, 16, 16, 12, 12, 12, 16, 16, 16, 16, 20, 20, 24},
        {20, 16, 16, 16, 12, 12, 12, 16, 16, 16, 20, 20, 24},
        {20, 20, 16, 16, 16, 12, 12, 12, 16, 16, 16, 20, 20},
        {20, 20, 16, 16, 16, 16, 12, 12, 12, 16, 16, 20, 20},
        {20, 20, 20, 16, 16, 16, 16, 12, 12, 12, 16, 16, 20},
        {24, 20, 20, 20, 16, 16, 16, 16, 12, 12, 16, 16, 20},
        {24, 24, 24, 20, 20, 20, 16, 16, 16, 16, 12, 12, 16},
        {28, 24, 24, 24, 20, 20, 20, 20, 16, 16, 12, 12, 16},
        {35, 35, 30, 30, 30, 30, 25, 25, 25, 25, 20, 20, 20}
};

    char* stations[13] = {
        "Recto", "Legarda", "Pureza", "V. Mapa", "J. Ruiz",
        "Gilmore", "Betty Go", "Cubao", "Anonas",
        "Katipunan", "Santolan", "Marikina", "Antipolo"
    };

    char rideAgain;
    char again;
    int stationindex = 0;

    printf("\033[0;32mWelcome to the Light Rail 2 Stations!\033[0m\n");
    for (int i = 0; i < 13; i++) {
        printf("%d - %s\n", i + 1, stations[i]);
    }
    if(switching == 0){
        printf("\n\033[0;33mEnter the origin (1-13): \033[0m");
        scanf("%d", &origin);
        origin -= 1;
    }

    do {
        printf("\033[0;33mEnter the destination (1-13): \033[0m");
        scanf("%d", &destination);

        destination -= 1;

        if (origin >= 0 && origin < 13 && destination >= 0 && destination < 13) {
            int fare = fareMatrix [origin][destination];
            totalfare += fare;
            if(balance - fare < 0){
                topUpBalance(fare);
            }

            balance -= fare;
            for (int i = origin; i < destination; ++i) {
                totaldistance += lrt2_distances[i];
            }

            stationspassed[stationindex++] = stations[origin];
            stationspassed[stationindex++] = stations[destination];
            printf("\033[0;32mThe fare from %s to %s is: %d PHP\033[0m\nCurrent Balance: %d\n", stations[origin], stations[destination], fare, balance);
        }

        else if (origin < 0 || origin > 13 || destination < 0 || destination > 13) {
            printf("\n\033[0;31mInvalid station selection.\033[0m\n");
            printf("\033[0;31mYou will be redirected back to the Rail Transit\033[0m\n");
            printf("\033[0;34mDo you wish to continue (Y/N): \033[0m");
            scanf(" %c" ,&again);

                if (again == 'Y' || again == 'y') {
                    main ();
                }

                else {
                    printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
                    printf("\033[1;32mYou will be redirected to the program.\033[0m\n");
                    main ();
                }
        }

        printf("\033[0;34mDo you want to ride again on the current station? (Y/N): \033[0m");
        scanf(" %c", &rideAgain);

        if (rideAgain == 'Y' || rideAgain == 'y') {
            switch (destination + 1){
                case 1:
                    printf("\033[0;32mDo you want to switch to LRT 1? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 11;
                        switching = 1;
                        lrt1_beepTMcard();
                        exit(0);
                    }
                    break;
                case 8:
                    printf("\033[0;32mDo you want to switch to MRT 3? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 4;
                        switching = 1;
                        mrt3_beepTMcard();
                        exit(0);
                    }
                    break;
                default:
                    break;
            }
            origin = destination;
            destination = 0;
        }

        else {
            printf("Are you sure? (Y/N): ");
            scanf(" %c", &sure);
            if(sure == 'Y' || sure == 'y'){
                printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
            }else{
                rideAgain = 'Y';
            }
        }

    } while (rideAgain == 'Y' || rideAgain == 'y');

    printf("\033[0;33mYour total payment is: %d PHP\033[0m\n", totalfare);
    printf("\033[0;33mTotal distance traveled: %.2f km\033[0m\n", totaldistance);
    printf("\033[0;33mStations passed: \033[0m");
    for (int i = 0; i < stationindex; i++) {
        printf("%s ", stationspassed[i]);
    }
    printf("\n");
}

void mrt3_sjt() {
    int fareMatrix[13][13] = {
        {13, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28, 28},
        {13, 13, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28},
        {13, 13, 13, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24},
        {16 ,13, 13, 13, 13, 13, 16, 16, 20, 20, 20, 24, 24},
        {16, 16, 13, 13, 13, 13, 13, 16, 16, 20, 20, 20, 24},
        {20, 16, 16, 13, 13, 13, 13, 13, 16, 16, 20, 20, 20},
        {20, 20, 16, 16, 13, 13, 13, 13, 13, 16, 16, 20, 20},
        {20, 20, 20, 16, 16, 13, 13, 13, 13, 13, 16, 16, 20},
        {24, 20, 20, 20, 16, 16, 13, 13, 13, 13, 13, 16, 16},
        {24, 24, 20, 20, 20, 16, 16, 13, 13, 13, 13, 13, 16},
        {24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 13, 13, 13},
        {28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 13, 13},
        {28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 13}
    };

    char* stations[13] = {
        "North Ave", "Quezon Ave", "GMA Kamuning",
        "Cubao", "Santolan", "Ortigas", "Shaw Blvd",
        "Boni Ave", "Guadalupe", "Buendia", "Ayala Ave",
        "Magallanes", "Taft"
    };

    char discount;
    char rideAgain;
    char again;
    int stationindex = 0;

    printf("\n\033[0;32mAre you a..\033[0m\nPWD (P)\nSenior Citizen (S)\nStudent (T)\nNone (N)\n");
        printf("\n\033[0;33mWhat discount do you want to avail: \033[0m");
        scanf(" %c", &discount);

            if (discount == 'P' || discount == 'p' || discount == 'S' || discount == 's' || discount == 'T' || discount == 't') {
                    discount;
                }

                else if (discount == 'N' || discount == 'n') {
                    origin, destination;
                }

                else {
                    printf("\033[0;31mInvalid input.\033[0m");
                    return;
                }

    printf("\033[0;32mWelcome to the Metro Rail 3 Stations !\033[0m\n");
    for (int i = 0; i < 13; i++) {
        printf("%d - %s\n", i + 1, stations[i]);
    }
    if(switching == 0){
        printf("\n\033[0;33mEnter the origin (1-13): \033[0m");
        scanf("%d", &origin);
        origin -= 1;
    }

    do {
        printf("\033[0;33mEnter the destination (1-13): \033[0m");
        scanf("%d", &destination);
        destination -= 1;

        if (origin >= 0 && origin < 13 && destination >= 0 && destination < 13) {
            int fare = fareMatrix[origin][destination];
            int final = fare;

            if (discount == 'P' || discount == 'p' || discount == 'S' || discount == 's' || discount == 'T' || discount == 't') {
                final *= 0.80;
            }

            else if (discount == 'N' || discount == 'n') {
                final = fare;
            }

            else {
                printf("\033[0;31mInvalid input.\033[0m");
                return;
            }

        printf("\033[1;32mYour fare from %s to %s is: %d PHP\033[0m\n", stations[origin], stations[destination], final);
        totalfare += final;

        for (int i = origin; i < destination; ++i) {
            totaldistance += mrt3_distances[i];
        }

        stationspassed[stationindex++] = stations[origin];
        stationspassed[stationindex++] = stations[destination];
    }

        else if (origin < 0 || origin > 13 || destination < 0 || destination > 13) {
            printf("\n\033[0;31mInvalid station selection.\033[0m\n");
            printf("\033[0;31mYou will be redirected back to the Rail Transit\033[0m\n");
            printf("\033[0;34mDo you wish to continue (Y/N): \033[0m");
            scanf(" %c" ,&again);

                if (again == 'Y' || again == 'y') {
                    main ();
                }

                else {
                    printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
                    printf("\033[1;32mYou will be redirected to the program.\033[0m\n");
                    main ();
                }
        }

        printf("\033[0;34mDo you want to ride again on the current station? (Y/N): \033[0m");
        scanf(" %c", &rideAgain);

        if (rideAgain == 'Y' || rideAgain == 'y') {
            switch (destination + 1){
                case 13:
                    printf("\033[0;32mDo you want to switch to LRT 1? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 2;
                        switching = 1;
                        lrt1_sjt();
                        exit(0);
                    }
                    break;
                case 4:
                    printf("\033[0;32mDo you want to switch to LRT 2? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 8;
                        switching = 1;
                        lrt2_sjt();
                        exit(0);
                    }
                    break;
                default:
                    break;
            }
            origin = destination;
            destination = 0;
        }

        else {
            printf("Are you sure? (Y/N): ");
            scanf(" %c", &sure);
            if(sure == 'Y' || sure == 'y'){
                printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
            }else{
                rideAgain = 'Y';
            }
        }

    } while (rideAgain == 'Y' || rideAgain == 'y');

    printf("\033[0;33mYour total payment is: %d PHP\033[0m\n", totalfare);
    printf("\033[0;33mTotal distance traveled: %.2f km\033[0m\n", totaldistance);
    printf("\033[0;33mStations passed: \033[0m");
    for (int i = 0; i < stationindex; i++) {
        printf("%s ", stationspassed[i]);
    }
    printf("\n");
}

void mrt3_beepcard() {
    int fareMatrix[13][13] = {
        {13, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28, 28},
        {13, 13, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28},
        {13, 13, 13, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24},
        {16 ,13, 13, 13, 13, 13, 16, 16, 20, 20, 20, 24, 24},
        {16, 16, 13, 13, 13, 13, 13, 16, 16, 20, 20, 20, 24},
        {20, 16, 16, 13, 13, 13, 13, 13, 16, 16, 20, 20, 20},
        {20, 20, 16, 16, 13, 13, 13, 13, 13, 16, 16, 20, 20},
        {20, 20, 20, 16, 16, 13, 13, 13, 13, 13, 16, 16, 20},
        {24, 20, 20, 20, 16, 16, 13, 13, 13, 13, 13, 16, 16},
        {24, 24, 20, 20, 20, 16, 16, 13, 13, 13, 13, 13, 16},
        {24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 13, 13, 13},
        {28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 13, 13},
        {28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 13}
    };

    char* stations[13] = {
        "North Ave", "Quezon Ave", "GMA Kamuning",
        "Cubao", "Santolan", "Ortigas", "Shaw Blvd",
        "Boni Ave", "Guadalupe", "Buendia", "Ayala Ave",
        "Magallanes", "Taft"
    };

    char discount;
    char rideAgain;
    char again;
    int stationindex = 0;

    printf("\033[0;32mWelcome to the Metro Rail 3 Stations !\033[0m\n");
    for (int i = 0; i < 13; i++) {
        printf("%d - %s\n", i + 1, stations[i]);
    }
    if(switching == 0){
        printf("\n\033[0;33mEnter the origin (1-13): \033[0m");
        scanf("%d", &origin);
        origin -= 1;
    }

    do {
        printf("\033[0;33mEnter the destination (1-13): \033[0m");
        scanf("%d", &destination);

        destination -= 1;

        if (origin >= 0 && origin < 13 && destination >= 0 && destination < 13) {
            int fare = fareMatrix [origin][destination];
            totalfare += fare;
            if(balance - fare < 0){
                topUpBalance(fare);
            }

            balance -= fare;
            for (int i = origin; i < destination; ++i) {
                totaldistance += mrt3_distances[i];
            }

            stationspassed[stationindex++] = stations[origin];
            stationspassed[stationindex++] = stations[destination];
            printf("\033[1;32mThe fare from %s to %s is: %d PHP\033[0m\nCurrent Balance: %d\n", stations[origin], stations[destination], fare, balance);
        }

        else if (origin < 0 || origin > 13 || destination < 0 || destination > 13) {
            printf("\n\033[0;31mInvalid station selection.\033[0m\n");
            printf("\033[0;31mYou will be redirected back to the Rail Transit\033[0m\n");
            printf("\033[0;34mDo you wish to continue (Y/N): \033[0m");
            scanf(" %c" ,&again);

                if (again == 'Y' || again == 'y') {
                    main ();
                }

                else {
                    printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
                    printf("\033[1;32mYou will be redirected to the program.\033[0m\n");
                    main ();
                }
        }

        printf("\033[0;34mDo you want to ride again on the current station? (Y/N): \033[0m");
        scanf(" %c", &rideAgain);

        if (rideAgain == 'Y' || rideAgain == 'y') {
            switch (destination + 1){
                case 13:
                    printf("\033[0;32mDo you want to switch to LRT 1? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 2;
                        switching = 1;
                        lrt1_beepcard();
                        exit(0);
                    }
                    break;
                case 4:
                    printf("\033[0;32mDo you want to switch to LRT 2? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 8;
                        switching = 1;
                        lrt2_beepcard();
                        exit(0);
                    }
                    break;
                default:
                    break;
            }
            origin = destination;
            destination = 0;
        }

        else {
            printf("Are you sure? (Y/N): ");
            scanf(" %c", &sure);
            if(sure == 'Y' || sure == 'y'){
                printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
            }else{
                rideAgain = 'Y';
            }
        }

    } while (rideAgain == 'Y' || rideAgain == 'y');

    printf("\033[0;33mYour total payment is: %d PHP\033[0m\n", totalfare);
    printf("\033[0;33mTotal distance traveled: %.2f km\033[0m\n", totaldistance);
    printf("\033[0;33mStations passed: \033[0m");
    for (int i = 0; i < stationindex; i++) {
        printf("%s ", stationspassed[i]);
    }
    printf("\n");
}

void mrt3_beepTMcard() {
    int fareMatrix[13][13] = {
        {13, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28, 28},
        {13, 13, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24, 28},
        {13, 13, 13, 13, 13, 16, 16, 20, 20, 20, 24, 24, 24},
        {16 ,13, 13, 13, 13, 13, 16, 16, 20, 20, 20, 24, 24},
        {16, 16, 13, 13, 13, 13, 13, 16, 16, 20, 20, 20, 24},
        {20, 16, 16, 13, 13, 13, 13, 13, 16, 16, 20, 20, 20},
        {20, 20, 16, 16, 13, 13, 13, 13, 13, 16, 16, 20, 20},
        {20, 20, 20, 16, 16, 13, 13, 13, 13, 13, 16, 16, 20},
        {24, 20, 20, 20, 16, 16, 13, 13, 13, 13, 13, 16, 16},
        {24, 24, 20, 20, 20, 16, 16, 13, 13, 13, 13, 13, 16},
        {24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 13, 13, 13},
        {28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 13, 13},
        {28, 28, 24, 24, 24, 20, 20, 20, 16, 16, 13, 13, 13}
    };

    char* stations[13] = {
        "North Ave", "Quezon Ave", "GMA Kamuning",
        "Cubao", "Santolan", "Ortigas", "Shaw Blvd",
        "Boni Ave", "Guadalupe", "Buendia", "Ayala Ave",
        "Magallanes", "Taft"
    };

    char discount;
    char rideAgain;
    char again;
    int stationindex = 0;

    printf("\033[0;32mWelcome to the Metro Rail 3 Stations !\033[0m\n");
    for (int i = 0; i < 13; i++) {
        printf("%d - %s\n", i + 1, stations[i]);
    }
    if(switching){
        printf("\n\033[0;33mEnter the origin (1-13): \033[0m");
        scanf("%d", &origin);
        origin -= 1;
    }

    do {
        printf("\033[0;33mEnter the destination (1-13): \033[0m");
        scanf("%d", &destination);

        destination -= 1;

        if (origin >= 0 && origin < 13 && destination >= 0 && destination < 13) {
            int fare = fareMatrix [origin][destination];
            totalfare += fare;
            if(balance - fare < 0){
                topUpBalance(fare);
            }

            balance -= fare;
            for (int i = origin; i < destination; ++i) {
                totaldistance += mrt3_distances[i];
            }

            stationspassed[stationindex++] = stations[origin];
            stationspassed[stationindex++] = stations[destination];
            printf("The fare from %s to %s is: %d PHP\nCurrent Balance: %d\n", stations[origin], stations[destination], fare, balance);
        }

        else if (origin < 0 || origin > 13 || destination < 0 || destination > 13) {
            printf("\n\033[0;31mInvalid station selection.\033[0m\n");
            printf("\033[0;31mYou will be redirected back to the Rail Transit\033[0m\n");
            printf("\033[0;34mDo you wish to continue (Y/N): \033[0m");
            scanf(" %c" ,&again);

                if (again == 'Y' || again == 'y') {
                    main ();
                }

                else {
                    printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
                    printf("\033[1;32mYou will be redirected to the program.\033[0m\n");
                    main ();
                }
        }

        printf("\033[0;34mDo you want to ride again on the current station? (Y/N): \033[0m");
        scanf(" %c", &rideAgain);

        if (rideAgain == 'Y' || rideAgain == 'y') {
            switch (destination + 1){
                case 13:
                    printf("\033[0;32mDo you want to switch to LRT 1? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 2;
                        switching = 1;
                        lrt1_beepTMcard();
                        exit(0);
                    }
                    break;
                case 4:
                    printf("\033[0;32mDo you want to switch to LRT 2? (Y/N): \033[0m");
                    scanf(" %c", &rideAgain);
                    if(rideAgain == 'Y' || rideAgain == 'y'){
                        origin = 8;
                        switching = 1;
                        lrt2_beepTMcard();
                        exit(0);
                    }
                    break;
                default:
                    break;
            }
            origin = destination;
            destination = 0;
        }

        else {
            printf("Are you sure? (Y/N): ");
            scanf(" %c", &sure);
            if(sure == 'Y' || sure == 'y'){
                printf("\033[1;32mThank you for using the Rail Transit System!\033[0m\n");
            }else{
                rideAgain = 'Y';
            }
        }

    } while (rideAgain == 'Y' || rideAgain == 'y');

    printf("\033[0;33mYour total payment is: %d PHP\033[0m\n", totalfare);
    printf("\033[0;33mTotal distance traveled: %.2f km\033[0m\n", totaldistance);
    printf("\033[0;33mStations passed: ");
    for (int i = 0; i < stationindex; i++) {
        printf("%s ", stationspassed[i]);
    }
    printf("\n");
}
