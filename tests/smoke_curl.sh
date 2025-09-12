#!/bin/bash
# smoke_curl.sh: 200/404/header check
curl -i http://localhost:8080/
curl -i http://localhost:8080/notfound
