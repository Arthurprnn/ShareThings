#include "../../include/temps.h"

int main(int argc, char *argv[]) {

    /*
    time_t begin = time( NULL );
    Temps timeInfos = localtime( & begin );

    printf("heure: %d minute: %d seconde: %d\n", timeInfos->tm_hour, timeInfos->tm_min, timeInfos->tm_sec);
    */

    Temps t = creer_temps(1585231358);
    printf("Temps : Le %02d/%02d/%4d à %02d:%02d:%02d\n", get_joursTemps(t), get_moisTemps(t)+1, get_anneesTemps(t)+1900, get_heuresTemps(t), get_minutesTemps(t), get_secondesTemps(t));
    return 0;
}