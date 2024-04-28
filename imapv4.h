#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define no_authenticate 0
#define authenticate    1
#define select          2
#define disconnection   3


#define num_commands 23

struct inbox{




 };

struct sub_mailbox{

	
 };

struct message{

	uint32_t uid;        //Atributo de mensaje Identificador Único
	uint32_t secuencial; //Atributo de mensaje Número de secuencia de mensaje
	char* flags;         //Atributo de mensaje Banderas
	char* fetch;         //Atributo de mensaje Fecha interna
	char* mimeb;		 //Atributo de mensaje Fecha interna
	char* message[];	 //text message
	
 } 

struct header{


 };

struct body{



 }; 

struct flags{

	bool Seen;
	bool Answered;
	bool Flagged;
	bool Deleted; 
	bool Recent;
	bool Draft;

 };

char* flags[6]{

	"/Seen"
	"/Answered"
	"/Flagged"
	"/Deleted" 
	"/Recent"
	"/Draft"

 };

char* commands[24]{

	"CAPABILITY"
	"NOOP"
	"LOGOUT"
	"AUTHENTICATE"
	"LOGIN"
	"SELECT"
	"EXAMINE"
	"CREATE"
	"DELETE"
	"RENAME"
	"SUBSCRIBE"
	"UNSUBSCRIBE"
	"LIST"
	"LSUB"
	"STATUS"
	"APPEND"
	"CHECK"
	"CLOSE"
	"EXPUNGE"
	"SEARCH"
	"FETCH"
	"COPY"
	"UID"
	"STATUS"

 };



esp_err_t NOOP(){}
esp_err_t LOGOUT(){}
esp_err_t AUTENTICATE(){}
esp_err_t LOGIN(){}
esp_err_t CREATE(){}
esp_err_t DELETE(){}
esp_err_t RENAME(){}
esp_err_t SELECT(){}
esp_err_t SEARCH(){}
esp_err_t FETCH(){}
esp_err_t COPY(){}
esp_err_t UID(){}

 

void func(void);
