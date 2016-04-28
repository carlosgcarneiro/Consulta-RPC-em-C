#include <rpc/rpc.h>
#include <stdio.h>
#include <string.h>
#include "msg.h"

extern __thread int errno;

int get_file(char *option, char *keyword, char *logname)
{
    CLIENT *clnt;
    int total_bytes = 0, write_bytes, count=0;
    readfile_res *result;
    request req;
    FILE *fp, *file;
    char *buffer, str;
    const char *name = "greplist"; 

    req.logname = logname;
    req.start = 0;
    req.option = option;	
    req.keyword = keyword;

	fp = fopen("ips","r");
	printf("\n\n");
	buffer = (char *)malloc(15 * sizeof(char));
	
  	//while (!feof(fp)) {		
	str = fgetc(fp);
	while(str != EOF) {
		while(str != '\n') {				
			buffer[count] = str;
			count++;
			str = fgetc(fp);
		}
		
		/* Create client handle used for calling FTPPROG on the server designated on the command line. */ 
		/* Use the tcp protocol when contacting the server. */    
		clnt = clnt_create(buffer, FTPPROG, FTPVER, "tcp");
        	if (clnt == NULL) {
        	/* Couldn't establish connection with server */
         	/* Print error message and stop */         
        		clnt_pcreateerror(buffer);
        		exit(1);
    	   	}
    		file = fopen(name, "a");
    		/* Call the remote procedure readdir on the server */
	    	while (1) {
			req.start = total_bytes;
			result = retrieve_file_1(&req, clnt);
			if (result == NULL) {
			    /* An RPC error occurred while calling the server */
			    /* Print error message and stop */             	    
			    clnt_perror(clnt, buffer);
			    exit(1);
			}
			if (result->errno != 0) {
			    /* A remote system error occurred */
			    /* Print error message and stop */
			    errno = result->errno;
			    perror(name);
			    exit(1);
			}

			/* wirte data received from server inside a file */
			write_bytes = fwrite(result->readfile_res_u.chunk.data, 1, result->readfile_res_u.chunk.bytes, file);
			fwrite("\n", 1, 1, file);
			total_bytes += result->readfile_res_u.chunk.bytes;
			if (result->readfile_res_u.chunk.bytes < MAXLEN) 
		    	break;
	    	}
		total_bytes = 0;
		fwrite("\n", 1, 1, file);
		printf("comando no IP: %s realisado com sucesso.\n", buffer);
		free(buffer);
		buffer = (char *)malloc(15 * sizeof(char));	
		count = 0;
		str = fgetc(fp);
    }

	fclose(fp);
    fclose(file);

	printf("\n\nTodos os logs foram salvos corretamente. Verifique o arquivo greplist.\n\n\n");

    return 0;
}

int main(int argc, char *argv[])
{
   int result;

   if (argc != 5) {		
        fprintf(stderr, "usage: grep <options> <keywork> <filename>\n");
        exit(1);
   }

	get_file(argv[2], argv[3], argv[4]);
	
   return 0;
}
