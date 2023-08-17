#include <stdio.h>
#include <string.h>

#define MAX_TRAINS 5
#define MAX_PASSENGERS 100


struct Train {
    int trainNumber;
    char name[50];
    int capacity;
    int availableSeats;
}

struct Passenger {
    char name[50];
    int trainNumber;
    int seatNumber;
};

struct Train trains[MAX_TRAINS];
struct Passenger passengers[MAX_PASSENGERS];
int totalTrains = 0;
int totalPassengers = 0;

void addTrain(int trainNumber, const char *name, int capacity) {
    if (totalTrains < MAX_TRAINS) {
        struct Train newTrain;
        newTrain.trainNumber = trainNumber;
        strcpy(newTrain.name, name);
        newTrain.capacity = capacity;
        newTrain.availableSeats = capacity;
        
        trains[totalTrains] = newTrain;
        totalTrains++;
        
        printf("Train added successfully!\n");
    } else {
        printf("Maximum number of trains reached.\n");
    }
}

void makeReservation(const char *passengerName, int trainNumber) {
    if (totalPassengers < MAX_PASSENGERS) {
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].trainNumber == trainNumber && trains[i].availableSeats > 0) {
                struct Passenger newPassenger;
                strcpy(newPassenger.name, passengerName);
                newPassenger.trainNumber = trainNumber;
                newPassenger.seatNumber = trains[i].capacity - trains[i].availableSeats + 1;
                
                passengers[totalPassengers] = newPassenger;
                totalPassengers++;
                
                trains[i].availableSeats--;
                printf("Reservation successful! Your seat number is %d.\n", newPassenger.seatNumber);
                return;
            }
        }
        printf("Train not found or no available seats.\n");
    } else {
        printf("Maximum number of passengers reached.\n");
    }
}

int main() {
    int choice;
    do {
        printf("1. Add Train\n");
        printf("2. Make Reservation\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int trainNumber, capacity;
                char name[50];
                printf("Enter train number: ");
                scanf("%d", &trainNumber);
                printf("Enter train name: ");
                scanf("%s", name);
                printf("Enter train capacity: ");
                scanf("%d", &capacity);
                addTrain(trainNumber, name, capacity);
                break;
            }
            case 2: {
                char passengerName[50];
                int trainNumber;
                printf("Enter passenger name: ");
                scanf("%s", passengerName);
                printf("Enter train number: ");
                scanf("%d", &trainNumber);
                makeReservation(passengerName, trainNumber);
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

