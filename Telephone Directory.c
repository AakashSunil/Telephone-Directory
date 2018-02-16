/*
*	Created by Aakash, Peter, Abhishek, Amit
*	
*	Implementation of a Digitized form of Telephone Directory
*	using the concepts of Linked Lists
*
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<malloc.h>
struct details{
	char fname[20],lname[20];
	char addr[100];
	char phno[15],mobno[15],ofno[15];
	struct details * next;
};
typedef struct details * DETAILS;
DETAILS head=NULL;
void gotoxy(int x, int y);
void intro();
void cover();
DETAILS getnode();
void insert();
void clearls();
void loadls();
void displayls();
void menu1();
void update();
void add_new();
void modify();
void search();
void src_by_name();
void src_by_number();
void del();
void writefiles();
int fordelay(int);
int login(int);
void main()
{
	intro();
	cover();
	loadls();
	menu1();
}
int fordelay(int j)
{   
	int i,k;
	for(i=0;i<j;i++)
		k=i;
} 
int login(int b)
{
	int ch,ch1,e,e1=0,check,d=1,i=0,j=0,q,check1=0;
	char pasword[15],rpasword[15],username[15],word[15],word1[15],password[15],word2[15];
	FILE *fp;
	system("cls");
	fp=fopen("Logins.txt","r");
	if(b==0)
	{
		printf("Do you have a Login ID??(yes=1-----no=0)\n");
		scanf("%d",&ch1);
	}
	else 
		ch1=1;
	if(ch1==1)
	{
		printf("Enter Username:\n");
		scanf("%s",username);
		while(fscanf(fp,"%s",word)!=EOF)
		{
			if(strcmp(username,word)==0)
			{
				e1=1;
				while(1)
				{
					while(j<3)
					{
						i=0;	
						password[0]='\0';
						printf("Enter your password:\n");
						while(1)
	 					{	
							ch = getch();
							if(ch==13)
								break;
		  					if(ch==8)
		  					{
		  						for(q=0;q<5;q++)
		  						{
									printf("\b");
		  							printf(" ");
		  							printf("\b");
		  						}
		  						i--;
		  						if(i<0)
					  				++i;
		  						continue;
			  				}			
			  				password[i++] = ch;
			  				ch = '*';
			  				printf("%c%c%c%c%c",ch,ch,ch,ch,ch);
		 				}
						password[i]='\0';
		 				fscanf(fp++,"%s",word1);
		 				if(d==1)
		 				{
		 					for(i=0;i<strlen(word1);i++)
		 					{
		 						word2[i]=word1[i];
		 					}
			 					word2[i]='\0';
		 				}		
			 			if(strcmp(password,word2)==0)
						{
							printf("\nPassword Accepted\n");
							e1=0;
							printf("Redirecting to the Next Menu");
							for(i=0;i<=6;i++)
							{
								fordelay(100000000);
								printf(".");
							}
							return e1;
						}
						else
						{
							if(j==2)
							{
								printf("\nLogin Credentials Failed\nRedirecting to the Previous Menu");
								e=0;
								for(i=0;i<=6;i++)
								{
									fordelay(100000000);
									printf(".");
								}
								j++;
								return 1;
							}
							else
							{
								j++;
								printf("\nEntered Password is not Correct\nPlease Try Again!!\n");				
								d=0;
							}
						}
					}
				}
			}
			else
			{
				e1=0;
			}
		}
		if(e1==0)
		{
			printf("Entered ID does not exist in the Records\nRedirecting to the main page");
				for(i=0;i<=6;i++)
				{
					fordelay(100000000);
					printf(".");
				}
		}
	}
	else
	{	
		system("cls");
		fp=fopen("Logins.txt","r");
		if(fp==NULL)
		{
			printf("Are you an Administrtor?(YES----1   NO----0): ");
			scanf("%d",&check);
			if(check==1)
			{
				fp=fopen("Logins.txt","w");
				printf("Enter your Login ID\n(This will be the username):\n");
				scanf("%s",username);
				for(j=0;;j++)
				{
					i=0;
					pasword[0]='\0';
					printf("Enter a Password(8 characters Minimum):\n");
					while(1)
					{
						ch = getch();
						if(ch==13)
				   			break;
						if(ch==8)
		  				{	
			 				printf("\b");
			  				printf(" ");
				  			printf("\b");
				  			i--;
				  			if(i<0)
				  				++i;
				  			continue;
						}
						pasword[i++] = ch;
		  				ch = '*' ;
		  				printf("%c",ch);
					}
					if(i<8)
					{	
						printf("\nInvalid Password Length\nPlease Try Again!!\n");
		 				fordelay(1);
					}
					else
					{	 
			    		pasword[i]='\0';
			 			break;
					} 
				}			
				while(1)
				{
					i=0;
			 		printf("\nRetype the Password for Confirmation:\n");
		 			while(1)
		 			{
			  			ch = getch();
			  			if(ch==13)
				   			break;
				 		if(ch==8)
						{
							printf("\b");
			  				printf(" ");
			  				printf("\b");
			  				i--;
			  				if(i<0)
			  					++i;
			  				continue;
						}
						rpasword[i++] = ch;
			 			ch = '*' ;
		 				printf("%c",ch);
		 			}
			 		rpasword[i]='\0';
			 		if(strcmp(rpasword,pasword)!=0)
						printf("\nRetyped Password is Not Matching\nPlease Try Again!!\n");		
			 		else
			 		{
						fprintf(fp,username);
						fprintf(fp,"\n");
			 			fprintf(fp,rpasword);
			 			fprintf(fp,"\n");
						printf("\nPassword is Accepted\nRedirecting to the login page");
						for(i=0;i<=6;i++)
				   		{
				       		fordelay(100000000);
			           		printf(".");
			    		}
						break;
			 		} 
				}
				fclose(fp);
				login(1);
				check1=0;
			}
			else
				check1=1;
		}
		else
			check1=1;
	}
	if(check1==1)
	{
		printf("You are not authorized for this section");
		printf("\nRedirecting to the main page");
		for(i=0;i<=6;i++)
		{
			fordelay(100000000);
			printf(".");
		}
	}
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void intro()
{
	int k=20;
	gotoxy(25+k,7);printf("OPERATING SYSTEM MINI PROJECT");
	gotoxy(27+k,8);printf("TOPIC: TELEPHONE DIRECTORY");
	gotoxy(30+k,10);printf("GUIDE : Dr. NALINI N. ");
	gotoxy(33+k,12);printf("TEAM MEMBERS");
	gotoxy(21+k,14);printf("1. A PETER HUDSON 	(1NT14CS001)");
	gotoxy(21+k,15);printf("2. AAKASH SUNIL    	(1NT14CS002)");
	gotoxy(21+k,16);printf("3. ABHISKEK DAYAL    	(1NT14CS005)");
	gotoxy(21+k,17);printf("4. AMIT KUMAR SINGH 	(1NT14CS016)");
	gotoxy(21+k,20);printf("PRESS ANY KEY TO PROCEED");
	getch();
	system("cls");
}

void cover()
{
	system("cls");
	int j,i;
	for(j=0;j<25;j++)
	{
		system("cls");
		for(i=0;i<10;i++);
		gotoxy(j+5,7);printf("________________________________");
		gotoxy(j+5,8);printf("________________________________");
		gotoxy(j+5,10);printf("000000 00000 0      00000 ");
		gotoxy(j+5,11);printf("  00   0     0      0     ");
		gotoxy(j+5,12);printf("  00   0000  0      0000  ");
		gotoxy(j+5,13);printf("  00   0     0      0     ");
		gotoxy(j+5,14);printf("  00   00000 000000 00000 ");
		gotoxy(j+5,15);printf("__________________________________");
		gotoxy(j+5,16);printf("__________________________________");
		gotoxy(80-j,7);printf("________________________________\r");
		gotoxy(80-j,8);printf("________________________________\r");
		gotoxy(80-j,10);printf("0000  0   0  0000   00   0 00000 \r");
		gotoxy(80-j,11);printf("0   0 0   0 0    0  00   0 0     \r");
		gotoxy(80-j,12);printf("0000  00000 0    0  0 0  0 0000  \r");
		gotoxy(80-j,13);printf("0     0   0 0    0  0  0 0 0     \r");
		gotoxy(80-j,14);printf("0     0   0  0000   0   00 00000 \r");
		gotoxy(80-j,15);printf("_______________________________\r");
		gotoxy(80-j,16);printf("_______________________________\r");
		gotoxy(j+7,17);printf("0000  0 0000  00000  00000 ");
		gotoxy(j+7,18);printf("0   0 0 0   0 0     0      ");
		gotoxy(j+7,19);printf("0   0 0 0000  0000  0      ");
		gotoxy(j+7,20);printf("0   0 0 0  0  0     0      ");
		gotoxy(j+7,21);printf("0000  0 0   0 00000  00000 ");
		gotoxy(j+7,22);printf("__________________________________");
		gotoxy(j+7,23);printf("__________________________________");
		gotoxy(83-j,17);printf("000000   0000  0000   00  00 \r");
		gotoxy(83-j,18);printf("  00    0    0 0   0   0  0  \r");
		gotoxy(83-j,19);printf("  00    0    0 0000     00   \r");
		gotoxy(83-j,20);printf("  00    0    0 0  0     00   \r");
		gotoxy(83-j,21);printf("  00     0000  0   0    00   \r");
		gotoxy(83-j,22);printf("__________________________  \r");
		gotoxy(83-j,23);printf("__________________________\r");
	}
//	for(i=0;i<4;i++)
//	{
//		fordelay(100000000);
//		printf(" ");
//	}
	printf("\n\nEnter any key to continue");
	getch();
}
DETAILS getnode()
{
	DETAILS temp;
	temp=(DETAILS)malloc(sizeof(struct details));
	if(temp==NULL)
	{
		printf("Allocation Failed\n");
		return NULL;
	}
	return temp;
} 
void insert(struct details d)
{ 
	DETAILS newnode=getnode();
	strcpy(newnode->fname,d.fname);
	strcpy(newnode->lname,d.lname);
	strcpy(newnode->phno,d.phno);
	strcpy(newnode->mobno,d.mobno);
	strcpy(newnode->ofno,d.ofno);
	strcpy(newnode->addr,d.addr);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	else
	{
		DETAILS cur=head,prev=NULL;
		if(strcmpi(head->fname,newnode->fname)>0)
		{
			newnode->next=head;
			head=newnode;
		}
		else
		{
			prev=head;
			cur=head;
			while(cur!=NULL && strcmpi(cur->fname,newnode->fname)<0)
			{
				prev=cur;
				cur=cur->next;
			}
			prev->next=newnode;
			newnode->next=cur;
		}
	}
}
void clearls()
{
	DETAILS temp,cur=head;
	while(cur!=NULL)
	{
		temp=cur;
		cur=cur->next;
		free(temp);
	}
	system("cls");
}
void loadls()
{
	struct details d;
	FILE *fp;
	fp=fopen("Contacts.dat","r");
	while(fread(&d,sizeof(d),1,fp))
	{
		insert(d);
	}
	fclose(fp);
}
void displayls()
{
	system("cls");
	DETAILS cur=head;
	while(cur!=NULL)
	{
		printf("\nName   : %s %s\n",cur->fname,cur->lname);
		printf("Address  : %s\n",cur->addr);
		printf("Telephone: %s\n",cur->phno);
		printf("Mob_no   : %s\n",cur->mobno);
		printf("Office_no: %s\n",cur->ofno);
		cur=cur->next;
	}
	printf("\nPress any key to go back to the Main Menu");
	getch();
	menu1();	
}
void display(DETAILS cur)
{
	printf("\nName   : %s %s\n",cur->fname,cur->lname);
	printf("Address  : %s\n",cur->addr);
	printf("Telephone: %s\n",cur->phno);
	printf("Mob_no   : %s\n",cur->mobno);
	printf("Office_no: %s\n",cur->ofno);
}
void menu1()
{
	int a;
	system("cls");
	int choice;
	gotoxy(30,8);printf("1. Update");
	gotoxy(30,9);printf("2. Search");
	gotoxy(30,10);printf("3. Delete");
	gotoxy(30,11);printf("4. View My Directory");
	gotoxy(30,12);printf("5. Exit");
	gotoxy(30,15);printf("Enter your option: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: a = login(0);
				if(a==0)update();
				else menu1();
				break;
		case 2: search();
				break;
		case 3: a = login(0);
				if(a==0)del();
				else menu1();
				break;
		case 4: displayls();
				break;
		case 5: clearls();
				exit(0);
		default: gotoxy(30,16);printf("Wrong Option!!!\nPlease Try Again");
				 menu1();
				 break;
	}
}
void update()
{
	system("cls");
	int choice;
	gotoxy(30,8);printf("1. Add a new contact");
	gotoxy(30,9);printf("2. Modify the existing one");
	gotoxy(30,10);printf("3. Main Menu");
	gotoxy(30,15);printf("Enter your option: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: add_new();
				break;
		case 2: modify();
				break;
		case 3: menu1();
				break;
		default: gotoxy(30,16);printf("Wrong Option!!!\nPlease Try Again");
				 update();
				 break;
	}
}
void add_new()
{
	system("cls");
	struct details user,u1;
	char tmp[20];
	gotoxy(30,10);printf("Enter the details\n");
	gotoxy(20,11);printf("First Name        : ");
	gotoxy(20,12);printf("Last Name         : ");
	gotoxy(20,13);printf("Home              : ");
	gotoxy(20,14);printf("Mobile Phone      : ");
	gotoxy(20,15);printf("Office Phone      : ");
	gotoxy(20,16);printf("Enter the address : ");
	gotoxy(40,11);fflush(stdin);gets(user.fname);
	gotoxy(40,12);fflush(stdin);gets(user.lname);
	gotoxy(40,13);fflush(stdin);gets(user.phno);
	gotoxy(40,14);fflush(stdin);gets(user.mobno);
	gotoxy(40,15);fflush(stdin);gets(user.ofno);
	gotoxy(40,16);fflush(stdin);gets(user.addr);
	insert(user);
	gotoxy(28,17);printf("Contact is added successfully!!!");
	writefiles();
	getch();
	menu1();
}
void writefiles()
{
	DETAILS cur=head;
	struct details user;
	FILE *fp,*fp1;
	fp=fopen("Contacts.dat","w");
	fp1=fopen("Phone_Directory.txt","w");
	while(cur!=NULL)
	{
		strcpy(user.fname,cur->fname);
	  	strcpy(user.lname,cur->lname);
	  	strcpy(user.phno,cur->phno);
	  	strcpy(user.mobno,cur->mobno);
	  	strcpy(user.ofno,cur->ofno);
	  	strcpy(user.addr,cur->addr);
		fwrite(&user,sizeof(user),1,fp);
		fprintf(fp1,"%s\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",user.fname,user.lname,user.phno,user.mobno,user.ofno,user.addr);
		cur=cur->next;
	}
	fclose(fp1);
	fclose(fp);
}
void del()
{
	system("cls");
	int choice,flag=0;
	char str[30],str1[30],ch='n';
	DETAILS cur=head,prev=cur,temp;
	gotoxy(30,8);printf("1. Delete by name");
	gotoxy(30,9);printf("2. Delete by number");
	gotoxy(30,10);printf("3. Main Menu");
	gotoxy(30,15);printf("Enter your option: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: system("cls");
				cur=head->next;
				prev=NULL;
				gotoxy(30,8);printf("Enter the First name: ");
				fflush(stdin);
				gets(str);
				gotoxy(30,9);printf("Enter the Last name: ");
				fflush(stdin);
				gets(str1);
				if(strcmpi(str,head->fname)==0 && strcmpi(str1,head->lname)==0)
				{
					display(head);
					flag=1;
					printf("\nDelete this Contact??(Y/N): ");
					scanf("%c",&ch);
					fflush(stdin);
					if(ch=='y'||ch=='Y')
					{
						temp=head;
						head=head->next;
						free(temp);
						printf("\nSuccessfully Deleted the Contact\n");
						writefiles();
						printf("\nPress any key to go back to the Delete Menu");
						getch();
						del();
					}
					else
						printf("\nContact not deleted\n");
				}
				if(ch=='n'||ch=='N')
				{
					prev=head;
					while(cur!=NULL)
					{
						if(strcmpi(str,cur->fname)==0 && strcmpi(str1,cur->lname)==0)
						{
							display(cur);
							flag=1;
							printf("\nDelete this Contact??(Y/N): ");
							scanf("%c",&ch);
							fflush(stdin);
							if(ch=='y'||ch=='Y')
							{
								temp=cur;
								if(cur->next==NULL)
							 		prev->next=NULL;
							 	else 
							 		prev->next=cur->next;
							 	free(temp);
							 	printf("\nSuccessfully Deleted the Contact\n");
						 		writefiles();
						 		printf("\nPress any key to go back to the Delete Menu");
								getch();
								del();
							}
							else
					 			printf("\nContact not deleted\n");
						}
						prev=cur;
						cur=cur->next;
					}
					if(flag==0)
						printf("\nContact not found!!!");
					printf("\nPress any key to go back to the Delete Menu");
					getch();
					del();
				}
				break;
		case 2: system("cls");
				cur=head->next;
				prev=NULL;
				gotoxy(30,8);printf("Enter the number: ");
				scanf("%s",&str);
				fflush(stdin);
				if(strcmp(str,head->phno)==0||strcmp(str,head->mobno)==0||strcmp(str,head->ofno)==0)
				{
					display(head);
					flag=1;
					printf("\nDelete this Contact??(Y/N): ");
					scanf("%c",&ch);
					if(ch=='y'||ch=='Y')
					{
						temp=head;
						head=head->next;
						free(temp);
						printf("\nSuccessfully Deleted the Contact\n");
						writefiles();
						printf("\nPress any key to go back to the Delete Menu");
						getch();
						del();
					}
					else
					 	printf("\nContact not deleted\n");
				}
				if(ch=='N'||ch=='n')
				{
					prev=head;
					while(cur!=NULL)
					{
						if(strcmp(str,cur->phno)==0||strcmp(str,cur->mobno)==0||strcmp(str,cur->ofno)==0)
						{
							display(cur);
							flag=1;
							printf("\nDelete this Contact??(Y/N): ");
							scanf("%c",&ch);
							if(ch=='y'||ch=='Y')
							{
								temp=cur;
								if(cur->next==NULL)
							 		prev->next=NULL;
							 	else 
							 		prev->next=cur->next;
							 	free(temp);
							 	printf("\nSuccessfully Deleted the Contact\n");
						 		writefiles();
						 		printf("\nPress any key to go back to the Delete Menu");
								getch();
								del();
							}
						}
						else
					 		printf("\nContact not deleted\n");
						prev=cur;
						cur=cur->next;
					}
					if(flag==0)
						printf("\nContact  not found!!!");
					printf("\nPress any key to go back to the Delete Menu");
					getch();
					del();
				}
				break;
		case 3: menu1();
				break;
		default: gotoxy(30,16);printf("Wrong Option!!!\nPlease Try Again");
				 del();
				 break;
	}
}
void modify()
{
	system("cls");
	int choice,flag=0;
	DETAILS cur=head;
	char str[30],str1[30],str2[30],str3[30],ch;
	gotoxy(30,8);printf("1. Change Name");
	gotoxy(30,9);printf("2. Change Number");
	gotoxy(30,10);printf("3. Previous menu");
	gotoxy(30,15);printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: system("cls");
				gotoxy(30,8);printf("Enter the First name: ");
				scanf("%s",&str);
					fflush(stdin);
				gotoxy(30,9);printf("Enter the Last name: ");
				scanf("%s",&str1);
				fflush(stdin);
				while(cur!=NULL)
				{
					if(strcmpi(str,cur->fname)==0 && strcmpi(str1,cur->lname)==0)
					{
						display(cur);
						flag=1;
						printf("Modify this contact??(Y/N) ");
						fflush(stdin);scanf("%c",&ch);
						if(ch=='y'||ch=='Y')
						{
							printf("\Enter the new name: ");
							printf("First Name        : ");
							fflush(stdin);gets(str1);
							printf("Last Name         : ");
							fflush(stdin);gets(str2);
							printf("Is the entered new detail correct? (Y/N): ");
							scanf("%c",&ch);
							fflush(stdin);
							if(ch=='y'||ch=='Y')
							{
								strcpy(cur->fname,str1);
								strcpy(cur->lname,str2);
								printf("\nSuccessfully Modified the Contact\n");
								writefiles();
								printf("\nPress any key to go back to the Modify Menu");
								getch();
								modify();
							}
						}
						else
				 			printf("\nContact not Modified\n");
					}
					cur=cur->next;
				}
				if(flag==0)
					printf("\nContact not found!!!");
				printf("\nPress any key to go back to the Modify Menu");
				getch();
				modify();
				break;
		case 2: system("cls");
				gotoxy(30,8);printf("Enter the First name: ");
				scanf("%s",&str);
				fflush(stdin);
				gotoxy(30,9);printf("Enter the Last name: ");
				scanf("%s",&str1);
				fflush(stdin);
				while(cur!=NULL)
				{
					if(strcmpi(str,cur->fname)==0 && strcmpi(str1,cur->lname)==0)
					{
						display(cur);
						flag=1;
						printf("Modify this Contact?(Y/N) ");
						fflush(stdin);scanf("%c",&ch);
						if(ch=='y'||ch=='Y')
						{
							printf("\Enter the new contact information: ");
							printf("Home        : ");
							fflush(stdin);gets(str1);
							printf("Mobile Phone: ");
							fflush(stdin);gets(str2);
							printf("Office Phone: ");
							fflush(stdin);gets(str3);
							printf("Is the entered new detail correct? (Y/N): ");
							scanf("%c",&ch);
							fflush(stdin);
							if(ch=='y'||ch=='Y')
							{
								strcpy(cur->phno,str1);
								strcpy(cur->mobno,str2);
								strcpy(cur->ofno,str3);
								printf("\nSuccessfully Modified the Contact\n");
								writefiles();
								printf("\nPress any key to go back to the Modify Menu");
								getch();
									modify();
							}
						}
						else
			 				printf("\nContact not Modified\n");
					}	
					cur=cur->next;
				}
				if(flag==0)
					printf("\nContact not found!!!");
				printf("\nPress any key to go back to the Modify Menu");
				getch();
				modify();
				break;
		case 3: update();
				break;
		default: gotoxy(30,16);printf("Wrong Option!!!\nPlease Try Again");
				 modify();
				 break;
	}
}
void search()
{
	system("cls");
	int choice;
	gotoxy(30,8);printf("1. Search by name");
	gotoxy(30,9);printf("2. Search by number");
	gotoxy(30,10);printf("3. Main Menu");
	gotoxy(30,15);printf("Enter your Option: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: src_by_name();
				break;
		case 2: src_by_number();
				break;
		case 3: menu1();
				break;
		default: gotoxy(30,16);printf("Wrong Option!!!\nPlease Try Again");
				 search();
				 break;
	}
}
void src_by_name()
{
	system("cls");
	int flag=0;
	char name[30];
	gotoxy(30,10);
	printf("Enter the name : ");
	scanf("%s",&name);
	DETAILS cur=head;
	while(cur!=NULL)
	{
		if(strcmpi(name,cur->fname)==0)
		{
			display(cur);
			flag=1;
		}
		cur=cur->next;
	}
	if(flag==0)
		printf("\nContact not found!!!");
	printf("\nPress any key to go back to the Main Menu");
	getch();
	menu1();
} 
void src_by_number()
{
	system("cls");
	int flag=0;
	char num[30];
	gotoxy(30,10);
	printf("Enter the number : ");
	scanf("%s",&num);
	DETAILS cur=head;
	while(cur!=NULL)
	{
		if(strcmp(num,cur->phno)==0||strcmp(num,cur->mobno)==0||strcmp(num,cur->ofno)==0)
		{
			display(cur);
			flag=1;
		}
		cur=cur->next;
	}
	if(flag==0)
		printf("\nContact not found!!!");
	printf("\nPress any key to go back to the Main Menu");
	getch();
	menu1();
}
