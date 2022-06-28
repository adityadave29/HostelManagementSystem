#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>    

/*
SEQUENCE:
1> Main Menu
2> New Student
3> Student Login
4> Admin Login
5> New Student View
6> Feedback View
7> Feedback Response
8> Feedback 
9> About Hostel
10> LeaveManager
11> ComplainBoard
12> BulletinBoard
13> LeaveDetails
14> Complains
15> BulletinStudent
*/

COORD coord= {0,0}; 
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void menu();
void NewStudent();
void newstudview();
void StudentLogin();
void admin();
void Feedback();
void feedbackview();
void feedbackresponse();
void AboutHostel();
void LeaveManager();
void ComplainBoard();
void BulletinBoard();
void Responce();
void retry();
void LeaveDetails();
void complains();
void BulletinStudent();



char name[20];
char password[10];

struct student
{
    char name[20];
    char mobile[10];
    char rollno[10];
    char course[20];
    char branch[20];
    char From[20];
    char To[20];
    char Mode[20];
    char Reason[20];
    char Name[20];
    char NAme[20];
    char Complain[100];
    char Notice[100];
    char Date[10];
};
 

struct feedback
{
	char first_name[20];
	char ftbk[200];
};

struct ftbres
{
	char whom[20];
	char response[100];
};





int main(){
	gotoxy(40,7);
	printf("<--- Hostel Management System --->");
	gotoxy(40,10);
	printf("<---- Press any key to continue ---->");
	getch();
	menu();
	return 0;
}


//========================================================================(1) Main Menu ===========================================================================================


void menu(){
	int choice;
	system("cls");
	gotoxy(25,3);
	printf("<---------------------------- Main Menu --------------------------------> ");
	gotoxy(25,5);
	printf("1. New Student");
	gotoxy(25,7);
	printf("2. Student Login");
	gotoxy(25,9);
	printf("3. Admin Login");
	gotoxy(25,11);
	printf("4. Feedback");
	gotoxy(25,13);
	printf("5. About Hostel");
	gotoxy(25,15);
	printf("6. Exit");
	gotoxy(25,18);
	printf("====================================================================");
	gotoxy(25,20);
	printf("Enter your choice : ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1 : 
			NewStudent();
			break;
		case 2 :
			system("cls");
			
			gotoxy(25,5);
			printf("<--------------- WELCOME STUDENT -----------------> ");
			gotoxy(25,7);	
			printf("Enter username: "); // Username : Student
			scanf("%s",name);
			gotoxy(25,9);
			printf("Enter password: "); // password : password
			scanf("%s",password);
			if (strcmp(name, "Student") == 0 && strcmp(password, "password") == 0){
				gotoxy(25,12);
				printf("Press any Key.......");
				getch();
			    system("cls");
				StudentLogin();
			}		
			else {
				gotoxy(25,12);
				printf("Press any Key.......");
				printf("Access denied\n");
				menu();
			}
			break;
		case 3:
			system("cls");
			gotoxy(25,5);
			printf("<--------------- WELCOME ADMIN -----------------> ");
			gotoxy(25,7);	
			printf("Enter username: "); // Username : guest
			scanf("%s",name);
			gotoxy(25,9);
			printf("Enter password: "); // password : guest
			scanf("%s",password);
			if (strcmp(name, "guest") == 0 && strcmp(password, "guest") == 0){
				gotoxy(25,22);
				printf("Press any Key.......");
				getch();
			    system("cls");
				admin();
			}		
			else {
				gotoxy(30,24);
				printf("Access denied\n");
				gotoxy(30,26);
				printf("Press any Key.......");
				
				
				menu();}
			break;
		case 4:
			Feedback();
			break;
		case 5:
			AboutHostel();
			break;
		case 6:
			exit(1);
			break;
		default :
				gotoxy(30,24);
				printf("Access denied\n");
				gotoxy(30,26);
				printf("Press any Key.......");
				
				menu();
	}
	
}
	
	
	
	
	
//===============================================================================(2) New Student ====================================================================================	
	

	

void NewStudent()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("NewStudent.txt","ab+");
    if(fp == NULL){
       
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(25,3);
        printf("<---------- New Student Application Form --------------->");
        gotoxy(25,5);
        printf("Enter details of student.");
        
        gotoxy(25,8);
        printf("Enter Name : ");
        gets(std.name);
        
        gotoxy(25,10);
        printf("Enter Mobile Number : ");
        gets(std.mobile);
        
        gotoxy(25,12);
        printf("Enter Roll No : ");
        gets(std.rollno);
        fflush(stdin);
        
        gotoxy(25,14); 
        printf("Enter Course : ");
        gets(std.course);
        
        gotoxy(25,16);
        printf("Enter Branch : ");
        gets(std.branch);
        fwrite(&std,sizeof(std),1,fp);
        
        gotoxy(25,19);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(25,20);
    printf("Press any key to continue.");
    getch();
    menu();

}



//================================================= (3) Student Login =============================================================================



void StudentLogin()
{
	int choice;
	gotoxy(25,3);
	printf("<-------------- STUDENT DESKBOARD ---------------->");
	gotoxy(25,6);
	printf("1. Leave Manager");
	gotoxy(25,8);
	printf("2. Complain Board");
	gotoxy(25,10);
	printf("3. Bulletin Board");
	gotoxy(25,12);
	printf("4. Goto Main Menu");
	gotoxy(25,15);
	printf("---------------------------------------------------");
	gotoxy(25,17);
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice){
		case 1 :
			LeaveManager();
			break;
		case 2 :
			ComplainBoard();
			break;
		case 3 :
			BulletinStudent();
			break;
		case 4 :
			menu();
			break;
	}
	
}







//================================================== (4) Admin Login ===============================================================================



void admin()
{

	int choice_adm_mmenu;
	char feedback_read;
		
	{
		system("cls");
		int choice_adm_mmenu;
		gotoxy(25,3);
		printf("<--------- ADMIN MENU ----------->");
		gotoxy(25,6);
		printf(" 1. Leave Manager Details");
		gotoxy(25,8);
		printf(" 2. Complains");
		gotoxy(25,10);
		printf(" 3. Bulletin Board");
		gotoxy(25,12);
		printf(" 4. New Student Information");
		gotoxy(25,14);
		printf(" 5. Feedbacks View");
		gotoxy(25,16);
		printf(" 6. Main Menu");
		gotoxy(25,18);
		printf("==================================");
		gotoxy(25,20);
		printf("Please Enter your choice here: ");
		scanf("%d", &choice_adm_mmenu);

		if (choice_adm_mmenu == 1)
		{
			LeaveDetails();
		}	
		else if (choice_adm_mmenu == 2)
		{
			complains();
		}
		else if (choice_adm_mmenu == 3)
		{
			BulletinBoard();
		}
		else if (choice_adm_mmenu == 4)
		{
			newstudview();	
		}
		else if (choice_adm_mmenu == 5)
		{
			feedbackview();
		}	
		else if (choice_adm_mmenu == 6)
		{
			menu();
		}
				
	}	
	
}




// =============================================== (5) New Student View ============================================================================================================================


void newstudview()
{
	system("cls");
	gotoxy(25,2);
	printf("<------------ NEW STUDENT LIST ------------>");
	
  	FILE*fp;
  	struct student std;
	fp = fopen("NewStudent.txt","rb+");
	
  	int i=1,j;
  	
  	
  	gotoxy(15,4);
  	printf("NAME");
  	gotoxy(30,4);
  	printf("MOBILE NUMBER");
  	gotoxy(45,4);
  	printf("ROLL NUMBER");
  	gotoxy(60,4);
  	printf("COURSE");
  	gotoxy(75,4);
  	printf("BRANCH");
  	
  	gotoxy(15,6);
  	printf("=======================================================================");
  	  	
  	j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
    	gotoxy(15,j);
        printf("%-15s%-15s%-15s%-15s%-15s",std.name,std.mobile,std.rollno,std.course,std.branch);
        i++;
        j++;
    }
  	fclose(fp);
  	gotoxy(25,15);
  	printf("Press any key to go to menu...");
  	getch();
  	admin();
  	
	
}






//===================================================================================== (6) Feedback View ================================================================================================

void feedbackview()
{
	char decide;
	system("cls");
  	FILE*fp;
  	struct feedback std;

  	int i=1,j;
  	
  	fp = fopen("Feedback.txt","rb+");
  	
  	
  	gotoxy(25,2);
  	printf("<------------ FEEDBACKS ------------>");
  	
  	gotoxy(15,4);
  	printf("NAME");
  	gotoxy(40,4);
  	printf("FEEDBACK");
  	
  	  	
  	j=6;
    while(fread(&std,sizeof(std),1,fp) == 1){
    	gotoxy(15,j);
        printf("%-22s%-12s",std.first_name,std.ftbk);
        i++;
        j++;
    }
  	
  	
  	fclose(fp);
    gotoxy(30,30);
	printf("Do you want to give respose ? [y/n]");
	scanf("%c", &decide);
	
	if (decide == 'y' || decide == 'Y')
	{
		feedbackresponse();
	}
	
	else if (decide=='n'|| decide == 'N'){
		gotoxy(10,j+3);
    	printf("Press any key to continue.");
    	getch();
    	admin();
	}
	
	else{
		system("cls");
		gotoxy(30,30);
		printf("Please enter correct!!");
		feedbackview();
	}
  	
  	
}




// ==================================================================== (7) Feedback Response =================================================================================================


void feedbackresponse()
{
	char choice='y';
	system("cls");
	FILE*fp;
	struct ftbres std;
	fp = fopen("Response.txt","ab+");
	gotoxy(20,2);
	printf("<-------------------- RESPONSE AREA ---------------------->");
	if(fp == NULL){
        
        printf("Error opening file...");
        menu();
        
    }
	   	fflush(stdin);
   		gotoxy(25,4);
		printf("WHOM TO WRITE(NAME): ");
 		gets(std.whom);
	
		gotoxy(25,6);	 
		printf("RESPONSE: ");
 		gets(std.response);
  		fwrite(&std,sizeof(std),1,fp);
  		fflush(stdin);
	
  		fclose(fp);
  		A:
  		gotoxy(25,10);
		printf("Do you want to write other response ? [y/n]");
		scanf("%c", &choice);
		if (choice == 'y'||choice == 'Y'){
			feedbackresponse();
		}
		else if(choice == 'n'||choice == 'N'){
			gotoxy(25,15);
  			printf("Press any key to continue.");
    		getch();
	
			menu();
		}
		
		else{
			gotoxy(25,13);
			printf("Invalid...");
			gotoxy(25,15);
  			printf("Press any key to continue...");
    		getch();
    		goto A;
		}
}
  	











//================================================== (8) Feedback =======================================================================================

void Feedback()
{
	int choice;
	system("cls");
	
	gotoxy(25,2);
	printf("<------------ FEEDBACK --------------->");
	gotoxy(25,4);
	printf(" 1. Write Feedback");
	gotoxy(25,6);
	printf(" 2. View Response");
	gotoxy(25,8);
	printf(" 3. Exit");
	gotoxy(25,10);
	printf("======================================");
	gotoxy(25,12);
	printf("Enter your choice: ");
	scanf("%d", &choice);
	
	if (choice == 1)
	{
		system("cls");
		gotoxy(25,2);
		printf("<------------ FEEDBACK --------------->");
	
	
		FILE*fp;
  		struct feedback std;
  	
  		fp = fopen("Feedback.txt","ab+");
  	
  		if(fp == NULL){
        
        	printf("Error opening file...");
        	menu();
        
    	}
    	fflush(stdin);
   		gotoxy(25,4);
		printf("NAME: ");
 		gets(std.first_name);
	
		gotoxy(25,6);	 
		printf("FEEDBACK: ");
 		gets(std.ftbk);
  		fwrite(&std,sizeof(std),1,fp);
  		fflush(stdin);
	
  		fclose(fp);
  		gotoxy(25,10);
  		printf("Thank you for your valuable feedback :)");
  		gotoxy(25,15);
  		printf("Press any key to continue.");
    	getch();
	
		menu();
	}
	
	else if (choice == 2)
	{
		
	int j,i=0;
	system("cls");
	
	FILE*fp;
  	struct ftbres std;
  	
  	fp = fopen("Response.txt","rb+");
  	
  	
  	gotoxy(25,2);
  	printf("<------------ RESPONSE ------------>");
  	
  	gotoxy(15,4);
  	printf("NAME");
  	gotoxy(40,4);
  	printf("RESPONSE");
  	
  	  	
  	j=6;
    while(fread(&std,sizeof(std),1,fp) == 1){
    	gotoxy(15,j);
        printf("%-22s%-12s",std.whom,std.response);
        i++;
        j++;
        
    }
    fclose(fp);
  	gotoxy(25,15);
  	printf("Press any key to go to menu...");
  	getch();
  	Feedback();
  	
  	
	}
	
	else if(choice == 3)
	{
		menu();
	}
	
	else{
		system("cls");
		gotoxy(25,4);
		printf("Invalid ans");
		gotoxy(25,8);
		printf("Press any key to continue");
		getch();
		Feedback();
	}	
}














//================================================ (9) About Hostel =================================================================================

void AboutHostel()
{

	system("cls");
	gotoxy(25,3);
	printf("<------------------------------------ About Hostel ----------------------------------->");
	gotoxy(25,5);
	printf("Facilities :");
	gotoxy(25,7);
	printf(" > Spacious Wardrobe & Extra Storage Space");
	gotoxy(25,8);
	printf(" > Air Conditioning");
	gotoxy(25,9);
	printf(" > Study Table & Chair");
	gotoxy(25,10);
	printf(" > Bed With Comfy Mattress");
	gotoxy(25,11);
	printf(" > Hot Water Supply");
	gotoxy(25,12);
	printf(" > Attached Washroom");
	gotoxy(25,15);
	printf(" Location :");
	gotoxy(25,17);
	printf(" > Gulbai Tekra near the Ahmedabad Passport Office.  ");
	gotoxy(25,20);
	printf(" Fees :");
	gotoxy(25,22);
	printf(" > Single Sharing : 19,500 per month");
	gotoxy(25,23);
	printf(" > Double Sharing : 17,500 per month");
	gotoxy(25,24);
	printf(" > Triple Sharing : 15,500 per month");
	gotoxy(25,26);
	printf(" <----- Enjoy hostel life at least once in a lifetime ----->");
	gotoxy(25,28);
	printf("Press any key to go to Main Menu.............");
	
	getch();
	menu();
	
}

//=====================================================================================(10) LeaveManager ================================================================================================

void LeaveManager(){
	FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("LeaveManager.txt","ab+");
    if(fp == NULL){
       
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(25,3);
        printf("<---------- Leave Manager --------------->");
        
        gotoxy(25,5);
        printf("Enter your Full Name : ");
        gets(std.Name);
        gotoxy(25,7);
        printf("From Which Date : ");
        gets(std.From);
        gotoxy(25,9);
        printf("To Which Date : ");
        gets(std.To);
        fflush(stdin);
        gotoxy(25,11);
        printf("Mode Of Transpotation : ");
        gets(std.Mode);
        gotoxy(25,13);
        printf("Reason And Mention City : ");
        gets(std.Reason);
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(25,16);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(25,18);
    printf("Press any key to continue.");
    getch();
    menu();

}

//=================================================================================================== (11) ComplainBoard ======================================================================================

void ComplainBoard(){
	FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("Complain.txt","ab+");
    if(fp == NULL){
       
        gotoxy(25,10);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(25,3);
        printf("<---------- Complain Box --------------->");
        gotoxy(25,6);
        printf("Enter your Full Name : ");
        gets(std.NAme);
        gotoxy(25,8);
        printf("Write Your Complain : ");
        gets(std.Complain);
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(25,10);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(25,12);
    printf("Press any key to continue.");
    getch();
    menu();


}

//================================================================================= (12) Bulletin Board ==================================================================================================


void BulletinBoard(){
	FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("BulletinBoard.txt","ab+");
    if(fp == NULL){
       
        gotoxy(25,10);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(25,3);
        printf("<---------- Bulletin Board --------------->");
        gotoxy(25,6);
        printf("Notice or Instruction: ");
        gotoxy(25,8);
        printf("Date : ");
        gets(std.Date);
        gotoxy(25,10);
        printf("Write Here: ");
        gets(std.Notice);
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(25,14);
        printf("Want to add of another Notice ? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(25,12);
    printf("Press any key to continue.");
    getch();
    menu();

}


//================================================================================== (13) LeaveDetails =========================================================================================================

void LeaveDetails(){
	
	system("cls");
	gotoxy(25,2);
	printf("<------------ LEAVE DETAILS OF STUDENT ------------>");
	
  	FILE*fp;
  	struct student std;
	fp = fopen("LeaveManager.txt","rb+");
	
  	int i=1,j;
  	
  	
  	
  	
  	gotoxy(15,4);
  	printf("NAME");
  	gotoxy(30,4);
  	printf("FROM");
  	gotoxy(45,4);
  	printf("TO");
  	gotoxy(60,4);
  	printf("MODE OF TRANS");
  	gotoxy(75,4);
  	printf("REASON & CITY");
  	
  	gotoxy(15,6);
  	printf("==================================================================================");
  	  	
  	j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
    	gotoxy(15,j);
        printf("%-15s%-15s%-15s%-20s%-20s",std.Name,std.From,std.To,std.Mode,std.Reason);
        i++;
        j++;
    }
  	fclose(fp);
  	gotoxy(25,15);
  	printf("Press any key to go to menu...");
  	getch();
  	menu();
}


//=============================================================================== (14) complains ============================================================================================
void complains(){
system("cls");
	gotoxy(25,2);
	printf("<------------ COMPLAINS------------>");
	
  	FILE*fp;
  	struct student std;
	fp = fopen("Complain.txt","rb+");
	
  	int i=1,j;
  	
  	
  	
  	
  	gotoxy(15,4);
  	printf("NAME");
  	gotoxy(30,4);
  	printf("COMPLAINS");
  	
  	gotoxy(15,6);
  	printf("==================================================================================");
  	  	
  	j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
    	gotoxy(15,j);
        printf("%-15s%-25s",std.NAme,std.Complain);
        i++;
        j++;
    }
  	fclose(fp);
  	gotoxy(25,15);
  	printf("Press any key to go to menu...");
  	getch();
  	menu();
}




//============================================================================= (15) BulletinStudent =======================================================================================






void BulletinStudent(){
		system("cls");
	gotoxy(25,2);
	printf("<------------ Bulletin Board ------------>");
	
  	FILE*fp;
  	struct student std;
	fp = fopen("BulletinBoard.txt","rb+");
	
  	int i=1,j;
  	
  	gotoxy(15,4);
  	printf("Date");
  	gotoxy(30,4);
  	printf("Notice or Instruction");
  	
  	gotoxy(15,6);
  	printf("==================================================================================");
  	  	
  	j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
    	gotoxy(15,j);
        printf("%-15s%-30s",std.Date,std.Notice);
        i++;
        j++;
    }
  	fclose(fp);
  	gotoxy(25,15);
  	printf("Press any key to go to menu...");
  	getch();
  	menu();}




void retry(){
	gotoxy(25,20);
	printf("Error !!");
	gotoxy(25,22);
	printf("Press any key to go back to main menu.....");
	getch();
	menu();
}


