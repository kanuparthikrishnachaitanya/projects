#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int main()
{
    FILE*file;
    int option;
    char name[100];
    char username[100];
    char password[100];
    char amtinacc[100];
    char filename[500];
    int withdrawamt;
    char buffer2[200];
    char checkingpassword[50];
    char checkingamt[50];
    char finalamt[50];
    
    char inputusername[100];
    char inputpassword[100];
    char openingfile[100];
    char inputamt[100];
    
  //  char inputamt3[100];
   // char finalamt3[100];
  //  char checkingpassword3[50];
  //  char checkingamt3[50];
 //   char inputusername[100];
 //   char inputpassword[100];
  //  char openingfile[100];




printf("To create an account enter 1 \n");
printf("For withdrawal enter 2\n ");
printf("For deposition enter 3 \n");
printf("To check balance enter 4 \n");
printf("enter the number : ");
scanf("%d", &option);
getchar();



switch (option)
{
    case 1:
    //for creating an acc

    printf("CREATING ACCOUNT \n");

    printf("Enter your name : ");
    fgets(name, sizeof(name), stdin);

    printf("enter username : ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")]=0;

    printf("create password : ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(username, "\n")]=0;

   snprintf(filename,sizeof(filename),"C:\\Users\\krish\\OneDrive\\Desktop\\finalatm\\%s.txt", username);

   file=fopen(filename, "w");

   if(file==NULL)
   {
    printf("the file could not be created %s", filename);
    return 1;
   }

   int amtinaccn1= atoi(amtinacc);
   amtinaccn1=0000;
   sprintf(amtinacc,"%d", amtinaccn1);

   fprintf(file, "username : %s\n", username);
  // fprintf(file, "name : %s", name);
   fprintf(file, "password : %s\n", password);
   fprintf(file, "amount : %s", amtinacc);

   fclose(file);
   

    break;







    case 2:


    printf("enter username: ");
    scanf("%s", &inputusername);
    
    printf("enter password : ");
    scanf("%s", &inputpassword);

    sprintf(openingfile, "C:\\Users\\krish\\OneDrive\\Desktop\\finalatm\\%s.txt", inputusername);
    
    file = fopen(openingfile, "r");

    if (file==NULL)
    {
        printf("the input username is incorrect ");
        return 0;
    }

    while(fgets(buffer2, sizeof(buffer2), file) != NULL)
    {
        if(strstr(buffer2, "password : ") !=NULL )
        {
            sscanf(buffer2, "password : %s", checkingpassword);
        }

        else if(strstr(buffer2, "amount : ") !=NULL)
        {
            sscanf(buffer2, "amount : %s", checkingamt);


        }
    }

    fclose(file);

    int checkingpasswordn2;
    int inputpasswordn2;

    checkingpasswordn2= atoi(checkingpassword);
    inputpasswordn2= atoi(inputpassword);

    if(checkingpasswordn2 == inputpasswordn2)
    {
        printf("enter the amount you want to withdraw : ");
        scanf("%s", &inputamt);

       int inputamtn2= atoi(inputamt);
       int checkingamtn2= atoi(checkingamt);
       int finalamtn2= atoi(finalamt);

       finalamtn2=checkingamtn2-inputamtn2;
       sprintf(finalamt, "%d", finalamtn2); 
       

        file = fopen(openingfile, "w");

        if(file==NULL)
   {
    printf("the file could not be opened %s", openingfile);
    return 1;
   }


        fprintf(file, "username : %s\n", inputusername);
        //fprintf(file, "name : %s", name);
        fprintf(file, "password : %s\n", inputpassword);
        fprintf(file, "amount : %s", finalamt);

        

    }
    else
    {
        printf("password incorect");
        return 0;
    }

    printf("heres your amount %s",inputamt);

    fclose(file);


    break;






    case 3 :


    printf("enter username: ");
    scanf("%s", &inputusername);
    
    printf("enter password : ");
    scanf("%s", &inputpassword);

    sprintf(openingfile, "C:\\Users\\krish\\OneDrive\\Desktop\\finalatm\\%s.txt", inputusername);
    
    file = fopen(openingfile, "r");

    if (file==NULL)
    {
        printf("the input username is incorrect ");
        return 0;
    }

    while(fgets(buffer2, sizeof(buffer2), file) != NULL)
    {
        if(strstr(buffer2, "password : ") !=NULL )
        {
            sscanf(buffer2, "password : %s", checkingpassword);
        }

        else if(strstr(buffer2, "amount : ") !=NULL)
        {
            sscanf(buffer2, "amount : %s", checkingamt);


        }
    }

    fclose(file);

    int checkingpasswordn3;
    int inputpasswordn3;

    checkingpasswordn3= atoi(checkingpassword);
    inputpasswordn3= atoi(inputpassword);

    if(checkingpasswordn3 == inputpasswordn3)
    {
        printf("enter the amount you want to deposit : ");
        scanf("%s", &inputamt);

       int inputamtn3= atoi(inputamt);
       int checkingamtn3= atoi(checkingamt);
       int finalamtn3= atoi(finalamt);

       finalamtn3=checkingamtn3+inputamtn3;
       sprintf(finalamt, "%d", finalamtn3); 
       

        file = fopen(openingfile, "w");

        if(file==NULL)
   {
    printf("the file could not be opened %s", openingfile);
    return 1;
   }


        fprintf(file, "username : %s\n", inputusername);
        //fprintf(file, "name : %s", name);
        fprintf(file, "password : %s\n", inputpassword);
        fprintf(file, "amount : %s", finalamt);

        

    }
    else
    {
        printf("password incorect");
        return 0;
    }

    printf("amount sucessfully deposited %s",inputamt);

    fclose(file);

    break;

    default :

    printf("enter numbers from 1 to 4 only");

    break;






















}

}