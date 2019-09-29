#!/bin/sh

for f in *.h *.c ; do
	echo indent $f
	indent $f
done

