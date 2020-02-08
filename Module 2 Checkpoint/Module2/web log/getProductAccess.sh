#!/bin/bash

logpath=$1

cut -d '	' -f 1,4 $logpath | sort -k1 | grep '/products/' | uniq