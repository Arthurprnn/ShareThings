#!/bin/sh

cd ./Entrees
make -f libentrees.mk clean
make -f libentrees.mk
cd ../Temps
make -f libtemps.mk clean
make -f libtemps.mk
cd ../Objets
make -f libobjets.mk clean
make -f libobjets.mk
cd ../Personnes
make -f libusers.mk clean
make -f libusers.mk
cd ../Prets
make -f libprets.mk clean
make -f libprets.mk
cd ../Administration
make -f libadministration.mk clean 
make -f libadministration.mk