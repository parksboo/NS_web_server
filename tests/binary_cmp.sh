#!/bin/bash
# binary_cmp.sh: Binary transfer identity verification
curl -s http://localhost:8080/assets/img/sample.png -o out.png
cmp out.png www/assets/img/sample.png && echo 'OK' || echo 'DIFF'
