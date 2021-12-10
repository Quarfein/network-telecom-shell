#!/bin/bash

gcc -c base.c ;
gcc -c deconcat.c ;
gcc -o final base.o deconcat.o ;
