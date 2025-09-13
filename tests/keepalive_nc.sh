#!/bin/bash
# keepalive_nc.sh: Pipelining/keep-alive scenario
# Example: Send two requests in one connection
#!/usr/bin/env bash
PORT=${1:-9000}
( echo -en "GET /index.html HTTP/1.1\r\nHost: localhost\r\nConnection: Keep-alive\r\n\r\n"; \
  sleep 5; \
  echo -en "GET /index.html HTTP/1.1\r\nHost: localhost\r\nConnection: Keep-alive\r\n\r\n"; \
  sleep 5; \
  echo -en "GET /index.html HTTP/1.1\r\nHost: localhost\r\nConnection: Close\r\n\r\n" ) | nc 127.0.0.1 "$PORT"