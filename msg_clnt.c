/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "msg.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

readfile_res *
retrieve_file_1(request *argp, CLIENT *clnt)
{
	static readfile_res clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, retrieve_file,
		(xdrproc_t) xdr_request, (caddr_t) argp,
		(xdrproc_t) xdr_readfile_res, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
