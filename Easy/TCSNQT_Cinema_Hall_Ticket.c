#include<stdio.h>
int main() {
    int no_of_per,total=0,count=0;
    float avg;

    printf("Enter number of Person bought tickets: ");
    scanf("%d",&no_of_per);

    if(no_of_per > 30) {
        return 0;
    }

    int ticketCost[no_of_per];
    for(int i=0; i<no_of_per; i++) {
        printf("Enter ticket price for Person %d: ",i+1);
        scanf("%d",&ticketCost[i]);
    }

    for(int i=0; i<no_of_per; i++) {
        if(ticketCost[i] > 1000) {
            printf("Error: Invalid Price");
            return 0;
        } else {
            if(ticketCost[i]%2!=0) {
                total += ticketCost[i];
                count++;
            } else {
                total += 0;
            }
        }
    }

    avg = total / count;
    printf("Total amount of ticket(Odd values):%d\nTotal number of Tickets:%d\nAvarage Amount of the odd Tickets:%f",total,count,avg);
}