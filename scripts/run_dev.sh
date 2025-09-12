#!/bin/bash
# run_dev.sh: 개발 실행 편의 스크립트
PORT=${1:-8080}
./http-server $PORT
