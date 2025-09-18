
#ifndef NSHTTP_RESPONSE_H_
#define NSHTTP_RESPONSE_H_

#include <string>
#include "http/status_codes.h"
#include "http/request.h"


namespace ns_http {

void Respond(int client_fd, Request& request);

void ErrorHandler(int client_fd, Request& request);


}  // namespace ns_http

#endif  // NSHTTP_RESPONSE_H_
