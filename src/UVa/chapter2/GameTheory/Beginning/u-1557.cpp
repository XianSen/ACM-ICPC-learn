#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date{
    int year;
    int month;
    int day;
    bool operator<(const Date & d) const{
	if(year < d.year) return true;
	if(year > d.year) return false;
	if(month < d.month) return true;
	if(month > d.month) return false;
	return day < d.day;
    }

    bool print(){
	printf("%04d-%02d-%02d\n", year, month, day);
    }
};

using namespace std;
map<Date, int> mdi;
//0 是正常的月份,1是闰年的月份
int days[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int* year_day(int year){
    if(year % 100 == 0)
	return (year % 400 == 0 ? days[1] : days[0]);
    return (year % 4 == 0 ? days[1] : days[0]);
}

bool next_day(Date &now){
    if(now.year == 2011 && now.month == 11 && now.day == 4)
	return false;

    int & year = now.year;
    int & month = now.month;
    int & day = now.day;
    
    day++;
    int* days = year_day(year);
    if(day > days[month]){ 
	day = 1;
	month ++;
    }

    if(month > 12){
	month = 1;
	year++;
    }

    return true;
}

bool next_month_day(Date & now){
    int day = now.day;  
    int month = now.month;
    if(month + 1 <= 12) month = month + 1;
    else month = 1;

    for(int i = 1; i <= 33; i++)
	if(next_day(now)){
	    if(now.day == day && now.month == month)
		return true;
	}else{
	    break;
	}

    return false;
}

int sg(Date now){
    Date next1 = now;
    Date next2 = now; 
    if(mdi.count(now) != 0)
	return mdi[now];

    int first = -1, second = -1;
    if(next_day(next1)){
	first = sg(next1);
    }

    if(next_month_day(next2)){
	second = sg(next2);
    }

    for(int i = 0;; i++)
	if(i != first && i != second){
	    mdi[now] = i;
	    return i;
	}
}

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
	Date now;
	scanf("%d %d %d",&now.year, &now.month, &now.day);

	Date next1 = now;
	Date next2 = now; 

	next_day(next1);
	next_month_day(next2);

	/*
	printf("\n\n");
	now.print();
	next1.print();
	next2.print();
	printf("\n\n");
	*/

	puts(sg(now) == 0 ? "NO" : "YES");
    }
    return 0;
}
