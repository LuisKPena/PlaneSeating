/*
 * This is a program that asks users to select a
 * seat on an airplance based on their preference
 * for either First Class or Economy.
 *
 * @author Luis Pena (PID 6300130)
 * @version 01/24/2023
 *
 * I, Luis K. Pena certify that this is my own original
 * program developed by me with no internet or outside
 * help
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{	
	//Instantiating and intializing  variables
	int planeSeats[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	int menuSelection = 0;
	int submenuSelection;
	int assignedSeat;
	bool displayMenu = true;
	bool fullFirstClass = false;
	bool fullEconomy = false;
	int i;

	//While loop for continuous menu selection
	while(displayMenu)
	{
		//Main menu
		printf("\nWelcome to Rahn Airlines! Please make a selection!\n");
		printf("\nPress 1 for First Class");
		printf("\nPress 2 for Economy");
		printf("\nPress 0 to quit\n");
		scanf("%d", &menuSelection);
		printf("\n");

		
		//Error message for invalid menu selection
		if((menuSelection < 0) || (menuSelection > 2))
		{
			printf("\nPlease select only 0, 1, or 2!\n");
		}	

		//Quit function
		else if(menuSelection == 0)
		{
			printf("Thank you! Have a great day!\n\n");
			displayMenu = false; 
		}

		//For loop to traverse planeSeats array
		for(i = 0; i < 12 ; i++)
		{
			//First Class selection if seats are available
			if((menuSelection == 1) && (i < 4) && (planeSeats[i] == 0))
			{
				planeSeats[i] = 1;
				assignedSeat = i + 1;

				//Print user's assagined seat
				printf("%s%d\n", "Your First Class seat is: ", assignedSeat);
				break;
			}

			//Set boolean fullFirstClass to true if section seats full
			if((menuSelection == 1) && (i > 3))
			{
				fullFirstClass = true;
			}

			//Recommend to user to select economy seat
			if((menuSelection == 1) && (i > 3) && (!fullEconomy))
			{
				printf("Sorry, all seats in First Class are taken!");
				printf("\nWould you like a seat in Economy?\n");
				printf("\nEnter 1 for Yes, enter 2 for No: ");
				scanf("%d", &submenuSelection);

				if(submenuSelection == 2)
				{
					printf("\nOur next flight is tomorrow! Thank you!\n\n");
					displayMenu = false;
					break;
				}

				else if(submenuSelection == 1)
				{
					printf("\nReturning you to our main menu to allow new selection!\n");
					break;
				}
			}

			//Economy selection if seats are available
			if((menuSelection == 2) && (i>3) && (planeSeats[i] == 0))
			{
				planeSeats[i] = 1;
				assignedSeat = i + 1;

				//Print user assigned seat
				printf("%s%d\n", "Your Economy seat is: ", assignedSeat);
				break;
			}

			//Set boolean fullEconomy to true if section seats full
			if((menuSelection == 2) && (i > 10))
			{
				fullEconomy = true;
			}

			//Recommend to user to select first class seat
			if((menuSelection == 2) && (i > 10) && (!fullFirstClass))
			{
				printf("Sorry, all seats in Economy are taken!");
				printf("\nWould you like a seat in First Class?\n");
				printf("\nEnter 1 for Yes, enter 2 for No: ");
				scanf("%d", &submenuSelection);

				if(submenuSelection == 2)
				{
					printf("\nOur next flight is tomorrow! Thank you!\n\n");
					displayMenu = false;
					break;
				}

				else if(submenuSelection == 1)
				{
					printf("\nReturning you to our main menu to allow new selection!\n");
					break;
				} 

				else
				{
					printf("\nPlease make a vali selection!\n");
				}
			}
						
		}

		//If all seats full, let user know next flight is tomorrow.
		if(fullFirstClass && fullEconomy)
		{
			printf("Sorry, all seats are taken! Our next flight is tomorrow!\n");
		}

	}

	return 0;
}
