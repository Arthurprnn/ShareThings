#! /bin/sh

C=`date -R | cut -f2 -d' '`
D=`date -R | cut -f4 -d' '`
E=`date -R | cut -f5 -d' '`
for elt in $(date -R)
do
case "$elt" in
	Mon,)
		A="Lundi "
		;;
	Tue,)
		A="Mardi "
		;;
	Wed,)
		A="Mercredi "
		;;
	Thu,)
		A="Jeudi "
		;;
	Fri,)
		A="Vendredi "
		;;
	Sat,)
		A="Samedi "
		;;
	Sun,)
		A="Dimanche "
		;;
	Jan)
		B="Janvier "
		;;
	Feb)
		B="Février "
		;;
	Mar)
		B="Mars "
		;;
	Apr)
		B="Avril "
		;;
	May)
		B="Mai "
		;;
	Jun)
		B="Juin "
		;;
	Jul)
		B="Juillet "
		;;
	Aug)
		B="Aout "
		;;
	Sep)
		B="Septembre "
		;;
	Oct)
		B="Octobre "
		;;
	Nov)
		B="Novembre "
		;;
	Dec)
		B="December "
		;;
esac
done
echo "-$A$C $B$D $E :" >> CarnetDeBord.txt

cat >> CarnetDeBord.txt
echo "" >> CarnetDeBord.txt

exit 0
