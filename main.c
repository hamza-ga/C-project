#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

int main(void)
{
	while(1)
	{
	    int mode;
	    printf("Choose 1. admin or 2. user or 3. exit? 1/2/3 : ");
	    scanf("%d",&mode);
		switch(mode)
		{
	        case 1:
	        {
	        	int pass,feature;
	            printf("Enter password : ");
	        	scanf("%d",&pass);
	        	for(int i=1;i<=3;i++)
	        	{
	                if(pass==1234)
	        	    {
	        			printf("\nADMIN MODE\n\n");
	        	    	printf("Choose a number.\n1-Add new patient.\n2-Edit patient record.\n3-Reserve a slot with the doctor.\n4-Cancel reservtion.\n");
	        	    	scanf("%d",&feature);
	        			switch(feature)
	        			{
	        	    	    case 1:
	        	    	    {
	        	    	    	creatlist();
	        					break;
	        	    	    }
	        	    	    case 2:
	        	    	    {
		    					edit();
		    					break;
	        	    	    }
	        				case 3:
	        				{
	        					reserveSlot();
		    					break;
	        				}
	        				case 4:
	        				{
	        					cancelSlot();
		    					break;
	        				}
	        			}
	        			break;
	        	    }
	        		else
	        		{
	        			printf("wrong password\nEnter password again: ");
	        			scanf("%d",&pass);
	        		}
	        		if(i==2)
	        		{
	        			printf("\nincorrect password for 3 times. no more tries\n");
	        			exit(1);
	        		}
	        	}
                break;				
	        }
	        case 2:
	        {
		    	int option;
	        	printf("\nUSER MODE\n\n");
	        	printf("1- view patient record\n2- view today reservation. \n");
	        	scanf("%d",&option);
	        	switch(option)
	        	{
	        		case 1:
	        		{
	        			print();
	        			break;
	        		}
	        		case 2:
	        		{
	        			printSlot();
		    			break;
	        		}
	        	}
				break;
	        	
	        }
			case 3:
			{
				exit(1);
			}
			default:
			{
				printf("incorect number!!\n");
			}
	    }
	}
}