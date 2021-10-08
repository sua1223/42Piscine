#!/bin/sh
cat /etc/passwd | grep -v "#" | cut -f 1 -d ':' |  awk 'NR%2 == 0' | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'
