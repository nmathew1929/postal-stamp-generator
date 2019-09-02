/******************************************************************************
*Name :			Postal Stamp Generator.
*Author:		Navin Mathew
*Date:			2/1/2018
*@file ass1.c
*@author Navin Mathew
*Description: This program takes in user input and prints out the stamp
*					according to user selected parameter.
*							Contains: 1)drawStamp function.
*												2)calculation function.
*												3)main function.
******************************************************************************/




#include <stdio.h>
#include <math.h>

void drawStamp(double fees, char area[])
{
    printf("----------\n");
    printf("|  USA   |\n");
		printf("| $%.2f  |\n",fees); // works best with fees that are under 10 dollars.
		printf("| %s |\n",area);
    printf("----------\n");

}


double calculation (double normal, double bonus, double weight){
	 double fees;

	if(weight == 0){
		printf("You entered invalid weight\n");
	}
	else {
		if(weight <= 0.5){
			fees = normal;
			printf("The fees are:  %f\n", fees);
		}
		else if(weight >= 0.5){
			if(fmod(weight,0.5) == 0){

				double timesOver = (weight / 0.5) - 1;
				double mult = (timesOver * (normal* bonus)) + normal; // so normal is 0.49 for local and 0.9  bonus changes.
				fees = mult;
				//printf("Perfectly divisible\n");
				//printf("rate: %f\n", fees);
			}
			else if(fmod(weight,0.5) != 0){

				double leftOver = fmod(weight,0.5);
				double clean = weight - leftOver;
				double timesOver = (clean / 0.5);

				double mult = timesOver * (normal * bonus); //local zone1

				//printf("Not perfectly divisble\n");
				//printf("timesOver: %f\n", timesOver);
				//printf("leftOver: %f\n", leftOver);


				if(timesOver == 1.00 ){
					printf("The rate is less than 1.\n");
					// add the normal value then add the extra value times one.
					//normal rate + leftOver zone 1 test local
					fees = normal + (normal* bonus);
					//printf("the fees are: %f\n", fees);
				}
				else if ( timesOver > 1.00){
					//printf("The rate is greater than 1.");
					// 1 will be normal rate .
					fees = normal +(timesOver * (normal* bonus)) + (normal*bonus);
					//printf("the fees are: %f\n", fees);
					}
			}
		}
}
	return fees;
}



int main (int argc, char **argv){
	double weight;
	int zone;
	int mode;
	double money;


	printf("Enter the weight in ounces: \n");
	scanf("%lf", &weight);
	printf("Choose zones from 1,2 and 3.Please only enter the digits. I don't how to input validate.Yet\n" );
	scanf("%d", &zone);
	printf("Mode of transportation Enter: \n1 for Local\n2 for Air.\n");
	scanf("%d", &mode);


switch(zone){

	case 1:
	printf("I am in zone 1.\n" );
	if(mode == 1){
		printf("I am using Local transportation\n");
		double pleasework = calculation(0.49,0.50,weight);
		printf("The fees are %.2f\n",pleasework);
		drawStamp(pleasework,"Local ");
	}
	else if(mode == 2){
		printf("I am using Air transportation\n");
		double pleasework = calculation(0.90,0.40,weight);
		printf("The fees are %.2f\n",pleasework);
		drawStamp(pleasework,"By Air");


	}
	break;


	case 2:
	printf("I am in zone 2.\n" );
	if(mode == 1){
		printf("I am using Local transportation\n");
		double pleasework = calculation(0.49,0.65,weight);
		printf("The fees are %.2f\n",pleasework);
		drawStamp(pleasework,"Local ");


	}
	else if(mode == 2){
		printf("I am using Air transportation\n");
		double pleasework = calculation(0.90,0.60,weight);
		printf("The fees are %.2f\n",pleasework);
		drawStamp(pleasework,"By Air");

	}
	break;

	case 3:
	printf("I am in zone 3.\n" );
	if(mode == 1){
		printf("I am using Local transportation\n");
		double pleasework = calculation(0.49,0.80,weight);
		printf("The fees are %.2f\n",pleasework);
		drawStamp(pleasework,"Local ");

	}
	else if(mode == 2){
		printf("I am using Air transportation\n");
		double pleasework = calculation(0.90,0.85,weight);
		printf("The fees are %.2f\n",pleasework);
		drawStamp(pleasework,"By Air");


	}
	break;

}


	return 0;
}
