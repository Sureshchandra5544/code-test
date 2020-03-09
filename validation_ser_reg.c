#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <regex.h>
#include<ctype.h>
#include<stdbool.h>
#include "validation.h"
#define MAX 255
int main_validation(char *cBuffer,int uid)
{
	int len=0,i=0,val_command=0,l=0,count=0;
	static int reg_user=0;
	char *command = NULL,*buffer = NULL;
	bool flag1=false;
	command=(char*)malloc(MAX*sizeof(char));
	buffer=(char*)malloc(MAX*sizeof(char));
	len=strlen(cBuffer);
	if(len==1)
		printf("\n Please,Enter command\n");
	else{
		strcpy(buffer,cBuffer);
		command=strtok(buffer,":");
		l=strlen(command);
		if(flag1==false){
			command[l]='\0';
			val_command=command_checking(command);
			if(val_command==1){
				command[l]='\0';
			}
			else{
				printf("\n Please Enter valid command\n");
			}

			if(strcmp(command,"REG_USR")==0){
				count=reg_usr_validation(cBuffer);
				if(count==1){
					reg_user++;
				}
				if(reg_user<=1)
					return count;
				
				else
					printf("\n Your already registered user,cannot register again\n");
			}
			
			else if(strcmp(command,"GET_SVC_LIST")==0){
				if(reg_user==1)
					return svc_list_validation(cBuffer,uid);
				
				else
					printf("\n First you need to register,enter REG_USR command\n");
				
			}
			else if(strcmp(command,"SUBSCRIBE")==0){
				if(reg_user==1)
					return subscribe_validation(cBuffer,uid);
				
				else
					printf("\n First you need to register,enter REG_USR command\n");
				
			}
/*			else if(strcmp(command,"START_SESSION")==0){
				if(reg_user==1)
					return start_session_validation(cBuffer,uid);
				
				else
					printf("\n First you need to register,enter REG_USR command\n");
				
			}*/
			else{
				printf("\n Sorry,Please check your command \n");
			}

		}
	}	
		free(command);
		free(buffer);
}

int command_checking(char *str)
{
	bool flag1=false;
	int i=0;
		for(i=0;i<strlen(str);i++){
                                if((isupper(str[i])) || (str[i]=='_')){
                                        continue;
                                }
                                else{
                                        flag1=true;
                                        break;
                                }
                        }
		

        	 if (flag1==false) 
                	return 1;
         	 
		 else
			 return 0;
}
