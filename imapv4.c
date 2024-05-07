/*
*
*	rfc: 2060 implement software 
*	copyright: 6/05/2024
*
*	CHANGE: function fetch becuase with switch case dont work
*	because is necesary that parameter convert in const case 
*
*/

#include <stdio.h>
#include "include/imapv4.h"

bool CAPABILITY(){

	switch(state){

		case no_authenticate:
		case authenticate   :
		case select         :
		case disconnection  :
		default:

	 }

	for (int id = 0; id < num_commands; id++){

		printf("%s\n", commands[id]);

	 }

	return true; 

 } 

bool NOOP(){

	return true;

 }
bool LOGOUT(){

 }
bool AUTENTICATE(){

 }
bool LOGIN(char* user,char* pass){

	for (int id = 0; id < size_users; id++){

		if (strcmp(user,users[id]) == 0 && strcmp(pass,passwords[id]) == 0){

			return true;

		 }

	 } 

	return false;

 }
bool CREATE(char* mailbox){

	for (int id = 0; id < num_mailbox; id++){
		
		if (strcmp(mailbox,mailboxs[id]) == 0){ //si  existe
 
			return false;			

		 }

	 }

	/* implement algorithm to add */

	//malloc();

	printf("Creation complete");
	return true;

 }
bool DELETE(char* mailbox){

	for (int id = 0; id < num_mailbox; id++){

		if (strcmp(mailbox,mailboxs[id]) != 0){  //si no existe

			return false;

		 }

	 }

	/*Implement delete of mailbox*/ 

	printf("Creation complete");
	return true;
 }
bool RENAME(char* mailbox, new_name){

	for (int id = 0; id < num_mailbox; id++){

		/* si no existe el buzon o si el nombre ya existe */
		if (strcmp(mailbox, mailboxs[id]) != 0 && strcmp(new_name, mailboxs[id]) == 0){ 

			return false;

		 }

	 }

	 /*implement rename of mailbox */
	 printf("rename complete\n");
	 return true;

 }

bool SUBSCRIBE(char* mailbox){

	/*listar servidores de correo suscritos*/
	LSUB();

	for (int id = 0; id < count; id++){

		if (strcmp(mailbox,sub_mailbox[id]) == 0){
		
			/*ya esta suscrito*/

 		 }

	 }

	/* subscribe list*/ 
 	printf("subscribe complete\n");
	return true;

 }


bool UNSUBSCRIBE(char* mailbox){

	/*listar servidores de correo suscritos*/
	LSUB();

	for (int id = 0; id < count; id++){

		if (strcmp(mailbox,sub_mailbox[id]) == 0){
		
			/*ya esta suscrito*/

 		 }

	 }

	/* unsubscribe list*/ 
 	printf("unsubscribe complete\n");
	return true;

 } 

bool LIST(char* flags, char* possible_mailbox){

	/*implement algorithm to search possibles mailboxs*/

 } 

bool SELECT(char* mailbox){

	int num = EXIST();
	printf("[mailbox] %d mails on %s",num,mailbox);

	return true;

 }
bool SEARCH(char* charset){

	switch(charset){

		case 'ALL':

			for (int id = 0; id < size_mailbox; id++){

				printf("subjet:\r\n", mailbox.messages[id].subject);

			 }

		case "ANSWERED":

			for (int id = 0; id < size_mailbox; id++){

				if (strcmp(mailbox.messages[id].flags,"/ANSWERED")){

					printf("subjet:\r\n", mailbox.messages[id].subject);

				 }
				
			 }

		case "BCC":

			/*Is neccesary to implement envolt for messages*/
		case "BEFORE":

			/* if the format is 12/27/2023*/

			if (charset[1]){ //comparar con formato de fecha correcto

				for (int id = 0; id < ; id){

					/* 

						comparar si la fecha es menor a la sumnistrada,
						para ello hay que implementar un algoritmo que permita 
						decidir cual de las dos fechas en menor

				 	 */

					if (lower_fetch(mailbox.messages[id].fetch,charset[1])) {

						printf("%s\r\n",mailbox.messages[id].subject);

						
					 }

				 }
				
			 }

		break;		 

		case "BODY":

			for (int id = 0; id < ; id++){

				if (strcmp(charset[1],mailbox.messages[id].body)){

					printf("%s\r\n",mailbox.messages[id].subject);
				
				 }
			}
			
		break;

		case "CC":

			/* implementar despues porque no se cual es la estructura de envoltorio*/
		break;

		case "DELETED":

			for (int id = 0; id < size_mailbox; id++){

				if (strcmp(mailbox.messages[id].flags,"/DELETED")){

					printf("subjet:\r\n", mailbox.messages[id].subject);

				 }
				
			 }


		case "DRAFT":

			for (int id = 0; id < size_mailbox; id++){

				if (strcmp(mailbox.messages[id].flags,"/DRAFT")){

					printf("subjet:\r\n", mailbox.messages[id].subject);

				 }
				
			 }

		break;

		case "FLAGGED":

			for (int id = 0; id < size_mailbox; id++){

				if (strcmp(mailbox.messages[id].flags,"/FLAGGED")){

					printf("subjet:\r\n", mailbox.messages[id].subject);

				 }
				
			 }

		break;	 

	    case "FROM":

	    	/* implementar despues porque no se cual es la estructura de envoltorio*/

	    case "HEADER":



	    case "KEYWORD":
	    case "LARGER":

	    	if (atoi(charset[1])){


	    		
	    	 }

	    	for (int id = 0; id < size_mailbox; id++){

				if (mailbox.messages[id].size > charset[1]){

	    			printf("%s\r\n",mailbox.messages[id].subject);

 	    		 }	    		

	    	 }

	    break;	 

	    case "NEW":

	    	for (int id = 0; id < size_mailbox; id++)
	    	{
	    		if (mailbox.messages[id].flags.recent == true && mailbox.messages[id].flags.seen == false)
	    		{
	    			printf("%s",mailbox.messages[id].subject);
	    		}
	    	}


	    case "NOT":

	    	/*no se como no implementar*/


	    case "OLD":

	    	for (int id = 0; id < size_mailbox; id++){

	    		if (mailbox.messages[id].flags.recent == false)
	    		{
	    			printf("%s",mailbox.messages[id].subject);
	    		}
	    		
	    	 }

	    case "ON":
	    case "OR":
	   	case "RECENT":

	   		for (int id = 0; id < size_mailbox; id++)
	    	{
	    		if (mailbox.messages[id].flags.recent == true)
	    		{
	    			printf("%s",mailbox.messages[id].subject);
	    		}
	    	}

	   	case "SEEN":

	   		for (int id = 0; id < size_mailbox; id++)
	    	{
	    		if (mailbox.messages[id].flags.seen == true)
	    		{
	    			printf("%s",mailbox.messages[id].subject);
	    		}
	    	}

	   	case "SENTBEFORE":

	   		for (int id = 0; id < size_mailbox; id++)
	    	{
	    		//lower_fetch(mailbox.messages[id].fetch,charset[1])
	    		if (lower_fetch(mailbox.messages[id].header.fetch,charset[1]))
	    		{
	    			printf("%s",mailbox.messages[id].subject);
	    		}
	    	}

	   	case "SENTON":



	   	case "SENTSINSE"
	   	case "SINCE":
	   	case "SMALLER":
	   	case "SUBJECT":
	   	case "TEXT":
	   	case "TO":
	   	case "UID":
	   	case "UNASWERED":

	   		for (int id = 0; id < size_mailbox; id++)
	    	{
	    		if (mailbox.messages[id].flags.aswered == false)
	    		{
	    			printf("%s",mailbox.messages[id].subject);
	    		}
	    	}

	   	case "UNDELETED":

	   		for (int id = 0; id < size_mailbox; id++)
	    	{
	    		if (mailbox.messages[id].flags.deleted == false)
	    		{
	    			printf("%s",mailbox.messages[id].subject);
	    		}
	    	}

	   	case "UNDRAFT":

	   		for (int id = 0; id < size_mailbox; id++)
	    	{
	    		if (mailbox.messages[id].flags.draft == false)
	    		{
	    			printf("%s",mailbox.messages[id].subject);
	    		}
	    	}

	    case "UNFLAGGED":
	    
	    	for (int id = 0; id < size_mailbox; id++)
	    	{
	    		if (mailbox.messages[id].flags.flagged == false)
	    		{
	    			printf("%s",mailbox.messages[id].subject);
	    		}
	    	}	

	   	default: printf("[imap server] error");


	 }

	for (int id = 0; id < size_inbox; id++){

		for (int i = 0; i < ; ++i){

			if (strcmp(charset[id],inbox.name[i])){

				printf("%d inbox",inbox[id].id, inbox.name[i]);

			 }

		 }

	 }

 }
bool FETCH(char* messages[],){

	int value;

	if(strcmp(value,"ALL"){



	 }
	if(strcmp(value,"BODY"){

	 }
	if(strcmp(value,"BODY.PEEK"){

	 }
	if(strcmp(value,"BODYSTRUCTURE"){

	 }
	if(strcmp(value,"ENVELOPE"){

	 }
	if(strcmp(value,"FAST"){

	 }
	if(strcmp(value,"FLAGS"){

	 }
	if(strcmp(value,"FULL"){

	 }
	if(strcmp(value,"INTERNALDATE"){



	 }
	if(strcmp(value,"UID"){

	 }
	else{

		printf("ERROR:"); 

	 }

 }
bool COPY(){

 }
bool UID(char* commands[]){



 }
bool STATUS(char* mailbox,char* state){

	if (strcmp(state,"MESSAGES")){

		printf("%d",mailbox.size);

	 }

	if (strcmp(state,"RECENT")){
	
		int n = 0;

		for (int id = 0; id < size_mailbox; id++){

			if (mailbox.messages[id].flags.recent == true){

				n++;

		 	 }

		 }

		printf("%d", n); 

	 }

	if (strcmp(state,"UIDNEXT")){
		
		/* no tengo idea de como implementarlo */

		int value;



		printf("%d\n", value);
 	 }
	if (strcmp(state,"UIDVALIDITY")){
		
		/* code */
	 }
	if (strcmp(state,"UNSEEN")){
		
		int n = 0;

		for (int id = 0; id < size_mailbox; id++){

			if (mailbox.messages[id].flags.seen == false){

				n++;

		 	 }

		 }

		printf("%d", n);

	 }

	 return true;

 }

bool STORE(char* messages,char* name_element,char* value){

	int lower_message;
	int upper_message;

	lower_message = messages[0];
	upper_message = messages[2];

	if (lower_message < 1 || upper_message > size_mailbox){

		printf("S: error with rank of messages\n");
		return false;

	 }

	if ("FLAGS"){

		if(strcmp(value, "/Seen"){

			for (int id = 0; id < ; id++){

				/* code */

			 }

		 }

		if(strcmp(value, "/Answered"){

			/* code */

		 }
		if(strcmp(value, "/Flagged"){

			/* code */

		 }
		if(strcmp(value, "/Deleted"){

			/* code */

		 }
		if(strcmp(value, "/Recent"){

			/* code */

		 }

		if(strcmp(value, "/Draft"){

			/* code */

		 }
		else{ 

			printf("error\n"); 

		 }

	 } 

	if("FLAGS.SILENT"){

		if(strcmp(value,"/Seen"){

			/* code */

		 }
		if(strcmp(value,"/Answered"){

			/* code */

		 }
		if(strcmp(value,"/Flagged"){

			/* code */

		 }
		if(strcmp(value,"/Deleted"){

			/* code */

		 }
		if(strcmp(value,"/Recent"){

			/* code */

		 }
		if(strcmp(value,"/Draft"){

			/* code */

		 }
		else{ 

			printf("error\n");

	     }
		 
     }
		case "+FLAGS":

			switch(value){

				if(strcmp(value,"/Seen":
				if(strcmp(value,"/Answered":
				if(strcmp(value,"/Flagged":
				if(strcmp(value,"/Deleted":
				if(strcmp(value,"/Recent":
				if(strcmp(value,"/Draft":
				default: printf("error\n");

			 }


		case "+FLAGS.SILENT":

			switch(value){

				case "/Seen":
				case "/Answered":
				case "/Flagged":
				case "/Deleted":
				case "/Recent":
				case "/Draft":
				default: printf("error\n");

			 }


		case "-FLAGS":

			switch(value){

				case "/Seen":
				case "/Answered":
				case "/Flagged":
				case "/Deleted":
				case "/Recent":
				case "/Draft":
				default: printf("error\n");

			 }

		case "-FLAGS.SILENT":

			switch(value){

				case "/Seen":
				case "/Answered":
				case "/Flagged":
				case "/Deleted":
				case "/Recent":
				case "/Draft":
				default: printf("error\n");

			 }

		default: printf("[IMAPV4] S: ");

	 }

 } 

bool APPEND(char* mailbox, char* flags, ){




 }

bool CHECK(){



	return true;

 }  

bool CLOSE(){

	for (int id = 0; id < size_mailbox; id++){

		if (mailbox.messages[id].flags.deleted == true){

			/* borrar estos mensajes */

		 }
				
	 }

	strcpy(mailbox.state,"authenticate");

	return true;

 } 

bool EXPUNGE(){

	for (int id = 0; id < size_mailbox; id++)
	{
		if (mailbox.messages[id].flags.deleted == true){

			/*borrar estos mensajes*/
			printf("S: *%d EXPUNGE\r\n", id);

		 }
	}

	printf("S: OK EXPUNGE completed %s",)

 }
void func(void){



	uint8_t state; 

	switch(state){

		case no_authenticate:
		case authenticate   :
		case select         :
		case disconnection  :
		default:

	 }

 }

int main(void){

	func();

	return 0;
 }
