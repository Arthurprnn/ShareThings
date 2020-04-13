#!/bin/sh

cd ../../data/Prets
ls | wc -l > ../../src/Administration/NombreFichierPrets.txt 

ls > ../../src/Administration/ListeFichierPretsjson.txt

exit 0

