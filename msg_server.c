#include <rpc/rpc.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "msg.h"

extern __thread int errno;

readfile_res* retrieve_file_1_svc(request *req, struct svc_req *rqstp)
{
    FILE *file;
    char data[1024], *name = "resultgrep", command[80],  hostname[10];
    int bytes;
    static readfile_res res;
	

	/* Create grep command and save result in resulgrep file */
	strcpy(command, "grep ");
	strcat(command,req->option);
	strcat(command," ");
	strcat(command,req->keyword);
	strcat(command," ");
	gethostname(hostname, sizeof hostname);	
	strcat(hostname, req->logname);
	strcat(command,hostname);
	strcat(command," > resultgrep");
	system(command);

	printf("%s\n", command);
	
	
    /* open resultgrep file */		
    file = fopen(name, "a+");
	if (file == NULL) {
        res.errno = errno;
        return (&res);
    }
	
    /* write inside resultgrep file the hostname */	
    fprintf(file, "%s", hostname);
 
    fseek (file, req->start, SEEK_SET);
    bytes = fread(data, 1, 1024, file);

    res.readfile_res_u.chunk.data = data;
    res.readfile_res_u.chunk.bytes = bytes;

    /* Return the result */
    res.errno = 0;
    fclose(file);
    return (&res);
}

