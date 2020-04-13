#!/bin/sh

cd ../../data/Objets/$1
ls | wc -l > ../../../src/HTML/NombreFichier.txt 

ls > ../../../src/HTML/ListeFichierjson.txt

exit 0

