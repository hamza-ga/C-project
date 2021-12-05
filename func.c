#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int l=0;

typedef struct
{
	int id,age,slotP;
	char name[20],gender[6];
}patient;
patient P[100]={0};

struct node
{
	patient data;
	struct node* next;
}*head = NULL;

/* Zero in slots means that the slot is reserved */
static char slots[6]  = {0,1,2, 3, 4, 5};

/* Zero in slotLog means that the slot is not reserved */
static char slotLog [10] = {0};

void reserveSlot()
{
	static char flag  = 0;
	static char choice;
	char i;
	int idIn;
	int idIn2;
	printf("please Enter your id : ");
	scanf("%d",&idIn);
	for(int h=0; h<l;h++)
	{
		if(P[h].id==idIn)
		{
			idIn2=idIn;
		}
	}
	if(idIn==idIn2)
	{
	    if (flag == 0)
	    {
	    	printf("Available Slots are: \n1. 2pm to 2:30pm.\n2. 2:30pm to 3pm.\n3. 3pm to 3.30pm.\n4. 3:30pm to 4pm.\n5. 4pm to 4:30pm.\n");
	    	printf("\nPlease choose slot number: ");
	    	scanf("%d", &choice);
	    	
	    	if (choice >= 1 && choice <= 5)
	    	{
	    		slots[choice] = 0;
	    		slotLog[idIn] = choice;
				for(int h=0; h<l;h++)
               	{
               		if(P[h].id==idIn)
               		{
               			P[h].slotP = choice;	
               		}
               	}
	    		flag++;
	    	}
	    	else 
	    	{
			    printf("There are only 5 slots!!\n");
			}
	    }
	    
	    else 
	    {
	    	printf("Available slots are: \n");
	    	
	    	printf("Slots\t\t available/not\n");
	    	printf("1. 2pm to 2:30pm.\t %d\n", slots[1]);
            printf("2. 2:30pm to 3pm.\t %d\n", slots[2]);
            printf("3. 3pm to 3.30pm.\t %d\n", slots[3]);
            printf("4. 3:30pm to 4pm.\t %d\n", slots[4]);
            printf("5. 4pm to 4:30pm.\t %d\n", slots[5]);			
	    	   
	    	printf("Please choose slot number: ");
	    	scanf("%d", &choice);
	    	
	    	if (choice >= 1 && choice <= 5)
	    	{
	    		if (slots[choice] == 0)
	    		{
					printf("Slot is not available!!\n");
				}
	    		else
	    		{ 
	    			slots[choice] = 0;
	    			slotLog[idIn] = choice;
                    for(int h=0; h<l;h++)
               	    {
               	    	if(P[h].id==idIn)
               	    	{
               	    		P[h].slotP = choice;	
               	    	}
               	    }
	    		}
	    	}
	    	else 
	    	{
	    	    printf("There are only 5 slots!!\n");
	   	    }
	   	}
    }
	else 
	{
		printf("incorect id!!\n");
	}
}

void cancelSlot()
{
	int idIn;
	char slotNum, i;
	printf("Enter Id: ");
	scanf("%d",&idIn);

	if (slotLog[idIn] == 0)
	{ printf("No previous reservation!!\n"); }
	else
	{
		slotNum = slotLog[idIn];
		slots[slotNum] = slotNum;
		slotLog[idIn] = 0;
		printf("Slots\t\t available/not\n\n");
	    printf("1. 2pm to 2:30pm.\t %d\n", slots[1]);
        printf("2. 2:30pm to 3pm.\t %d\n", slots[2]);
        printf("3. 3pm to 3.30pm.\t %d\n", slots[3]);
        printf("4. 3:30pm to 4pm.\t %d\n", slots[4]);
        printf("5. 4pm to 4:30pm.\t %d\n", slots[5]);
	}
	printf("Done\n");
}


void creatlist()
{
	printf("\n");
	struct node* temp =(struct node*)malloc(sizeof(struct node));
	printf("Enter number of entry you want to add : ");
	int e;
	scanf("%d",&e);
	for(int i=0;i<e;i++)
	{
	    printf("Enter Id: ");
	    scanf("%d",&temp->data.id);
		P[l].id = temp->data.id;
	    printf("Enter name: ");
	    scanf("%s",&temp->data.name);
		strcpy(P[l].name,temp->data.name);
	    printf("enter age: ");
	    scanf("%d",&temp->data.age);
		P[l].age = temp->data.age;
	    printf("enter gender: ");
	    scanf("%s",&temp->data.gender);
		strcpy(P[l].gender,temp->data.gender);
		l++;
	}
	printf("\n");

}

void print()
{
	int x;
	printf("please Enter patient ID");
	scanf("%d",&x);
	for(int i=0;i<l;i++)
	{
		if(P[i].id==x)
		{
		    printf("the Patient name: %s\n",P[i].name);
		    printf("the Patient age: %d\n",P[i].age);
		    printf("the Patient gender: %s\n\n",P[i].gender);
	    }
	}
}
void edit()
{
	int d;
	printf("enter the id of the patient you want to edit: ");
	scanf("%d",&d);
	for(int i=0; i<l;i++)
	{
		if(P[i].id==d)
		{
			int info;
			printf("the request accepted\n");
			printf("what information you want to edit?\n");
			printf("1. Name : %s\n",P[d].name);
			printf("2. Age : %d\n",P[d].age);
			printf("3. Gender : %s\n",P[d].gender);
			scanf("%d",&info);
			switch(info)
			{
				case 1:
				{
					printf("Enter the new name");
					scanf("%s",P[d].name);
					printf("**done**\n\n");
					break;
				}
				case 2:
				{
					printf("Enter the new age");
					scanf("%d",P[d].age);
					printf("**done**\n\n");
					break;
				}
				case 3:
				{
					printf("Enter the new gender");
					scanf("%s",P[d].gender);
					printf("**done**\n\n");
					break;
				}
				default:
				{
					printf("\ninvalid input!!\n");
					break;
				}
			}
		}
		else
		{
			printf("\nundefind id\n");
		}
	}
}

void printSlot()
{
	printf("The Slots are: \n1. 2pm to 2:30pm.\n2. 2:30pm to 3pm.\n3. 3pm to 3.30pm.\n4. 3:30pm to 4pm.\n5. 4pm to 4:30pm.\n\n");
	for(int i=0;i<=l;i++)
    {
	    if(P[i].id!=0 && P[i].slotP!=0)
	    {
			printf("Id= %d  Slot number = %d \n",P[i].id,P[i].slotP);
        }
    }
}