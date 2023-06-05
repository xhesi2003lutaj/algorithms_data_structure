#include "Windgauge.h"


int main(){
	//Create a WindGauge object.
		WindGauge a;
    //Add five wind speeds:
		a.currentWindSpeed(15);
		a.currentWindSpeed(16);
		a.currentWindSpeed(12);
		a.currentWindSpeed(15);
		a.currentWindSpeed(15);
		a.print();



		a.currentWindSpeed(16);
		a.currentWindSpeed(17);
		a.currentWindSpeed(16);
		a.currentWindSpeed(20);
		a.currentWindSpeed(17);
		a.currentWindSpeed(16);
		a.currentWindSpeed(15);
		a.currentWindSpeed(16);
		a.currentWindSpeed(20);
		//dump the numbers again
		a.print();
		cout<<"Max "<<a.highest()<<endl;
		cout<<"Min "<<a.lowest()<<endl;
		cout<<"Avg "<<a.average()<<endl;



		return 0;
}
