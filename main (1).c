#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Creating a struct to save data inside it
typedef struct{
int ID;
char medicinename[50];
char compname[50];
char Mdate[50];
char Edate[50];
int quantity;
int medprice;

}data;

data MANOHMAN[1000];
//Creating function Prototypes to be able to use them before writing their body.
void AddMedicine();
void DeleteMedicine();
void UpdateMedicine(int MedID);
void PrintMedicinesInStock();
void GetMedicineInfo ();
void SellMedicine ();
void Quit ();
void displaymenu();
void case_insensitive(char Mname[]);
void filingin();
void filingout();

int counter = -1;
int *ptc = &counter;
int selection;

FILE *fptr;
FILE *fptro;

int main() //main
{
    filingin();
    int mainloop = 1;
    //Printing for the user the menu to choose from
    while (mainloop == 1)
        {
        displaymenu();
        printf("Please enter your selection: ");
        scanf("%d",&selection);

        if (selection == 1)
            {
            AddMedicine();
            }


        else if (selection == 2)
            {
                DeleteMedicine();
            }



        else if (selection == 3)
            {
                int MedID;
                printf("Enter the ID: ");
                scanf("%d", &MedID);
                UpdateMedicine(MedID);

            }



        else if (selection == 4)
            {

                PrintMedicinesInStock();
            }



        else if (selection == 5)
            {
                GetMedicineInfo();
            }



        else if (selection == 6)
            {
                SellMedicine();

            }



        else if (selection == 7)
            {
                filingout();
                printf("Goodbye :)");
                Quit();

            }

         // if the user didn't enter a number included inside the menu it will print none
        else
        {
            printf("none\n");
        }
         //checks if the user wants to see the menu again and choose another selection.
        printf("Enter 1 to continue with other options, otherwise enter any other number: ");
        scanf("%d", &mainloop);

    }
    filingout();
    printf("Goodbye :)");
    Quit();

    return 0;
}


//functions



void AddMedicine()
//Adds a medicine into the structs
 {
     int coco = 0;
     char medicinename[50];
     char compname[50];
     char Mdate[11];
     char Edate[11];
     counter += 1;
     char temp[100];


     printf("Enter Medicine Id: ");
     scanf("%d", &MANOHMAN[counter].ID);
     //Checks if the entered id by the user is already used for another medicine before since every id should be unique
     for (coco = 0; coco < counter; coco++)
     {
         while (MANOHMAN[counter].ID == MANOHMAN[coco].ID)
         {
             printf("This ID has been assigned before, enter a new one: ");
             scanf("%d", &MANOHMAN[counter].ID);
         }
     }
     printf("Enter Medicine Name: ");
     scanf("%s", MANOHMAN[counter].medicinename);
     case_insensitive(MANOHMAN[counter].medicinename);

          for (coco = 0; coco < counter; coco++)
     {
         while (strcmp(MANOHMAN[counter].medicinename, MANOHMAN[coco].medicinename) == 0)
         {
            //Checks if the entered name by the user is already used for another medicine before since every name should be unique

             printf("This name has been assigned before, enter a new one: ");
             char temp[100];
             scanf("%s", temp);
             strcpy(MANOHMAN[counter].medicinename, temp);
         }
     }
     //asks the user to enter the medicine data

     printf("Enter Company Name: ");
     scanf("%s", MANOHMAN[counter].compname);

     printf("Enter Manufactured Date: ");
     scanf("%s", MANOHMAN[counter].Mdate);

     printf("Enter Expiry Date: ");
     scanf("%s", MANOHMAN[counter].Edate);

     printf("Enter Quantity: ");
     scanf("%d", &MANOHMAN[counter].quantity);

     printf("Enter Price: ");
     scanf("%d", &MANOHMAN[counter].medprice);

     printf("Medicine with id %d Added Successfully: \n", MANOHMAN[counter].ID);


 }


 void UpdateMedicine(MedID)
 //Updates any medicine data that the user choose to change
  {
      int loop = 1;
      while (loop == 1)
      {
      int updatecounter = 0;
      int UPS;
      printf("Enter\n1 - Change Quantity\n2 - Change Price\n3 - Change Name\n4 - Change Company\n5 - Change Manufaturing Date\n6 - Change Expiry Date\nAny other number to exit: \n");
      scanf("%d", &UPS);

      for (int updatecounter = 0; updatecounter < counter+1; updatecounter++)
      {
          if (MANOHMAN[updatecounter].ID == MedID)
          {
              break;
          }
      }



      if (UPS == 1) //Medicine quantity
      {

        int newval;

        printf("Enter new Quantity: ");
        scanf("%d", &newval);

        MANOHMAN[updatecounter].quantity = newval;

        printf("quantity changed successfully\n");


      }

      else if (UPS == 2) //Medicine price
      {

      int newval;

      printf("Enter new Price: ");
      scanf("%d", &newval);

      MANOHMAN[updatecounter].medprice = newval;

      printf("Medicine price changed successfully\n");


      }

      else if (UPS == 3) //Medicine name
      {
      char newval[100];

      printf("Enter new Medicine Name: ");
      scanf("%s", newval);

      case_insensitive(newval);

      strcpy(MANOHMAN->medicinename, newval);

      printf("Medicine name changed successfully\n");



      }

      else if (UPS == 4) //Company name
      {
      char newval[100];

      printf("Enter new Company Name: ");
      scanf("%s", newval);

      strcpy(MANOHMAN->compname, newval);

      printf("Company name changed successfully\n");


      }

      else if (UPS == 5) //M Date
      {
      char newval[100];

      printf("Enter new Manufacturing Date: ");
      scanf("%s", newval);

      strcpy(MANOHMAN->Mdate, newval);
      printf("Manufacturing date changed successfully\n");



      }

      else if (UPS == 6) //E Date
      {
      char newval[100];

      printf("Enter new Expiry Date: ");
      scanf("%s", newval);

      strcpy(MANOHMAN->Edate, newval);

      printf("Expiry date changed successfully\n");
      }

      else
      {
          printf("none\n");
      }

      printf("Enter 1 to change other details Else any other number: ");
      scanf(" %d",&loop);


      }

  }


void GetMedicineInfo ()
//Prints the info of any medicine the user chooses
 {

     int loop = 1;
     while (loop == 1)
      {
     int coco = 0;
     int MedID;
     char MedN[100];
     int choice;
     //Asks the user whether he wants to search for the medicine using the name or the ID
     printf("Would you like to enter\n1 - Medicine ID\n2 - Medicine Name\n:");
     scanf("%d", &choice);
      //If the user chose ID
     if (choice == 1)
     {
     printf("Enter Medicine ID: ");
     scanf("%d", &MedID);

     while (MANOHMAN[coco].ID != MedID)
        {
        coco++;
        }

     printf("\nMedicine name: %s\nCompany name: %s\nManufacturing date: %s\nExpiry date: %s\nQuantity: %d\nPrice: %dLE\n",
            MANOHMAN[coco].medicinename, MANOHMAN[coco].compname, MANOHMAN[coco].Mdate,
            MANOHMAN[coco].Edate, MANOHMAN[coco].quantity,MANOHMAN[coco].medprice);
     }
    //If the user chose name

     else if (choice == 2)
    {

        printf("Enter Medicine Name: ");
        scanf("%s", MedN);
        case_insensitive(MedN);

        int res = strcmp(MANOHMAN[coco].medicinename, MedN);
        while (res != 0)
            {
            ++coco;
            res = strcmp(MANOHMAN[coco].medicinename, MedN);
            }
     //Prints the updated medicine details
     printf("\nMedicine name: %s\nCompany name: %s\nManufacturing date: %s\nExpiry date: %s\nQuantity: %d\nPrice: %d\n",
            MANOHMAN[coco].medicinename, MANOHMAN[coco].compname, MANOHMAN[coco].Mdate,
            MANOHMAN[coco].Edate, MANOHMAN[coco].quantity,MANOHMAN[coco].medprice);

     }
      printf("Enter 1 to see other details, Else any other number: ");
      scanf(" %d",&loop);
      }
 }


void DeleteMedicine()
//Deletes the data saved inside the struct.
  {
      //Asks the user whether he will use the name or the ID to delete the medicine
     int MedID;
     char MedN[50];
     int choice;
     printf("Would you like to enter\n1 - Medicine ID\n2 - Medicine Name\n");
     scanf("%d", &choice);
     //if the user chose to delete using the name it will check if the name is available and delete it
     if (choice == 1)
     {
     printf("Enter Medicine ID: ");
     scanf("%d", &MedID);
     for (int i=0; i<1000 ;i++){
      char arr1[50];
      char arr2[50];
      char arr3[50];
      char arr4[50];
    //comparing the 2 strings
    char nullStr[20] = {"\0"};
    int result ;
    result = strcmp(MedN,MANOHMAN[i].medicinename);
    if (MANOHMAN[i].ID == MedID){
        //To delete the ID
        MANOHMAN[i].ID = nullStr[20] ;
        //To delete med name
         MANOHMAN[1000-1].medicinename;
        strcpy(MANOHMAN[i].medicinename,nullStr);
        //To delete company name
         MANOHMAN[1000-1].compname;
        strcpy(MANOHMAN[i].compname,nullStr);
        //To delete Mdate
         MANOHMAN[1000-1].Mdate;
        strcpy(MANOHMAN[i].Mdate,nullStr);
        //To delete Edate
         MANOHMAN[1000-1].Edate;
        strcpy(MANOHMAN[i].Edate,nullStr);
        //To delete the Quantity
        MANOHMAN[i].quantity = MANOHMAN[i + 10].quantity;
        MANOHMAN[1000-1];
        //To delete the Quantity
        MANOHMAN[i].medprice = MANOHMAN[i + 10].medprice;
        MANOHMAN[1000-1];}
         }}
    //if the user chose to delete using the ID it will check if the Id is available and delete it

     else if (choice == 2)
    {

    printf("Enter Medicine Name: ");
    scanf("%s",MedN);
    case_insensitive(MedN);
    for (int i=0; i<1000 ;i++){
      char arr1[50];
      char arr2[50];
      char arr3[50];
      char arr4[50];

    //comparing the 2 strings
    int result ;
    result = strcmp(MedN,MANOHMAN[i].medicinename);
    char nullStr[20] = {"\0"};
    if (result == 0){
        //To delete the ID
        MANOHMAN[i].ID = MANOHMAN[i+10].ID;
        //To delete med name
         MANOHMAN[1000-1].medicinename;
        strcpy(MANOHMAN[i].medicinename,nullStr);
        //To delete company name
         MANOHMAN[1000-1].compname;
        strcpy(MANOHMAN[i].compname,nullStr);
        //To delete Mdate
         MANOHMAN[1000-1].Mdate;
        strcpy(MANOHMAN[i].Mdate,nullStr);
        //To delete Edate
         MANOHMAN[1000-1].Edate;
        strcpy(MANOHMAN[i].Edate,nullStr);
        //To delete the Quantity
        MANOHMAN[i].quantity = MANOHMAN[i + 10].quantity;
        MANOHMAN[1000-1];
        //To delete the Quantity
        MANOHMAN[i].medprice = MANOHMAN[i + 10].medprice;
        MANOHMAN[1000-1];}
      }

    }

printf("Medicine Deleted Successfully\n");

  }

void PrintMedicinesInStock()
//Prints all medicines saved in inventory
  {
      //loops on the array of structures to print every medicine data
      for (int coco = 0; coco <= counter; coco++)
        {
        if (MANOHMAN[coco].ID==0)
            {
            continue;
            }
        if (coco != counter)
            {
            printf("%d %s %s %s %s %d %dLE\n", MANOHMAN[coco].ID, MANOHMAN[coco].medicinename, MANOHMAN[coco].compname, MANOHMAN[coco].Mdate, MANOHMAN[coco].Edate, MANOHMAN[coco].quantity, MANOHMAN[coco].medprice);
            }
        else
            {
            printf("%d %s %s %s %s %d %dLE\n", MANOHMAN[coco].ID, MANOHMAN[coco].medicinename, MANOHMAN[coco].compname, MANOHMAN[coco].Mdate, MANOHMAN[coco].Edate, MANOHMAN[coco].quantity, MANOHMAN[coco].medprice);

            }



        }
  }

void SellMedicine ()
//User buys medicine using id or name
 {
     int coco = 0;
     int loop = 1;
     //Giving user the choice either to buy a medicine using name or ID.

     int MedID;
     char MedN[100];
     int choice;
     printf("Would you like to enter\n1 - Medicine ID\n2 - Medicine Name\n:");
     scanf("%d", &choice);

     if (choice == 1)
     {
     printf("Enter Medicine ID: ");
     scanf("%d", &MedID);
     //Loops on the registered IDS until finding the entered Id.
     while (MANOHMAN[coco].ID != MedID)
        {
        coco++;
        }

     printf("\nMedicine name: %s\nCompany name: %s\nManufacturing date: %s\nExpiry date: %s\nQuantity: %d\nPrice: %dLE\n",
            MANOHMAN[coco].medicinename, MANOHMAN[coco].compname, MANOHMAN[coco].Mdate,
            MANOHMAN[coco].Edate, MANOHMAN[coco].quantity,MANOHMAN[coco].medprice);
     }

     else if (choice == 2)
    {

        printf("Enter Medicine Name: ");
        scanf("%s", MedN);

        int res = strcmp(MANOHMAN[coco].medicinename, MedN);
        //If user chooses to use name it checks if entered name is available
        while (res != 0)
            {
            ++coco;
            res = strcmp(MANOHMAN[coco].medicinename, MedN);
            }

     printf("\nMedicine name: %s\nCompany name: %s\nManufacturing date: %s\nExpiry date: %s\nQuantity: %d\nPrice: %dLE\n",
            MANOHMAN[coco].medicinename, MANOHMAN[coco].compname, MANOHMAN[coco].Mdate,
            MANOHMAN[coco].Edate, MANOHMAN[coco].quantity,MANOHMAN[coco].medprice);

     }

     char option;
//asking user if he wants to buy
  while (1) {
    printf("Would you like to buy this medicine? (y/n) \n");
    if (scanf(" %c", &option) != 1) {
      printf("Error occurred while reading option.\n");
      continue;
    }

    if (option == 'n' || option == 'N') {
      return 1;
    }
    //If yes he will be asked to determine the quantity he wants
    else if (option == 'y' || option == 'Y')
     {
       printf("How many do you want  to buy? \n");
       int QUA;
      scanf("%d",&QUA );
      //Checks if the quantity the user entered is available in the inventory or not
      while (QUA > MANOHMAN[coco].quantity)
      {
          printf("We don't have that many in stock, pick a lower quantity: \n");
          scanf("%d", &QUA);
      }
      //Calculated the price of the wanted quantity and prints it to the user and makes sure if he wants to buy
      int total= MANOHMAN[coco].medprice * QUA;
      MANOHMAN[coco].quantity-=QUA;
      printf("The price will be %dLE.\n", total);
      return 0;
    } else {
      printf("Only (y)es or (n)o are acceptable.\n");
    }




  }
}







  void displaymenu()
 {
     printf("MENU \n 1-Add Medicine: \n 2-Delete Medicine: \n 3-Update Medicine Details: \n 4-Print Medicine in Stock: \n 5-Get Medicine Info: \n 6-Sell Medicine: \n 7-quit \n");
 }


 void filingin()
 {
     //Creates a file in a read mode in the status of reading what's inside the file

    fptr = fopen("bonus.txt", "r");
    if (fptr != NULL)
    {
            //Adds the data registered in the structs by the user into the file
            while(!feof(fptr))
            {
                    ++(*ptc);
                fscanf(fptr,"%d %s %s %s %s %d %d", &MANOHMAN[counter].ID, &MANOHMAN[counter].medicinename, &MANOHMAN[counter].compname, &MANOHMAN[counter].Mdate, &MANOHMAN[counter].Edate, &MANOHMAN[counter].quantity, &MANOHMAN[counter].medprice);

            }
            fclose(fptr);

    }
    //if there isn't a file it Creates a new file to save data into it
    else if (fptr == NULL)
    {
        fptr = fopen("bonus.txt", "w");
    }


 }

//It opens the file to print the data inside it
void filingout()
{
    fptro = fopen("bonus.txt", "w");

    for (int coco = 0; coco <= counter; coco++)
    {
        if (MANOHMAN[coco].ID==0){
            continue;
        }
        if (coco != counter)
        {
        fprintf(fptro,"%d %s %s %s %s %d %d\n", MANOHMAN[coco].ID, MANOHMAN[coco].medicinename, MANOHMAN[coco].compname, MANOHMAN[coco].Mdate, MANOHMAN[coco].Edate, MANOHMAN[coco].quantity, MANOHMAN[coco].medprice);
        }
        else
        {
        fprintf(fptro,"%d %s %s %s %s %d %d", MANOHMAN[coco].ID, MANOHMAN[coco].medicinename, MANOHMAN[coco].compname, MANOHMAN[coco].Mdate, MANOHMAN[coco].Edate, MANOHMAN[coco].quantity, MANOHMAN[coco].medprice);

        }

    }
    fclose(fptro);

}

void Quit ()
 {
     //exits the program
     exit(0);
 }
//Just makes any strings entered by the user lowercase since the ID and Name of the medicine are case insensitive
void case_insensitive(char Mname[])
{
    for (int x = 0; Mname[x]!='\0'; x++){
        if (isalpha(Mname[x]))
            Mname[x] = tolower(Mname[x]);
    }
}
