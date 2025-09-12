#!/bin/bash
# smoke_curl.sh: 200/404/헤더 확인
curl -i http://localhost:8080/
curl -i http://localhost:8080/notfound
