/*
*
*	rfc: 2060
*
*
*/
#include <stdio.h>
#include "imapv4.h"

esp_err_t CAPABILITY(){

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

	return ESP_OK; 

 } 

esp_err_t NOOP(){

	return ESP_OK;

 }
esp_err_t LOGOUT(){

 }
esp_err_t AUTENTICATE(){

 }
esp_err_t LOGIN(char* user,char* pass){

	for (int id = 0; id < size_users; id++){

		if (strcmp(user,users[id]) == 0 && strcmp(pass,passwords[id]) == 0){

			return ESP_OK;

		 }

	 } 

	return ESP_NO;

 }
esp_err_t CREATE(char* mailbox){

	for (int id = 0; id < num_mailbox; id++){
		
		if (strcmp(mailbox,mailboxs[id]) == 0){ //si  existe
 
			return ESP_NO;			

		 }

	 }

	/* implement algorithm to add */

	//malloc();

	printf("Creation complete");
	return ESP_OK;

 }
esp_err_t DELETE(char* mailbox){

	for (int id = 0; id < num_mailbox; id++){

		if (strcmp(mailbox,mailboxs[id]) != 0){  //si no existe

			return ESP_NO;

		 }

	 }

	/*Implement delete of mailbox*/ 

	printf("Creation complete");
	return ESP_OK;
 }
esp_err_t RENAME(char* mailbox, new_name){

	for (int id = 0; id < num_mailbox; id++){

		/* si no existe el buzon o si el nombre ya existe */
		if (strcmp(mailbox, mailboxs[id]) != 0 && strcmp(new_name, mailboxs[id]) == 0){ 

			return ESP_NO;

		 }

	 }

	 /*implement rename of mailbox */
	 printf("rename complete\n");
	 return ESP_OK;

 }

esp_err_t SUBSCRIBE(char* mailbox){

	/*listar servidores de correo suscritos*/
	LSUB();

	for (int id = 0; id < count; id++){

		if (strcmp(mailbox,sub_mailbox[id]) == 0){
		
			/*ya esta suscrito*/

 		 }

	 }

	/* subscribe list*/ 
 	printf("subscribe complete\n");
	return ESP_OK;

 }


esp_err_t UNSUBSCRIBE(char* mailbox){

	/*listar servidores de correo suscritos*/
	LSUB();

	for (int id = 0; id < count; id++){

		if (strcmp(mailbox,sub_mailbox[id]) == 0){
		
			/*ya esta suscrito*/

 		 }

	 }

	/* unsubscribe list*/ 
 	printf("unsubscribe complete\n");
	return ESP_OK;

 } 

esp_err_t LIST(char* flags, char* possible_mailbox){

	/*implement algorithm to search possibles mailboxs*/

 } 

esp_err_t SELECT(char* mailbox){

	int num = EXIST();
	printf("[mailbox] %d mails on %s",num,mailbox);

	return ESP_OK;

 }
esp_err_t SEARCH(char* charset[]){

	switch(charset){

		case "ALL":

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
esp_err_t FETCH(){

	switch(){

		case "ALL":
		case "BODY":
		case "BODY.PEEK":
		case "BODYSTRUCTURE":
		case "ENVELOPE":
		case "FAST":
		case "FLAGS":
		case "FULL":
		case "INTERNALDATE":
		case "UID":
		default: printf("ERROR:");

	 }



 }
esp_err_t COPY(){

 }
esp_err_t UID(char* commands[]){



 }
esp_err_t STATUS(char* mailbox,char* state){

	if (strcmp(state,"MESSAGES")){

		/* code */
	 }
	if (strcmp(state,"RECENT")){
	
		/* code */
	 }
	if (strcmp(state,"UIDNEXT")){
		
		/* code */
 	 }
	if (strcmp(state,"UIDVALIDITY")){
		
		/* code */
	 }
	if (strcmp(state,"UNSEEN")){
		
		/* code */
	 }

	 return ESP_OK;

 }

esp_err_t STORE(char* messages[],char* name_element,char* value){

	switch(name_element){

		case "FLAGS":

			switch(value){

				case "/Seen":
				case "/Answered":
				case "/Flagged":
				case "/Deleted":
				case "/Recent":
				case "/Draft":
				default: printf("error\n");

			 }

		case "FLAGS.SILENT":

			switch(value){

				case "/Seen":
				case "/Answered":
				case "/Flagged":
				case "/Deleted":
				case "/Recent":
				case "/Draft":
				default: printf("error\n");

			 }

		case "+FLAGS":

			switch(value){

				case "/Seen":
				case "/Answered":
				case "/Flagged":
				case "/Deleted":
				case "/Recent":
				case "/Draft":
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
