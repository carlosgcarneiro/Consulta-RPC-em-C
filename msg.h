/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _MSG_H_RPCGEN
#define _MSG_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAXLEN 1024

typedef char *filename;

struct request {
	filename logname;
	int start;
	filename option;
	filename keyword;
};
typedef struct request request;


typedef char *filechunk;

struct chunkreceive {
	filechunk data;
	int bytes;
};
typedef struct chunkreceive chunkreceive;


struct readfile_res {
	int errno;
	union {
		chunkreceive chunk;
	} readfile_res_u;
};
typedef struct readfile_res readfile_res;

#define FTPPROG 0x20000011
#define FTPVER 1

#if defined(__STDC__) || defined(__cplusplus)
#define retrieve_file 1
extern  readfile_res * retrieve_file_1(request *, CLIENT *);
extern  readfile_res * retrieve_file_1_svc(request *, struct svc_req *);
extern int ftpprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define retrieve_file 1
extern  readfile_res * retrieve_file_1();
extern  readfile_res * retrieve_file_1_svc();
extern int ftpprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_filename (XDR *, filename*);
extern  bool_t xdr_request (XDR *, request*);
extern  bool_t xdr_request (XDR *, request*);
extern  bool_t xdr_filechunk (XDR *, filechunk*);
extern  bool_t xdr_chunkreceive (XDR *, chunkreceive*);
extern  bool_t xdr_chunkreceive (XDR *, chunkreceive*);
extern  bool_t xdr_readfile_res (XDR *, readfile_res*);

#else /* K&R C */
extern bool_t xdr_filename ();
extern bool_t xdr_request ();
extern bool_t xdr_request ();
extern bool_t xdr_filechunk ();
extern bool_t xdr_chunkreceive ();
extern bool_t xdr_chunkreceive ();
extern bool_t xdr_readfile_res ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_MSG_H_RPCGEN */
