const MAXLEN = 1024;

/*
 * Type for storing path
 */
typedef string filename<MAXLEN>;

/*
 * Structure for sending request. Expects the path of the file
 * and the byte number at which to start reading the file from
 */
struct request {
	filename logname;
	int start;
	filename option;
	filename keyword; 
};

/*
 * Type that represents the structute for request
 */
typedef struct request request;

/*
 * Type for storing a chunk of the file that is being
 * sent from the server to the client in the current
 * remote procedure call
 */
typedef string filechunk<MAXLEN>;

/*
 * Response sent by the server to the client as a response
 * to remote procedure call, containing the filechunk for
 * the current call and number of bytes actually read
 */
struct chunkreceive {
    filechunk data;
    int bytes;
};

/*
 * Type that represents the structure for file's chunks
 * to be received from the server
 */
typedef struct chunkreceive chunkreceive;

/*
 * union for returning from remote procedure call, returns
 * the proper chunkdata response if everything worked fine
 * or will return the error number if an error occured
 */
union readfile_res switch (int errno) {
    case 0:
        chunkreceive chunk;
    default:
        void;
};

/*
 * Remote procedure defined in the Interface Definition Language
 * of SUN RPC, contains PROGRAM and VERSION name definitions and
 * the remote procedure signature
 */
program FTPPROG {
    version FTPVER {
        readfile_res retrieve_file(request *) = 1;        
    } = 1;
} = 0x20000011;
