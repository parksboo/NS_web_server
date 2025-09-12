#!/bin/bash
# binary_cmp.sh: 바이너리 전송 동일성 검증
curl -s http://localhost:8080/assets/img/sample.png -o out.png
cmp out.png www/assets/img/sample.png && echo 'OK' || echo 'DIFF'
