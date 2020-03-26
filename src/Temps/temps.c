#include "../../include/temps.h"

Temps init_temps(){
    Temps t = (Temps)malloc(sizeof(struct tm));
    t->tm_sec = 0;
    t->tm_min = 0;
    t->tm_hour = 0;
    t->tm_mday = 0;
    t->tm_mon = 0;
    t->tm_year = 0;
    t->tm_wday = 0;
    t->tm_yday = 0;
    t->tm_isdst = 0;
    return t;
}

Temps creer_temps(time_t temps) {
    Temps t = init_temps();
    localtime_r(&temps, t);
    return t;
}

time_t creer_secondes_depuis_1970(Temps temps) {
    time_t t = mktime(temps);
    return t;
}

int get_secondesTemps(Temps t){
    return t->tm_sec;
}

int get_minutesTemps(Temps t){
    return t->tm_min;
}

int get_heuresTemps(Temps t){
    return t->tm_hour;
}

int get_joursTemps(Temps t){
    return t->tm_mday;
}

int get_moisTemps(Temps t){
    return t->tm_mon;
}

int get_anneesTemps(Temps t){
    return t->tm_year;
}

int get_jour_semaineTemps(Temps t){
    return t->tm_wday;
}

int get_jour_anneeTemps(Temps t){
    return t->tm_yday;
}

int get_isdstTemps(Temps t){
    return t->tm_isdst;
}

void set_secondesTemps(Temps t, int sec){
    t->tm_sec = sec;
}

void set_minutesTemps(Temps t, int min){
    t->tm_min = min;
}

void set_heuresTemps(Temps t, int hour){
    t->tm_hour = hour;
}

void set_joursTemps(Temps t, int day){
    t->tm_mday = day;
}

void set_moisTemps(Temps t, int mon){
    t->tm_mon = mon;
}

void set_anneesTemps(Temps t, int year){
    t->tm_year = year;
}

void set_jour_semaineTemps(Temps t, int wday){
    t->tm_wday = wday;
}

void set_jour_anneeTemps(Temps t, int yday){
    t->tm_yday = yday;
}

void set_isdstTemps(Temps t, int dst){
    t->tm_isdst = dst;
}