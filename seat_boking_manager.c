#include<stdio.h>
int main()
{
    int base_length = 12, choiced_place, count = 0, x=0;
    char choiced_seat, operation, cancelable_seat;

    char seat[12]={'a','b','c','d','e','f','g','h','i', 'j', 'k','l'};
    int seat_index[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    printf ("*****welcome to Metro Rail Seat booking System******* \n\n   \t\tWhere you want to go? \n\n Please Select:\n\n 1:Mirpur to Uttora \t\t 2:Rampura to Uttora \n 3:Bonani to Uttora \t\t 4:Gazipur to Uttora\n\n Here:");
    scanf("%d",&choiced_place);

    if (choiced_place<=4){
            printf("Thank You for selecting your pleace!\n");
        }
    else
        {
            printf("Service not available sorry");
        }

    while(x<10){
        printf("\n\n");
        printf("\n Choose an option to continue.... \n a. for available seat, \n b. for booking \n c. cancel your booking");
        printf("\n What do you want? ");
        scanf("%s",&operation);
        if(operation=='a'){
            count = 0;
            for(int i=0; i<base_length; i++){
                if (seat_index[i]==0){
                    count++;
                    if(i!=base_length-1){
                        printf("%c, ",seat[i]);
                    }else{
                    printf("%c",seat[i]);
                    }

                }
            }
            if(count==0){
                printf("No seat available");
            }
            else{
                printf("\nTotal %d seats are available", count);
            }
        }
        else if(operation=='b'){
            printf("\n Choose a seat number: ");
               scanf("%s", &choiced_seat);
               printf("Choosed item: %c", choiced_seat);

               for(int j=0; j<base_length; j++){
                   if(choiced_seat == seat[j] && seat_index[j] == 0){
                    seat_index[j]=1;
                    printf("\nYou have booked your seat");
                    break;
                   }
                   else if(choiced_seat == seat[j] && seat_index[j] == 1){
                    printf("\nSeat already booked");
                    break;
                   }
                   else{
                    printf('\nSeat not found');
                    break;
                   }
                   printf("index %d", j);
                }
        }
        else if(operation=='c'){
            printf("\n Enter your seat number: ");
            scanf("%s", &cancelable_seat);
            for(int i=0; i<base_length; i++){
                if(cancelable_seat == seat[i] && seat_index[i]==1){
                    seat_index[i] = 0;
                    printf("\nYour booking has been canceled");
                    break;
                }
                else if (cancelable_seat == seat[i] && seat_index[i]!=1){
                    printf("\nThis seat is not booked yet.");
                    break;
                }
                else{
                    printf("\nSeat not found.");
                    break;
                }
            }
        }
        else{
            printf("Operation not found");
        }
    x++;
}
    getch();
    return 0;
}
