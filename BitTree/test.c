/*
 * 枚举
 **/
#include <stdio.h>

enum day {sun,mon,tue,wed,thu,fri,sat};

enum day day_after (enum day d) {
	
	enum day nd;
	switch (d) {
		case sun: nd = mon;
					break;
		case mon: nd = tue;
					break;
		case tue: nd = wed;
					break;
		case wed: nd = thu;
					break;
		case thu: nd = fri;
					break;
		case fri: nd = sat;
					break;
		case sat: nd = sun;
					break;	
	}
		return (nd);

}

int main (void) {
	
	enum day d = mon;
	int i;
	for (i=0; i<7; i++){
		d = day_after (d);
		printf("%d\n",d);
		
	}
}



