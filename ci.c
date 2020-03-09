#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "cpfapi.h"
#define MAX 2048

char* User_Validation(char *cInput_Buffer)
{
	int i=0,len=4;
	char *str;
	bool flag=false;
      
	printf("cInput_Buffer =>%s",cInput_Buffer);
	while(cInput_Buffer[i]!='\0'){
		if(cInput_Buffer[i]==':'){
			flag=true;
			break;
		}
			i++;
	}
	
	if(flag){
		str=Command_Interpreter(cInput_Buffer);
		printf("\n in ci.c uservalidation=%s",str);
		return(str);
	}
		//	else
//		Uid_Validation(cInput_Buffer);*/
	return NULL;
}

char* Command_Interpreter( char *cInput_Buffer )
{
	char cCommand[MAX];
	char cInput_Fields[MAX];

	int iOpt=0,iLength=0,i=0,iCommand_Length=0,j=0,sid=0,session_id=0;
	int iUid=0;
	int iSubid = 0;
	char *str=(char *)malloc(MAX*sizeof(char));
	char *cUid=(char*)malloc(5*sizeof(char));
	char *cSid=(char*)malloc(5*sizeof(char));
	char *cSubid=(char*)malloc(MAX*sizeof(char));
	char *cSessionid=(char*)malloc(5*sizeof(char));
	char *p = NULL;

	memset(str,0,sizeof(str));
	memset(&cInput_Fields,0,sizeof(cInput_Fields));
	memset(&cCommand,0,sizeof(cCommand));

	iLength=strlen(cInput_Buffer);
	cInput_Buffer[strlen(cInput_Buffer)]='\0';
	printf("\ncinptu --------> %s",cInput_Buffer);
	if((p = strchr(cInput_Buffer,':')) != NULL){
		printf("\n p is %s %d",p,p);
		strncpy(cCommand,cInput_Buffer,p-cInput_Buffer);
		p++;
		printf("\n p is %s %d",p,p);
		strcpy(cInput_Fields,p);
	}
	cCommand[strlen(cCommand)]='\0';
	if(strcmp(cCommand,"REG_USR")==0){
		iUid=uim(cInput_Fields);
		getDecStr(cUid, 4, iUid);
		printf("\n in ci.c--->%s",cUid);
		return cUid;
	}
	
	 else if(strcmp(cCommand,"REG_SVC") == 0){
		printf("\nREG_svc-->cInput_Fields =>%s",cInput_Fields);
                sid=svc_reg(cInput_Fields);
		getDecStr(cSid, 4, sid);
	//	printf("\nservice id :%d",sid)
		return cSid;		 
	}	 		
  
	else if(strcmp(cCommand,"GET_SVC_LIST") == 0){
		printf("\nget_svc_list-->cInput_Fields =>%s",cInput_Fields);
		str= get_svc_list(cInput_Fields);
		printf("\nstr=>%s\n",str);
		return str;
	}
	 else if(strcmp(cCommand,"SUBSCRIBE") == 0){
		printf("\nsubscribe-->cInput_Fields =>%s",cInput_Fields);
		cSubid=sub_subscribe(cInput_Fields);
		return cSubid;
	}
/*	else if(strcmp(cCommand,"START_SESSION")==0){
		session_id=start_session(cInput_Fields);
		getDecStr(cSessionid, 4, session_id);
		printf("\nsession id :%s",cSessionid);
		return cSessionid;
	}*/
	/*else if(strcmp(cCommand,"END_SESSION")==0)
		end_session(cInput_Fields);*/
//	return(cInput_Buffer);
	/*else{
		printf("No proper command");
		return -1;
	}*/
	printf(".............................................");
}
