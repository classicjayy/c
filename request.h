#ifndef REQUEST_H
#define REQUEST_H

#include <stddef.h>

// Enum to define common HTTP methods
typedef enum {
    REQ_GET,
    REQ_POST,
    REQ_PUT,
    REQ_DELETE
} RequestMethod;

// Struct to represent an HTTP/API Request
typedef struct {
    RequestMethod method;
    char *url;
    char *headers;
    char *body;
    size_t body_len;
} Request;

// Function declarations (Prototypes)

/**
 * Initializes a new Request object with default values.
 * @param req Pointer to the Request struct to initialize.
 * @param method The HTTP method (e.g., REQ_GET).
 * @param url The target URL.
 * @return 0 on success, -1 on failure.
 */
int request_init(Request *req, RequestMethod method, const char *url);

/**
 * Attaches a body payload to a POST/PUT request.
 * @param req Pointer to the initialized Request.
 * @param body The text data payload.
 */
void request_set_body(Request *req, const char *body);

/**
 * Frees all dynamically allocated memory inside the Request struct.
 * @param req Pointer to the Request to clean up.
 */
void request_free(Request *req);

#endif // REQUEST_H
